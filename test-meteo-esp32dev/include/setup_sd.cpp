void setup_sd()
{
SD.begin(15);
delay(50);
   // initialize SD card
    Serial.println("Initializing SD card...");
    if (!SD.begin(15)) {
        Serial.println("ERROR - SD card initialization failed!");
        //return;    // init failed
    }
    else
    {
    Serial.println("SUCCESS - SD card initialized.");
    }
    // check for index.htm file
    if (!SD.exists("/index.htm")) {
        Serial.println("ERROR - Can't find index.htm file!");
       // return;  // can't find index file
    }
     else
    {
    Serial.println("SUCCESS - Found index.htm file.");
}


  
}
