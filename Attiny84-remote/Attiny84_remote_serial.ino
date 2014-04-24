int redLED = 4;
int greenLED = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int thisPin = 5; thisPin < 11; thisPin++)  {
    pinMode(thisPin, INPUT);
  }
 //pinMode(greenLED, OUTPUT); 
 //digitalWrite(greenLED, HIGH);
}



void loop()  {
  Serial.println(String(digitalRead(9)) + String(digitalRead(7)) + String(digitalRead(8)) + String(digitalRead(6)) + String(digitalRead(5)) + String(digitalRead(10)));
  delay(100);
  
}
