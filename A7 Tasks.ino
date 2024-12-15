#include <Servo.h>
Servo servo1;
Servo servo2;

int ir1 = 2;
int ir2 = 13;
int led1 = 4;
int buzz1 = 7;
int led2g = 8;
int i;
int check1;
int check2;
bool bool1;


int v_ldr;
int led_ldr = 12;

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
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);  
  pinMode(led_ldr, OUTPUT);  
  pinMode(buzz1, OUTPUT);
  pinMode(led2g, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  servo1.write(0);
  servo2.write(0);
  bool1 = false;
    
  digitalWrite(led2g, HIGH);  
  
  digitalWrite(trig1, LOW);
  delay(3);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  dura1 = pulseIn(echo1, HIGH); 
  dis1 = (dura1 * 0.034)/2;  

  check1 = digitalRead(ir1);
  
  
  v_ldr = analogRead(A3);
  //Serial.println(dis1);
  //Serial.println(v_ldr);  
  if(check1 == LOW && v_ldr > 300)
  {
  digitalWrite(led_ldr, HIGH);
  delay(5);
  }
  //else
  //{
  //digitalWrite(led_ldr, LOW);  
  //}      

  if (check1 == LOW && dis1 <= 5) {
    //servo1.write(0);
    //delay(100); 

    //servo2.write(0);
    //delay(100);
     
    // buzzer/led on
    digitalWrite(led2g, LOW);    
    digitalWrite(led1, HIGH);
    digitalWrite(buzz1, HIGH);
    for(i = 0; i <= 90; i = i + 5)
    {
    servo1.write(i);
    servo2.write(i);
    delay(200);
    }
    //delay(3000);
    
    // buzzer/led off 

      
    Serial.println(i); 
    while(bool1 == false){
      check2 = digitalRead(ir2);
      //Serial.println(bool1);            
      if (check2 == LOW && i == 95){
        digitalWrite(led_ldr, LOW);
        for(i = 90; i >= 0 ; i = i - 5)
        {
          servo1.write(i);
          servo2.write(i);
          delay(200);
        }
        digitalWrite(led1, LOW);
        digitalWrite(buzz1, LOW);
        digitalWrite(led2g, HIGH);
        bool1 = true;        
      }  
    }    
  }
  digitalWrite(led_ldr, LOW);    
}
//sketch_dec5a.ino