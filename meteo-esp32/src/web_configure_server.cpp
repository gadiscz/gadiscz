#include <Arduino.h>
#include "global_vars.h"
//AsyncWebServer *server;   

// parses and processes webpages
// if the webpage has %SOMETHING% or %SOMETHINGELSE% it will replace those strings with the ones defined

String processor(const String& var) {
  if (var == "FIRMWARE") {
 //   return FIRMWARE_VERSION;
  }

  if (var == "FREESPIFFS") {
//    return humanReadableSize((SPIFFS.totalBytes() - SPIFFS.usedBytes()));
int pouzito(SD.usedBytes() / (1024 * 1024));
int celkem(SD.totalBytes() / (1024 * 1024));
String zbyva = String(celkem-pouzito);
 return zbyva;
  }

  if (var == "USEDSPIFFS") {
//    return humanReadableSize(SPIFFS.usedBytes());
int pouzito(SD.usedBytes() / (1024 * 1024));
  String thisString = String(pouzito);
 return thisString;
  }

  if (var == "TOTALSPIFFS") {
//    return humanReadableSize(SPIFFS.totalBytes());
 int celkem(SD.totalBytes() / (1024 * 1024));
  String thisString = String(celkem);
 return thisString;
  }
}

void configureWebServer()
{





///////////////////web na SD karte//////////////////////////////////////////////////////////////////

 server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SD, "/index.html", "text/html");
  });

 server->serveStatic("/", SD, "/");


   // presents a "you are now logged out webpage
  server->on("/IP", HTTP_GET, [](AsyncWebServerRequest * request) {
    String ipadresa = WiFi.localIP().toString().c_str();
    Serial.println(ipadresa);
     request->send(200, "text/plain", ipadresa);
  });
  }
 
////////////////////////////////////////////////////////////////////////////////////
  // configure web server
/*
   if url isn't found
  server->onNotFound(notFound);

  // run handleUpload function when any file is uploaded
  server->onFileUpload(handleUpload);

  // visiting this page will cause you to be logged out
  server->on("/logout", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->requestAuthentication();
    request->send(401);
  });

  // presents a "you are now logged out webpage
  server->on("/SD/logged-out", HTTP_GET, [](AsyncWebServerRequest * request) {
    String logmessage = "Client:" + request->client()->remoteIP().toString() + " " + request->url();
    Serial.println(logmessage);
    request->send_P(401, "text/html", logout_html, processor);
  });

  server->on("/SD", HTTP_GET, [](AsyncWebServerRequest * request) {
    String logmessage = "Client:" + request->client()->remoteIP().toString() + + " " + request->url();

    if (checkUserWebAuth(request)) {
      logmessage += " Auth: Success";
      Serial.println(logmessage);
      request->send_P(200, "text/html", index_html, processor);
    } else {
      logmessage += " Auth: Failed";
      Serial.println(logmessage);
      return request->requestAuthentication();
    }

  });

  server->on("/reboot", HTTP_GET, [](AsyncWebServerRequest * request) {
    String logmessage = "Client:" + request->client()->remoteIP().toString() + " " + request->url();

    if (checkUserWebAuth(request)) {
      request->send(200, "text/html", reboot_html);
      logmessage += " Auth: Success";
      Serial.println(logmessage);
      shouldReboot = true;
    } else {
      logmessage += " Auth: Failed";
      Serial.println(logmessage);
      return request->requestAuthentication();
    }
  });

  server->on("/listfiles", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    String logmessage = "Client:" + request->client()->remoteIP().toString() + " " + request->url();
    if (checkUserWebAuth(request)) {
      logmessage += " Auth: Success";
      Serial.println(logmessage);
      request->send(200, "text/plain", listFiles(true));
    } else {
      logmessage += " Auth: Failed";
      Serial.println(logmessage);
      return request->requestAuthentication();
    }
  });
  */
