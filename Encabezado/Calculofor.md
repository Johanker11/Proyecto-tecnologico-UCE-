# Husillo con un Paso

Un husillo de un paso es un husillo con un único surco, en el que el **paso** y el **avance** son iguales.  

- **Paso**: Distancia entre dos valles de la rosca del husillo.  
- **Avance**: Distancia lineal que recorre la tuerca al girar el husillo una vuelta.  

# Husillo con un Paso

## Selección del Husillo
Para la realización y peso de objetos, optamos por el husillo **T8x2**, que es suficiente para cargas de **300 a 500 g**.

## Paso del Husillo
El paso define la distancia que avanza la tuerca por cada giro del husillo. Un paso más pequeño proporciona:

- **Mayor precisión**: Útil para movimientos pequeños y controlados.
- **Mayor torque requerido**: Porque el motor necesita más esfuerzo para mover la carga.

## Material del Husillo
- **Acero Inoxidable**: Duradero, resistente al desgaste y adecuado para aplicaciones de alta carga.
- **Acero al Carbono**: Más económico, pero puede oxidarse.
- **Recubrimientos**: Se recomienda usar husillos con recubrimientos antifricción para mejorar la eficiencia.

## Avance por Vuelta
Se calcula multiplicando el paso por el número de entradas de la rosca como lo indica la fórmula siguiente:

A=P×Numero de Entradas 

## Selección de Husillos por Ejes
### Eje Z
En esta parte se necesita alta capacidad de carga y menor avance para evitar que el peso descienda por gravedad. Por ello, se optó por el husillo **T8x2**, que tiene buen equilibrio entre precisión y rigidez.

### Ejes X y Y
Para estos ejes, donde se requiere mayor velocidad de movimiento, también se usará el husillo **T8x2**, ya que su avance permite movimientos rápidos con menor número de revoluciones.

## Fuerza Lineal ( F )
La fuerza lineal que puede generar el husillo depende del torque del motor:

F = r/T 

Donde:
- T : Torque del motor (en N·m).
- r : Radio efectivo del husillo, calculado como:

r=A/2π

### Eficiencia (η)
Los husillos trapezoidales tienen una eficiencia típica del **30-50%** debido al rozamiento. Si consideramos pérdidas por eficiencia:

F=(n*t)/r

## Cálculo con el Husillo **T8x2**
- **Avance por vuelta**:  A = 2 mm.
- **Torque del motor**: T = 0.4 N·m.
- **Eficiencia**: η = 0.4.
- **Radio efectivo**:

r=2/2π=0.318mm=0.000318m


- **Fuerza generada**:

F=(0.4*0.4)/(0.318mm)=502.2 N

Este cálculo indica que el husillo puede cargar un total de **500 g**.

## Análisis del Peso y Torque
- **Carga total**: 500 g (4.905 N)
- **Peso**:

W=m*g=0.5kg⋅9.8m/s2=4.905 N

### Cálculo para el Eje Z
- **Husillo con paso**: r=2 mm/rev = 0.002 m/rev
- **Torque requerido**:

T=F(W)*R

T= 49 N*0.002 mm/rev=0.000098 N/m

Convertido a cm:

T=0.000098  N/m*100=0.0098 N/m

**Nota**: El motor **Nema 17**, con un torque de **40 N·cm**, es adecuado para el eje **Z**.

### Cálculo para los Ejes X y Y
- **Husillo con paso**: r=2mm/rev = 0.002 m/rev
- **Fuerza generada**:

F=T/r=(40 N*cm)/0.002m=200 N

**Nota**: La fuerza lineal generada es muy superior a la carga horizontal de **4.905 N**, lo que garantiza un movimiento suave.


# Distribución de los Motores

## Eje Z:
Coloca un motor **NEMA 17** conectado a un husillo trapezoidal. Este eje soporta el peso y es crítico que el husillo tenga **rosca antirretorno** para evitar caídas.

## Ejes X y Y:
Cada eje debe tener su propio motor **NEMA 17** con husillos o correas.  
Si se opta por correas, debemos tener en cuenta usar una relación de transmisión **2:1 o 3:1** para aumentar el torque.

---

# Cálculos en los ejes 

## Peso en eje X

