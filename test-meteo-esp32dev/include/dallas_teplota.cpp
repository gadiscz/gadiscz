void dallas_teplota()
 {
  dallas.requestTemperatures();
  temp1 = dallas.getTempCByIndex(0);
  temp2 = dallas.getTempCByIndex(1);
  
  Serial.print("Temp1 is ");
  Serial.print(temp1, 1); // one decimal places
//Serial.print(temp1, 4); // four decimal places
  Serial.println(" C");
  Serial.print("Temp2 is ");
  Serial.print(temp2, 1);
  Serial.println(" C\n");
  }
