
void preruseni_vitr_prepocet()
{
  
  // Vypocitej pocet celych otocek za minutu
  // Jedna otocka ma dva pulzy * 20, protoze
  // tato funkce se vola kazde tri sekundy
   rpm = pulzyvitr / 4;
  rpm = rpm * 12;
  pulzyvitr = 0;
 
    
  if (lastrpm <= rpm){ 
  if (rpm >= rpmmax){
  rpmmax = rpm;
  }
  }
  lastrpm = rpm;
  

  
   ///////////////////////////////
float  rpmsmax = rpmmax / 60;

  // kmhodmax = (rpmmax *60);
  float msecmax = rpmsmax * 0.22;
        kmhodmax = msecmax * 3.6;
float lastrpms = lastrpm / 60;
float ms = lastrpms * 0.22; // x 0,22 = m/hod
kmhod = ms *3.6;   // m/hod x 3.6 = km/hod
 Serial.print("rpm : ");
Serial.println(lastrpm); 
 Serial.print("rpm max: ");
Serial.println(rpmmax); 
Serial.print("Km/hod max: ");
Serial.println(kmhodmax);
Serial.print("Km/hod: ");
Serial.println(kmhod);
//////////////////////////////////////   
///////////////////////////////////
  

}
////////////////////////////////////
