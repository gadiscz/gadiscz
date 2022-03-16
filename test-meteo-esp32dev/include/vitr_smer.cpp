void vitr_smer()
 {

///////////////////////smer vetru vypocet a prumer////////////////////////////////
        // subtract the last reading:
   if (readIndex == 0){
    total = 0;
  }
  // read from the sensor:
  
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
    readIndex = 0;
  }
  else {
   vitr_smer(); 
  }

  

  
 }
