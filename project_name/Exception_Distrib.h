#ifndef EXCEPTION_DISTRIB_H
#define EXCEPTION_DISTRIB_H

#include <exception>
#include <string>

// Classe mère pour toutes les erreurs du distributeur (à voir si on rajoute d'autre fonctionnalité donc d'autre potentiel erreur)
class Exception_Distrib : public std::exception
{
protected:
    std::string message;

public:
    Exception_Distrib(const std::string &erreur);

    // Redéfinition de la méthode standard what() pour récupérer le texte de l'erreur
    virtual const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class horsCreneau : public Exception_Distrib
{
public:
    horsCreneau();
};

#endif