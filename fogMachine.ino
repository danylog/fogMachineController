// Definición de constantes para el tiempo de encendido y el umbral de luminosidad
#define turnOnTime 3000
#define turnOnTreshold 100  // Valor entre 0 y 1023 por el cual la máquina debe empezar a expulsar humo (cuanto más bajo, más iluminación)

// Definición de pines para el sensor LDR y la máquina de humo
#define ldrPin A0
#define fogMachinePin 2

// Variables para controlar el temporizador y la bandera

// Configuración inicial del programa
void setup() {
  // Configurar el pin del LDR como entrada y el pin de la máquina de humo como salida
  pinMode(ldrPin, INPUT);
  pinMode(fogMachinePin, OUTPUT);
  Serial.begin(9600);
}

// Función principal que se ejecuta continuamente
void loop() {
  // Leer el valor de luminosidad del LDR
  int brightness = analogRead(ldrPin);

  Serial.println(brightness);
  
  // Verificar si la luminosidad es mayor o igual al umbral y la máquina no está activada
  if (brightness <= turnOnTreshold) {
    digitalWrite(fogMachinePin, 1);
  }

  // Verificar si la luminosidad es menor al umbral, resetear la bandera a 0
  if (brightness > turnOnTreshold) {
    digitalWrite(fogMachinePin, 0);
  }
}
