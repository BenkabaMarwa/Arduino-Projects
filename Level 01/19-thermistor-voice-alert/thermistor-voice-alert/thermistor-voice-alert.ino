int thermistorPin = A0;

int thermistorValue;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  thermistorValue = analogRead(thermistorPin);

  Serial.println(thermistorValue);

  if (thermistorValue > 140)
  {
    Serial.println("HOT");
  }
  else
  {
    Serial.println("NORMAL");
  }

  delay(500);
}