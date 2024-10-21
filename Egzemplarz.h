#pragma once
#include <iostream>
//#include <vector>

class Egzemplarz
{
protected:
    std::string tytul;
    std::string autor;
    std::string gatunek;
    std::string rokWydania;

public:
    Egzemplarz(const std::string& tytul, const std::string& autor, const std::string& gatunek, const std::string& rokWydania); //konstruktor kopiujący
    const std::string& getAutor(); //referencja na obiekt string'a, ktorego wartosc nie bedzie zmieniana
    void setAutor(const std::string& autor);
    const std::string& getTytul();
    void setTytul(const std::string& tytul);
    const std::string& getGatunek();
    void setGatunek(const std::string& gatunek);
    void setRokWydania(const std::string& rokWydania);
    const std::string& getRokWydania();
};