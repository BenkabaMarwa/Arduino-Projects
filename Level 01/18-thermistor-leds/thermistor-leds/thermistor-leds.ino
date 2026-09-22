int thermistorPin = A0;

int greenLED = 8;
int yellowLED = 9;
int redLED = 10;

int thermistorValue;

void setup()
{
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop()
{
  thermistorValue = analogRead(thermistorPin);

  Serial.print("Temperature value: ");
  Serial.println(thermistorValue);

  // Turn all LEDs OFF
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);

  // 🟢 LOW
  if (thermistorValue < 110)
  {
    digitalWrite(greenLED, HIGH);
    Serial.println("LOW");
  }

  // 🟡 MEDIUM
  else if (thermistorValue < 125)
  {
    digitalWrite(yellowLED, HIGH);
    Serial.println("MEDIUM");
  }

  // 🔴 HIGH
  else 
  {
    digitalWrite(redLED, HIGH);
    Serial.println("HOT");
  }

  delay(500);
}