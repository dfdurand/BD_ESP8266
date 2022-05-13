#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "nom_de_votre_wifi";
const char* password = "mot_de_passe";

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
 int lightValue = getLightValue();
 sendData(lightValue);
 
  delay(1000);        // delay in between reads for stability
}


int getLightValue(){
   // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  return sensorValue;
}

void sendData(int data) {
  if(WiFi.status() != WL_CONNECTED ){
    Serial.println("Wifi not connected...");
    WiFi.begin(ssid, password); 
  } 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  } 

  Serial.print("Connected to: "); Serial.println(WiFi.SSID());
  Serial.print("Your IP: "); Serial.println(WiFi.localIP());
  
  HTTPClient http;

  String datatosend = "/light/setdata.php?value=" + String(data);
  Serial.print("Sensor value: "); Serial.println(datatosend);

  //-- Change the IP address below to your server's IP --
  http.begin("192.168.1.33", 80, datatosend);
 
  int httpCode = http.GET();
  
  if(httpCode > 0){
    Serial.printf("GET code: %d\n", httpCode);
    if(httpCode == HTTP_CODE_OK){
      String response = http.getString();
      Serial.println(response);
    }
  } else {
    Serial.printf("GET failed: error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}
