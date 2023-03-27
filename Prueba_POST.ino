#include <WiFi.h>
#include <HTTPClient.h>

//Credenciales para la red wifi
const char* ssid = "Bolognesa";
const char* password = "0804169194";

// Domain Name with full URL Path for HTTP POST Request
const char* serverName = "http://192.168.100.6/esp_post.php";

// Service API Key
//String apiKey = "8FWNUSPZB93PNQH1";

float valor1 = 0.0, valor2=0.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
    
  if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http; 
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);    
      // Specify content-type header
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");    
      // Data to send with HTTP POST
      String httpRequestData = "tem=" + (String)random(100)+"&hum="+(String)random(100);          
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);  

      if (httpResponseCode==200){
        String cuerpo_respuesta = http.getString();
        Serial.println("El servidor respondió: ");
        Serial.println(cuerpo_respuesta);
      }   
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected...");
    }

    delay(40000);
}
