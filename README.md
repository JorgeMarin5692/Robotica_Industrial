# Proyecto Robotica 

Este repositorio GitHub contiene los documentos y archivos necesarios para construir un robot de 5 grados de libertad (5DOF). El robot está diseñado para ser una plataforma versátil para el aprendizaje y la experimentación en robótica. Se puede utilizar para una amplia gama de tareas, incluyendo:

- Manipulación de objetos: El robot puede agarrar y mover objetos de diferentes formas y tamaños.
- Brazo robótico: El robot se puede utilizar como un brazo robótico para realizar tareas más complejas.

# Diseño 3D
El inicio del proyecto de creación de un brazo robótico por parte de estudiantes estuvo marcado por la crucial etapa del diseño 3D, utilizando la herramienta Solidworks como piedra angular para el éxito del mismo. Solidworks, un software de CAD (Diseño Asistido por Computadora) de gran potencia y versatilidad, permitió a los estudiantes plasmar sus ideas en modelos digitales precisos y detallados.

Esta etapa inicial fue de vital importancia, ya que sentó las bases para el posterior desarrollo físico del brazo robótico. Mediante Solidworks, los estudiantes pudieron crear representaciones virtuales de cada componente del brazo, desde las articulaciones y eslabones hasta los elementos de sujeción y control. Esto permitió a los involucrados en el proyecto visualizar con claridad la forma, dimensiones y relaciones entre las distintas partes del robot, facilitando así la toma de decisiones técnicas acertadas.

La precisión y el detalle de los modelos 3D generados en Solidworks no solo fueron útiles para la conceptualización del diseño, sino que también sirvieron como insumo fundamental para la etapa de manufactura. Los modelos digitales pudieron exportarse en formatos compatibles con las impresoras 3D, permitiendo la fabricación precisa y eficiente de cada componente del brazo robótico. De esta manera, las ideas de los estudiantes se materializaron en piezas físicas tangibles.

![WhatsApp Image 2024-06-09 at 6 02 45 PM](https://github.com/JorgeMarin5692/Robotica_Industrial/assets/171969761/d1a17bea-0247-4295-a1cb-0f577bfce9d9)

# Adquisición de los componentes

Tras la meticulosa etapa de diseño 3D, llegó el momento de materializar el brazo robótico mediante la adquisición de los componentes necesarios para su construcción. Con base en las especificaciones técnicas definidas durante la fase de diseño, se procedió a la compra de los siguientes elementos:

Servomotores: Se seleccionaron dos tipos de servomotores para el proyecto: los MG996R y los SG90. Los MG996R, con su mayor torque y precisión, se destinaron a las articulaciones principales del brazo, mientras que los SG90, más económicos y livianos, se emplearon en las articulaciones secundarias.

Placa Arduino Uno: Esta placa microcontroladora, reconocida por su facilidad de uso y versatilidad, se convirtió en el cerebro del brazo robótico. Su capacidad de procesamiento y comunicación con los periféricos la convirtió en la opción ideal para controlar los movimientos del brazo y la interacción con los sensores.

Placa PCA9685: Para ampliar la capacidad de control de servomotores del Arduino Uno, se incorporó la placa PCA9685. Esta placa de expansión permitió conectar y controlar hasta 16 servomotores adicionales, lo que resultó fundamental para la compleja estructura articulada del brazo robótico.

Jumpers: Estos cables de conexión flexibles sirvieron para establecer las conexiones eléctricas entre la placa Arduino Uno, la placa PCA9685, los servomotores y los sensores. Su practicidad y facilidad de uso agilizaron el proceso de ensamblaje y configuración del sistema.

Fuente de voltaje: Para alimentar de forma estable a todos los componentes electrónicos del brazo robótico, se adquirió una fuente de voltaje de corriente continua con la capacidad y el voltaje adecuados. Esto garantizó el correcto funcionamiento de los servomotores, la placa Arduino Uno y la placa PCA9685.

Filamento PLA: Para la impresión 3D de las piezas diseñadas en Solidworks, se utilizó filamento PLA (ácido poliláctico). Este material biodegradable, de alta calidad y fácil impresión, fue la elección ideal para la fabricación de las estructuras livianas y resistentes del brazo robótico.

Tornillería: Para asegurar la fijación precisa y robusta de las piezas impresas en 3D y los componentes electrónicos, se adquirió un surtido de tornillos, tuercas y arandelas de diferentes tamaños y materiales. La selección cuidadosa de la tornillería garantizó la estabilidad y durabilidad del brazo robótico.

![WhatsApp Image 2024-06-09 at 6 11 08 PM](https://github.com/JorgeMarin5692/Robotica_Industrial/assets/171969761/3f5cd8d2-0c31-45c2-80f0-4fdaa4f4331e)


# Entorno de simulación 

Tras haber desarrollado el brazo robótico físico y su sistema de control mediante programación automática, el siguiente paso crucial en el proyecto es la creación de un entorno de simulación virtual. Este entorno permitirá probar, validar y optimizar el funcionamiento del brazo robótico en un ambiente controlado antes de su implementación en el mundo real.

Para la creación del entorno de simulación, se utilizará la combinación de dos potentes herramientas:

- ROS2 (Robot Operating System 2): Un marco de software de código abierto ampliamente utilizado en robótica para la comunicación entre diferentes nodos y la ejecución de tareas de forma distribuida.

- MoveIt: Un conjunto de herramientas de software para la planificación de movimiento y la manipulación robótica, integrado en el ecosistema ROS2. MoveIt proporciona algoritmos avanzados para generar trayectorias seguras y eficientes para el brazo robótico, considerando las limitaciones físicas y las restricciones del entorno.

Pasos para la creación del entorno de simulación:

- Instalación de ROS2 y MoveIt: Se instalará ROS2 y MoveIt en el sistema Ubuntu siguiendo las instrucciones oficiales de instalación.

- Modelado del brazo robótico: Se creará un modelo 3D preciso del brazo robótico utilizando herramientas de modelado 3D como es Solidworks. El modelo debe incluir todas las articulaciones, dimensiones y propiedades físicas del brazo real.

- Integración del modelo en ROS2: Se integrará el modelo 3D del brazo robótico en el entorno de simulación ROS2 utilizando herramientas como RViz. Esto permitirá visualizar el brazo robótico en el entorno virtual y controlar sus movimientos mediante comandos ROS2.

- Configuración de MoveIt: Se configurará MoveIt para que funcione con el modelo del brazo robótico y el entorno de simulación. Esto implica definir las articulaciones, las propiedades físicas y los límites de movimiento del brazo, así como los parámetros de planificación de movimiento.

- Pruebas y validación: Se realizarán pruebas exhaustivas para verificar el correcto funcionamiento del entorno de simulación, la precisión del modelo del brazo robótico y la eficacia de los algoritmos de planificación de movimiento de MoveIt.

Beneficios del entorno de simulación:

- Validación de movimientos: El entorno de simulación permite probar y validar diferentes movimientos del brazo robótico sin necesidad de riesgo para el hardware real.

- Optimización de la programación: Se puede optimizar la programación del brazo robótico en el entorno de simulación antes de implementarla en el sistema físico.

- Detección de errores: El entorno de simulación facilita la detección de errores en la programación o en el modelo del brazo robótico antes de que causen problemas en el sistema real.

- Entrenamiento de algoritmos: El entorno de simulación puede utilizarse para entrenar y optimizar algoritmos de control o de planificación de movimiento para el brazo robótico.

- Pruebas en diferentes entornos: Se pueden realizar pruebas en diferentes entornos virtuales para evaluar el comportamiento del brazo robótico en diversas situaciones y condiciones.

