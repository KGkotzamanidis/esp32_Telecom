#include "Settings.h"

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
  apache.on("/login",HTTP_GET,[](AsyncWebServerRequest *request){
    String inputMessage0,inputMessage1,inputParam0,inputParam1;
    if((request->hasParam(param_AccountID)) && (request->hasParam(param_PasswordID))){
      inputMessage0 = request->getParam(param_AccountID)->value();
      inputMessage1 = request->getParam(param_PasswordID)->value();
      inputParam0 = param_AccountID;
      inputParam1 = param_PasswordID;
    }
   if((inputMessage0 == default_username) && (inputMessage1 == default_password)){
      request->send(SPIFFS,"/attack_wifi.html");
    }
    else{
      request->send(SPIFFS,"/403.html");
    }
  });
  apache.begin();
}

void loop(void){
}