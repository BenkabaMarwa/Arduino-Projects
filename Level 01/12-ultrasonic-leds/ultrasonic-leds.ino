int trigPin = 6;
int echoPin = 7;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn all LEDs OFF first
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);

  // Distance intervals
  if (distance > 60)
  {
    // All LEDs OFF
  }
  else if (distance > 45)
  {
    digitalWrite(led1, HIGH);
  }
  else if (distance > 30)
  {
    digitalWrite(led2, HIGH);
  }
  else if (distance > 15)
  {

    digitalWrite(led3, HIGH);
  }
  else
  {

    digitalWrite(led4, HIGH);
  }

  delay(100);
}