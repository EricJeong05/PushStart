#define MotorA_PWM 10
#define IN2 9
#define IN1 8
#define button 7
#define onLED 6
#define modeButton 5
#define modeLED 4

#define ENCODEROUTPUT 792
#define ENCA 2 // YELLOW

// Start Button Variables
int ledState = LOW;     // the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
int pwmValue = 0;

// Mode Button Variables
int modeState = LOW;     // the current state of LED
int lastModeState;    // the previous state of button
int currentModeState; // the current state of button

// Encoder Variables
volatile long encoderValue = 0;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;

int rpm = 0;
boolean measureRpm = false;
int motorPwm = 0;
int captureTime = 1;

void setup() {
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(onLED, OUTPUT);
  pinMode(button, INPUT);
  pinMode(modeLED, OUTPUT);
  pinMode(modeButton, INPUT);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  

  currentButtonState = digitalRead(button);
  currentModeState = digitalRead(modeButton);

  attachInterrupt(digitalPinToInterrupt(ENCA),updateEncoder,RISING);
  encoderValue = 0;
  previousMillis = millis();
  Serial.begin(9600);

}

void loop() {  
// ---------------------------------- START/STOP BUTTON LOGIC ----------------------------------
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(button); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {

    // toggle state of LED
    ledState = !ledState;

    if(modeState){
      modeState = 0;
      digitalWrite(modeLED, modeState);
    }
    
    if(pwmValue == 0){
      pwmValue = 255;
    }else{
      pwmValue = 0;
    }

    digitalWrite(onLED, ledState);
    analogWrite(MotorA_PWM, pwmValue);
  }

// ---------------------------------- 30/2 MODE BUTTON LOGIC ----------------------------------
  lastModeState    = currentModeState;      // save the last state
  currentModeState = digitalRead(modeButton); // read new state

  if(lastModeState == HIGH && currentModeState == LOW && ledState) {

    // toggle state of LED
    modeState = !modeState;
    encoderValue = 0;
    digitalWrite(modeLED, modeState);
  }

  if (modeState){
    if (encoderValue > ENCODEROUTPUT*30){
      currentMillis = millis();
      
      if(captureTime){
        previousMillis = millis(); 
        captureTime = 0;     
      }
      
      if(currentMillis - previousMillis > 3000){
        analogWrite(MotorA_PWM, 255);
        captureTime = 1;
        encoderValue = 0;
      }else{
        analogWrite(MotorA_PWM, 0);
      }
  
      Serial.println(currentMillis - previousMillis);
    }
    
    Serial.print("Revolutions: " );
    Serial.println(encoderValue/ENCODEROUTPUT); 
  }
  delay(20);
}

//  Add encoderValue by 1, each time it detects rising signal from hall sensor A 
void updateEncoder(){
  encoderValue++;
}
