#ifndef CRENEAU_REPAS_H
#define CRENEAU_REPAS_H

#include <Arduino.h>

class Creneau_Repas
{
private:
    unsigned int debut; // Début de la plage (en secondes) mettre maybe unsigned long ça dépend du type de variable pour le temps
    unsigned int fin;   // Fin de la plage (en secondes)
    bool dejaPris;      // Évite les doublons sur un même créneau

public:
    Creneau_Repas(unsigned int ndebut, unsigned int nfin); // Constructeur pour initialiser le créneau avec un temps de début et de fin

    bool estAutorise(unsigned int tempsActuel); // Vérifie si le créneau est autorisé à distribuer un repas à l'heure actuelle
    void marquerCommePris();                    // Marque le créneau comme ayant été utilisé pour éviter les doublons
    bool estDejaPris();                         // Vérifie si le créneau a déjà été utilisé
    void resetDejaPris();
    String disponibilite_heure() const; // Retourne une chaîne de caractères représentant la disponibilité du créneau (PRIS ou DISPO) avec les heures de début et de fin
};

#endif