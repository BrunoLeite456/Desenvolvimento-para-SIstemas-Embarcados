# 🤖 Controle de Servo com Arduino e Sensores LDR

Projeto com Arduino que utiliza dois sensores de luz (LDR) para controlar um servo motor. O sensor conectado ao pino **A0** controla o ângulo máximo do servo, enquanto o sensor conectado ao pino **A1** ajusta a velocidade do movimento.

## 📋 Como funciona

O código lê os dois sensores e movimenta o servo do ângulo 0° até a posição calculada pelo A0. Em seguida, o servo retorna a 0°. Durante cada etapa do movimento, o valor do A1 é lido novamente para que a velocidade acompanhe mais rapidamente as mudanças na luminosidade.

| Componente | Pino do Arduino | Função |
|---|---|---|
| Servo motor (sinal) | 9 | Controla o ângulo |
| LDR 1 | A0 | Define o ângulo máximo entre 0° e 180° |
| LDR 2 | A1 | Ajusta o intervalo de espera do servo |
| Sensores | 5V e GND | Alimentação dos divisores de tensão |

### Velocidade do servo

A leitura do A1 é convertida para um intervalo entre **5 ms e 50 ms**:

- **5 ms:** menor intervalo de espera, movimento mais rápido.
- **50 ms:** maior intervalo de espera, movimento mais lento.

A velocidade também depende dos limites físicos do servo motor.

## 🧰 Materiais utilizados

- 1x Arduino UNO ou compatível
- 1x servo motor
- 2x sensores LDR
- 2x resistores de aproximadamente 10 kΩ para os divisores de tensão
- 1x protoboard
- Jumpers / fios
- Cabo USB

## 🔌 Ligações

| Componente | Pino do Arduino |
|---|---|
| Sinal do servo | 9 |
| Saída do divisor de tensão do LDR 1 | A0 |
| Saída do divisor de tensão do LDR 2 | A1 |
| Alimentação dos divisores | 5V e GND |

Cada LDR deve ser ligado em um divisor de tensão com um resistor. Confira a montagem do circuito antes de ligar o Arduino.

> ⚠️ **Atenção:** dependendo do servo utilizado, pode ser necessária uma fonte de alimentação externa adequada. Nesse caso, conecte o GND da fonte ao GND do Arduino. Não alimente um servo que consome muita corrente diretamente do pino 5V do Arduino.

## ▶️ Como abrir e executar

### Opção 1: Arduino IDE

1. Instale a [Arduino IDE](https://www.arduino.cc/en/software).
2. Abra o arquivo `servo_ldr.ino`.
3. Conecte o Arduino ao computador via USB.
4. Em **Ferramentas → Placa**, selecione a placa utilizada.
5. Em **Ferramentas → Porta**, selecione a porta correta.
6. Clique em **Carregar (Upload)**.
7. Abra o Monitor Serial em **9600 baud** para acompanhar as leituras.

### Opção 2: VS Code

1. Abra a pasta do projeto no VS Code.
2. Abra o arquivo `servo_ldr.ino`.
3. Utilize a extensão Arduino ou a Arduino IDE para compilar e enviar o programa à placa.

## 🖥️ Monitor Serial

O programa mostra:

- Valor lido pelo sensor A0.
- Ângulo calculado para o servo.
- Valor lido pelo sensor A1.
- Intervalo de espera usado para ajustar a velocidade.

## 📁 Estrutura do projeto

```text
servo-ldr-arduino/
├── servo_ldr.ino
├── README.md
└── imagens/
    └── COLOQUE_SUA_FOTO_AQUI.txt
```

Adicione uma foto ou GIF real do circuito à pasta `imagens/` para registrar o projeto. Se quiser exibi-la no README, use um caminho relativo, por exemplo: `![Circuito montado](imagens/projeto-arduino.jpg)`.

## ✏️ Personalizando

- Altere o intervalo `5, 50` no `map()` para ajustar a resposta de velocidade.
- Altere o intervalo `0, 180` no `map()` para limitar o ângulo do servo.
- Modifique as ligações e os pinos no código se o circuito for diferente.

## 📄 Licença

Projeto educacional, livre para estudar e modificar.
