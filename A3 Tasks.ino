int light = 13;
int ir = 2;
int check;

void setup() {
  pinMode(light, OUTPUT);
  pinMode(ir, INPUT);
}

void loop() {
  check = digitalRead(ir);
  if (check == LOW) {
    digitalWrite(light, HIGH);   
  }
  else{
    digitalWrite(light, LOW);          
  }
  delay(300);
}

//in ldr more light acts like short
#include <Servo.h>
Servo servo1;
int i;

void setup()
{
  servo1.attach(10);
}

void loop()
{

  servo1.write(0);
  delay(2000);

  // buzzer on
  for(i = 0; i <= 90; i = i + 5)
  {
   servo1.write(i);
   delay(300);
  }

  // buzzer off 
  for(i = 90; i >= 0 ; i = i - 5)
  {
   servo1.write(i);
   delay(300);
  }
}

//New code
#include <Servo.h>
Servo servo1;
int ir1 = 2;
int led1 = 4;
int i;
int check;

void setup()
{
  servo1.attach(10);
  pinMode(led1, OUTPUT);
}

void loop()
{
  check = digitalRead(ir1);
  if (check == LOW) {
    servo1.write(0);
    delay(200);

    // buzzer on
    digitalWrite(led1, HIGH);
    for(i = 0; i <= 90; i = i + 5)
    {
    servo1.write(i);
    delay(200);
    }
    delay(3000);
    // buzzer off 
    digitalWrite(led1, LOW);
    for(i = 90; i >= 0 ; i = i - 5)
    {
    servo1.write(i);
    delay(300);
    }
  }
    
}