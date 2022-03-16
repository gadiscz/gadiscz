void setup_wifi()
 {
if (WiFi.status() != WL_CONNECTED) {
 
// scan....
Serial.print("scan.... ");
 int n = WiFi.scanNetworks();
 for (int i = 0; i < n; ++i) {
 if (WiFi.SSID(i)== ssid ) {
  Serial.print("Connecting to ");
    Serial.println(ssid);
 WiFi.begin(ssid,password); //trying to connect the modem
 break;
 }
 if (WiFi.SSID(i)== ssid2) {
  Serial.print("Connecting to ");
    Serial.println(ssid2);
 WiFi.begin(ssid2,password2); //trying to connect the modem
 break;
 }
  if (WiFi.SSID(i)== ssid3) {
  Serial.print("Connecting to ");
    Serial.println(ssid3);
 WiFi.begin(ssid3,password3); //trying to connect the modem
 break;
 }
 }
///////////////////////////////////    
      WiFi.hostname(aHostname);
    if (WiFi.status() != WL_CONNECTED) {      // Potvrzení připojení k síti
      reconnectwifi++;
      
      Serial.print(reconnectwifi);
      Serial.println("/3");
      delay (500);
      if (reconnectwifi < 3){
     // ESP.restart();
      setup_wifi();
      }
    else {
     delay (5000);
    wifistatus = false;
    reconnectwifi = 0;  
    }
    }
    if (WiFi.status() == WL_CONNECTED){
     delay (500);
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    String ipadresa = WiFi.localIP().toString().c_str();
    delay (500);
    wifistatus = true;
    reconnectwifi = 0;
    server.begin();
    Serial.println("Nastavena WIFI");
   
serialmonitor = serialmonitor + "Nastavena WIFI\n";
serialmonitor = serialmonitor + "ipadresa je:";
serialmonitor = serialmonitor + ipadresa + "\n";

}
else {
Serial.println("Wifi nejede");
  }
 }
 }
