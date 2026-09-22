int led1 = 8;
int led2 = 9;
int led3 = 10;

// Ultrasonic
int trigPin = 6;
int echoPin = 7;

// Sensors
int thermistorPin = A0;
int ldrPin = A1;

long duration;
int distance;
int temperatureValue;
int lightValue;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // =========================
  // 1. Ultrasonic Sensor
  // =========================

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  // LED 1
  if (distance <= 10)
  {
    digitalWrite(led1, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
  }


  // =========================
  // 2. Thermistor
  // =========================

  temperatureValue = analogRead(thermistorPin);

  // LED 2
  if (temperatureValue >= 340)
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
  }


  // =========================
  // 3. Light Sensor
  // =========================

  lightValue = analogRead(ldrPin);

  // LED 3
  if (lightValue <= 300)
  {
    digitalWrite(led3, HIGH);
  }
  else
  {
    digitalWrite(led3, LOW);
  }


  // Display values
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Thermistor: ");
  Serial.print(temperatureValue);
  Serial.print(" | Light: ");
  Serial.println(lightValue);

  delay(200);
}