///////////////////////////////////////////////////////////////////
/*
    server->on("/sdcreatedir", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    String datazwebu = request->getParam("data_in")->value();
 Serial.print("sdcreatedir: ");
 Serial.println(datazwebu);
 
 //File root = SD.open("/"+dir_actual+"/");
 // root.rewindDirectory();

   Serial.print("Dir_nazev je: ");
  Serial.println(datazwebu);
  datazwebu = datazwebu;
  //datazwebu = "/" + datazwebu
  if (SD.exists("/" +datazwebu)){
   Serial.println("Slozka uz existuje!!!");
 datazwebu = "Slozka uz existuje!!!";
 }
 else{
  datazwebu = "/" + datazwebu;
 Serial.print("Vytvářím složku: ");
 Serial.println(datazwebu);
 
 if (SD.mkdir(datazwebu)){
  Serial.println("Slozka vytvorena");
 datazwebu = "Slozka vytvorena";
 }
 else
 { 
   Serial.print("ERROR pri vytvareni složky: ");
 Serial.println(datazwebu);
   datazwebu = "ERROR pri vytvareni složky...";     
      }
  }
 request->send(200, "text/plain", datazwebu);
  });


 ///////////////////////////////////////////////////////////////////
    server->on("/selectfiles", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    const char *fileName = request->getParam("name")->value().c_str();
 Serial.print("select files: ");
 Serial.println(fileName);
  select_files = fileName;
  request->send(200, "text/plain", fileName);
  });

     server->on("/selectdir", HTTP_GET, [](AsyncWebServerRequest * request)
  {
    const char *dirName = request->getParam("name")->value().c_str();
 Serial.print("select dir: ");
  Serial.println(dirName);
  select_dir = dirName;
  request->send(200, "text/plain", dirName);
  });
  ///////////////////////////////////////
    server->on("/readdir", HTTP_GET, [](AsyncWebServerRequest * request)
  {
  request->send(200, "text/plain", select_dir);
  });
  
    server->on("/readfile", HTTP_GET, [](AsyncWebServerRequest * request)
  {
     request->send(200, "text/plain", select_files);
  });


     server->on("/resetsd", HTTP_GET, [](AsyncWebServerRequest * request)
  {
     select_dir = "/";
     select_files = "";
     request->send(200, "text/plain", "Reset");
  });

  /////////////////////////////////////

  server->on("/file", HTTP_GET, [](AsyncWebServerRequest * request) {
    String logmessage = "Client:" + request->client()->remoteIP().toString() + " " + request->url();
    if (checkUserWebAuth(request)) {
      logmessage += " Auth: Success";
      Serial.println(logmessage);

      if (request->hasParam("name") && request->hasParam("action")) {
        const char *fileName = request->getParam("name")->value().c_str();
        const char *fileAction = request->getParam("action")->value().c_str();

        logmessage = "Client:" + request->client()->remoteIP().toString() + " " + request->url() + "?name=" + String(fileName) + "&action=" + String(fileAction);
 ////////////////////////////////////////////////////
 //       if (!SPIFFS.exists(fileName)) {
 ////////////////////////////////////////////////////
  if (!SD.exists(fileName)) {
 ////////////////////////////////////////////////////
          Serial.println(logmessage + " ERROR: file does not exist");
          request->send(400, "text/plain", "ERROR: file does not exist");
        } else {
          Serial.println(logmessage + " file exists");
          if (strcmp(fileAction, "download") == 0) {
            logmessage += " downloaded";
  ////////////////////////////////////////////////////           
         //   request->send(SPIFFS, fileName, "application/octet-stream");
  ////////////////////////////////////////////////////
   request->send(SD, fileName, "application/octet-stream");
   ////////////////////////////////////////////////////           
          } else if (strcmp(fileAction, "delete") == 0) {
            logmessage += " deleted";
               ////////////////////////////////////////////////////    
       //     SPIFFS.remove(fileName);
               //////////////////////////////////////////////////// 
               
               SD.remove(fileName);
               SD.rmdir(fileName);  
                  ////////////////////////////////////////////////////    
            request->send(200, "text/plain", "Deleted File: " + String(fileName));
          } else {
            logmessage += " ERROR: invalid action param supplied";
            request->send(400, "text/plain", "ERROR: invalid action param supplied");
          }
          Serial.println(logmessage);
        }
      } else {
        request->send(400, "text/plain", "ERROR: name and action params required");
      }
    } else {
      logmessage += " Auth: Failed";
      Serial.println(logmessage);
      return request->requestAuthentication();
    }
  });
 }

 void notFound(AsyncWebServerRequest *request) {
  String logmessage = "Client:" + request->client()->remoteIP().toString() + " " + request->url();
  Serial.println(logmessage);
  request->send(404, "text/plain", "Not found");
 }

 // used by server.on functions to discern whether a user has the correct httpapitoken OR is authenticated by username and password
 bool checkUserWebAuth(AsyncWebServerRequest * request) {
  bool isAuthenticated = false;

  if (request->authenticate(config.httpuser.c_str(), config.httppassword.c_str())) {
    Serial.println("is authenticated via username and password");
    isAuthenticated = true;
  }
  return isAuthenticated;
 }


 }
 // handles uploads to the filserver

 void handleUpload(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
  // make sure authenticated before allowing upload
  if (checkUserWebAuth(request)) {
    String logmessage = "Client:" + request->client()->remoteIP().toString() + " " + request->url();
    Serial.println(logmessage);

    if (!index) {
      logmessage = "Upload Start: " + String(filename);
      // open the file on first call and store the file handle in the request object

 /////////////////////////////////////////////////////////////////////////////      
 //     request->_tempFile = SPIFFS.open("/" + filename, "w");
 //////////////////////////////////////////////////////////////////////////////  
   if (select_dir == "/"){
     request->_tempFile = SD.open(select_dir + filename, "w");
     }
     else
     {
       request->_tempFile = SD.open(select_dir + "/" + filename, "w");
     }

 //////////////////////////////////////////////////////////////////////////////    
      Serial.println(logmessage);
    }

    if (len) {
      // stream the incoming chunk to the opened file
      request->_tempFile.write(data, len);
      logmessage = "Writing file: " + String(filename) + " index=" + String(index) + " len=" + String(len);
      Serial.println(logmessage);
    }

    if (final) {
      logmessage = "Upload Complete: " + String(filename) + ",size: " + String(index + len);
      // close the file handle as the upload is now done
      request->_tempFile.close();
      Serial.println(logmessage);
      request->redirect("/");
    }
  } else {
    Serial.println("Auth: Failed");
    return request->requestAuthentication();
  }
 }
//*/