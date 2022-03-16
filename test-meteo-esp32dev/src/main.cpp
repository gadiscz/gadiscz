
/*
 * 
 * 
Neni stejna knihovna pro LAN(ENC28J60) a WIFI(ESP32) proto je rozdvojeni programu a pak zase spojeni...
Ota WEB nejde na LAN je jen psany pro wifi...




*/

#include <Arduino.h>
#include <stdint.h>
byte id = 99;                                /// číslo senzoru volitelne
const char* aHostname = "ESP32-testy";  /// hostname wifi
String verzeprg = "0.1";  /// hostname wifi
String serialmonitor = "";
bool sm = false;



#include "preruseni_vitr_prepocet.cpp"
#include "inc_lan.h"
#include "inc_opakovani.h"
#include "inc_ota.h"
#include "ota_web.h"

#include "inc_cas.h"
#include "inc_sd.h"

#include "inc_wifi.h"
#include "inc_ota_web.h"
#include "inc_vitr.h"
#include "inc_bme.h"
#include "inc_dallas.h"

#include "inc_eeprom.h"

int cislotest = 0;

#include "index.h"
#include "setting.h"
char c;

/////////////////////////////////
extern void cas();
extern void opakovani();
extern void preruseni_srazky();
extern void vitr();
extern void vitr_smer();
extern void preruseni_vitr();
extern void preruseni_vitr_prepocet();
extern void send_data_wifi(String datasend);
extern void setup_wifi();
extern void setup_lan();
extern void lan_web();
extern void preruseni_vitr_prepocet();
extern void send_data();
extern void opakovani();
extern void dallas_teplota();
extern void setup_ota();
extern void setup_ota_web();
extern void setup_sd();
void reset_esp(); 

/////////////////////////////////////////////SD karta////////////////////////////////////////

File webFile;               // the web page file on the SD card
char HTTP_req[REQ_BUF_SZ] = {0}; // buffered HTTP request stored as null terminated string
char req_index = 0;              // index into HTTP_req buffer
////////////////////////////////////////////////////////////////


////////////////////////////bme//////////////////////////////////////
////////////////////////////////////////////////

unsigned long previousMillis = 0;
const long interval = 1000;
const int ledwifi = 25;
const int ledlan = 26;
int ledState = LOW;
//////////////////////////////////////////////////
///////////////////////////////////
unsigned long aktualnicassrazky;
unsigned long startcassrazky;
const unsigned long prodlevasrazky = 1000; //ms
bool srazkypovoleni;
// Globalni promenna indikujici pulz
// Slovo volatile dava prekladaci vedet, ze k promenne bude
// pristupovat jak asynchronni preruseni, tak moje smycka loop,
// takze nesmi dojit ke kolizi pri pokusu o jeji zmenu
//volatile bool s = false;

// globalni promenna s poctem pulzu
int pulzysrazky = 0;
float srazkymm = 0.0;
/*
void srazky_p(){
  // Pokud doslo k preruseni, nastav pulz na true
 s = true;
}
*/
#include "inc_data_web.h"
#include "inc_data_lan.h"
#include "inc_data_wifi.h" 


void handleRoot() 
{
  if (wifistatus==true)
  {
 String s = webpage;
  server.send(200, "text/html", s);
}
}

void handleSetting() 
{
  if (wifistatus==true)
  {
 String s = setting;
  server.send(200, "text/html", s);
}
}
void setup() {
  // put your setup code here, to run once:
EEPROM.begin(512);
Serial.begin(115200);
/////////////////////////////////////////////////////
delay(100);
Serial.print("---------------------Verze: ");
Serial.print(aHostname);
Serial.print("-");
Serial.print(verzeprg);
Serial.println("--------------------");
  /////////////////////casovac//////////////////////////////////
timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 5000000, true);
  timerAlarmEnable(timer);

  //////////////////////////////////////////
  startcassrazky = millis();
  startcasvitr = millis();
/////////////////////////////////////////////////////
  pinMode(4, INPUT);
  pinMode(13, INPUT);
  pinMode(33, INPUT);
pinMode(ledwifi, OUTPUT);
pinMode(ledlan, OUTPUT);
  // Nastav interrupt: Pokud se bude menit stav z HIGH na LOW,
  // spust funkci preruseni
  // Nastav interrupt: Pokud se bude menit stav z HIGH na LOW,
  // spust funkci preruseni
  attachInterrupt(digitalPinToInterrupt(4), preruseni_srazky, FALLING);
  attachInterrupt(digitalPinToInterrupt(13), preruseni_vitr, FALLING);
///////////bme/////////////////////
//////////////////////////////////

// disable Ethernet chip
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    pinMode(12, INPUT);        // switch is attached to Arduino pin 7
   ////////////////////////////////////////////////////////////////////////////

  int x = 0;
  for (int i = 70; i < 77; ++i)
    {
      set_bit[x] = bool(EEPROM.read(i));
      x++;
    }

Serial.print("set_bit[x]: ");
Serial.println(set_bit[0]); 
Serial.print("set_bit[x]: ");
Serial.println(set_bit[1]);
Serial.print("set_bit[x]: ");
Serial.println(set_bit[2]);
Serial.print("set_bit[x]: ");
Serial.println(set_bit[3]);
Serial.print("set_bit[x]: ");
Serial.println(set_bit[4]);
if (set_bit[0]==true){
sm=true; 
}
else{
 sm=false; 
}
Serial.print("sm: ");
Serial.println(sm);    

    
delay(100);
//////////////////////////////////////
setup_lan();
if (lan == false){ 
setup_wifi();
}

