#include "Buzzer.h"

Buzzer::Buzzer(uint8_t p) : Actionneur(p, "Buzzer") {}

void Buzzer::init() {
    pinMode(pin, OUTPUT);
}

void Buzzer::jouerNote(unsigned int frequence, unsigned int dureeMs) {
    tone(pin, frequence, dureeMs);
    delay(dureeMs + 50);
}

void Buzzer::activer() {
    // Do - Mi - Sol - Do aigu
    const unsigned int notes[] = {523, 659, 784, 1047};
    for (unsigned int f : notes) {
        jouerNote(f, 150);
    }
    desactiver();
}

void Buzzer::desactiver() {
    noTone(pin);
}