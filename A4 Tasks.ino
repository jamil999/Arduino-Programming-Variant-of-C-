#include <Servo.h>
Servo servo1;
int ir1 = 2;
int led1 = 4;
int i;
int check;

int trig1 = A4;
int echo1 = A5;
float dis1;
float dura1;

void setup()
{
  servo1.attach(10);
  pinMode(led1, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
}

void loop()
{
  
  digitalWrite(trig1, LOW);
  delay(3);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  dura1 = pulseIn(echo1, HIGH); 
  dis1 = (dura1 * 0.034)/2;

  check = digitalRead(ir1);
  if (check == LOW && dis1 <= 10) {
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
   
  Serial.println(v);
  delay(500);
  
  if(v > 400)
  {
  digitalWrite(my_led, HIGH);
  }

  else
  {
  digitalWrite(my_led, LOW);  
  }
}

//New code
#include <Servo.h>
Servo servo1;
Servo servo2;

int ir1 = 2;
int led1 = 4;
int i;
int check;

//int v_ldr;
//int led_ldr = 12;

int trig1 = A4;
int echo1 = A5;
float dis1;
float dura1;

void setup()
{
  servo1.attach(10);
  servo2.attach(11);

  pinMode(led1, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  //pinMode(led_ldr, OUTPUT);  
  
}

void loop()
{
  //v_ldr = analogRead(A3);
  //if(v > 400)
  //{
  //digitalWrite(led_ldr, HIGH);
  //}
  //else
  //{
  //digitalWrite(led_ldr, LOW);  
  //}  
  
  digitalWrite(trig1, LOW);
  delay(3);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  dura1 = pulseIn(echo1, HIGH); 
  dis1 = (dura1 * 0.034)/2;

  check = digitalRead(ir1);
  if (check == LOW && dis1 <= 10) {
    servo1.write(0);
    delay(100); 

    servo2.write(0);
    delay(100);
     
    // buzzer/led on
    digitalWrite(led1, HIGH);
    for(i = 0; i <= 90; i = i + 5)
    {
    servo1.write(i);
    servo2.write(i);
    delay(200);
    }
    delay(3000);
    
    // buzzer/led off 
    digitalWrite(led1, LOW);
    for(i = 90; i >= 0 ; i = i - 5)
    {
    servo1.write(i);
    delay(300);
    }
  }
    
}