MDNS.begin(aHostname);
 if (!MDNS.begin(aHostname)) { //http://esp32.local
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");
  ///////////////////////////////
  ///////////bme/////////////////////
 unsigned status;
    
    // default settings
    status = bme.begin(0x76);  
    // You can also pass in a Wire library object like &Wire2
    // status = bme.begin(0x76, &Wire2)
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); 
        Serial.println(bme.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        //while (1) delay(10);
        }
        else {
         Serial.println("BME280 - OK"); 
        
    }
//////////////////dallas//////////////////
dallas.begin();
/////////////////sdcard

setup_sd();

/////////////////////////////////////////////CAS////////////////////////////////////////
//init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  cas();
  
/////////////////////////////////////////////CAS////////////////////////////////////////

server.on("/setting", handleSetting);
server.on("/", handleRoot);
server.on("/reset", reset_esp);
server.on("/serial_print", serial_print_w);
server.on("/eeprom_value2", eeprom_data_2_w);
server.on("/eeprom_bit_0_read", eeprom_bit_0_read_w);
server.on("/eeprom_bit_1_read", eeprom_bit_1_read_w);
//server.on("/zapis_eeprom", zapis_eeprom);
server.on("/zapis_eeprom", data_zapis_eeprom_w);
server.on("/zapis_eeprom_bit", data_zapis_eeprom_bit_w);
server.on("/adcread", data_zapis_cas_w);
server.on("/wifi_nebo_lan", wifi_nebo_lan_w);
server.on("/srazky_mm", srazky_mm_w);
server.on("/vitr_rychlost", vitr_rychlost_w);
server.on("/verze", verze_w);

server.begin();


//lserver.begin();
Serial.println("HTTP server started");
setup_ota();
setup_ota_web();
 //////////////////////////reset prumeru smeru/////////////////////////////////// 
    // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }

}

void loop() {
int x =0;  
for (int i = 70; i < 77; ++i)
    {
      set_bit[x] = bool(EEPROM.read(i));
      x++;
    }

 bool set_bit_sm = set_bit[0];  
if (set_bit_sm == true){
   sm=true; 
}
else{
 sm=false; 
}

    //////////kontrola pripojeni///////////////
if ((Ethernet.linkStatus() != LinkON)&&(WiFi.status() != WL_CONNECTED)) {
setup_wifi();
lan = false;
}

if ((WiFi.status() != WL_CONNECTED)&&(Ethernet.linkStatus() == LinkON)&&(lan != true)) {
setup_lan();
wifistatus = false;
}
/////////////////////////////////////////////////////
ArduinoOTA.handle();

///////////////////////////////////////////////////////////////////////////////////////////////
if (wifistatus == true){
  ledState=HIGH;

server.handleClient(); 
digitalWrite(ledwifi, ledState);  
}

else{
    ledState=LOW;
digitalWrite(ledwifi, ledState); 
}

if (lan == true){
lan_web();
digitalWrite(ledlan, HIGH); 
 
}
else{
  digitalWrite(ledlan, LOW);
}

vitr_smer();
opakovani();
if (opakovani_ok==true){
dallas_teplota();
//bme_teplota();
cas();

Serial.print(pulzysrazky);
Serial.println(" Pulzy srazky");
Serial.print(pulzyvitr);
Serial.println(" Pulzy vitr");
Serial.print("Otacky prumer: ");
Serial.println(averagevitr);
Serial.print("Km/hod: ");
Serial.println(kmhod);
Serial.print("Km/hod naraz: ");
Serial.println(kmhodmax);
    vitr();
   send_data();
    
    pulzysrazky=0;
    srazkymm=0;
     
    rpmmax=0;
    kmhod=0;
    kmhodmax=0;
    opakovani_ok=false;
 }

 ////////////////vyvolani casovacem pocitadlo rychlosti vetru///////////////////////////////////
   if (interruptCounter > 0) {
 
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
 
    totalInterruptCounter++;
    preruseni_vitr_prepocet();

}
////////////////////////////////////////


}
///////////////////////////////////////////////////////////////////////////////////////////////









void test_funkce()
{
 Serial.println ("test funkce");
 }
 
////////////////////////////////////////////////////////////////////////
void sensor_data() 
{
 int a = analogRead(A0);
 
 String sensor_value = String(a);
 server.send(200, "text/plane", sensor_value);
 }
//////////////////////////////////////////////////////////////////
void reset_esp() 
{
  Serial.print("Restartuji ESP");
ESP.restart();
}

// sets every element of str to 0 (clears array)
void StrClear(char *str, char length)
{
    for (int i = 0; i < length; i++) {
        str[i] = 0;
    }
}

// searches for the string sfind in the string str
// returns 1 if string found
// returns 0 if string not found
char StrContains(char *str, char *sfind)
{
    char found = 0;
    char index = 0;
    char len;

    len = strlen(str);
    
    if (strlen(sfind) > len) {
        return 0;
    }
    while (index < len) {
        if (str[index] == sfind[found]) {
            found++;
            if (strlen(sfind) == found) {
                return 1;
            }
        }
        else {
            found = 0;
        }
        index++;
    }

    return 0;
}
