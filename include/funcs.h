#include <Arduino.h>
#include <MIDI.h>

int serialFormatPrint(int note, int val, int ch){
    int result = 0;
    Serial.print("MIDI ");
    Serial.print(note);
    Serial.print(" ");
    Serial.print(val);
    Serial.print(" ");
    Serial.println(ch);
    return result;
}