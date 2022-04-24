#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); // TX, RX respetively
String readvoice;

#define MLa 8  // left motor 1st pin
#define MLb 9  // left motor 2nd pin
#define MRa 10 // right motor 1st pin
#define MRb 11 // right motor 2nd pin

void setup()
{
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(MLa, OUTPUT); // declaring Motors pin as output pin
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
}

void loop()
{
  while (BT.available())
  {                     // Check if there is an available byte to read
    delay(10);          // Delay added to make thing stable
    char c = BT.read(); // Conduct a serial read
    readvoice += c;     // build the string- "go straight", "reverse", "left" and "right"
  }
  if (readvoice.length() > 0)
  {
    Serial.println(readvoice);
    if (readvoice == "forward")
    {
      // forward
      digitalWrite(MLa, HIGH);
      digitalWrite(MLb, HIGH);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, LOW);
      delay(5);
    }
    else if (readvoice == "back")
    {
      // backward
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, HIGH);
      digitalWriMRb, HIGH);
      delay(5);
    }

    else if (readvoice == "spin right")
    {
      // Rightturn
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, HIGH);
      digitalWrite(MRa, HIGH);
      digitalWrite(MRb, LOW);
      delay(5);
    }
    else if (readvoice == "spin left")
    {
      // LeftTurn
      digitalWrite(MLa, HIGH);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, HIGH);
      delay(5);
    }
    else if (readvoice == "calm down")
    {
      // Stop
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, LOW);
      delay(5);
    }

    readvoice = "";
  } // Reset the variable
}