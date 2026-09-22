// Code for testing Ultrasonic Module

#define ECHOPIN 9    // Pin to receive echo pulse
#define TRIGPIN 10   // Pin to send trigger pulse

float distance = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop()
{
  // Start Ranging - Generating a trigger of 10us burst
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Distance Calculation
  distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 58;

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}