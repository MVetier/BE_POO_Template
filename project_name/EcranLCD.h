#ifndef ECRANLCD_H
#define ECRANLCD_H

#include <rgb_lcd.h>       // bibliothèque "Grove - LCD RGB Backlight"
#include "Actionneur.h"

// Écran Grove LCD RGB : affiche l'horaire et l'état du distributeur
class EcranLCD : public Actionneur {
private:
    rgb_lcd lcd;

public:
    EcranLCD();                        // I2C : pas de broche dédiée
    void init() override;
    void activer() override;           // allume l'affichage
    void desactiver() override;        // éteint l'affichage
    void afficher(const String& ligne1, const String& ligne2 = "");
    void couleur(uint8_t r, uint8_t g, uint8_t b);
};

#endif 
