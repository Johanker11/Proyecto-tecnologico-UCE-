# Marco Teórico

El desarrollo de un brazo robótico cartesiano se sustenta en diversos fundamentos teóricos y tecnológicos que abarcan áreas como la robótica, la mecatrónica, la automatización y el diseño modular. Estas disciplinas proporcionan las bases para entender y abordar los retos asociados con el diseño, la construcción y la operación de sistemas robóticos capaces de realizar tareas repetitivas con precisión y eficiencia.

## Brazo Eléctrico Automatizado

Los brazos robóticos industriales han revolucionado la manufactura moderna, desempeñando tareas que antes eran realizadas por humanos. Según Shimoga (2018), "los brazos robóticos han demostrado ser herramientas invaluables en la automatización de procesos, mejorando la eficiencia, precisión y seguridad en una amplia gama de industrias". Su diseño, inspirado en la anatomía humana, les permite realizar movimientos complejos y adaptarse a diversas configuraciones, lo que los convierte en instrumentos versátiles y adaptables a las necesidades cambiantes de la producción.

Esta consta de una estructura articulada, similar a la de un brazo, que se mueve gracias a motores eléctricos, el cual también tiene integrado un sistema de control y monitoreo para saber si existen fallas que pueden ser preventivas. Generalmente, este usa un sistema computarizado controlado por un microcontrolador, el cual dirige los movimientos del brazo, que se mueve gracias a las instrucciones programadas.

Según Antillón (2021), "La cinética inversa se implementó para poder mover las primeras tres juntas del brazo robótico asistencial", la cual es primordial para el estudio del movimiento del brazo, el cual tendrá que moverse de manera eficiente para desarrollar movimientos repetitivos de manera precisa y así evitar errores de operabilidad.

## Brazo Robótico Cartesiano

Este brazo también se le conoce como robot lineal, el cual es un tipo de manipulador mecánico que tiene la facilidad de desplazarse por los ejes X, Y, Z, lo cual significa que este se mueve en línea recta a diferencia de los brazos articulados que realizan movimientos rotatorios.

Los brazos robóticos cartesianos, también conocidos como robots lineales, son ampliamente utilizados en la industria manufacturera debido a su precisión y capacidad para realizar tareas repetitivas. Según Siciliano et al. (2009), "los robots cartesianos son ideales para aplicaciones que requieren movimientos lineales simples y una alta precisión, como el ensamblaje de componentes electrónicos y la manipulación de materiales". Su diseño modular y su facilidad de programación los convierten en una elección popular en diversas industrias.

### Principales Aplicaciones

- **Pick and place**: Recoger y colocar objetos.
- **Ensamblaje**: Unir componentes.
- **Paletizado**: Apilar productos.
- **Corte y taladrado**: Trabajar con diversos materiales.
- **Inspección de calidad**: Detectar defectos.

## Grados de Libertad y su Importancia

Los grados de libertad (GDL) de un robot son fundamentales para determinar su rango de movimiento y la complejidad de las tareas que puede realizar. Al igual que las articulaciones humanas permiten una amplia gama de movimientos, cada GDL en un robot representa un eje o articulación que puede moverse independientemente. Como lo señala Siciliano et al. (2009), "el número de grados de libertad de un robot determina su capacidad para alcanzar una posición y orientación específicas en el espacio de trabajo". En otras palabras, los GDL son la clave para la flexibilidad y versatilidad de un robot.

Cabe recalcar que la movilidad y el alcance que tiene este brazo determinarán las funciones aplicables para el desarrollo de trabajos de manera autónoma y así se produzca un trabajo más eficaz debido a que las industrias requieren de procesos automatizados para la producción masiva de productos o ventas de servicios.

### Importancia

- **Adaptabilidad**: Al tener más movimientos independientes, el robot puede adaptarse a diferentes entornos y tareas sin necesidad de rediseñar su estructura física.
- **Precisión**: Un mayor número de GDL permite un posicionamiento más preciso de la herramienta del robot, lo que es fundamental en tareas que requieren alta exactitud.
- **Versatilidad**: Robots con diferentes configuraciones de GDL pueden realizar una amplia gama de tareas, desde simples movimientos de pick and place hasta operaciones de ensamblaje complejas.

### Ejemplo

Imagina un robot industrial que debe ensamblar un componente electrónico. Si tiene pocos GDL, su movimiento estará limitado y podría tener dificultades para alcanzar todos los ángulos necesarios para colocar el componente correctamente. Sin embargo, un robot con muchos GDL puede mover su brazo y muñeca de múltiples maneras, lo que le permite acceder a cualquier punto del espacio de trabajo y realizar el ensamblaje con precisión.

## Componentes Básicos de un Brazo Robótico (Articulaciones, Actuadores, Sensores)

### Articulaciones

Las articulaciones de los robots industriales son el corazón de su funcionalidad. A diferencia de las articulaciones biológicas, diseñadas para una amplia gama de movimientos, las articulaciones robóticas están optimizadas para tareas específicas, ofreciendo una precisión y repetibilidad excepcionales. Como lo expresa Corke (2017) en su obra *Robotics, Vision and Control*, "la robótica moderna ha evolucionado hacia robots más ágiles y versátiles, donde las articulaciones juegan un papel crucial en la capacidad de adaptarse a entornos dinámicos". Esta evolución se evidencia en robots colaborativos, que trabajan estrechamente con humanos y requieren articulaciones más suaves y seguras.

#### Tipos

- Rotativas
- Prismáticas
- Esféricas
- Cilíndricas

#### ¿Por qué son tan importantes las articulaciones?

