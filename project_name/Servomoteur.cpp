#include "Servomoteur.h"

Servomoteur::Servomoteur(uint8_t p, int aOuvert, int aFerme)
    : Actionneur(p, "Servo trappe"),
      angleOuvert(aOuvert), angleFerme(aFerme), ouvert(false) {}

void Servomoteur::init() {
    servo.attach(pin);
    desactiver();                      // trappe fermée au démarrage
}

void Servomoteur::activer() {
    servo.write(angleOuvert);
    ouvert = true;
}

void Servomoteur::desactiver() {
    servo.write(angleFerme);
    ouvert = false;
}

bool Servomoteur::estOuvert() const { return ouvert; }