const int trigpin = 4;
const int echopin = 5;

int readfrom_ultrasonic()
{
  long duration;
  int distance;

  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034/2;

  return distance;
   
}
void setup() 
{
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);

}

void loop() 
{
  Serial.print("Distance: ");
  
  Serial.println(readfrom_ultrasonic());
  delay(2000);
}
