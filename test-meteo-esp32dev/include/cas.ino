void cas()
{
 
struct tm timeinfo;
if(!getLocalTime(&timeinfo)){ 
  Serial.println("Failed to obtain time");
  return; 
  } //
  Serial.println(&timeinfo, "%m %d %Y / %H:%M:%S");
  //
 // scanf(&timeinfo, "%m %d %Y / %H:%M:%S") 
  cas_hour = timeinfo.tm_hour;
  cas_min = timeinfo.tm_min;
  cas_sec = timeinfo.tm_sec;

cas_day = timeinfo.tm_mday;
cas_month = timeinfo.tm_mon + 1;
cas_year = timeinfo.tm_year +1900; 
}
