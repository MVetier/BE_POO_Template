#include "Led.h"

Led::Led(uint8_t p) : Actionneur(p, "Led"), allumee(false) {}

void Led::init() {
    pinMode(pin, OUTPUT);
    desactiver();
}

void Led::activer() {
    digitalWrite(pin, HIGH);
    allumee = true;
}

void Led::desactiver() {
    digitalWrite(pin, LOW);
    allumee = false;
}

bool Led::estAllumee() const { return allumee; }
