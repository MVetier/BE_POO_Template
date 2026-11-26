#include "EcranLCD.h"

EcranLCD::EcranLCD() : Actionneur(0, "LCD RGB") {}

void EcranLCD::init() {
    lcd.begin(16, 2);
    couleur(0, 255, 0);
}

void EcranLCD::activer() {
    lcd.display();
}

void EcranLCD::desactiver() {
    lcd.noDisplay();
}

void EcranLCD::afficher(const String& ligne1, const String& ligne2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(ligne1);
    lcd.setCursor(0, 1);
    lcd.print(ligne2);
}

void EcranLCD::couleur(uint8_t r, uint8_t g, uint8_t b) {
    lcd.setRGB(r, g, b);
}
