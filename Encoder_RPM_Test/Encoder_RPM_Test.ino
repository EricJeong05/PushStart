#define ENCODEROUTPUT 396

#define ENCA 2 // YELLOW
#define PWM 10
#define IN2 9
#define IN1 8

volatile long encoderValue = 0;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;

int rpm = 0;
boolean measureRpm = false;
int motorPwm = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),updateEncoder,RISING);
  
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  
  encoderValue = 0;
  previousMillis = millis();
}

void loop() {
  analogWrite(PWM, 255);
//  currentMillis = millis();
//  if(currentMillis - previousMillis < 60000){
//    Serial.print((currentMillis - previousMillis) * 1000);
//    Serial.println(encoderValue);
//    
//  }
  
  // put your main code here, to run repeatedly:
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;

   

    // Revolutions per minute (RPM) =
    // (total encoder pulse in 1s / motor encoder output) x 60s
    rpm = (float)(encoderValue * 60 / ENCODEROUTPUT);

    // Only update display when there have readings
    if ( rpm > 0) {
      

      Serial.print(encoderValue);
      Serial.print(" pulse / ");
      Serial.print(ENCODEROUTPUT);
      Serial.print(" pulse per rotation x 60 seconds = ");
      Serial.print(rpm);
      Serial.println(" RPM");
    }
    
    encoderValue = 0;
  }
}

void updateEncoder()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue++;
}
