void setup()
{
  pinMode(4, OUTPUT);  //7-segment Display PIN 1   ---   Segment E
  pinMode(5, OUTPUT);  //7-segment Display PIN 2   ---   Segment D
  pinMode(6, OUTPUT);  //7-segment Display PIN 4   ---   Segment C
  pinMode(7, OUTPUT);  //7-segment Display PIN 5   ---   Segment Decimal Point
  pinMode(8, OUTPUT);  //7-segment Display PIN 10  ---   Segment G
  pinMode(9, OUTPUT);  //7-segment Display PIN 9   ---   Segment F
  pinMode(11, OUTPUT); //7-segment Display PIN 7   ---   Segment A
  pinMode(12, OUTPUT); //7-segment Display PIN 6   ---   Segment B
}

void loop()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  
  delay(5000); // Wait for 1000 millisecond(s)


  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);

  delay(10000);
  //digitalWrite(13, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
}