### Datos:
- **Motor NEMA 17:** 450 g o 0.450 kg  
  
  w=0.45 Kg x 9.8  m/s
  w=4.41 N
- **Tornillo sin fin:**  
  - **Densidad del acero:** 1500 g/cm³  
  - **Altura:** 40 cm o 0.4 m  
  - **Diámetro:** 0.95 cm o 0.095 m  
  - **Radio:** diametro/2  

  **Volumen teórico para el husillo:**

 V= π*r^2*h 

 V= π*〖0.47〗^2*0.4

 V= 0.277 〖cm〗^3

  **Cálculo del peso:**

  Peso=0.277〖cm〗^3*1500 g/〖cm〗^3  Peso=415.5g o 0.4155Kg

  w=0.4155 Kg x 9.8  m/s

  w=4.071  N

- **Soportes:**  
  - **Densidad del aluminio:** 2.7 g/cm³  
  - **Longitud:** 45 cm o 0.45 m  
  - **Diámetro:** 2 cm  
  - **Radio:** 1 cm  

  **Formula del Volumen:**

V= π*r^2*h  

V= π*1^2*0.45 = 0.014 m^3  o 1.413 cm^3


**Formula del peso:**
Peso=1.413〖cm〗^3*2.7 g/〖cm〗^3  
  
Peso=3.81g o 0.0381Kg
Peso=3.81g o 0.0381Kg cantidad dos
Peso=3.81g*2=7.62g o 0.0381Kg*2=0.0762Kg
w=0.0762 Kg x 9.8  m/s
w=0.746 N 


**Total, del peso del eje “Z”** = 0.9807Kg 
W= 0.450kg + 0.4155Kg + 0.0762Kg + 0.9807Kg  
Total, Wx = 2.6075 Kg   


---

## Peso en eje Y

**Datos:**
- **Motor NEMA 17:** 450 g o 0.45 Kg  

w=0.45 Kg x 9.8  m/s
w=4.41 N

- **Volumen teórico para el usillo** *(Mismos valores que eje X)*  

V= π*r^2*h 
V= π*〖0.47〗^2*0.4
V= 0.277 〖cm〗^3

- **Formula del peso** *(Mismos valores que eje X)*  

Peso=0.277〖cm〗^3*1500 g/〖cm〗^3 
Peso=415.5g o 0.4155Kg

w=0.4155 Kg x 9.8  m/s
w=4.071  N
---

**Soportes:**

**Densidad del aluminio=** 2.7  g/〖cm〗^3 

**Longitud=** 45 cm o 0.45 m

**Diámetro=** 2 cm Radio = 1 cm

**Formula del Volumen:** V= π*r^2*h  

V= π*1^2*0.45 = 0.014 m^3  o 1.413 cm^3

**Formula del peso** 1.413〖cm〗^3*2.7 g/〖cm〗^3

Peso=3.81g o 0.0381Kg
Peso=3.81g o 0.0381Kg cantidad dos
Peso=3.81g*2=7.62g o 0.0381Kg*2=0.0762Kg

w=0.0762 Kg x 9.8  m/s
w=0.746 N 

**Total, del peso del eje “x”=** 2.6075 Kg   

**Total, del peso del eje “Z” =** 0.9807Kg 

**Total Wy=** 0.45Kg+0.4155Kg+ 0.0762Kg+2.6075 Kg   +0.9807Kg =4.5299 Kg

**Peso en eje Z**
**Datos**
**Motor nema 17**

w=0.45 Kg x 9.8  m/s

w=4.41 N

**Volumen teórico para el usillo:** V= π*r^2*h 

V= π*〖0.47〗^2*0.4

V= 0.277 〖cm〗^3

**Formula del peso** 

0.277〖cm〗^3*1500 g/〖cm〗^3

Peso=415.5g o 0.4155Kg

w=0.4155 Kg x 9.8  m/s

w=4.071  N
**Soportes:**

Densidad del aluminio= 2.7  g/〖cm〗^3 

Longitud= 45 cm o 0.45 m

Diámetro = 2 cm Radio = 1 cm

**Formula del Volumen:** 

V= π*r^2*h  

V= π*1^2*0.45 = 0.014 m^3  o 1.413 cm^3

**Sensor electromagnetico**= 27 g
