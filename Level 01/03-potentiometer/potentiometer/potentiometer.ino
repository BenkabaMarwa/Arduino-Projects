int potPin = A5;
int ledPin = 9;

int potValue;
int brightness;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // قراءة قيمة potentiometer
  potValue = analogRead(potPin);

  // تحويل القيمة من 0-1023 إلى 0-255
  brightness = map(potValue, 0, 1023, 0, 255);

  // التحكم في شدة LED
  analogWrite(ledPin, brightness);
}