#ifndef CRENEAU_REPAS_H
#define CRENEAU_REPAS_H

// #include <Arduino.h>

class Creneau_Repas {
private:
    unsigned int debut; // Début de la plage (en secondes) mettre maybe unsigned long ça dépend du type de variable pour le temps
    unsigned int fin;   // Fin de la plage (en secondes)
    bool dejaPris;          // Évite les doublons sur un même créneau

public:
    Creneau_Repas(unsigned int ndebut, unsigned int nfin);

    bool estAutorise(unsigned int tempsActuelSec) ;
    void marquerCommePris();
    bool estDejaPris() ;
    String disponibilite_heure() const;
};

#endif