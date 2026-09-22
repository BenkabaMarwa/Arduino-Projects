int thermistorPin = A0;

// RGB-led
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int temperatureValue;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Read thermistor
  temperatureValue = analogRead(thermistorPin);

  Serial.print("Temperature value: ");
  Serial.println(temperatureValue);

  // LOW temperature
  if (temperatureValue < 110)
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }

  // MEDIUM temperature
  else if (temperatureValue < 145)
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }

  // HIGH temperature
  else
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }

  delay(500);
}