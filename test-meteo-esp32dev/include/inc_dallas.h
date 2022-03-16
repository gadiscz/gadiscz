#include <DallasTemperature.h>
#include <OneWire.h>

OneWire oneWire(14); // pin D6
DallasTemperature dallas(&oneWire);
float temp1, temp2;

////////////////////////////////////////////////
