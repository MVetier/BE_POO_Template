#ifndef COMPONENT_H
#define COMPONENT_H

#include <Arduino.h>
#include <string>

class Component {
protected:
    uint8_t pin;
    std::string nom;

public:
    Component(uint8_t p, const std::string& n);
    virtual ~Component();

    virtual void init() = 0;
    const std::string& getNom() const;
    uint8_t getPin() const;
};

#endif