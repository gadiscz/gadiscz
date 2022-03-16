#include "FS.h"              //To access the file system 
#include <SD.h> 

bool SD_present;
File UploadFile;

#include "sd_spravce_webpages.h"

String nazev ="";
String select_dir = "/";
String select_files = "";
String listFiles(bool ishtml = false);