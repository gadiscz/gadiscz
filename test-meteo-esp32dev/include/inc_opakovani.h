#include <Arduino.h>
#include <ESP32TimerInterrupt.h>
bool opakovani_ok;
unsigned long actualniMillis;
unsigned long startMillis;
const unsigned long prodleva = 60000;
