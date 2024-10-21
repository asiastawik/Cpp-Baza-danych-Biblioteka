#include "Ksiazka.h"

Ksiazka::Ksiazka(const std::string& tytul, const std::string& autor, const std::string& gatunek, const std::string& rokWydania, int liczbaNagrod, float iloscStron, float ocena)
    : Egzemplarz(tytul, autor, gatunek, rokWydania), liczbaNagrod(liczbaNagrod), iloscStron(iloscStron), ocena(ocena) //lista inicjalizacyjna
{
    this->tytul = tytul;
    this->autor = autor;
    this->gatunek = gatunek;
    this->rokWydania = rokWydania;
    this->liczbaNagrod = liczbaNagrod;
    this->iloscStron = iloscStron;
    this->ocena = ocena;
}

const float Ksiazka::getIloscStron()
{
    return iloscStron;
}

void Ksiazka::setIloscStron(float iloscStron)
{
    Ksiazka::iloscStron = iloscStron;
}

const int Ksiazka::getLiczbaNagrod()
{
    return liczbaNagrod;
}

void Ksiazka::setLiczbaNagrod(int liczbaNagrod)
{
    Ksiazka::liczbaNagrod = liczbaNagrod;
}

const float Ksiazka::getOcena()
{
    return ocena;
}

void Ksiazka::setOcena(float ocena)
{
    Ksiazka::ocena = ocena;
}
