#ifndef __SETTINGS_H
#define __SETTINGS_H
/*
*   Project Includes
*/
#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <WiFiClient.h>
/*
*   WebServer Settings
*/
#define web_port 80
AsyncWebServer apache(web_port);
/*
*   Wifi Settings
*/
const char* ssid = "Electronic_Stuff";
const char* pswd = "Z75cA6895BcTu1";
/*
*   Account Settings
*/
const char* param_AccountID = "AccountID:";
const char* param_PasswordID = "PasswordID:";
const char* default_username = "admin";
const char* default_password = "admin";
#endif