const int analogInPin = A0;
const int In1 = 7;
const int In2 = 8;
//const int EnA = ; // we are controlling motor using jumper on enable PIN

int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value to output to a PWM pin

void setup() {
  Serial.begin(115200);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  //Serial.println(sensorValue);
  
  //float voltage = sensorValue * (3.2 / 1023.0);
  //Serial.println(voltage);

  if (sensorValue > 600) {
    //Serial.println("Very heavy Rain");
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);
   }
  else{
    //Serial.println("Dry Weather");
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
  }
  delay(10000);
}
