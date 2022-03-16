#include <SPI.h>
#include <EthernetENC.h>
#define REQ_BUF_SZ   50

////////////////////////////////////////////////////
#ifdef CORE_TEENSY
  // For Teensy 4.0
  #if defined(__IMXRT1062__)
  #define BOARD_TYPE      "TEENSY 4.0"
  #elif ( defined(__MKL26Z64__) || defined(ARDUINO_ARCH_AVR) )
  #define BOARD_TYPE      "TEENSY LC or 2.0"
  #else
  #define BOARD_TYPE      "TEENSY 3.X"
  #endif
#else
// For Mega
#define BOARD_TYPE      "AVR Mega"
#endif
//////////////////////////////////////////////////////////////////

int activon=0;
int activoff=0;

bool linkon;
bool linkoff;
bool lan = false;




///////////////////////////

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 209, 199);
EthernetServer lserver(80);
