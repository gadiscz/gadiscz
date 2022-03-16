String data_zapis_eeprom(String result)
 {
  void send_data_wifi(String data_in);
  
  String data_in;  
  String cislostring;
  String datastring;
  int eeprom_cislo = eeprom_byte; 
  String ok = "OFF";
//////////////////////////
if (lan==true){
  datastring = HTTP_req;
}
  else
  {
    datastring = server.arg("data_in");
  }

int znakzacatek = datastring.indexOf("=");
int znakkonec = datastring.lastIndexOf("=");
int znakdatakonec = datastring.lastIndexOf("-");
if (lan == true){
cislostring = (datastring.substring(znakzacatek+2, znakkonec));

}else{
cislostring = (datastring.substring(znakzacatek+1, znakkonec));  
}



int cisloint = cislostring.toInt(); //p
cisloint = (cisloint * 8) - 8;
eeprom_cislo = eeprom_cislo+cisloint;

String hodnota = (datastring.substring(znakkonec+1,znakdatakonec));

        for (int i = eeprom_cislo; i < eeprom_cislo+8; ++i) { EEPROM.write(i, 0); }
              for (int i = 0; i < hodnota.length(); ++i)
            {
              EEPROM.write(eeprom_cislo+i, hodnota[i]);
     
            }
      EEPROM.commit();
eeprom_cislo = eeprom_byte;
cisloint = cislo;
      
     data_in = "Zapsáno:" + hodnota;
     Serial.print("data_in: ");
     Serial.println(data_in);

if (lan==true){
  return data_in;
}
  else
  {
    send_data_wifi(data_in);
    return "nic";
  }
}
///////////////////////////////zapis eeprom bit////////////////////////////////////////////
String data_zapis_eeprom_bit(String result)
 {
  void send_data_wifi(String data_in);
  
  String data_in;  
  String cislostring;
  String datastring;
  int eeprom_cislo = eeprom_bit; 
  String ok = "OFF";
//////////////////////////
if (lan==true){
  datastring = HTTP_req;
}
  else
  {
    datastring = server.arg("data_in");
  }
Serial.print("datastring: ");
Serial.println(datastring);
int znakzacatek = datastring.indexOf("=");
int znakkonec = datastring.lastIndexOf("=");
int znakdatakonec = datastring.lastIndexOf("-");
if (lan == true){
cislostring = (datastring.substring(znakzacatek+2, znakkonec));
Serial.print("cislostring: ");
Serial.println(cislostring);
}else{
cislostring = (datastring.substring(znakzacatek+1, znakkonec)); 
Serial.print("cislostring: ");
Serial.println(cislostring); 
}



int cisloint = cislostring.toInt(); //p
Serial.print("cisloint: ");
Serial.println(cisloint);
//cisloint = cisloint * 4;
eeprom_cislo = eeprom_cislo+cisloint;

String hodnota = (datastring.substring(znakkonec+1,znakdatakonec));
Serial.print("eeprom_cislo: ");
Serial.println(eeprom_cislo);
Serial.print("hodnota: ");
Serial.println(hodnota);
bool hodnota_bool;

if (hodnota == "true"){
hodnota_bool = true;
Serial.print("true: ");
Serial.println(hodnota_bool);
}

if (hodnota == "false"){
hodnota_bool = false; 
Serial.print("false: ");
Serial.println(hodnota_bool);
}

Serial.print("hodnota.length: ");
Serial.println(hodnota.length());

EEPROM.write(eeprom_cislo, 0);

EEPROM.write(eeprom_cislo, hodnota_bool);

  
   EEPROM.commit();
//eeprom_cislo = eeprom_byte_;
cisloint = cislo;
      
     data_in = "Zapsáno:" + hodnota;
     Serial.print("data_in: ");
     Serial.println(data_in);

if (lan==true){
  return data_in;
}
  else
  {
    send_data_wifi(data_in);
    return "nic";
  }
}
///////////////////////////////////////////////////////////////////////////
String data_zapis_cas(String result)
 {
void send_data_wifi(String data_in);
  
  cislotest++;
  String cisloteststring = String(cislotest);

  if (lan==true){
  return cisloteststring;
}
  else
  {
   send_data_wifi(cisloteststring);
   return "nic";
  }
}
///////////////////////////////////////////////////////////////////////////
String verze(String result)
 {
void send_data_wifi(String data_in);
  
 
  
  if (lan==true){
  return verzeprg;
}
  else
  {
   send_data_wifi(verzeprg);
   return "nic";
  }
}
///////////////////////////////////////////////////////////////////////////
String serial_print(String result)
 {
void send_data_wifi(String data_in);


  if (lan==true){
   
  return serialmonitor;
}
  else
  {
    
   send_data_wifi(serialmonitor);
   return "nic";
   
  }
}
////////////////////////////////////////////////////////////////////////////////////////
String eeprom_data_2(String result)
 {
void send_data_wifi(String data_in);
  
      //////////////////////////////////////
//  Serial.println("Reading EEPROM data1");
   String eeprom_value_2;
  for (int i = 96; i < 104; ++i)
    {
      eeprom_value_2 += char(EEPROM.read(i));
    }

    

  if (lan==true){
  return eeprom_value_2;
}
  else
  {
   send_data_wifi(eeprom_value_2);
   return "nic";
  }
}
////////////////////////eeprom read bit////////////////////////////////////////////////////////////////


