#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time  t;
int speakerPin = 3;

void PlaySignal(int signalNumber) {
  for (int i = 55; i < 880; i += 5)
  {
    tone(speakerPin, i, 175);
    delay(1);
  }
  
  delay(100);
  
  for (int i = 880; i > 440; i -= 5)
  {
    tone(speakerPin, i, 175);
    delay(1);
  }
  
  delay(275);
  
  for (int i = 55; i < 660; i += 12)
  {
    tone(speakerPin, i, 50);
    delay(1);
  }
  
  delay(75);
  
  tone(speakerPin, 660, 250);

  delay(500);

  if (signalNumber == 2)
  {
    for (int i = 55; i < 440; i += 16)
    {
      tone(speakerPin, i, 100);
      delay(1);
    }
    
    delay(75);
  
    tone(speakerPin, 660, 66);
    delay(100);
    tone(speakerPin, 880, 250);
  }

  if (signalNumber == 3)
  {
    for (int i = 55; i < 880; i += 16)
    {
      tone(speakerPin, i, 100);
      delay(1);
    }
    
    delay(75);
  
    tone(speakerPin, 660, 66);
    delay(100);
    tone(speakerPin, 440, 250);
  }

  if (signalNumber == 4)
  {
    for (int i = 55; i < 660; i += 16)
    {
      tone(speakerPin, i, 50);
      delay(1);
    }
    
    delay(75);
  
    tone(speakerPin, 660, 66);
    delay(100);
    tone(speakerPin, 660, 250);
  }

  delay(500);
}

void setup() {dfd'
  rtc.begin();
}

void loop() {
  t = rtc.getTime();

  if (t.min == 50 && t.sec == 0)
  {
    if (t.hour == 9 || t.hour == 10 || t.hour == 13 || t.hour == 15)
    PlaySignal(1);
    if (t.hour == 14)
    PlaySignal(4);
  }
  if (t.min == 0 && t.sec == 0)
  {
    if (t.hour == 12)
    PlaySignal(2);
    if (t.hour == 17)
    PlaySignal(3);
  }

  delay(900);
}
