String setting = R"=====(
<!DOCTYPE html>
<html>
<head>
  <title>Meteo - Nastavení</title>
  <meta charset="UTF-8">
  <meta name="description" content="Nastavení">
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
<h1>Nastavení</h1>
<a href="/firmware" target="_blank">Update Firmware (jen pro wifi)</a><br><br>
<a href="/">Home</a><br><br>
Jedu na: <b><span id="wifi_nebo_lan_view">NA</span></b><br>
Verze: <b><span id="verze_view">NA</span></b>
<!---->
<br>
  <button class="button" onclick="restart_esp()">Restart_ESP</button>
  
</div>
<!---->
<br>
<!--//////////////////zapis 1///////////////////-->
<table border="1" width="600">
<tr>
<th>Informace</th>
<th>Hodnota</th>
<th>Potvrzení zápisu</th>
<th>Nastaveno</th>
</tr>
<!--//////////////////zapnuti serial monitor///////////////////-->
<tr>
<div>
<td><h3>Monitoring dat</h3></td>

<td><button onclick="zapsateeprom_bit('0',this)" value="OFF">OFF</button></td>
<td><span id="0_response">  </span></td>
<td><b><span id="eeprom_bit_0_view">NA</span></b></td>
</div>
<!--//////////////////rezerva///////////////////-->
<tr>
<div>
<td><h3>rezerva1</h3></td>

<td><button onclick="zapsateeprom_bit('1',this)" value="OFF">OFF</button></td>
<td><span id="1_response">  </span></td>
<td><b><span id="eeprom_bit_1_view">NA</span></b></td>
</div>
<!--//////////////////rezerva1///////////////////-->
<tr>
<div>
<td><h3>rezerva2</h3></td>

<td><button onclick="zapsateeprom_bit('2',this)" value="OFF">OFF</button></td>
<td><span id="2_response">  </span></td>
<td><b><span id="eeprom_bit_2_view">NA</span></b></td>
</div>
<!--//////////////////rezerva2///////////////////-->
<tr>
<div>
<td><h3>rezerva3</h3></td>

<td><button onclick="zapsateeprom_bit('3',this)" value="OFF">OFF</button></td>
<td><span id="3_response">  </span></td>
<td><b><span id="eeprom_bit_3_view">NA</span></b></td>
</div>
<!--//////////////////zapis pocet eeprom///////////////////-->
<tr>
<div>
<td><h3>zapsani poctu eeprom</h3></td>
<td><input type="text" oninput="this.value = this.value.replace(/[^0-9.]/g, '').replace(/(\..*?)\..*/g, '$1');" id="eeprom_value_2" size="3" maxlength="3" ><input type="button" onclick="zapsateeprom('eeprom_value_2', 2)" value="Zapsat" /></td>
<td><span id="eeprom_value_2_response">  </span></td>
</div>
<!--//////////////////zapis 1///////////////////-->
<tr>
<div>
<td><h3>Nastavení hodnoty pro tmu (2)</h3></td>
<td><input type="text" oninput="this.value = this.value.replace(/[^0-9.]/g, '').replace(/(\..*?)\..*/g, '$1');" id="eeprom_value_3" size="8" maxlength="8" ><input type="button" onclick="zapsateeprom('eeprom_value_3', 3)" value="Zapsat" /></td>
<td><span id="eeprom_value_3_response">  </span></td>
</div>
<!--//////////////////zapis 2///////////////////-->
</tr>
<tr>
<div>
<td><h3>zapsani dat 3 jen znaky bez cisel</h3></td>
<td><input type="text" onkeypress="return (event.charCode > 64 && event.charCode < 91) || (event.charCode > 96 && event.charCode < 123) || (event.charCode==32)" id="eeprom_value_4" size="8" maxlength="8" ><input type="button" onclick="zapsateeprom('eeprom_value_4', 4)" value="Zapsat" /></td>
<td><span id="eeprom_value_4_response">  </span></td>
</div>
<!--//////////////////zapis 3///////////////////-->
<tr>
<div>
<td><h3>zapsani dat 4</h3></td>
<td><input type="text" id="eeprom_value_5" size="8" maxlength="8" ><input type="button" onclick="zapsateeprom('eeprom_value_5', 5)" value="Zapsat" /></td>
<td><span id="eeprom_value_5_response">  </span></td>
</tr>
</div>
</table>
<!--//////////////////tlacitko 1///////////////////-->
 <br> <br>
 // zapad W         50-250<br>
 // severozapad    250-600<br>
 // sever N        600-1200<br>
 // jihozapad     1200-1800<br>
 // Severovychod  1800-2400<br>
 // jih S         2400-3100<br>
 // jihovychod    3100-3550<br>
 // vychod E      3550-4100<br>