String eeprom_bit_0_read(String result)
 {
void send_data_wifi(String data_in);
  
      //////////////////////////////////////
//  Serial.println("Reading EEPROM data1");
    String data_read;
    int i = 70;
    data_read = bool(EEPROM.read(i));
    
    data_read= String(data_read);
    Serial.print("data_read");
    Serial.println(data_read);
  if (lan==true){
  return data_read;
}
  else
  {
   send_data_wifi(data_read);
   return "nic";
  }
}
////////////////////////eeprom read bit////////////////////////////////////////////////////////////////


String eeprom_bit_1_read(String result)
 {
void send_data_wifi(String data_in);
  
      //////////////////////////////////////
//  Serial.println("Reading EEPROM data1");
    String data_read;
    int i = 71;
    data_read = bool(EEPROM.read(i));
    
    data_read= String(data_read);
    Serial.print("data_read");
    Serial.println(data_read);
  if (lan==true){
  return data_read;
}
  else
  {
   send_data_wifi(data_read);
   return "nic";
  }
}

/////////////////////////wifi nebo lan///////////////////////////////////////////////////////////////
String wifi_nebo_lan(String result)
 {
void send_data_wifi(String data_in);
  

  if (lan==true){
   String wifi_lan="Lan";
   return wifi_lan;
}
  else
  {
    String data_in="WIFI";
    send_data_wifi(data_in);
    Serial.println("prikaz na cteni wifi nebo lan...");
    return "nic";
  }
 
}
////////////////////////srazky mm////////////////////////////////////////////////////////////////
String srazky_mm(String result)
 {
void send_data_wifi(String data_in);
  

  if (lan==true){
  String data_in = String(srazkymm);
  Serial.print("Srazky - data_in: ");
  Serial.println(data_in);
  return data_in;
}
  else
 {
   String data_in = String(srazkymm);
  
   Serial.print("Srazky - data_in: ");
   Serial.println(data_in);
   send_data_wifi(data_in);
   return "nic";
  }
}
////////////////////////vitr_rychlost////////////////////////////////////////////////////////////////
String vitr_rychlost(String result)
 {
void send_data_wifi(String data_in);
  

  if (lan==true){
  String data_in = String(kmhod);
  Serial.print("vitr_rychlost: ");
  Serial.println(data_in);
  return data_in;
}
  else
 {
   String data_in = String(kmhod);
  
   Serial.print("vitr_rychlost: ");
   Serial.println(data_in);
   send_data_wifi(data_in);
   return "nic";
  }
}
