#ifndef DISTRIBUTEUR_H
#define DISTRIBUTEUR_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <vector>
#include <iostream>
#include "Creneau_Repas.h"


class Distributeur
{
private:
    std::vector<Creneau_Repas> planning;
    std::vector<String> historique;

    bool ordreDistrib; // Drapeau lu par le .ino pour actionner le servo
    unsigned int nbRepas_Servis;

    ESP8266WebServer server;
    String ssid;
    String password;

    // Génération de la page HTML et routes HTTP
    String PageHTML() const;
    void configurerRoutes();

public:
    Distributeur(const char *ssid, const char *password); // Constructeur pour initialiser le distributeur avec les informations WiFi

    // Initialisation Wi-Fi et serveur web
    void initialiserWiFi(); // à appeler dans le setup() du .ino
    void gererClientWeb();  // À appeler dans le loop() du .ino

    // Gestion du planning horaire
    void ajouter_Creneau(unsigned int ndebut, unsigned int nfin); // Regarde si le chien appuie sur le pavé
    void reinitialiserJournee();

    // Gestion des demandes de repas
    void demanderRepasTactile(unsigned int tempsActuel); // Vérifie les conditons pour délivrer le repas demandé par l'animal, ordonne le servo d'ouvrir, met à jour l'historique
    void repasWifi(unsigned int tempsActuel);            // Ordonne le servo d'ouvrir par WiFi, met à jour l'historique,

    // Gestion de l'ordre de distribution
    bool getOrdreDistribution(); // Retourne l'état du drapeau ordreDistrib

    const std::vector<String> &getHistorique() const;
    const std::vector<Creneau_Repas> &getPlanning() const;

    // Surcharge de l'opérateur << pour affichage complet
    friend std::ostream& operator<<(std::ostream& os, const Distributeur& distrib);
};

#endif