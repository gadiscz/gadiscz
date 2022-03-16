String webpage = R"=====(
<!DOCTYPE html>
<html>
<head>
  <title>Meteo - GadisCZ</title>
  <meta charset="UTF-8">
  <meta name="description" content="Dvířka - Nykl">
  <meta name="keywords" content="HTML, CSS, JavaScript">
  <meta name="author" content="GadisCZ">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<!--/////////////////////////////////////css/////////////////////////////////-->
<style type="text/css">
.button {
  background-color: #4CAF50; /* Green */
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
}

table, th, td {
  border:1px solid black;
  border-collapse: collapse;
}


<!--/////////////////////////////////////css/////////////////////////////////-->



</style>
<body style="background-color: #f9e79f ">
<center>
<div>
<h1>AJAX BASED ESP8266 WEBSERVER</h1>
<a href="/firmware" target="_blank">Update Firmware (jen pro wifi)</a><br><br>
<a href="/setting">Nastavení</a><br><br>
Jedu na: <b><span id="wifi_nebo_lan_view">NA</span></b><br>
počet položek v eeprom: <b><span id="pocet_eeprom">NA</span></b>
<!---->
<br>

  
</div>
<!---->
<br>
<!--//////////////////zapis 1///////////////////-->

<!--//////////////////tlacitko 1///////////////////-->
 <br>

<div><h2>
  Aktualní hodnota tmy: <span id="adc_val">0</span><br><br>
  Srážky mm: <span id="srazkymm_view">0</span><br><br>
  Nastavená hodnota pro tmu: <span id="eeprom_value_2_view">0</span><br><br>
  Rychlost větru: <span id="vitr_rychlost_view">0</span><br><br>
  EEprom 3: <span id="eeprom_val_3">0</span><br><br>
  EEprom 4: <span id="eeprom_val_4">0</span><br><br>
  EEprom Nová: <span id="eeprom_value_nova">0</span><br><br>
  Otevřeno: <span id="state_z">NA</span><br>
  Zavřeno: <span id="state_o">NA</span>
</h2>
</div>
<script>

////////////////////////////////////////////////////////////
    //////////////////////zapis 1 eeprom ////////////////////////////////
function zapsateeprom(input_form_id, value_type)
 {  
      
  var data = document.getElementById(input_form_id).value;  // text tlacitka pri prepnuti
  if (data){
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById(input_form_id + "_response").innerHTML = this.responseText;
      console.log("input form id je:");
      console.log(input_form_id);
      console.log("this responseText je:");
      console.log(this.responseText);
    }
  };
//  xhttp.open('GET', `zapis_eeprom?data_in==${value_type}=${data}`, true);
  xhttp.open("GET", "zapis_eeprom?data_in=="+ value_type +"="+ data + "-", true);
  xhttp.send();
}
}

///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
setInterval(function() 
{
  getData();
  
  //////////////////////////////////////////////
}, 1000); 

setInterval(function() 
{
 getData_wifi_nebo_lan();
 getData_read_eeprom_2();
 getData_srazky_mm();
 
  //////////////////////////////////////////////
}, 5000); 


/////////////////////cteni eeprom 2//////////////////////////////////////
function getData_read_eeprom_2() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("eeprom_value_2_view").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "eeprom_value2", true);
  xhttp.send();
}
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////cteni eeprom wifimanager/////////////////////////////////////////
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("adc_val").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "adcread", true);
  xhttp.send();
}
/////////////////////////cteni polozek/////////////////////////////////////////
function getData_wifi_nebo_lan() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("wifi_nebo_lan_view").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "wifi_nebo_lan", true);
  xhttp.send();
}
////////////////////////////////////////////////////////////////////////
function getData_srazky_mm() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("srazkymm_view").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "srazky_mm", true);
  xhttp.send();
}
////////////////////////////////////////////////////////////////////////
function getData_vitr_rychlost() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("vitr_rychlost_view").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "vitr_rychlost", true);
  xhttp.send();
}
////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////
</script>
</center>
</body>
</html>
)=====";
