#include <WiFi.h>
#include <WebServer.h>  // Librería para servidor web

// Pines para los motores A4988
#define DIR_PIN_1 12
#define STEP_PIN_1 13
#define DIR_PIN_2 26
#define STEP_PIN_2 27
#define DIR_PIN_3 32
#define STEP_PIN_3 33

// Credenciales WiFi
const char* ssid = "iPhone de Ariel";         // Reemplaza con el nombre de tu red
const char* password = "12345678"; // Reemplaza con tu contraseña

// Servidor web en el puerto 80
WebServer server(80);

// Variables para almacenar los pasos de los motores
int steps1 = 0, steps2 = 0, steps3 = 0;

void conectarWiFi() {
  Serial.print("Conectando a WiFi...");
  WiFi.begin(ssid, password);
  unsigned long tiempoInicio = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - tiempoInicio < 15000) {  // Máx. 15s de espera
    Serial.print(".");
    delay(1000);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ Conexión establecida.");
    Serial.print("🔗 Dirección IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ No se pudo conectar. Reintentando...");
  }
}

void setup() {
  Serial.begin(115200);
  conectarWiFi();

  // Configurar pines de los motores
  pinMode(DIR_PIN_1, OUTPUT); pinMode(STEP_PIN_1, OUTPUT);
  pinMode(DIR_PIN_2, OUTPUT); pinMode(STEP_PIN_2, OUTPUT);
  pinMode(DIR_PIN_3, OUTPUT); pinMode(STEP_PIN_3, OUTPUT);

  // Página principal del servidor web
  server.on("/", HTTP_GET, []() {
    String html = "<html><head><style>";
    html += "body { background-color: #0000FF; color: white; font-family: Arial, sans-serif; text-align: center; }";  // Fondo azul
    html += ".container { width: 60%; margin: 0 auto; background: #333; padding: 20px; border-radius: 10px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.5); }";
    html += ".motor-section { display: flex; align-items: center; justify-content: space-between; margin-bottom: 20px; border-bottom: 2px solid #555; padding-bottom: 10px; }";
    html += ".motor-section label { font-weight: bold; color: #fff; }";
    html += "input[type='number'] { width: 60px; padding: 5px; font-size: 16px; }";
    html += "input[type='submit'] { background-color: #28a745; color: white; padding: 10px 20px; border: none; border-radius: 5px; cursor: pointer; font-size: 16px; }";
    html += "</style></head><body>";
    html += "<center><h2>Universidad Central del Ecuador</h2>";
    html += "<h3>Facultad de Filosofia, Letras y Ciencias de la Educacion</h3>";
    html += "<h4>Carrera Pedagogia Tecnica de la Mecatronica</h4>";
    html += "<h4>Subtema: Proyecto de Automatizacion</h4>";
    html += "<h1>Control de Motores</h1>";
    html += "<div class='container'><form action='/girar' method='GET'>";

    html += "<div class='motor-section'>";
    html += "<label for='steps1'>Controlador del Motor 1:</label>";
    html += "<input type='number' name='steps1' id='steps1' value='0' required>";
    html += "</div>";

    html += "<div class='motor-section'>";
    html += "<label for='steps2'>Controlador del Motor 2:</label>";
    html += "<input type='number' name='steps2' id='steps2' value='0' required>";
    html += "</div>";

    html += "<div class='motor-section'>";
    html += "<label for='steps3'>Controlador del Motor 3:</label>";
    html += "<input type='number' name='steps3' id='steps3' value='0' required>";
    html += "</div>";

    html += "<input type='submit' value='Girar'>";
    html += "</form></div></body></html>";
    // Enviar respuesta HTML
    server.send(200, "text/html", html);
  });

  // Ruta para recibir los valores y mover los motores
  server.on("/girar", HTTP_GET, []() {
    if (server.args() == 3) { // Cambié de 9 a 3, ya que solo usas 3 motores
      steps1 = server.arg("steps1").toInt();
      steps2 = server.arg("steps2").toInt();
      steps3 = server.arg("steps3").toInt();

      // Mover los motores
      rotateMotor(DIR_PIN_1, STEP_PIN_1, steps1);
      rotateMotor(DIR_PIN_2, STEP_PIN_2, steps2);
      rotateMotor(DIR_PIN_3, STEP_PIN_3, steps3);

      server.send(200, "text/html", "<html><body><h2>Motores girados correctamente.</h2><a href='/'>Volver</a></body></html>");
    } else {
      server.send(400, "text/html", "<html><body><h2>Error: Faltan parámetros.</h2><a href='/'>Volver</a></body></html>");
    }
  });

  // Iniciar servidor
  server.begin();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("⚠️ Conexión perdida. Reintentando...");
    conectarWiFi();
  }
  server.handleClient();  // Atender peticiones web
}

void rotateMotor(int dirPin, int stepPin, int steps) {
  digitalWrite(dirPin, (steps > 0) ? HIGH : LOW);
  steps = abs(steps);

  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }
}
