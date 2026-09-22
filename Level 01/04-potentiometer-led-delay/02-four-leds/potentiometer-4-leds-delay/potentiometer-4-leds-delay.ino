int potPin = A0;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

int potValue;
int delayTime;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop()
{
  // Read potentiometer
  potValue = analogRead(potPin);

  // Convert 0-1023 to 100-1000 milliseconds
  delayTime = map(potValue, 0, 1023, 100, 1000);

  // LED 1 ON
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(delayTime);

  // LED 2 ON
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(delayTime);

  // LED 3 ON
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(delayTime);

  // LED 4 ON
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(delayTime);
}