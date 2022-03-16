void opakovani()
 {

actualniMillis = millis();
if (actualniMillis - startMillis >= prodleva) {
opakovani_ok=true;
startMillis = actualniMillis;
 }
 }
