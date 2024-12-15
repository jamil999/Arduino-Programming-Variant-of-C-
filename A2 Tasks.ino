int trig1 = A4;
int echo1 = A5;
float dis1;
float dura1;

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig1, LOW); //initally low kore jate agge kono pulse genreate kore thakle baad jaye
  delay(3);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);       // 10 microsec er jonno pulse generate kore(at the time echo1 will be auto high) low kore dibo sobsomye on thakle calculate kora jabe na
  digitalWrite(trig1, LOW);

  dura1 = pulseIn(echo1, HIGH); // generally echo1 low thake...jokhoni high hobe ei func count korbe kotokkhon high chilo (in microseconds)
  dis1 = (dura1 * 0.034)/2;          //1 microsec e jaye 0.034 cm
  Serial.print("The distance is: ");
  Serial.print(dis1);
  Serial.print("cm");
  delay(600);
}

\\LDR
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

\\IR
int var1 = A3;
int var2;

void setup() {
 pinMode(var1, INPUT);
Serial.begin(9600); 
   
}

void loop() {
  var2 = analogRead(var1);
  Serial.println(var2);   // no obstacle = HIGH voltage
  delay(500);
}
