#include <Arduino.h>
#include <MIDI.h>
#include <funcs.h>

int peizoIn = 34;
int threshold = 1;
int val = 0;
int MIDI_Val = 0;

int NOTE = 42;
int CHANNEL = 1;

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  analogSetPinAttenuation(peizoIn, ADC_6db);
}

void loop() {
  val = analogRead(peizoIn);
  MIDI_Val = sqrt(val)*(1.98461727);

  if (val > 255) {
    digitalWrite(2, HIGH);
    serialFormatPrint(NOTE, MIDI_Val, CHANNEL);
    delay(20);
  }
  else if (val > threshold)
  {
    digitalWrite(2, HIGH);
    serialFormatPrint(NOTE, MIDI_Val, CHANNEL);
    delay(10);
  }
  else {
    digitalWrite(2, LOW);
  }

}