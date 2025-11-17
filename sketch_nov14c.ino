#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3);  // RX, TX

char t;

void setup() {
  pinMode(13, OUTPUT); // Left motor forward
  pinMode(12, OUTPUT); // Left motor backward
  pinMode(11, OUTPUT); // Right motor forward
  pinMode(10, OUTPUT); // Right motor backward

  BT.begin(9600);
  Serial.begin(9600);
}

void stopCar() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}

void loop() {
  if (BT.available()) {
    t = BT.read();
    Serial.println(t);

    if (t == 'F') {           // forward
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
    }
    else if (t == 'B') {      // backward
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
    }
    else if (t == 'L') {      // left
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
    }
    else if (t == 'R') {      // right
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
    }
    else if (t == 'S') {      // stop
      stopCar();
    }
  }
}
