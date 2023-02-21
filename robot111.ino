/** Initial Code **/
// Variable for measure distance of 3 sensors
long durationF, durationL, durationR;
int distanceF, distanceL, distanceR;
const int trigF = 7;
const int echoF = 6;
const int trigL = 5;
const int echoL = 4;
const int trigR = 3;
const int echoR = 2;

// Variable for 2 motors and drivers
//Motor R
int enA = 11;
int in1 = 10;
int in2 = 12;
//Motor L
int in3 = 13;
int in4 = 8;
int enB = 9;

// Sensor code:
void setup() {
  // Sensor Pin Setup
  pinMode(trigF, OUTPUT);
  pinMode(echoF, INPUT);
  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  // Motor Pin Setup
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}
// Distance calculation functions
int calculateDistanceF() {
  digitalWrite(trigF, LOW);
  delayMicroseconds(2);
  digitalWrite(trigF, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigF, LOW);
  durationF = pulseIn(echoF, HIGH);
  distanceF = durationF * 0.034 / 2;
  return distanceF;
}
int calculateDistanceL() {
  digitalWrite(trigL, LOW);
  delayMicroseconds(2);
  digitalWrite(trigL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigL, LOW);
  durationL = pulseIn(echoL, HIGH);
  distanceL = durationL * 0.034 / 2;
  return distanceL;
}
int calculateDistanceR() {
  digitalWrite(trigR, LOW);
  delayMicroseconds(2);
  digitalWrite(trigR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigR, LOW);
  durationR = pulseIn(echoR, HIGH);
  distanceR = durationR * 0.034 / 2;
  return distanceR;
}
// Make motor run functions
void goStraight() {
  // A, in1, in2 = R , B, in3, in4 = L
  analogWrite(enA, 100);  // speed from 0 -> 255
  analogWrite(enB, 100);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stopMotor() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void turnLeft() {
  analogWrite(enA, 100);  // speed from 0 -> 255
  analogWrite(enB, 100);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(400);
}
void turnRight() {
  analogWrite(enA, 100);  // speed from 0 -> 255
  analogWrite(enB, 100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(400);
}
void reverse() {
  analogWrite(enA, 100);  // speed from 0 -> 255
  analogWrite(enB, 100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(500);
}
void loop() {
  distanceF = calculateDistanceF();
  distanceL = calculateDistanceL();
  distanceR = calculateDistanceR();
  // Serial.println("Front:");
  // Serial.println(distanceF);
  // Serial.println("Left:");
  // Serial.println(distanceL);
  // Serial.println("Right:");
  // Serial.println(distanceR);
  if (distanceF < 10) {
    stopMotor();
    delay(200);
    if (distanceL > distanceR && distanceR > 10) {
      turnLeft();
      Serial.println("Left");
    } else if (distanceR > distanceL && distanceL > 10) {
      turnRight();
      Serial.println("Right");
    } else {
      reverse();
      if (distanceL > distanceR && distanceR > 10) {
        turnLeft();
        Serial.println("Reverse And Left");
      } else if (distanceR > distanceL && distanceL > 10) {
        turnRight();
        Serial.println("Reverse And Right");
      } else {
        Serial.println("Reverse");
      }
    }
  }
  if (distanceF >= 10) {
    goStraight();
    Serial.println("Straight");
  }
  delay(500);
}
