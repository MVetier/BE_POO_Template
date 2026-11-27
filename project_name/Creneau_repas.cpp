#include "Creneau_Repas.h"
#include <Arduino.h>
Creneau_Repas::Creneau_Repas(unsigned int ndebut, unsigned int nfin) : debut(ndebut), fin(nfin), dejaPris(false) {}

bool Creneau_Repas::estAutorise(unsigned int tempsActuel)
{
    return (!dejaPris && tempsActuel >= debut && tempsActuel <= fin);
}

void Creneau_Repas::marquerCommePris()
{
    dejaPris = true;
}

bool Creneau_Repas::estDejaPris()
{
    return dejaPris;
}

void Creneau_Repas::resetDejaPris()
{
    dejaPris = false;
}

String Creneau_Repas::disponibilite_heure() const
{
    String etat;
    if (dejaPris == true)
    {
        etat = "PRIS";
    }
    else
    {
        etat = "DISPO";
    }
    return String(debut) + "s - " + String(fin) + "s" + etat;
}