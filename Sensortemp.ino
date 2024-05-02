const int pinSensorTemp = A0; // Pin analógico donde está conectado el sensor de temperatura

void setup() {
  Serial.begin(9600); // Iniciar comunicación serial a 9600 baudios
}

void loop() {
  // Leer el valor analógico del sensor de temperatura
  int lecturaSensor = analogRead(pinSensorTemp);
  
  // Convertir el valor leído a temperatura en grados Celsius
  float tempCelsius = (lecturaSensor * 5.0 / 1024.0) * 100.0;
  
  // Imprimir la temperatura en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(tempCelsius);
  Serial.println(" °C");
  
  delay(1000); // Esperar 1 segundo antes de realizar la siguiente lectura
}
