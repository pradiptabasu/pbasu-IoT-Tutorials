#include <IRremote.h>
int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

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
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     if (results.value == 0xFF30CF) // Display 1
     {   
        //results.value = key_value;
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
  
        //delay(5000); // Wait for 1000 millisecond(s)
     }
     else if (results.value == 0xFF18E7) // Display 2
     {   
        //results.value = key_value;
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
  
        //delay(5000); // Wait for 1000 millisecond(s)
     }
     else if (results.value == 0xFF7A85) // Display 3
     {   
        //results.value = key_value;
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
  
        //delay(5000); // Wait for 1000 millisecond(s)
     }
     else if (results.value == 0xFF10EF) // Display 4
     {   
        //results.value = key_value;
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
  
        //delay(5000); // Wait for 1000 millisecond(s)
     }
     irrecv.resume(); // Receive the next value
    }
}
