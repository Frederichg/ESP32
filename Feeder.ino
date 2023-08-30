// feeder code 
// Jacob Vautour 2023

#define IR_FOOD 22
#define IR_LOG 23

#define ENA 12
#define DIR 13
#define PUL 14

#define H_LED 15
#define F_LED 16

const int steps = 100;

void setup() {
  Serial.begin(115200);

  pinMode(IR_FOOD, INPUT_PULLUP);
  pinMode(IR_LOG, INPUT_PULLUP);

  pinMode(ENA, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(PUL, OUTPUT);
}

void loop() {
  while(Serial.available()){
    String data = Serial.readString();
    Serial.println(data);
    if(data == "FDR") {feed();}
    if(data == "IR") {Serial.println(digitalRead(IR_LOG));}
    if(data == "H_LED_ON") {digitalWrite(H_LED, HIGH);}
    if(data == "H_LEN_OFF") {digitalWrite(H_LED, LOW);}
  }
  delay(10);
}

void feed() {
  digitalWrite(F_LED, HIGH);
  digitalWrite(ENA, LOW);

  if(digitalRead(IR_FOOD) == LOW) {
    digitalWrite(DIR, HIGH);
    for(int x = 0; x < steps; x++) {
      digitalWrite(PUL,HIGH);
      delayMicroseconds(500);
      digitalWrite(PUL,LOW);
      delayMicroseconds(500);
    }
  }
  else {
    digitalWrite(DIR, HIGH);
    for(int x = 0; x < steps/2; x++) {
      digitalWrite(PUL,HIGH);
      delayMicroseconds(500);
      digitalWrite(PUL,LOW);
      delayMicroseconds(500);
    }
    digitalWrite(DIR, LOW);
    for(int x = 0; x < steps/2; x++) {
      digitalWrite(PUL,HIGH);
      delayMicroseconds(500);
      digitalWrite(PUL,LOW);
      delayMicroseconds(500);
    }
  }

  digitalWrite(ENA, HIGH);
  digitalWrite(F_LED, LOW);
}