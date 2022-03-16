void lan_web()
 {
  String inStr;
EthernetClient client = lserver.available();  // try to get client

    if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                // buffer first part of HTTP request in HTTP_req array (string)
                // leave last element in array as 0 to null terminate string (REQ_BUF_SZ - 1)
                if (req_index < (REQ_BUF_SZ - 1)) {
                    HTTP_req[req_index] = c;          // save HTTP request character
                    req_index++;
                }
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                 if (inStr.length() < 100) {
                   inStr += c;
               }
                if (c == '\n' && currentLineIsBlank) {
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                 
                   if (inStr.indexOf("setting") > 0) {
                    
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: keep-alive");
                    client.println();
                        // send web page
                        webFile = SD.open("/index.htm");        // open web page file
                    client.print(webFile); // send web page to client
                    }
                                 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    
                    
                    else{       
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");


                    /////////////////////////////////////////////////////////////////////////////
                    
                    // remainder of header follows below, depending on if
                    // web page or XML page is requested
                    // Ajax request - send XML file
 //////////////////////////////////////////////////////////////////////////////////
                    if (StrContains(HTTP_req, "adcread")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                         response_hodnota_cas_l(client);
                    }
 //////////////////////////////////////////////////////////////////////////////////
                    if (StrContains(HTTP_req, "verze")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                         verze_l(client);
                    }

                    
 //////////////////////////////////////////////////////////////////////////////////


                    else if (StrContains(HTTP_req, "serial_print")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                         serial_print_l(client);
                    }
  //////////////////////////////////////////////////////////////////////////////////
 
                    else if (StrContains(HTTP_req, "srazky_mm")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                         srazky_mm_l(client);
                    }
 //////////////////////////////////////////////////////////////////////////////////
 
                    else if (StrContains(HTTP_req, "vitr_rychlost")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                         vitr_rychlost_l(client);
                    }

                    
  //////////////////////////////////////////////////////////////////////////////////                   
                    else if (StrContains(HTTP_req, "reset")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                   //     reset_esp();
                    }

                    else if (StrContains(HTTP_req, "test_pozadavek")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                   //     test_funkce();
                    }

                    else if (StrContains(HTTP_req, "wifi_nebo_lan")) {
                        // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                        wifi_nebo_lan_l(client);
                    }

                   else if (StrContains(HTTP_req, "zapis_eeprom")) {
                    // send rest of HTTP header
                          client.println("Content-Type: text/plain");
                          client.println("Connection: keep-alive");
                          client.println();
                         // send XML file containing input states
                        zapis_eeprom_l(client);
                        
                    }

                  else if (StrContains(HTTP_req, "zapis_eeprom_bit")) {
                    // send rest of HTTP header
                          client.println("Content-Type: text/plain");
                          client.println("Connection: keep-alive");
                          client.println();
                         // send XML file containing input states
                        zapis_eeprom_bit_l(client);
                        
                    }

                    

                     else if (StrContains(HTTP_req, "eeprom_value2")) {
                    // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                        eeprom_data_2_l(client);
                    }
                    
                       else if (StrContains(HTTP_req, "eeprom_bit_0_read")) {
                    // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                        eeprom_bit_0_read_l(client);
                    }
                           else if (StrContains(HTTP_req, "eeprom_bit_1_read")) {
                    // send rest of HTTP header
                        client.println("Content-Type: text/plain");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send XML file containing input states
                        eeprom_bit_1_read_l(client);
                    }
  //////////////////////////////////////////////////////////////////////////////////                  
                    else {  // web page request
                        // send rest of HTTP header
                        client.println("Content-Type: text/html");
                        client.println("Connection: keep-alive");
                        client.println();
                        // send web page
                      //  webFile = SD.open("/index.htm");        // open web page file
                      client.print(webpage); // send web page to client
                            
                        }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                  }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    // display received HTTP request on serial port
                   // Serial.print("Přijate data z www:");
                   // Serial.println(HTTP_req);
                    // reset buffer index and all buffer elements to 0
                    req_index = 0;
                    StrClear(HTTP_req, REQ_BUF_SZ);
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
}
