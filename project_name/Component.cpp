#include "Component.h"


Component::Component(const std::string& nom, int pin)
    : nom(nom), pin(pin), actif(false) {}





iostream &operator<<(iostream &os, const Component &c) {
    os << "[Component] " << c.nom
       << " (pin=" << c.pin
       << ", actif=" << (c.actif ? "oui" : "non") << ")";
    return os;
}

//hey