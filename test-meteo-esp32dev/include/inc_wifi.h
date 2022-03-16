#ifdef ESP32
  #include <WiFi.h>
  #include <WiFiClient.h>
 // #include <WiFiUdp.h>
  #include <WebServer.h>
  #include <ESPmDNS.h>
  #include <Update.h>
#else
  #include <ESP8266WiFi.h>
  #include <WiFiClient.h>
  #include <ESP8266WebServer.h>
  #include <ESP8266mDNS.h>
#endif


WiFiClient client;
WebServer server(80);




/////////////////////////wifi///////////////////////////////////////////
const char* ssid      = "GadisFCB3-2.4G";               // Nastavení připojení k síti
const char* password  = "banikfcb";
const char *ssid2     = "GadisFCB";
const char *password2 = "banikfcb";
const char *ssid3     = "GadisFCB2-2.4G";
const char *password3 = "banikfcb";
//const char* server = "http://doma.gadis.cz"; //URL adresa serveru    
const char* serverurl = "http://doma.gadis.cz"; //URL adresa serveru 
//////////////////////////////////////////////////////////////////
int reconnectwifi = 0;
bool wifi;
bool wifistatus = false;
