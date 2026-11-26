#ifndef BUZZER_H
#define BUZZER_H


#include "Actionneur.h"

// Buzzer : joue une petite musique au service des croquettes
class Buzzer : public Actionneur {
public:
    Buzzer(uint8_t p);
    void init() override;
    void activer() override;           // joue la mélodie
    void desactiver() override;        // coupe le son
    void jouerNote(unsigned int frequence, unsigned int dureeMs);
};

#endif 