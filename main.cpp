
#include <Keypad.h>

#define BUZZER 10
#define PIR 9

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {1, 2, 3, 4};
byte colPins[COLS] = {5, 6, 7, 8};

Keypad keypad = Keypad(makeKeymap(keys),
                       rowPins, colPins,
                       ROWS, COLS);

int melody[] = {2000, 1000};
int noteDuration = 500;

bool systemON = false;


// WSZYSTKIE DIODY ZGASZONE
void ledsOff() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}


// MIGANIE ŻÓŁTEJ DIODY PRZEZ 5 SEKUND
void transition() {

  ledsOff();

  noTone(BUZZER);

  for (int i = 0; i < 10; i++) {

    digitalWrite(LED_YELLOW, HIGH);
    delay(250);

    digitalWrite(LED_YELLOW, LOW);
    delay(250);
  }

  digitalWrite(LED_YELLOW, LOW);
}


// UZBRAJANIE SYSTEMU
void armSystem() {

  Serial.println("UZBRAJANIE SYSTEMU...");

  transition();

  systemON = true;

  ledsOff();
  digitalWrite(LED_GREEN, HIGH);

  Serial.println("SYSTEM UZBROJONY!");
}


// ROZBRAJANIE SYSTEMU
void disarmSystem() {

  Serial.println("ROZBRAJANIE SYSTEMU...");

  transition();

  systemON = false;

  ledsOff();
  digitalWrite(LED_RED, HIGH);

  noTone(BUZZER);

  Serial.println("SYSTEM ROZBROJONY!");
}


void setup() {

  pinMode(BUZZER, OUTPUT);
  pinMode(PIR, INPUT);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  ledsOff();

  // Początkowo system jest rozbrojony
  digitalWrite(LED_RED, HIGH);

  Serial.begin(9600);

  Serial.println("SYSTEM ROZBROJONY");
  Serial.println("Nacisnij # aby uzbroic system");
}


void loop() {

  char key = keypad.getKey();


  // UZBRAJANIE LUB ROZBRAJANIE
  if (key == '#') {

    if (systemON == false) {
      armSystem();
    }
    else {
      disarmSystem();
    }
  }


  // SYSTEM ROZBROJONY
  if (!systemON) {

    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);

    noTone(BUZZER);

    return;
  }


  // SYSTEM UZBROJONY
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, HIGH);


  // WYKRYWANIE RUCHU
  if (digitalRead(PIR) == HIGH) {

    Serial.println("WYKRYTO RUCH!");

    for (int i = 0; i < 2; i++) {

      if (digitalRead(PIR) == LOW) {
        noTone(BUZZER);
        break;
      }

      tone(BUZZER, melody[i]);
      delay(noteDuration);

      noTone(BUZZER);
      delay(30);
    }

  } else {

    noTone(BUZZER);
  }
}
