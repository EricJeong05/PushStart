#define MotorA_PWM 10
#define input1 7
#define input2 8
#define button 4
#define directionLED 3

void setup() {
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  
  pinMode(2, OUTPUT);
  pinMode(directionLED, OUTPUT);
  pinMode(button, INPUT);

  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);  
  Serial.begin(9600);
}

int buttonState = 0;
int pressed = false;
int rotDirection = 0;

void loop() {  
  int potValue = analogRead(A0);  
  int pwmOutput = map(potValue, 0, 1023, 0, 255);
   analogWrite(MotorA_PWM, pwmOutput); //Full Output - 2V drop

  if(pwmOutput > 20){
    digitalWrite(2, HIGH);
  }else{
    digitalWrite(2, LOW);  
  }

  // Read button - Debounce
  if (digitalRead(button) == true) {
    pressed = !pressed;
  }
  while (digitalRead(button) == true);
  delay(20);

  // If button is pressed - change rotation direction
  if (pressed == true  & rotDirection == 0) {
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
    digitalWrite(directionLED, HIGH);
    rotDirection = 1;
    delay(20);
  }
  // If button is pressed - change rotation direction
  if (pressed == false & rotDirection == 1) {
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    digitalWrite(directionLED, LOW);
    rotDirection = 0;
    delay(20);
  }
}
