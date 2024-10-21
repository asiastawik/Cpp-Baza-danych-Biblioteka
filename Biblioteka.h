#pragma once
#include <vector>
#include "Ksiazka.h"

class Biblioteka
{
private:
    std::vector<Ksiazka> zbiorKsiazek;

public:
    float getSredniaOcen();
    float getSredniaIloscStron();
    float getSredniaLiczbaNagrod();

    Ksiazka getKsiazkaMaxNagrod();
    Ksiazka getKsiazkaMaxIloscStron();
    Ksiazka getKsiazkaMaxOcena();

    std::vector<Ksiazka>& getzbiorKsiazek();

    void wypiszWszystkieKsiazki();
    void dodajKsiazke();
    void zmienDaneKsiazki();
    void wyszukajKsiazke();
    void usunKsiazke();
};