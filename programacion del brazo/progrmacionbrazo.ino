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
const char* ssid = "J王";         // Reemplaza con el nombre de tu red
const char* password = "julieswg7"; // Reemplaza con tu contraseña

// Servidor web en el puerto 80
WebServer server(80);

// Variables para almacenar los pasos de los motores
int steps1 = 0, steps2 = 0, steps3 = 0;
int steps4 = 0, steps5 = 0, steps6 = 0;
int steps7 = 0, steps8 = 0, steps9 = 0;

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
    String html = "<html><body><h1>Control de Motores</h1>";
    html += "<p>Ingresa los pasos para mover los motores:</p>";
    html += "<form action='/girar' method='GET'>";
    
    for (int i = 1; i <= 9; i++) {
      html += "<label>Pasos " + String(i) + ":</label> ";
      html += "<input type='number' name='steps" + String(i) + "' value='0' required><br>";
    }
    
    html += "<input type='submit' value='Girar'>";
    html += "</form></body></html>";
    server.send(200, "text/html", html);
  });

  // Ruta para recibir los valores y mover los motores
  server.on("/girar", HTTP_GET, []() {
    if (server.args() == 9) {
      steps1 = server.arg("steps1").toInt();
      steps2 = server.arg("steps2").toInt();
      steps3 = server.arg("steps3").toInt();
      steps4 = server.arg("steps4").toInt();
      steps5 = server.arg("steps5").toInt();
      steps6 = server.arg("steps6").toInt();
      steps7 = server.arg("steps7").toInt();
      steps8 = server.arg("steps8").toInt();
      steps9 = server.arg("steps9").toInt();

      // Mover los motores
      rotateMotor(DIR_PIN_1, STEP_PIN_1, steps1);
      rotateMotor(DIR_PIN_1, STEP_PIN_1, steps2);
      rotateMotor(DIR_PIN_1, STEP_PIN_1, steps3);
      rotateMotor(DIR_PIN_2, STEP_PIN_2, steps4);
      rotateMotor(DIR_PIN_2, STEP_PIN_2, steps5);
      rotateMotor(DIR_PIN_2, STEP_PIN_2, steps6);
      rotateMotor(DIR_PIN_3, STEP_PIN_3, steps7);
      rotateMotor(DIR_PIN_3, STEP_PIN_3, steps8);
      rotateMotor(DIR_PIN_3, STEP_PIN_3, steps9);

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