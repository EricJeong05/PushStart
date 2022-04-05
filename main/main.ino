#define MotorA_PWM 10
#define input1 6
#define input2 7

void setup() {
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);

  // Set rotation direction
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
}

void loop() {  
  analogWrite(MotorA_PWM, 255); //Full Output - 2V drop
}
