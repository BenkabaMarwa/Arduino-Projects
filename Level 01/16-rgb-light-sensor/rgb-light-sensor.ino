int ldrPin = A0;
// RGB-led
int redPin = 11;
int greenPin = 9;
int bluePin = 10;

int lightValue;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Read light sensor
  lightValue = analogRead(ldrPin);

  Serial.print("Light: ");
  Serial.println(lightValue);

  // Bright
  if (lightValue > 700)
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }

  // Medium light
  else if (lightValue > 300)
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }

  // Dark
  else
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }

  delay(200);
}