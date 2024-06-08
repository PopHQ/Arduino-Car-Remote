void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial a 9600 baudios
}

void loop() {
  // Simulación de valores de joystick para eje X y Y
  // Estos valores pueden ser ajustados para simular diferentes posiciones del joystick
  
  // Simula un movimiento del joystick de 0 a 1023 y de vuelta a 0 en pasos de 200
  for (int i = 0; i <= 1023; i += 200) {
    int xAxis = i;
    int yAxis = 1023 - i;

    // Envía los valores del joystick al receptor a través de la comunicación serial
    Serial.print(xAxis);
    Serial.print(",");
    Serial.println(yAxis);

    delay(500);  // Pequeña pausa para observar el movimiento
  }
}


