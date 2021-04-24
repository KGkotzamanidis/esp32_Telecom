#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <WiFiClient.h>

AsyncWebServer apache(80);
String processor(const String& var);

const char* ssid = "Electronic_Stuff";
const char* pswd = "Z75cA6895BcTu1";
const char* Account_id ="anatolius";
const char* Account_pswd = pswd;

void setup(void){
  Serial.begin(115200);
    if(!SPIFFS.begin(true)){
    Serial.println("Error whime mounting data FS.");
  }
  WiFi.begin(ssid,pswd);
  Serial.print("Try to connect:");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  Serial.printf("Connect in %s with LocalIP: ",ssid);
  Serial.print(WiFi.localIP());
  Serial.print(" and MAC: ");
  Serial.print(WiFi.macAddress());
  Serial.println();
  apache.on("/",HTTP_GET,[](AsyncWebServerRequest *request){
    request->send(SPIFFS,"/index.html");
  });
  apache.on("/img/icon.png",HTTP_GET,[](AsyncWebServerRequest *request){
    request->send(SPIFFS,"/img/icon.png");
  });
  apache.on("/css/styles.css",HTTP_GET,[](AsyncWebServerRequest *request){
    request->send(SPIFFS,"/css/styles.css","text/css");
  });
  apache.begin();
}

void loop(void){

}