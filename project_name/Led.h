#ifndef LED_H
#define LED_H

#include "Actionneur.h"

// LED : s'allume quand les croquettes sont servies
class Led : public Actionneur {
private:
    bool allumee;

public:
    Led(uint8_t p);
    void init() override;
    void activer() override;           // allume
    void desactiver() override;        // éteint
    bool estAllumee() const;
};
# endif 