<br>
<br>
////////////////////////////////////////////////////////
 <center>
         
        <h2> 
            Serial výstup z ESP
        </h2>
       
        
        <textarea id="serialprint" rows="10" cols="100">
</textarea>
    </center>
<br>
<br>

////////////////////////////////////////////////////////////////////

<div><h2>
  Aktualní hodnota tmy: <span id="adc_val">0</span><br><br>

</h2>
</div>
///////////////////////////////////////

////////////////////////////////


<script>


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
  xhttp.open("GET", "zapis_eeprom?data_in=="+ input_form_id +"="+ data + "-", true);
  xhttp.send();
}
}

//////////////////////////zapis eeprom bit/////////////////////////////////////
function zapsateeprom_bit(input_form_id, button) {
    if(button.value=="OFF") {
        button.value="ON"
        button.innerHTML="ON"
        data = false;
} else if(button.value=="ON") {
        button.value="OFF"
        button.innerHTML="OFF"
        data = true;
       
    }

 var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById(input_form_id + "_response").innerHTML = this.responseText;
      console.log("input form id je:");
      console.log(input_form_id);
      console.log("this responseText je:");
      console.log(this.responseText);
    // getData_eeprom_bit_0();
    // getData_eeprom_bit_1();
      
    }
  };
//  xhttp.open('GET', `zapis_eeprom?data_in==${value_type}=${data}`, true);
  xhttp.open("GET", "zapis_eeprom_bit?data_in=="+ input_form_id +"="+ data + "-", true);
  xhttp.send();

}

///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
function restart_esp() 
{
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET", "reset", true);
  xhttp.send();
}
///////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
setInterval(function() 
{
  getData();
  serial_print();
  getData_eeprom_bit_0();
  getData_eeprom_bit_1();
  //getData_eeprom_bit(); // jen jednou nacist
 // getData_read_eeprom_2();
 //////////////////////////////////////////////
}, 1000); 

setInterval(function() 
{
 getData_wifi_nebo_lan();
 getData_verze();
 //////////////////////////////////////////////
}, 5000); 


/////////////////////cteni eeprom 2//////////////////////////////////////
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("adc_val").innerHTML =
      this.responseText;
    //  document.getElementById("serialprint").value = this.responseText;
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
/////////////////////////cteni verze/////////////////////////////////////////
function getData_verze() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("verze_view").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "verze", true);
  xhttp.send();
}
/////////////////////////cteni polozek bit/////////////////////////////////////////
function getData_eeprom_bit_0() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("eeprom_bit_0_view").innerHTML =
      this.responseText;
    
    }
  };
  xhttp.open("GET", "eeprom_bit_0_read", true);
  xhttp.send();
}
/////////////////////////cteni polozek bit/////////////////////////////////////////
function getData_eeprom_bit_1() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("eeprom_bit_1_view").innerHTML =
      this.responseText;
    
    }
  };
  xhttp.open("GET", "eeprom_bit_1_read", true);
  xhttp.send();
}
///////////////////////////////////////////////////////////////////////////////////////////
function serial_print() {
            var txt;
            txt = document.getElementById("serialprint").value;
            // txt1 = document.getElementById('a').value;
            
       //////////////////////////////////////////////////////////     
             var strtime = "";

    var currentTime = new Date()
    var hours = currentTime.getHours()
    var minutes = currentTime.getMinutes()
    var seconds = currentTime.getSeconds()

    if (minutes < 10) {
        minutes = "0" + minutes
    }
    if (seconds < 10) {
        seconds = "0" + seconds
    }
    strtime += hours + ":" + minutes + ":" + seconds + " ";
    if(hours > 11){
        strtime += "PM"
    } else {
        strtime += "AM"
    }
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
       var txt1 = this.responseText;
       if (txt1 != ""){
       txt2 =  strtime +" - " + txt1 +"\n"; 
       var str = txt2 + txt;
      document.getElementById("serialprint").value = str;
    }
  }};
  xhttp.open("GET", "serial_print", true);
  xhttp.send();

            
        }
/////////////////////////cteni polozek/////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/////////////////////////cteni eeprom wifimanager/////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////
</script>
</center>
</body>
</html>
)=====";