Permiten ejecutar una rotación en torno al eje central, lo cual nos indica que su base va a estar fijada en un solo punto, ósea que va a tener un alcance mínimo y un alcance máximo.

- **Alcance y flexibilidad**: Las articulaciones determinan el área de trabajo del robot y su capacidad para alcanzar diferentes posiciones y orientaciones.
- **Precisión**: La combinación de diferentes tipos de articulaciones permite movimientos precisos y repetitivos.
- **Versatilidad**: Al variar el número y tipo de articulaciones, se pueden crear robots adaptados a una amplia gama de tareas.

### Actuadores

Son dispositivos capaces de generar una fuerza a partir de líquidos, de energía eléctrica o gases. "Los actuadores hidráulicos, neumáticos y eléctricos son usados para manejar aparatos mecatrónicos. Por lo general, los actuadores hidráulicos se emplean cuando lo que se necesita es potencia, y los neumáticos son simples posicionamientos" (Diego Núñez).

#### Tipos de Actuadores

- **Motores eléctricos**: Corriente continua (DC), corriente alterna (AC)
- **Actuadores neumáticos**: Utilizan aire comprimido para generar fuerza.
- **Actuadores hidráulicos**: Emplean líquidos a alta presión para generar fuerzas elevadas.

### Sensores

"Un sensor es un dispositivo que detecta y mide diferentes tipos de variables físicas o químicas, como la temperatura, la luz, la distancia, la presión, el sonido, etc." (Pérez). Permitiéndole percibir su entorno y tomar decisiones informadas. Al igual que nosotros utilizamos nuestros ojos, oídos y tacto para interactuar con el mundo, los robots emplean una variedad de sensores para "ver", "oír" y "sentir".

#### Tipos de Sensores y sus Funciones

- **Sensores de posición**: Estos sensores son como los propioceptores humanos, informando al robot sobre la posición exacta de cada una de sus articulaciones. Esto es crucial para realizar movimientos precisos y coordinados. Los sensores de posición cumplen una función similar en los robots: les proporcionan una referencia constante de la posición de sus articulaciones y componentes.

  - **Importancia**:
    - Miden ángulos: Indican el ángulo exacto en el que se encuentra cada articulación del robot.
    - Detectan desplazamientos: Informan sobre cualquier movimiento o desplazamiento de un componente específico.
    - Proporcionan retroalimentación: Envían datos al controlador del robot sobre su posición actual, permitiendo ajustes precisos en tiempo real.

  - **Tipos de Sensores de Posición**:
    - Encoders incrementales: Cuentan los pulsos generados al girar un eje, proporcionando información sobre la posición relativa.
    - Encoders absolutos: Indican la posición exacta de un eje en cualquier momento, sin necesidad de una referencia inicial.
    - Resolvers: Similares a los encoders, pero utilizan señales sinusoidales para determinar la posición.
    - Potenciómetros: Miden la posición angular de un eje mediante un divisor de tensión.
    - Sensores de efecto Hall: Detectan campos magnéticos para determinar la posición de un imán unido a un eje rotativo.

Gracias a ellos, los robots pueden realizar tareas complejas y repetitivas con una eficiencia y fiabilidad que superan a la mano de obra humana.

- **Sensores de fuerza/torque**: Estos sensores miden la fuerza y el torque que se aplica en las articulaciones, permitiendo al robot realizar tareas delicadas que requieren una fuerza controlada, como recoger objetos frágiles o insertar piezas pequeñas. "La galga extensométrica (strain gauge) es uno de los dispositivos más utilizados para la medición de esfuerzos y deformaciones; se basan en el principio piezoresistivo descubierto por Lord Kelvin en 1856" (Wilder, 2023). Esto significa que pueden detectar no solo la intensidad de la fuerza, sino también la dirección en la que se aplica.

  - **Se clasifican de la siguiente manera**:
    - Sensores de 4 ejes: Estos sensores miden las fuerzas en los ejes X, Y y Z, así como los momentos de flexión alrededor de esos ejes. Son los más versátiles y se utilizan en una amplia gama de aplicaciones.
    - Sensores de par: Miden únicamente el momento de fuerza (torque) alrededor de un eje. Se utilizan en aplicaciones donde el control preciso del torque es crucial, como en herramientas eléctricas.

- **Sensores de velocidad**: Normalmente la velocidad depende de 2 cosas primordiales, la primera sus componentes si esta tiene mayor operabilidad como la velocidad de revoluciones esta será más veloz y la segunda su programación si su tiempo de respuesta está programada a menor tiempo de delay esta será más veloz.

  - **Tipos de Sensores de Velocidad**:
    - Encoders incrementales: Miden la velocidad contando los pulsos generados por un disco codificado que gira junto con el eje.
    - Tacho-generadores: Producen una tensión analógica proporcional a la velocidad de rotación de un eje.
    - Resolvers: Utilizan señales sinusoidales para determinar la posición y la velocidad angular.

  - **Importancia**:
    - Realizar movimientos suaves y coordinados.
    - Optimizar el consumo de energía.
    - Aumentar la precisión.
    - Mejorar la seguridad.
    - Facilitar la adaptación a diferentes entornos.

- **Sensores de proximidad**: Estos sensores detectan la presencia de objetos cercanos sin necesidad de contacto físico, como los sensores ultrasónicos o los sensores infrarrojos. Son fundamentales para evitar colisiones y navegar en entornos complejos. Como se muestra en la Tabla # 1 los diferentes tipos de sensores con sus ventajas y desventajas y sus distintas aplicaciones en diferentes campos.
