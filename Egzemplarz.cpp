#include "Egzemplarz.h"

Egzemplarz::Egzemplarz(const std::string& tytul, const std::string& autor, const std::string& gatunek, const std::string& rokWydania)
    : tytul(tytul),  //lista inizjalizacyjna
    autor(autor),
    gatunek(gatunek),
    rokWydania(rokWydania)
{
    this->tytul = tytul;
    this->autor = autor;
    this->gatunek = gatunek;
    this->rokWydania = rokWydania;
}

const std::string& Egzemplarz::getAutor()
{
    return autor;
}

void Egzemplarz::setAutor(const std::string& autor)
{
    Egzemplarz::autor = autor;
}

const std::string& Egzemplarz::getTytul()
{
    return tytul;
}

void Egzemplarz::setTytul(const std::string& tytul)
{
    Egzemplarz::tytul = tytul;
}

const std::string& Egzemplarz::getGatunek()
{
    return gatunek;
}

void Egzemplarz::setGatunek(const std::string& gatunek)
{
    Egzemplarz::gatunek = gatunek;
}

void Egzemplarz::setRokWydania(const std::string& rokWydania)
{
    Egzemplarz::rokWydania = rokWydania;
}

const std::string& Egzemplarz::getRokWydania()
{
    return rokWydania;
}