#include <Servo.h>

Servo joint1;
Servo joint2;
Servo joint3;

#define PIN_JOINT_1 2
#define PIN_JOINT_2 3
#define PIN_JOINT_3 4

uint8_t joint_index = 0;
float configuration[3];

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  joint1.attach(PIN_JOINT_1);
  joint2.attach(PIN_JOINT_2);
  joint3.attach(PIN_JOINT_3);
}

void setServoPositions() {
  joint1.write(configuration[0] * 180 / PI);
  joint2.write(configuration[1] * 180 / PI);
  joint3.write(configuration[2] * 180 / PI);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  if (Serial.available()) {
    digitalWrite(LED_BUILTIN, HIGH);
    for (int i = 0; i < 3; i++)
      configuration[i] = Serial.parseFloat();
    setServoPositions();
    Serial.flush(); 
  }
}