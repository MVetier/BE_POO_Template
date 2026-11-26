#ifndef SERVOMOTEUR_H
#define SERVOMOTEUR_H

#include <Servo.h>
#include "Actionneur.h"

// Servomoteur : ouvre et ferme la trappe des croquettes
class Servomoteur : public Actionneur {
private:
    Servo servo;
    int  angleOuvert;
    int  angleFerme;
    bool ouvert;

public:
    Servomoteur(uint8_t p, int aOuvert = 90, int aFerme = 0);
    void init() override;
    void activer() override;           // ouvre la trappe
    void desactiver() override;        // ferme la trappe
    bool estOuvert() const;
};



#endif 