////////////////////////////bme//////////////////////////////////////
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
int teplotabme;
int tlakbme;
int vlhkostbme;
int korekce = 33;
///////////////////////dallas////////////////////////////////////
