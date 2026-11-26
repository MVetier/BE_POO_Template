#ifndef ACTIONNEUR_H
#define ACTIONNEUR_H

#include "Component.h"
#include <string>

class Actionneur : public Component {
public:
    Actionneur(uint8_t p, const std::string& n);
    virtual ~Actionneur() = default;

    virtual void activer() = 0;
    virtual void desactiver();
};

#endif