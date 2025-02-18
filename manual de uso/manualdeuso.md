# **Manual de Usuario - Brazo Robótico Cartesiano**

## 📷 Colocar una foto del brazo acabado aquí

## **Índice**
1. [Introducción](#introducción)
2. [Materiales Necesarios](#materiales-necesarios)
3. [Ensamblaje Mecánico](#ensamblaje-mecánico)
4. [Conexión Electrónica](#conexión-electrónica)
5. [Programación y Configuración](#programación-y-configuración)
6. [Pruebas y Ajustes](#pruebas-y-ajustes)
7. [Funcionamiento General](#funcionamiento-general)
8. [Mejoras Futuras](#mejoras-futuras)

---

## **1. Introducción**
Este manual describe el ensamblaje y funcionamiento de un brazo robótico cartesiano basado en motores NEMA 17, controlado por dos ESP32. Se mueve en tres ejes (X, Y, Z) mediante tornillos sin fin y utiliza una garra Dipper para manipulación de objetos.

---

## **2. Materiales Necesarios**

### **Estructura Mecánica**
- Varillas metálicas (aluminio/acero inoxidable)
- Tornillos sin fin (3 unidades, uno por eje)
- Rodamientos lineales (LM8UU o similares)
- Placas de soporte (corte láser o impresas en 3D)
- Garra Dipper  

### **📷 Colocar imagen de los materiales aquí**

### **Sistema de Movimiento**
- Motores NEMA 17 (3 unidades)
- Drivers A4988 o DRV8825 (uno por motor)
- Fuente de alimentación 12V 5A
- Acopladores flexibles  

### **Sistema Electrónico**
- 2 ESP32 (uno para movimientos y otro para comunicación)
- Finales de carrera (3 unidades, uno por eje)
- Cables Dupont, conectores y soldadura  

---

## **3. Ensamblaje Mecánico**

### **Paso 1: Estructura Base**
1. Ensamblar las varillas metálicas en un marco rectangular.
2. Instalar los rodamientos lineales en los ejes X, Y y Z.
3. Fijar los tornillos sin fin con soportes y rodamientos.

### **📷 Colocar imagen del ensamblaje base aquí**

### **Paso 2: Montaje de Motores y Tornillos sin Fin**
1. Fijar cada motor NEMA 17 en su respectivo eje.
2. Usar acopladores flexibles para conectar los motores.

### **📷 Colocar imagen de los motores instalados aquí**

### **Paso 3: Instalación de la Garra Dipper**
1. Montar la garra Dipper en el eje Z.
2. Conectarla a un servo SG90 o MG995.

### **📷 Colocar imagen de la garra instalada aquí**

---

## **4. Conexión Electrónica**
### **Motores y Drivers**
Cada motor NEMA 17 se conecta a su driver A4988 o DRV8825. Definir correctamente los pines en el código.

### **Finales de Carrera**
Colocar los switches de límite en los extremos de los ejes.

### **ESP32 y Comunicación**
- ESP32 principal: Control de motores.
- ESP32 secundario: Para control remoto (WiFi/Bluetooth).

### **📷 Colocar imagen del esquema de conexiones aquí**

---

## **5. Programación y Configuración**
Ejemplo de código para el control de motores:

```cpp
#include <AccelStepper.h>

AccelStepper motorX(1, 5, 4);  // STEP=5, DIR=4
AccelStepper motorY(1, 18, 19); // STEP=18, DIR=19
AccelStepper motorZ(1, 21, 22); // STEP=21, DIR=22

void setup() {
  motorX.setMaxSpeed(1000);
  motorX.setAcceleration(500);
  motorY.setMaxSpeed(1000);
  motorY.setAcceleration(500);
  motorZ.setMaxSpeed(1000);
  motorZ.setAcceleration(500);
}

void loop() {
  motorX.moveTo(200);
  motorY.moveTo(150);
  motorZ.moveTo(100);
  
  motorX.run();
  motorY.run();
  motorZ.run();
}
