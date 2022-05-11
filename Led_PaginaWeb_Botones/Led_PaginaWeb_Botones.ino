// Cargar la libreria Wi-Fi 

#include <ESP8266WiFi.h>



// Reemplace con sus credenciales de red

const char* ssid     = "HOTSPOT";

const char* password = "123456789";



// Establezca el número de puerto del servidor web en 80

WiFiServer server(80);



// Variable para almacenar la solicitud HTTP

String header;



// Variables auxiliares para almacenar el estado de salida actual

String output5State = "off";

//String output4State = "off";



// Asigne variables de salida a los pines GPIO

const int output5 = 2;

//const int output4 = 4;



// Tiempo actual

unsigned long currentTime = millis();

// Tiempo previo

unsigned long previousTime = 0; 

// Defina el tiempo de espera en milisegundos (ejemplo: 2000ms = 2s

const long timeoutTime = 2000;



void setup() {

  Serial.begin(115200);

  // Inicializar las variables de salida como salidas

  pinMode(output5, OUTPUT);

  //pinMode(output4, OUTPUT);

  // Establecer salidas en BAJO apagados

  digitalWrite(output5, LOW);

  //digitalWrite(output4, LOW);



  // Conéctese a la red Wi-Fi con SSID y contraseña

  Serial.print("Conectado a ");

  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  // Imprima la dirección IP local e inicie el servidor web

  Serial.println("");

  Serial.println("WiFi conectada.");

  Serial.println("Dirección IP: ");

  Serial.println(WiFi.localIP());

  server.begin();

}



void loop(){

  WiFiClient client = server.available();   // Escuche los clientes entrantes



  if (client) {                             // Si un nuevo cliente se conecta,

    Serial.println("Nuevo cliente.");          // imprimir un mensaje en el puerto serie

    String currentLine = "";                // hacer una cadena para contener los datos entrantes del cliente

    currentTime = millis();

    previousTime = currentTime;

    while (client.connected() && currentTime - previousTime <= timeoutTime) { // Crear bucle mientras el cliente está conectado

      currentTime = millis();         

      if (client.available()) {             // Si hay bytes para leer del cliente,

        char c = client.read();             // leer un byte, entonces

        Serial.write(c);                    // imprimirlo en el monitor serie

        header += c;

        if (c == '\n') {                    // if the byte is a newline character

          // si la línea actual está en blanco, tienes dos caracteres de nueva línea seguidos.

          // ese es el final de la solicitud HTTP del cliente, así que envíe una respuesta:

          if (currentLine.length() == 0) {

            // Los encabezados HTTP siempre comienzan con un código de respuesta (e.g. HTTP/1.1 200 OK)

            // y un tipo de contenido para que el cliente sepa lo que viene, luego una línea en blanco:

            client.println("HTTP/1.1 200 OK");

            client.println("Content-type:text/html");

            client.println("Connection: close");

            client.println();

            

            // enciende y apaga los GPIO

            if (header.indexOf("GET /5/on") >= 0) {

              Serial.println("GPIO 5 on");

              output5State = "on";

              digitalWrite(output5, HIGH);

            } else if (header.indexOf("GET /5/off") >= 0) {

              Serial.println("GPIO 5 off");

              output5State = "off";

              digitalWrite(output5, LOW);

            } /*else if (header.indexOf("GET /4/on") >= 0) {

              Serial.println("GPIO 4 on");

              output4State = "on";

              digitalWrite(output4, HIGH);

            } else if (header.indexOf("GET /4/off") >= 0) {

              Serial.println("GPIO 4 off");

              output4State = "off";

              digitalWrite(output4, LOW);

            }*/

            

            // Mostrar la página web HTML

            client.println("<!DOCTYPE html><html>");

            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");

            client.println("<link rel=\"icon\" href=\"data:,\">");

            // CSS para dar estilo a los botones de encendido/apagado

            // Siéntase libre de cambiar los atributos de color de fondo y tamaño de fuente para que se ajusten a sus preferencias

            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");

            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");

            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");

            client.println(".button2 {background-color: #77878A;}</style></head>");

            

            // Encabezado de página web

            client.println("<body><h1>ESP8266 Web Server</h1>");

            

            // Muestra el estado actual y los botones ON/OFF para GPIO 5  

            client.println("<p>GPIO 5 - State " + output5State + "</p>");

            // Si output5State está apagado, muestra el botón ON       

            if (output5State=="off") {

              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");

            } else {

              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");

            } 

               

            // Muestra el estado actual y los botones ON/OFF para GPIO 4  

            /*client.println("<p>GPIO 4 - State " + output4State + "</p>");

            // Muestra el estado actual y los botones ON/OFF para GPIO 4       

            if (output4State=="off") {

              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");

            } else {

              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");

            }*/
            client.println("</body></html>");

            

            // La respuesta HTTP termina con otra linea en blanco

            client.println();

            // Salir del bucle while

            break;

          } else { // si tiene una nueva línea, borre currentLine

            currentLine = "";

          }

        } else if (c != '\r') {  // si tiene algo más que un carácter de retorno de carro,

          currentLine += c;      // aañádelo al final de la línea actual

        }

      }

    }

    // Borrar la variable de encabezado

    header = "";

    // Cerrar la conexión

    client.stop();

    Serial.println("Cliente desconectado.");

    Serial.println("");

  }

}
