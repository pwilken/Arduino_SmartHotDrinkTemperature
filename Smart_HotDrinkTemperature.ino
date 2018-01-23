
#include "Songs.h"
#include "drinkTemperatures.c"

int ledPinGreen = 12;
int ledPinRed = 13; 
int speakerPin = 8;  
int analogTempPin = 0;

void setup() {
  pinMode(ledPinRed, OUTPUT); 
  pinMode(ledPinGreen, OUTPUT);
  startSong();
}

void loop() {
  float temperatureC = getTemperatureC();

  temperatureControl(temperatureC, drinkType::SPECIALDRINK);
}

float getTemperatureC()
{
  float reading = analogRead(analogTempPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  return (voltage - 0.5) * 100 / 4.51;
}

void temperatureControl(float temperatureC, drinkType dt)
{
  int rightTemperatureLow = getLowTemperature(dt);
  int rightTemperatureHigh = getHighTemperature(dt);
  
  if(temperatureC > rightTemperatureHigh+10) // Wait more then 10 minutes
  {
    digitalWrite(ledPinRed, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else if(temperatureC > rightTemperatureHigh+5 && temperatureC <= rightTemperatureHigh+10) // Wait 10 minutes or less, but at least more then 5 minutes
  {
    digitalWrite(ledPinGreen, LOW);   
    
    digitalWrite(ledPinRed, HIGH);
    delay(2000);                     // wait for 2 seconds
    digitalWrite(ledPinRed, LOW);    // turn the LED off by making the voltage LOW
    delay(2000); 
  }
  else if(temperatureC > rightTemperatureHigh && temperatureC <= rightTemperatureHigh+5) // Wait 5 Minutes or less
  {
    digitalWrite(ledPinGreen, LOW);   
    
    digitalWrite(ledPinRed, HIGH);  
    delay(1000);                    
    digitalWrite(ledPinRed, LOW); 
    delay(1000);                  
  } 
  else if(temperatureC > rightTemperatureLow && temperatureC <= rightTemperatureHigh) // perfect temperature
  {
    digitalWrite(ledPinRed, LOW); 
    
    if(temperatureC == rightTemperatureHigh) // 2 second signal, we have reached the right temperature ( Low-Tone-Frequency )
      tone(8, 1000, 2000);
      
    digitalWrite(ledPinGreen, HIGH);
  }
  else if(temperatureC <= rightTemperatureLow) // temperature too low
  {
    digitalWrite(ledPinRed, LOW); 
    
    if(temperatureC == rightTemperatureLow) // Two short signals, we have left the right temperature ( Higher-Tone-Frequency )
    {
      tone(8, 1500, 500);
      tone(8, 1500, 500);
    }
      
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
    tone(speakerPin, melodyStartSong[thisNote],noteDuration * 0.9);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
    //delay(pauseBetweenNotes);
    delay(noteDuration);
  }
}

