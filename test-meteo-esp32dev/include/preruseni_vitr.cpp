#include <Arduino.h>
void preruseni_vitr()
{
/////////////////////////////////////////////////////
  aktualnicasvitr = millis();
if (aktualnicasvitr - startcasvitr >= prodlevavitr) {
  vitrpovoleni=true;
  startcasvitr = aktualnicasvitr;
}
else {
 vitrpovoleni=false; 
}
  // Pokud eviduji preruseni
  if(vitrpovoleni==true){
    // Pozastav detekci preruseni
    cli();
    // Navys pocet pulzu
    pulzyvitr++;
    // Resetuj informaci o preruseni
  //  v = false;
    // Vypis aktualni pocet pulzu do seriove linky
  
    // Opet spust detekci preruseni
    sei();
  }
}
