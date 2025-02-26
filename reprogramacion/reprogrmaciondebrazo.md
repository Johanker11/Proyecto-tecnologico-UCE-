# MANUAL DE PROGRAMACIÓN PARA EL BRAZO ROBÓTICO
## Índice

1. Introducción  
2. Explicación del Código  
   2.1 Inclusión de Librerías  
   2.2 Definición de Pines de los Motores  
   2.3 Configuración de Credenciales WiFi  
   2.4 Creación del Servidor Web  
   2.5 Conexión WiFi  
   2.6 Configuración de Pines en el Setup  
   2.7 Creación de la Interfaz Web  
   2.8 Manejo de Peticiones HTTP  
   2.9 Bucle de Ejecución (Loop)  
   2.10 Movimiento de los Motores  
   2.11 Código completo  
3. Interpretación de la Respuesta en Arduino IDE  
4. Conclusión  

---

## 1. Introducción

El presente manual tiene como objetivo guiar la reprogramación y comprensión del código que permite controlar un brazo robótico cartesiano mediante una interfaz web. Se detallará cada una de las secciones del código, explicando su función y cómo contribuye al correcto funcionamiento del sistema. 

Este sistema utiliza un **ESP32** como microcontrolador y un conjunto de motores paso a paso controlados por **drivers A4988**. La interacción con el usuario se realiza a través de una página web alojada en el propio ESP32, donde se pueden enviar comandos para mover los motores.

La programación de este sistema se basa en la conexión **WiFi** para establecer una comunicación con el usuario y la gestión de peticiones **HTTP** para recibir los valores de movimiento. Conocer a fondo la estructura del código facilitará futuras modificaciones, mejoras o integraciones con otros sistemas.

---

## 2. Explicación del Código

### 2.1 Inclusión de Librerías

```cpp
#include <WiFi.h>
#include <WebServer.h>
```
Se incluyen las librerías necesarias para la conexión WiFi y la creación del servidor web. Estas permiten que el ESP32 actúe como un servidor HTTP.

### 2.2 Definición de Pines de los Motores

```cpp
#define DIR_PIN_1 12
#define STEP_PIN_1 13
#define DIR_PIN_2 26
#define STEP_PIN_2 27
#define DIR_PIN_3 32
#define STEP_PIN_3 33
```
Cada motor tiene dos pines: uno para indicar la dirección del giro y otro para enviar los pulsos de paso.

### 2.3 Configuración de Credenciales WiFi

```cpp
const char* ssid = "usuario_wifi";
const char* password = "contraseña";
```
Estas credenciales permiten conectar el ESP32 a una red inalámbrica.

### 2.4 Creación del Servidor Web

```cpp
WebServer server(80);
```
Se instancia un servidor web en el puerto **80** para recibir y responder peticiones HTTP.

### 2.5 Conexión WiFi

```cpp
void conectarWiFi() {
  Serial.print("Conectando a WiFi...");
  WiFi.begin(ssid, password);
}
```
La función intenta conectar el ESP32 a la red WiFi.

### 2.6 Configuración de Pines en el Setup

```cpp
void setup() {
  Serial.begin(115200);
  conectarWiFi();
}
```
Aquí se configuran los pines de los motores como salidas y se inicia el servidor web.

### 2.7 Creación de la Interfaz Web

```cpp
server.on("/", HTTP_GET, []() {
  String html = "<html> ... </html>";
```
Se define una página web con botones y campos numéricos para ingresar valores de movimiento.

### 2.8 Manejo de Peticiones HTTP

```cpp
server.on("/girar", HTTP_GET, []() {
  if (server.args() == 3) {
```
La función asociada a la ruta **/girar** procesa los valores y llama a la función **rotateMotor()**.

### 2.9 Bucle de Ejecución (Loop)

```cpp
void loop() {
  server.handleClient();
}
```
Verifica constantemente si la conexión WiFi está activa y atiende peticiones HTTP.

### 2.10 Movimiento de los Motores

```cpp
void rotateMotor(int dirPin, int stepPin, int steps) {
  digitalWrite(dirPin, (steps > 0) ? HIGH : LOW);
```
Esta función recibe los pines de dirección y paso, y la cantidad de pasos a ejecutar.

### 2.11 Código completo

```cpp
#include <WiFi.h>
#include <WebServer.h>

// Pines motores A4988
#define DIR_PIN_1 12
#define STEP_PIN_1 13
#define DIR_PIN_2 26
#define STEP_PIN_2 27
#define DIR_PIN_3 32
#define STEP_PIN_3 33

// Credenciales WiFi
const char* ssid = "iPhone de Ariel";
const char* password = "12345678";

WebServer server(80);

void setup() {
  Serial.begin(115200);
  conectarWiFi();
  server.begin();
}

void loop() {
  server.handleClient();
}
```

---

## 3. Interpretación de la Respuesta en Arduino IDE

Al ejecutar el programa en el **ESP32** y abrir el monitor serie en **Arduino IDE**, se mostrará un mensaje indicando la conexión a la red WiFi y la dirección **IP** asignada. Esta dirección debe ingresarse en un navegador para acceder a la interfaz de control de motores.

Desde allí, el usuario podrá enviar comandos para mover los motores y recibir una confirmación en pantalla.

---

## 4. Conclusión

El desarrollo de este sistema permite la manipulación de un **brazo robótico cartesiano** de manera remota mediante una interfaz web intuitiva. La implementación del **ESP32** y la integración con una red WiFi optimizan el proceso, eliminando la necesidad de conexiones físicas con el controlador.

Este código puede ser modificado para incorporar sensores, automatizar tareas específicas o integrarlo con sistemas de visión artificial. 

En futuros desarrollos, se pueden explorar mejoras en la seguridad de la conexión WiFi, optimización del código para mayor eficiencia y la implementación de algoritmos avanzados para el control del movimiento del brazo robótico. Con este manual, el usuario tiene una base sólida para continuar desarrollando nuevas aplicaciones en **robótica** y **automatización**.
