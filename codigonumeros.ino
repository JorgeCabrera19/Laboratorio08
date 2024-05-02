// Definir pines para cada segmento del display
const int segmentos[] = {2, 3, 4, 5, 6, 7, 8};
const int punto = 9; // Pin para el punto decimal
const int totalSegmentos = sizeof(segmentos) / sizeof(segmentos[0]);

// Definir los patrones para cada número
const byte numeros[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}  // 9
};

void setup() {
  configurarPines();
}

void loop() {
  for (int i = 0; i < 10; i++) {
    mostrarNumero(i);
    delay(1000); // Esperar un segundo
  }
}

// Función para configurar los pines
void configurarPines() {
  // Configurar los pines de los segmentos como salida
  for (int i = 0; i < totalSegmentos; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
  // Configurar el pin del punto como salida
  pinMode(punto, OUTPUT);
}

// Función para mostrar un número en el display
void mostrarNumero(int numero) {
  // Apagar todos los segmentos y el punto
  apagarDisplay();
  // Encender los segmentos correspondientes al número
  for (int i = 0; i < totalSegmentos; i++) {
    digitalWrite(segmentos[i], !numeros[numero][i]); // Ánodo común
  }
  digitalWrite(punto, !numeros[numero][totalSegmentos]); // Encender el punto si está activo
}

// Función para apagar todos los segmentos y el punto
void apagarDisplay() {
  for (int i = 0; i < totalSegmentos; i++) {
    digitalWrite(segmentos[i], HIGH); // Apagar segmentos
  }
  digitalWrite(punto, HIGH); // Apagar el punto
}

