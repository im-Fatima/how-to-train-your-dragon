#define MOTOR1 19
#define MOTOR2 18
#define MOTOR3 5
#define MOTOR4 17

void setup() {
  
  pinMode(MOTOR1,OUTPUT);
  pinMode(MOTOR2,OUTPUT);
  pinMode(MOTOR3,OUTPUT);
  pinMode(MOTOR4,OUTPUT);
}

void loop() {
  
  digitalWrite(MOTOR1, HIGH);
  digitalWrite(MOTOR1, LOW);
  delay(100);
  digitalWrite(MOTOR2, HIGH);
  digitalWrite(MOTOR2, LOW);
  delay(100);
  digitalWrite(MOTOR3, HIGH);
  digitalWrite(MOTOR3, LOW);
  delay(100);
  digitalWrite(MOTOR4, HIGH);
  digitalWrite(MOTOR4, LOW);
  delay(1000);
}
