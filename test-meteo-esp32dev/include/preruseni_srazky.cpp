#include <Arduino.h>
void preruseni_srazky()
{
///////////////////////////////////////////////
  aktualnicassrazky = millis();
if (aktualnicassrazky - startcassrazky >= prodlevasrazky) {
  srazkypovoleni=true;
  startcassrazky = aktualnicassrazky;
}
else {
 srazkypovoleni=false; 
}
  // Pokud eviduji preruseni
  if(srazkypovoleni==true){
    // Pozastav detekci preruseni
    cli();
    // Navys pocet pulzu
    pulzysrazky++;
    // Resetuj informaci o preruseni
   // s = false;
    // Vypis aktualni pocet pulzu do seriove linky
    
    // Opet spust detekci preruseni
    sei();
    Serial.print(" Detekovany spulzy srazky: ");
    Serial.println(pulzysrazky);
    if (sm==true){
      Serial.print(" podminka sm ok ");
  serialmonitor = serialmonitor + "Detekovany spulzy srazky:";
  serialmonitor = serialmonitor + String(pulzysrazky) + "\n";
    }

    srazkymm =  pulzysrazky * 0.3;
  }
}
