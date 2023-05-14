#include <WiFi.h>
#include <HTTPClient.h>

//Credenciales para la red wifi
const char* ssid = "NombreDelaRed";
const char* password = "ContraseñaDeLaRed";

// Dirección del posteo por HTTP a la base de datos del servidor de la universidad o a ThingSpeak
const char* serverName = "http://192.168.4.146/directorio_Archivos";

// Clave del servicio API
//String apiKey = "claveDeThingSepak";

float valor1 = 0.0, valor2=0.0;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  delay(5000);
}

void loop() {
  //Se valida conexión a WiFi    
  if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http; 
      // Se establece el inicio del cliente HTTP para posteo de información.
      http.begin(client, serverName);    
      // Se especifica el encabezao content-type (en este caso por XML)
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");    
      //Información a enviar al servidor
      String httpRequestData = "tem=" + (String)random(100)+"&hum="+(String)random(100);          
      // Se envía solicitud HTTP POST
      int httpResponseCode = http.POST(httpRequestData);
      Serial.print("Código de respuesta HTTP: ");
      Serial.println(httpResponseCode);  

    //Esta validación es para verificar que hubo conexión correcta con el servidor y nos arroja lo que envíe como respuesta.
      if (httpResponseCode==200){
        String cuerpo_respuesta = http.getString();
        Serial.println("El servidor respondió: ");
        Serial.println(cuerpo_respuesta);
      }   
      // Se liberan recursos del cliente HTTP
      http.end();
    }
    else {
      Serial.println("WiFi Desconectado..."); //Si Wifi se desconecta nos arroja este mensaje
    }

    delay(10000); //Intervalo de envío entre mediciones de los sensores.
}
