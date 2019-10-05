//need logic shifter for 3.3 to 5V for this to work on Wemos or NodeMCU boards

const int analogInPin = A0;
const int In1 = D6;
const int In2 = D7;
//const int EnA = ; // we are controlling motor using jumper on enable PIN

int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value to output to a PWM pin

void setup() {
  Serial.begin(115200);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
}

void loop() {
  //sensorValue = analogRead(analogInPin);
  //float voltage = sensorValue * (3.2 / 1023.0);
  //Serial.println(sensorValue);
  //Serial.println(voltage);

  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
}
