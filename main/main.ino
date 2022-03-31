
#define enableMotorA 9
#define input1 6
#define input2 7


void setup() {
  // put your setup code here, to run once:
  pinMode(enableMotorA, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);

  // Set rotation direction
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
