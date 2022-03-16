
/*
 * 
 *  zmena pro git
Neni stejna knihovna pro LAN(ENC28J60) a WIFI(ESP32) proto je rozdvojeni programu a pak zase spojeni...
Ota WEB nejde na LAN je jen psany pro wifi...
*/

#include <Arduino.h>

#include "web_configure_server.h"

/////////////////////////wifi///////////////////////////////////////////
#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
//#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>


#define aHostname "meteo"
#define FIRMWARE_VERSION "v0.9.9"

const String default_ssid = "GadisFCB";
const String default_wifipassword = "banikfcb";
const String default_httpuser = "gadis";
const String default_httppassword = "398500";
const int default_webserverporthttp = 80;

// configuration structure
struct Config {
  String ssid;               // wifi ssid
  String wifipassword;       // wifi password
  String httpuser;           // username to access web admin
  String httppassword;       // password to access web admin
  int webserverporthttp;     // http port number for web admin
};

// variables
Config config;                        // configuration
bool shouldReboot = false;            // schedule a reboot
// AsyncWebServer *server;               // initialise webserver
///////
int reconnectwifi = 0;
bool wifi;
bool wifistatus = false;
///////



#include "web_configure_server.h"

void configureWebServer();


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);


  //////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
  Serial.println("Loading Configuration ...");

  config.ssid = default_ssid;
  config.wifipassword = default_wifipassword;
  config.httpuser = default_httpuser;
  config.httppassword = default_httppassword;
  config.webserverporthttp = default_webserverporthttp;

  Serial.print("\nConnecting to Wifi: ");
  WiFi.begin(config.ssid.c_str(), config.wifipassword.c_str());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n\nNetwork Configuration:");
  Serial.println("----------------------");
  Serial.print("         SSID: "); Serial.println(WiFi.SSID());
  Serial.print("  Wifi Status: "); Serial.println(WiFi.status());
  Serial.print("Wifi Strength: "); Serial.print(WiFi.RSSI()); Serial.println(" dBm");
  Serial.print("          MAC: "); Serial.println(WiFi.macAddress());
  Serial.print("           IP: "); Serial.println(WiFi.localIP());

  Serial.println();

  // configure web server
  Serial.println("Configuring Webserver ...");
  server = new AsyncWebServer(config.webserverporthttp);
  configureWebServer();

//////////////////////////////////////////////////////////////////////////////////////// 
// scan....
Serial.print("scan.... ");
  
  Serial.print("Connecting to ");
    Serial.println(config.ssid.c_str());
WiFi.begin(config.ssid.c_str(), config.wifipassword.c_str());

 
///////////////////////////////////    
      WiFi.hostname(aHostname);

    if (WiFi.status() == WL_CONNECTED){
     delay (500);
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    }


  //////////////////////////////////////////////////////////////

}

void loop() {
  // put your main code here, to run repeatedly:

}

#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
//#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>