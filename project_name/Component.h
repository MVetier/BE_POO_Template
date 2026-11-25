#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>

using namespace std ; 

class Component {
protected:
    string nom; // Nom du composant
    int pin;         // Broche 
    bool actif;      // Composant active ou non

public:
    Component(const string &nom, int pin);


    virtual ~Component(){} ; 

  
    virtual void initialiser(int mode = 0) = 0;
  
    friend iostream &operator<<(iostream &os, const Component &c);
};

#endif 

//hey