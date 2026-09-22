int potPin = A0;

int led1 = 8;
int led2 = 9;

int potValue;
int delayTime;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Read potentiometer
  potValue = analogRead(potPin);

  // Convert 0-1023 to 100-1000 ms
  delayTime = map(potValue, 0, 1023, 100, 1000);

  // Send delayTime to Python
  Serial.println(delayTime);

  // -------------------------
  // LED 1
  // -------------------------
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);

  delay(delayTime);

  // -------------------------
  // LED 2
  // -------------------------
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);

  delay(delayTime);
}