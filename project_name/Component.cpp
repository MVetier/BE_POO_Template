#include "Component.h"

Component::Component(uint8_t p, const std::string& n) : pin(p), nom(n) {}

Component::~Component() {}

const std::string& Component::getNom() const { 
    return nom; 
}

uint8_t Component::getPin() const { 
    return pin; 
}