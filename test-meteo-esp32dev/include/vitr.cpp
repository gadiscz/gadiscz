 void vitr()
 {
  ///////////////////////////////////////////
  
 // zapad W         50-250
 // severozapad    250-600
 // sever N        600-1200
 // jihozapad     1200-1800
 // Severovychod  1800-2400
 // jih S         2400-3100
 // jihovychod    3100-3550
 // vychod E      3550-4100
  
 


  Serial.print("Prumer: ");
  Serial.println(average);
  if (sm){
   serialmonitor = serialmonitor + "Prumer:";
   serialmonitor = serialmonitor + String(average) + "\n";
}

  if ((average <= 250)&&(average >= 50))
   {
  Serial.println("Fouká ze západu (W)");
  if (sm){
  serialmonitor = serialmonitor + "Fouká ze západu (W)\n";
  }
  smer="W";
  smer_stupne=270;
}
  if ((average <= 599)&&(average >= 250))
   {
  Serial.println("Fouká ze severozápadu (N-W)");
  if (sm){
  serialmonitor = serialmonitor + "Fouká ze severozápadu (N-W)\n";
  }
  smer="NW";
  smer_stupne=315;
}
  if ((average <= 1199)&&(average >= 600))
   {
  Serial.println("Fouká ze severu (N)");
  if (sm){
  serialmonitor = serialmonitor + "Fouká ze severu (N)\n";
  }
  smer="N";
  smer_stupne=0;
}
  if ((average <= 1799)&&(average >= 1200))
   {
  Serial.println("Fouká z jihozápadu (S-W)");
  if (sm){
  serialmonitor = serialmonitor + "Fouká z jihozápadu (S-W)\n";
  }
  smer="SW";
  smer_stupne=225;
}
  if ((average < 2399)&&(average >= 1800))
   {
  Serial.println("Fouká ze severovýchodu (N-E)");
  if (sm){
  serialmonitor = serialmonitor + "Fouká ze severovýchodu (N-E)\n";
  }
  smer="NE";
  smer_stupne=45;
}
  if ((average < 3099)&&(average >= 2400))
   {
  Serial.println("Fouká z jihu (S)");
  if (sm){
  serialmonitor = serialmonitor + "Fouká z jihu (S)\n";
  }
  smer="S";
  smer_stupne=180;
}
  if ((average <= 3549)&&(average >= 3100))
   {
  Serial.println("Fouká z jihovýchodu (S-E)");
  if (sm){
  serialmonitor = serialmonitor + "Fouká z jihovýchodu (S-E)\n";
  }
  smer="SE";
  smer_stupne=135;
}
  if ((average <= 4200)&&(average >= 3550))
   {
  Serial.println("Fouká z východu (E)");
  if (sm){
  serialmonitor = serialmonitor + "Fouká z východu (E)\n";
  }
  smer="E";
  smer_stupne=90;
}
}
