/*
   Simple mains detector
*/

#define pinVolts 3
int previousState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(pinVolts, INPUT);

  int pinState = digitalRead(pinVolts);

  Serial.print("Setup Completed: ");
  if (pinState == HIGH)
  {
    previousState = HIGH;
    Serial.println("MAINS OFF");
  }
  else
  {
    previousState = LOW;
    Serial.println("MAINS ON");
  }
}

void loop() {
  uint32_t curMS = millis();
  int pinState = digitalRead(pinVolts);

  if (pinState == HIGH && previousState == LOW)
  {
    previousState = HIGH;
    Serial.print(curMS);
    Serial.println(" MAINS OFF");
  }
  else if (pinState == LOW && previousState == HIGH)
  {
    previousState = LOW;
    Serial.print(curMS);
    Serial.println(" MAINS ON");
  }
}
