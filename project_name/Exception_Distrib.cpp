#include "Exception_Distrib.h"

Exception_Distrib::Exception_Distrib(const std::string &erreur) : message(erreur) {}

horsCreneau::horsCreneau() : Exception_Distrib("You dey craze, aucun repas n'est autorise sur cette plage horaire.") {}