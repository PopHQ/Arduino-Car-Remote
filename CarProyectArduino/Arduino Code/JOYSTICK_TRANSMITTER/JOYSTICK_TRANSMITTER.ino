#include <Servo.h>

Servo servomecatronicos;
String receivedData;
int xAxis = 0;
int yAxis = 0;

void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial a 9600 baudios
  servomecatronicos.attach(3); // Adjunta el servo al pin 3

  // Configurar los pines del L298N como salida
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // Lee la cadena enviada por el transmisor
    receivedData = Serial.readStringUntil('\n');

    // Divide la cadena recibida en los valores de x e y
    int commaIndex = receivedData.indexOf(',');
    xAxis = receivedData.substring(0, commaIndex).toInt();
    yAxis = receivedData.substring(commaIndex + 1).toInt();

    // Mapeo de los valores del joystick para el control del servo
    int servoAngle = map(xAxis, 0, 1023, 0, 180);

    // Mueve el servo basado en los valores del joystick
    servomecatronicos.write(servoAngle);

    // Mapeo de los valores del joystick para el control de los motores
    int motorSpeedX = map(xAxis, 0, 1023, -255, 255);
    int motorSpeedY = map(yAxis, 0, 1023, -255, 255);

    // Controlar los motores basados en los valores del joystick
    controlMotor(motorSpeedX, motorSpeedY);
  }
}

void controlMotor(int motorSpeedX, int motorSpeedY) {
  // Control del motor A
  if (motorSpeedX > 0) {
    analogWrite(9, motorSpeedX);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  } else {
    analogWrite(9, -motorSpeedX);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }

  // Control del motor B
  if (motorSpeedY > 0) {
    analogWrite(10, motorSpeedY);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else {
    analogWrite(10, -motorSpeedY);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
}


