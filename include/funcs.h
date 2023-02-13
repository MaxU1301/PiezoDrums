#include <Arduino.h>
#include <MIDI.h>

void serialFormatPrint(int note, int val, int ch){
    Serial.print("MIDI ");
    Serial.print(note);
    Serial.print(" ");
    Serial.print(val);
    Serial.print(" ");
    Serial.println(ch);
}

void midiOnOff(int note, int val, int ch, int DELAY){
    MIDI.sendNoteOn(note, val, ch);
    delay(DELAY);
    MIDI.sendNoteOff(note, 0, ch);
}