int thermistorPin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(thermistorPin);
  Serial.println(value);

  delay(500);
}