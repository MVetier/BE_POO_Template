class Distributeur {
private:
    std::vector<CreneauRepas> planning;
    std::vector<String> historique;
    bool ordreDistrib;   // Drapeau lu par le .ino pour actionner le servo

    ESP8266WebServer server;
    String ssid;
    String password;

    // Génération de la page HTML et routes HTTP
    String genererPageHTML() const;
    void configurerRoutes();

public:
    Distributeur(/* numéros de pins */);
    void initialiser();       // Initialise tous les capteurs/actionneurs
    void verifierDemande();   // Regarde si le chien appuie sur le pavé
    void distribuerPortion(); // Vérifie les règles, ouvre le servo, met à jour l'historique
};