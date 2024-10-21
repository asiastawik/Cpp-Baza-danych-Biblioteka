#pragma once
#include "Egzemplarz.h"

class Ksiazka : public Egzemplarz
{
private:
    int liczbaNagrod;
    float iloscStron;
    float ocena;

public:
    Ksiazka(const std::string& tytul, const std::string& autor, const std::string& gatunek, const std::string& rokWydania, int liczbaNagrod, float iloscStron, float ocena); //konstruktor
    const float getIloscStron();
    void setIloscStron(float iloscStron);
    const int getLiczbaNagrod();
    void setLiczbaNagrod(int liczbaNagrod);
    const float getOcena();
    void setOcena(float ocena);
};
