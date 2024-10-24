#include <SPI.h>
#include <MFRC522.h>

// Definição dos pinos de conexão para o Arduino Mega 2560
#define PINO_SS 9  
#define PINO_RST 8  

// Definição dos LEDs
#define LED_VERDE 7        
#define LED_VERMELHO 6     
#define LED_BUZZER 5       

MFRC522 mfrc522(PINO_SS, PINO_RST);  // Instancia o objeto do RFID

int tentativas_invalidas = 0;  // Contador de tentativas inválidas

void setup() {
  Serial.begin(9600);      // Inicializa a comunicação serial
  SPI.begin();             // Inicializa a comunicação SPI
  mfrc522.PCD_Init();      // Inicializa o módulo RFID
  
  pinMode(LED_VERDE, OUTPUT);     
  pinMode(LED_VERMELHO, OUTPUT);  
  pinMode(LED_BUZZER, OUTPUT);     
  
  digitalWrite(LED_VERMELHO, HIGH);  // Inicialmente, LED vermelho aceso
  Serial.println("Sistema Inicializado: Aproxime o token");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  Serial.print("UID da tag: ");
  String conteudo = "";  

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  conteudo.toUpperCase();  

  if (conteudo.substring(1) == "F3 7A EA 11") {
    Serial.println("Acesso liberado!");
    digitalWrite(LED_VERMELHO, LOW);   
    digitalWrite(LED_VERDE, HIGH);     
    delay(2000);                      
    digitalWrite(LED_VERDE, LOW);      
    digitalWrite(LED_VERMELHO, HIGH);  
    tentativas_invalidas = 0;          
  } else {
    Serial.println("Cartão inválido!");
    piscaLED(LED_VERMELHO, 3);  
    tentativas_invalidas++;     

    if (tentativas_invalidas >= 5) {
      Serial.println("SISTEMA BLOQUEADO");
      digitalWrite(LED_BUZZER, HIGH);  
      for (int i = 0; i < 5; i++) {
        piscaLED(LED_VERMELHO, 1);  
        delay(1000);  
      }
      digitalWrite(LED_BUZZER, LOW);  
      tentativas_invalidas = 0;  
    }
  }
  delay(1000);  
}

void piscaLED(int ledPin, int vezes) {
  for (int i = 0; i < vezes; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}