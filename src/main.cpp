#include <Arduino.h>
#include <funcs.h>
#include <MIDI.h>

const int RXD1 = 16;
const int TXD1 = 17;

int peizoIn = 34;
int threshold = 1;
int val = 0;
int MIDI_Val = 0;

int NOTE = 62;
int CHANNEL = 1;


MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  analogSetPinAttenuation(peizoIn, ADC_2_5db);

  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  val = analogRead(peizoIn);
  MIDI_Val = sqrt(val)*(1.98461727);
  //MIDI_Val = log(val)*15.26852251;

  if (val > 255) {
    digitalWrite(2, HIGH);
    serialFormatPrint(NOTE, MIDI_Val, CHANNEL);
    MIDI.sendNoteOn(NOTE, MIDI_Val, CHANNEL);
    delay(20);
    MIDI.sendNoteOff(NOTE, 0, CHANNEL);
  }
  else if (val > threshold)
  {
    digitalWrite(2, HIGH);
    serialFormatPrint(NOTE, MIDI_Val, CHANNEL);
    MIDI.sendNoteOn(NOTE, MIDI_Val, CHANNEL);
    delay(10);
    MIDI.sendNoteOff(NOTE, 0, CHANNEL);
  }
  else {
    digitalWrite(2, LOW);
  }

}