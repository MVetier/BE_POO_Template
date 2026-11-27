#include "Distributeur.h"
#include "Exception_Distrib.h"

Distributeur::Distributeur(const char *ssid, const char *password) : ssid(ssid), password(password), ordreDistrib(false), server(80) ,nbRepas_Servis(0) {}

void Distributeur::initialiserWiFi()
{
    WiFi.begin(ssid.c_str(), password.c_str());
    Serial.print("Connexion au Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnecte ! Adresse IP : " + WiFi.localIP().toString());

    configurerRoutes();
    server.begin();
}

void Distributeur::gererClientWeb()
{
    server.handleClient();
}

void Distributeur::configurerRoutes()
{
    // Page d'accueil
    server.on("/", [this]()
              { server.send(200, "text/html", PageHTML()); });

    // Bouton : distribuer maintenant
    server.on("/distribuer", [this]()
              {
        try {
            repasWifi(millis() / 1000);
            server.sendHeader("Location", "/");
            server.send(303);
        } catch (const Exception_Distrib& erreur) {
            server.send(400, "text/plain", String("Erreur : ") + erreur.what());
        } });

    // Bouton : réinitialiser les créneaux
    server.on("/reset", [this]()
              {
        reinitialiserJournee();
        server.sendHeader("Location", "/");
        server.send(303); });
}

String Distributeur::PageHTML() const
{
    String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
    html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
    html += "<title>Distributeur Connectee</title></head><body style='font-family:sans-serif; max-width:500px; margin:auto; padding:20px;'>";
    html += "<h1>Distributeur de Croquettes</h1>";
    html += "<p><a href='/distribuer'><button style='padding:10px 15px;'>Servir une portion</button></a> ";
    html += "<a href='/reset'><button style='padding:10px 15px;'>Reinitialiser journee</button></a></p>";

    html += "<h2>Planning horaire</h2><ul>";
    for (const Creneau_Repas &c : planning)
    {
        html += "<li>" + c.disponibilite_heure() + "</li>";
    }
    html += "</ul>";

    html += "<h2>Historique des repas</h2><ul>";
    if (historique.empty())
    {
        html += "<li>Aucun repas enregistre</li>";
    }
    else
    {
        for (const String &ligne : historique)
        {
            html += "<li>" + ligne + "</li>";
        }
    }
    html += "</ul></body></html>";
    return html;
}

void Distributeur::ajouter_Creneau(unsigned int ndebut, unsigned int nfin)
{
    planning.push_back(Creneau_Repas(ndebut, nfin));
}

void Distributeur::reinitialiserJournee()
{
    for (Creneau_Repas &creneau : planning)
    {
        creneau.resetDejaPris();
    }
    historique.push_back("Réinitialisation de la journée");
}

void Distributeur::demanderRepasTactile(unsigned int tempsActuel)
{
    for (Creneau_Repas &creneau : planning)
    {
        if (creneau.estAutorise(tempsActuel) == true)
        {
            ordreDistrib = true;
            creneau.marquerCommePris();
            historique.push_back("Repas Tactile servie à" + String(tempsActuel) + "s");
            return;
        }
    }
    throw horsCreneau();
}

void Distributeur::repasWifi(unsigned int tempsActuel)
{
    ordreDistrib = true;
    historique.push_back("Repas par 4G servie à" + String(tempsActuel) + "s");
}

bool Distributeur::getOrdreDistribution()
{
    if (ordreDistrib == true)
    {
        ordreDistrib = false;
        return true;
    }
    return false;
}
const std::vector<String> &Distributeur::getHistorique() const
{
    return historique;
}

const std::vector<Creneau_Repas> &Distributeur::getPlanning() const
{
    return planning;
}

std::ostream& operator<<(std::ostream& os, const Distributeur& distrib) {
    os << "=== Etat du Distributeur ===\n";
    os << "Creneaux configures : " << distrib.planning.size() << "\n";
    for (const Creneau_Repas& c : distrib.planning) {
        os << "  - " << c.disponibilite_heure().c_str() << "\n";
    }
    return os;
}
