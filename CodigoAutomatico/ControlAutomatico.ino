#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Definición de los límites de pulso para los servos
#define SERVOMIN  150 // Pulso 'mínimo' en microsegundos
#define SERVOMAX  600 // Pulso 'máximo' en microsegundos

// Limites específicos de cada servo
#define SERVO0_MIN 0
#define SERVO0_MAX 180

#define SERVO1_MIN 0
#define SERVO1_MAX 85

#define SERVO2_MIN 0
#define SERVO2_MAX 90

#define SERVO3_MIN 2
#define SERVO3_MAX 90

#define SERVO4_MIN 0
#define SERVO4_MAX 80

// Bandera para controlar la automatización
bool automationActive = false;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando PCA9685...");
  
  pwm.begin();
  pwm.setPWMFreq(60);  // Frecuencia PWM estándar para servos
  
  Serial.println("Presiona 'Y' para comenzar la automatización o 'S' para detenerla.");
}

void loop() {
  // Verificar si hay datos disponibles en el puerto serial
  if (Serial.available()) {
    char input = Serial.read();
    
    // Comenzar la automatización si se presiona 'Y'
    if (input == 'Y' || input == 'y') {
      automationActive = true;
      ejecutarSecuencia();
    }
    
    // Detener la automatización si se presiona 'S'
    if (input == 'S' || input == 's') {
      automationActive = false;
      Serial.println("Automatización detenida.");
    }
  }
}

void moverServo(int servo, int angulo) {
  int pulseLength = map(angulo, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servo, 0, pulseLength);
  Serial.print("Moviendo servo ");
  Serial.print(servo);
  Serial.print(" a ");
  Serial.print(angulo);
  Serial.println(" grados.");
}

void ejecutarSecuencia() {
  // Posición inicial
  moverServo(0, 90); // Servo 0 a la posición media
  moverServo(1, 0);  // Servo 1 a la posición inicial
  moverServo(2, 0);  // Servo 2 a la posición inicial
  moverServo(3, 2);  // Servo 3 a la posición inicial
  moverServo(4, 80); // Abrir pinza

  delay(1000);

  // Mover brazo a la posición del objeto
  moverServo(0, 90); // Ajustar posición de base
  moverServo(1, 45); // Ajustar posición vertical
  moverServo(2, 45); // Ajustar extensión del brazo
  moverServo(3, 45); // Ajustar inclinación del brazo
  delay(1000); // Esperar para estabilizar

  // Cerrar pinza para agarrar el objeto
  moverServo(4, 0); // Cerrar pinza
  delay(1000); // Esperar para asegurar el agarre

  // Mover brazo a la posición de destino
  moverServo(0, 150); // Ajustar posición de base
  moverServo(1, 20);  // Ajustar posición vertical
  moverServo(2, 20);  // Ajustar extensión del brazo
  moverServo(3, 20);  // Ajustar inclinación del brazo
  delay(1000); // Esperar para estabilizar

  // Abrir pinza para soltar el objeto
  moverServo(4, 80); // Abrir pinza
  delay(1000); // Esperar para asegurar que el objeto se haya soltado

  // Regresar a la posición inicial
  moverServo(0, 90); // Servo 0 a la posición media
  moverServo(1, 0);  // Servo 1 a la posición inicial
  moverServo(2, 0);  // Servo 2 a la posición inicial
  moverServo(3, 2);  // Servo 3 a la posición inicial
  moverServo(4, 80); // Pinza abierta
}
