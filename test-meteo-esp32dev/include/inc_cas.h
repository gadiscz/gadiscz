#include <Arduino.h>

//////////////////////////////////////////////////////////////////////////
const char* ntpServer = "0.cz.pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

 byte cas_hour;
 byte cas_min;
 byte cas_sec;

byte cas_day;
byte cas_month;
int cas_year;
/////////////////////////wifi///////////////////////////////////////////
