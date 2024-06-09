#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // Pulso 'mínimo' (valor en microsegundos)
#define SERVOMAX  600 // Pulso 'máximo' (valor en microsegundos)

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando PCA9685...");
  
  pwm.begin();
  pwm.setPWMFreq(60);  // Frecuencia PWM estándar para servos
  
  // Prueba inicial: Mueve todos los servos a la posición de inicio
  for (int i = 0; i < 5; i++) {
    pwm.setPWM(i, 0, SERVOMIN);
  }

  Serial.println("Listo para recibir comandos.");
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    processCommand(command);
  }
}

void processCommand(String command) {
  if (command.length() < 2) {
    Serial.println("Comando demasiado corto. Use formato <servo><ángulo> (ej. 2150 para mover el servo 2 a 150 grados).");
    return;
  }

  int servoIndex = command.charAt(0) - '0';
  int angle = command.substring(1).toInt();

  if (servoIndex >= 0 && servoIndex < 5 && angle >= 0 && angle <= 180) {
    int pulseLength = map(angle, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(servoIndex, 0, pulseLength);
    Serial.print("Servo ");
    Serial.print(servoIndex);
    Serial.print(" movido a ");
    Serial.print(angle);
    Serial.println(" grados.");
  } else {
    Serial.println("Comando inválido. Use formato <servo><ángulo> (ej. 2150 para mover el servo 2 a 150 grados).");
  }
}

