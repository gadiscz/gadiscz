#include <EEPROM.h>
byte set_bit[] = {0,1,2,3,4,5,6,7}; //pole s piny připojených LED diod

int pocet_eeprom = 4; //pocet polozek nastaveni
int eeprom_byte = 88; // zacatek eeprom
int eeprom_bit = 70; // zacatek eeprom
int eeprom_int = 80; // zacatek eeprom
int eeprom_byte_nova = 16; // zacatek eeprom
int max_hodnota_z_eeprom = 8;
int max_hodnota_z_eeprom_int = 4;
int id_eeprom_read = 0;
int cislo = 1;
/////////////////////////////////////////
struct package_eeprom_1 {
  uint val = 0;
  char prvni[20] = "";
  char druhy[20] = "";
  char treti[20] = "";
  char ctvrty[20] = "";
  char paty[20] = "";
  };
typedef struct package_eeprom_1 Package_eeprom_1;
Package_eeprom_1 data_eeprom_1;
//////////////////////
