void setup_lan()
{

  Ethernet.init(GPIO_NUM_5);  // ESP32 with Adafruit Featherwing Ethernet

 

  
  
  Ethernet.begin(mac, ip);
delay (1000);
  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
     lan = false;
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
    lan = false;
     }
   if (Ethernet.linkStatus() == LinkON) {
    Serial.println("Ethernet cable connected.");
    lan = true;
    lserver.begin();
Serial.println("Nastavena LAN");
Serial.print("IP je: ");
Serial.println(ip);
String ipadresa = ip.toString().c_str();
Serial.print("ipadresa je: ");
 Serial.println(ipadresa);

serialmonitor = serialmonitor + "Nastavena LAN\n";
serialmonitor = serialmonitor + "IP je:";
serialmonitor = serialmonitor + (ipadresa) + ", ";
   
  }

  
  
}
