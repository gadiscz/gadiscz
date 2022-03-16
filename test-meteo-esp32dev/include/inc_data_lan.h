void serial_print_l(EthernetClient cll) 
{
String data_in;  
String serial_print(String data_in);

data_in = serial_print(data_in);

Serial.print("zpetna serial_print: ");
Serial.println(data_in);
 
cll.print(data_in);
serialmonitor = "";
  }   
///////////////////////////
void verze_l(EthernetClient cll) 
{
String data_in;  
String verze(String data_in);

data_in = verze(data_in);

Serial.print("zpetna verze: ");
Serial.println(data_in);
 
cll.print(data_in);
  }   
///////////////////////////

void zapis_eeprom_l(EthernetClient cll) 
{
String data_in;  
String data_zapis_eeprom(String data_in);

data_in = data_zapis_eeprom(data_in);

Serial.print("zpetna data_zapis_eeprom: ");
Serial.println(data_in);
 
cll.print(data_in);
  }   
     
///////////////////////////


void zapis_eeprom_bit_l(EthernetClient cll) 
{
String data_in;  
String data_zapis_eeprom_bit(String data_in);

data_in = data_zapis_eeprom_bit(data_in);

Serial.print("zpetna data_zapis_eeprom_bit: ");
Serial.println(data_in);
 
cll.print(data_in);
  }  
///////////////////////////


void wifi_nebo_lan_l(EthernetClient cll) 
{
String data_in;  
String wifi_nebo_lan(String data_in);

data_in = wifi_nebo_lan(data_in);

Serial.print("zpetna wifi_nebo_lan: ");
Serial.println(data_in);
 
cll.print(data_in);
  }      
////////////////////////////////////////
void srazky_mm_l(EthernetClient cll) 
{
String data_in;  
String srazky_mm(String data_in);

data_in = srazky_mm(data_in);

Serial.print("zpetna srazky_mm: ");
Serial.println(data_in);
 
cll.print(data_in);
  }      
////////////////////////////////////////
void vitr_rychlost_l(EthernetClient cll) 
{
String data_in;  
String vitr_rychlost(String data_in);

data_in = vitr_rychlost(data_in);

Serial.print("zpetna vitr_rychlost: ");
Serial.println(data_in);
 
cll.print(data_in);
  }   
////////////////////////////////////////
void eeprom_data_2_l(EthernetClient cll) 
{
String data_in;  
String eeprom_data_2(String data_in);

data_in = eeprom_data_2(data_in);

Serial.print("zpetna vazba 2: ");
Serial.println(data_in);

cll.print(data_in);
 }
 ////////////////////////////////////////////////


void eeprom_bit_0_read_l(EthernetClient cll) 
{
String data_in;  
String eeprom_bit_0_read(String data_in);

data_in = eeprom_bit_0_read(data_in);

Serial.print("zpetna eeprom_bit_0_read: ");
Serial.println(data_in);

cll.print(data_in);
 }
////////////////////////////////////////////////


void eeprom_bit_1_read_l(EthernetClient cll) 
{
String data_in;  
String eeprom_bit_1_read(String data_in);

data_in = eeprom_bit_1_read(data_in);

Serial.print("zpetna eeprom_bit_1_read: ");
Serial.println(data_in);

cll.print(data_in);
 }
/////////////////////////////////////////////

void response_hodnota_cas_l(EthernetClient cll)
{
    
String data_in;  
String data_zapis_cas(String data_in);

data_in = data_zapis_cas(data_in);

Serial.print("zpetna vazba 2: ");
Serial.println(data_in);
 
cll.print(data_in);
}
//////////////////////////////////////////////////
