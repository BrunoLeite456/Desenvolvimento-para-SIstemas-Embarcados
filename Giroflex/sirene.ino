// Sirene de polícia com Arduino: 2 LEDs alternando + buzzer piezo

const int LED_8 = 8;   // LED vermelho
const int LED_9 = 9;   // LED azul
const int PIEZO = 10;  // Buzzer piezo

void setup()
{
  pinMode(PIEZO, OUTPUT);
  pinMode(LED_8, OUTPUT);
  pinMode(LED_9, OUTPUT);
}

void loop()
{
  // Fase 1: LED azul aceso + tom grave (1000 Hz)
  digitalWrite(LED_9, HIGH);
  digitalWrite(LED_8, LOW);

  tone(PIEZO, 1000);
  delay(300);
  noTone(PIEZO);

  // Fase 2: LED vermelho aceso + tom agudo (1500 Hz)
  digitalWrite(LED_8, HIGH);
  digitalWrite(LED_9, LOW);

  tone(PIEZO, 1500);
  delay(300);
  noTone(PIEZO);
}
