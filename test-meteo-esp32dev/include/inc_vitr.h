///////////////////////////////
float kmhodmax = 0;
float kmhod = 0;
float lastrpm = 0;
float rpmmax = 0;
float rpm = 0;
char* smer;
volatile long pulzy = 0;
unsigned long aktualnicasvitr;
unsigned long startcasvitr;
const unsigned long prodlevavitr = 100; //ms
bool vitrpovoleni;
// Globalni promenna indikujici pulz
// Slovo volatile dava prekladaci vedet, ze k promenne bude
// pristupovat jak asynchronni preruseni, tak moje smycka loop,
// takze nesmi dojit ke kolizi pri pokusu o jeji zmenu
//volatile bool v = false;
// globalni promenna s poctem pulzu
int pulzyvitr = 0;
/*
void vitr_p(){
  // Pokud doslo k preruseni, nastav pulz na true
 v = true;
}
*/
/////////////////////////////////////////////////
volatile int interruptCounter;
int totalInterruptCounter;
 
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
 
void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
 
}
///////////////////////mereni prumerny vitr///////////////////////////////
int averagevitr = 0;
///////////////////////mereni smeru///////////////////////////////
int smer_stupne = 0;
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int inputPin = 33;
///////////////////////////////
