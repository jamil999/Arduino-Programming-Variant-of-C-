#include <Servo.h>
Servo var1;
int i;

void setup()
{
  var1.attach(3);
}

void loop()
{

  var1.write(0);
  delay(2000);
  var1.write(90);
  delay(2000);
    
  var1.write(180);
  delay(2000);

  for(i = 0; i < 180; i = i + 5)
  {
   var1.write(i);
  delay(300);
  }  

}

//New code

int v;
int my_led = 12;
void setup()
{
  Serial.begin(9600);
  pinMode(my_led, OUTPUT);
}

void loop()
{
  v = analogRead(A3);
  //Serial.println(v);
  //delay(500);
  if(v < 100)
  {
  digitalWrite(my_led, HIGH);
  }

  else
  {
  digitalWrite(my_led, LOW);  
  }
}