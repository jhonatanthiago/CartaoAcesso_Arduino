# Projeto: Sistema de Controle de Acesso com RFID

## Descrição do Projeto

Este projeto implementa um **sistema de controle de acesso** utilizando o módulo **RFID** para leitura de tags, dois **LEDs** (verde e vermelho), e um terceiro **LED vermelho** que simula um buzzer para alertas. O sistema é programado em **Arduino Mega 2560** e foi desenvolvido para validar o acesso com base no UID (identificador único) da tag RFID.

- **Se a tag for reconhecida (UID cadastrado)**, o LED verde acende e uma mensagem "Acesso liberado" é exibida no monitor serial.
- **Se a tag for inválida (não cadastrada)**, o LED vermelho pisca três vezes, e a mensagem "Cartão inválido" é exibida.
- **Após cinco tentativas de uso de tags inválidas**, o sistema é bloqueado, uma luz vermelha adicional (que simula um buzzer) é ativada, e a mensagem "SISTEMA BLOQUEADO" aparece no monitor serial.

## Componentes Utilizados

1. **Arduino Mega 2560**
2. **Módulo RFID RC522**
3. **Dois LEDs vermelhos**: um para indicar cartão inválido e outro para simular um buzzer
4. **Um LED verde**: indica acesso permitido
5. **Resistores** para os LEDs
6. **Jumpers** para conexões
7. **Protoboard**

## Conexões

- **RFID Módulo RC522**
  - **SDA** → Pino 9 no Arduino Mega
  - **SCK** → Pino 52 no Arduino Mega
  - **MOSI** → Pino 51 no Arduino Mega
  - **MISO** → Pino 50 no Arduino Mega
  - **RST** → Pino 8 no Arduino Mega
  - **VCC** → 3.3V
  - **GND** → GND
  
- **LEDs**
  - **LED Verde** → Pino 7
  - **LED Vermelho (para cartão inválido)** → Pino 6
  - **LED Vermelho (simulando buzzer)** → Pino 5

## Como Funciona

- **Aproximação de uma tag RFID**: O sistema verifica se a tag lida corresponde a um UID cadastrado.
  - Se a tag for reconhecida, o LED verde acende por 2 segundos, e o LED vermelho se apaga, indicando acesso permitido.
  - Se a tag não for reconhecida, o LED vermelho pisca três vezes e a mensagem "Cartão inválido" é exibida no monitor serial.
- **Após 5 tentativas inválidas**: O sistema bloqueia o acesso, acendendo um LED vermelho que simula um buzzer e piscando o LED vermelho na porta 6 por 30 segundos.

## Intenção do Projeto

Este projeto visa criar uma **simulação simples de controle de acesso** utilizando um leitor RFID e componentes básicos de eletrônica, como LEDs e resistores. Ele pode ser utilizado como uma introdução ao desenvolvimento de sistemas de segurança e autenticação com Arduino.

## Possíveis Melhorias

- Adicionar um display LCD para mostrar mensagens diretamente no hardware.
- Implementar comunicação com banco de dados para armazenar e verificar múltiplos usuários.
- Utilizar um buzzer real para indicar alarmes e avisos sonoros.
