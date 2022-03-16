void send_data()
{ 
if (lan == true){
  EthernetClient client;
  }
if (wifistatus == true){
  WiFiClient client;
  }
        client.connect(serverurl, 80);
delay(1000);
       client.print("GET http://meteo.gadis.cz/meteo.php?pw=7tJPZ6LaArRimrlz&data=");
//1 <#date format=dd-mm-yy> datum ve formátu dd-mm-yy

//Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

       client.print(cas_year);
       client.print('-');
       client.print(cas_month);
       client.print('-');
       client.print(cas_day);
       client.print(";");
//2 <#timehhmmss> čas ve formátu hh:mm:ss
       client.print(cas_hour);
       client.print(':');
       client.print(cas_min);
       client.print(':');
       client.print(cas_sec);
       client.print(";");
//3  teplota      
client.print(teplotabme);
client.print(";");
//4 vlhkost vzduchu  
client.print(vlhkostbme);
client.print(";");
//5 Tlak
client.print(tlakbme);
client.print(";");
//6 vitr
client.print(kmhod);
client.print(";");
//7 smer vetru
client.print(smer);
client.print(";");
//8 srážky
client.print(srazkymm);
client.print(";");
//9 sluneční svit
client.print("0");
client.print(";");
//10 Výška hladiny
client.print("4");
client.print(";");
//13 UV
client.print("0");
client.print(";");
//14 Blesky
client.print("6");
client.print(";");
//15 Vzdalenost blesku
client.print("7");
client.print(";");
//16 Teplota zarizeni
client.print("23.0");
client.print(";");
//17 Vlhkost půdy
client.print("9");
client.print(";");
//18 Teplota senzor 1
client.print("9");
client.print(";");
//19 vitr naraz
client.print(kmhodmax);
client.print(";");
//20 vitr smer stupne
client.print(smer_stupne);
client.println();
       client.stop();
 Serial.println("Data poslané");   
  if (sm == true){
  serialmonitor = serialmonitor + "Data poslané...";
    }  
   
    //serialmonitor = serialmonitor + String(pulzysrazky) + "\n";    
   }
   
  
