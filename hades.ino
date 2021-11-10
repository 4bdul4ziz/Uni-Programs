#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); //TX, RX respetively
String readvoice;

int Lmotor_1= 10;
int Lmotor_2= 11;
int Rmotor_1= 12;
int Rmotor_2= 13;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(Lmotor_1, OUTPUT);// declaring Motors pin as output pin
  pinMode(Lmotor_2, OUTPUT);
  pinMode(Rmotor_1, OUTPUT);
  pinMode(Rmotor_2, OUTPUT);

}


void loop() {
  while (BT.available())
  {  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readvoice.length() > 0) 
  {
    Serial.println(readvoice);
    if(readvoice == "forward") 
    {
      //forward
      digitalWrite(Lmotor_1, HIGH);
      digitalWrite(Lmotor_2, LOW);
      digitalWrite(Rmotor_1, HIGH);
      digitalWrite(Rmotor_2, LOW);
      delay(100);
    }
    else if(readvoice == "back")
    {
      //backward
      digitalWrite(Lmotor_1, LOW);
      digitalWrite(Lmotor_2, HIGH);
      digitalWrite(Rmotor_1, LOW);
      digitalWrite(Rmotor_2, HIGH);
      delay(100);
    }
  
    else if (readvoice == "turn right" )
    {
      //Rightturn
      digitalWrite(Lmotor_1, HIGH);
      digitalWrite(Lmotor_2, LOW);
      digitalWrite(Rmotor_1, LOW);
      digitalWrite(Rmotor_2, LOW);
      delay (100);
    
    }
    else if ( readvoice == "turn left")
   {
      //LeftTurn
      digitalWrite(Lmotor_1, LOW);
      digitalWrite(Lmotor_2, LOW);
      digitalWrite(Rmotor_1, HIGH);
      digitalWrite(Rmotor_2, LOW);
     delay (100);
   }
   else if (readvoice == "stop")
   {
      //Stop
      digitalWrite(Lmotor_1, LOW);
      digitalWrite(Lmotor_2, LOW);
      digitalWrite(Rmotor_1, LOW);
      digitalWrite(Rmotor_2, LOW);
      delay (100);
   }
  
  readvoice="";}//Reset the variable

}