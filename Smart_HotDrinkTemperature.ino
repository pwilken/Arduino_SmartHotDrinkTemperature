
#include "Songs.h"

int ledPinGreen = 12;
int ledPinRed = 13;   
int analogTempPin = 0;

void setup() {
  pinMode(ledPinRed, OUTPUT); 
  pinMode(ledPinGreen, OUTPUT);
  startSong();
}

void loop() {
  float reading = analogRead(analogTempPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage - 0.5) * 100 / 4.51;

  if(temperatureC > 53) // Wait more then 10 minutes
  {
    digitalWrite(ledPinRed, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else if(temperatureC > 47 && temperatureC <= 53) // Wait 10 minutes or less, but at least more then 5 minutes
  {
    digitalWrite(ledPinRed, HIGH);
    delay(2000);                     // wait for 2 seconds
    digitalWrite(ledPinRed, LOW);    // turn the LED off by making the voltage LOW
    delay(2000); 
  }
  else if(temperatureC > 42 && temperatureC <= 47) // Wait 5 Minutes or less
  {
    digitalWrite(ledPinRed, HIGH);  
    delay(1000);                    
    digitalWrite(ledPinRed, LOW); 
    delay(1000);                  
  } 
  else if(temperatureC > 40 && temperatureC <= 42) // perfect temperature
  {
    if(temperatureC == 42)
      tone(8, 1000, 1000);
      
    digitalWrite(ledPinGreen, HIGH);
  }
  else if(temperatureC <= 40) // temperature too low
  {
    if(temperatureC == 40)
      tone(8, 1500, 1000);
      
    digitalWrite(ledPinGreen, HIGH); 
    delay(1000);                      
    digitalWrite(ledPinGreen, LOW);   
    delay(1000);                  
  }
}

// Just for fun
void startSong()
{
  // iterate over the notes of the melody:
  for (int thisNote = 0; noteDurationsStartSong[thisNote] != 0; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 2000/noteDurationsStartSong[thisNote];
    tone(8, melodyStartSong[thisNote],noteDuration * 0.9);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
    //delay(pauseBetweenNotes);
  delay(noteDuration);
  }
}

