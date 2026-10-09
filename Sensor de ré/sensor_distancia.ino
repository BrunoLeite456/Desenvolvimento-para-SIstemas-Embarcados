// Sensor de distância (estilo sensor de ré) com Arduino
// Sensor ultrassônico HC-SR04 + LED RGB + buzzer piezo

const int TRIG = 8;
const int ECHO = 9;

const int LED_VERMELHO = 4;
const int LED_VERDE = 2;
const int LED_AZUL = 3;

const int PIEZO = 6;

long duracao;
int distancia;

void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  pinMode(PIEZO, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Envia um pulso ultrassônico
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Mede o tempo até o eco voltar e converte para centímetros
  duracao = pulseIn(ECHO, HIGH, 30000);
  distancia = duracao * 0.034 / 2;

  Serial.println(distancia);

  // Nada detectado ou muito longe: tudo desligado
  if (duracao == 0 || distancia > 330)
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AZUL, LOW);
    noTone(PIEZO);
  }

  // Longe (170 a 330 cm): verde, bipe lento e grave
  else if (distancia > 170)
  {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AZUL, LOW);
    tone(PIEZO, 500);
    delay(400);
    noTone(PIEZO);
    delay(600);
  }

  // Médio (70 a 170 cm): amarelo (verde + vermelho), bipe médio
  else if (distancia > 70)
  {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AZUL, LOW);

    tone(PIEZO, 1000);
    delay(200);
    noTone(PIEZO);
    delay(300);
  }

  // Perto (até 70 cm): vermelho, bipe agudo e cada vez mais rápido
  else
  {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AZUL, LOW);

    tone(PIEZO, 2000);
    delay(distancia * 4);
    noTone(PIEZO);
    delay(distancia * 4);
  }

  delay(50);
}
