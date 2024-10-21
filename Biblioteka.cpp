#include <regex> //do wyszukiwania fraz
#include <iostream>
#include <exception>
#include <sstream>
#include "Biblioteka.h"

Ksiazka Biblioteka::getKsiazkaMaxNagrod()
{
    std::vector<Ksiazka> zbiorKsiazekAll = Biblioteka::getzbiorKsiazek();
    int maxLiczbaNagrod = -1; //wstepna wartosc, sluzy do porownania
    int indexNajwiecejNagrod;
    for (int i = 0; i < zbiorKsiazekAll.size(); i++)
    {
        if (maxLiczbaNagrod < zbiorKsiazekAll[i].getLiczbaNagrod())
        {
            maxLiczbaNagrod = zbiorKsiazekAll[i].getLiczbaNagrod();
            indexNajwiecejNagrod = i;
        }
    }
    return zbiorKsiazek[indexNajwiecejNagrod];
}

Ksiazka Biblioteka::getKsiazkaMaxOcena()
{
    std::vector<Ksiazka> zbiorKsiazek = Biblioteka::getzbiorKsiazek();
    float maxOcena = -1;
    int indexNajlepszaOcena;
    for (int i = 0; i < zbiorKsiazek.size(); i++)
    {
        if (maxOcena < zbiorKsiazek[i].getOcena())
        {
            maxOcena = zbiorKsiazek[i].getOcena();
            indexNajlepszaOcena = i;
        }
    }
    return zbiorKsiazek[indexNajlepszaOcena];
}

Ksiazka Biblioteka::getKsiazkaMaxIloscStron()
{
    std::vector<Ksiazka> zbiorKsiazek = Biblioteka::getzbiorKsiazek();
    float maxIloscStron = -1;
    int indexNajdluzszaKsiazka;
    for (int i = 0; i < zbiorKsiazek.size(); i++)
    {
        if (maxIloscStron < zbiorKsiazek[i].getIloscStron())
        {
            maxIloscStron = zbiorKsiazek[i].getIloscStron();
            indexNajdluzszaKsiazka = i;
        }
    }
    return zbiorKsiazek[indexNajdluzszaKsiazka];
}


float Biblioteka::getSredniaLiczbaNagrod()
{
    std::vector<Ksiazka> zbiorKsiazek = Biblioteka::getzbiorKsiazek();
    float sumaNagrod = 0;
    for (int i = 0; i < zbiorKsiazek.size(); i++)
    {
        sumaNagrod += zbiorKsiazek[i].getLiczbaNagrod(); //zliczamy
    }
    return sumaNagrod / float(zbiorKsiazek.size()); //srednia to suma podzielona przez ilosc
}

float Biblioteka::getSredniaOcen()
{
    std::vector<Ksiazka> zbiorKsiazek = Biblioteka::getzbiorKsiazek();
    float sumaOcen = 0;
    for (int i = 0; i < zbiorKsiazek.size(); i++)
    {
        sumaOcen += zbiorKsiazek[i].getOcena();
    }
    return sumaOcen / float(zbiorKsiazek.size());
}

float Biblioteka::getSredniaIloscStron()
{
    std::vector<Ksiazka> zbiorKsiazekAll = Biblioteka::getzbiorKsiazek();
    float sumaIloscStron = 0;
    for (int i = 0; i < zbiorKsiazekAll.size(); i++)
    {
        sumaIloscStron += zbiorKsiazekAll[i].getIloscStron();
    }
    return sumaIloscStron / float(zbiorKsiazek.size());
}

std::vector<Ksiazka>& Biblioteka::getzbiorKsiazek()
{
    return zbiorKsiazek;
}

void Biblioteka::wypiszWszystkieKsiazki()
{
    std::cout << "\nLista ksiazek:\n" << std::endl;
    for (int i = 0; i < Biblioteka::zbiorKsiazek.size(); i++)
    {
        std::cout << i << ". " << Biblioteka::zbiorKsiazek[i].getTytul();
        std::cout << " | " << Biblioteka::zbiorKsiazek[i].getAutor();
        std::cout << " | " << Biblioteka::zbiorKsiazek[i].getGatunek();
        std::cout << " | " << Biblioteka::zbiorKsiazek[i].getRokWydania();
        std::cout << " | " << Biblioteka::zbiorKsiazek[i].getLiczbaNagrod();
        std::cout << " | " << Biblioteka::zbiorKsiazek[i].getIloscStron();
        std::cout << " | " << Biblioteka::zbiorKsiazek[i].getOcena();
        std::cout << std::endl;
    }
}

void Biblioteka::usunKsiazke()
{
    std::cout << "\nPodaj index ksiazki do usuniecia z listy ponizej:\n";
    wypiszWszystkieKsiazki();

    std::string indexS;
    getline(std::cin, indexS);
    int index;

    try
    {
        index = stoi(indexS); //stoi(x) zamienia x na wartosc int
        Biblioteka::zbiorKsiazek.erase(Biblioteka::zbiorKsiazek.begin() + index);
        std::cout << "Ksiazke usunieto pomyslnie.\n";
    }

    catch (std::exception exception)
    {
        throw "Nie ma takiej ksiazki. Usuwanie nie powiodlo sie!\n";
    }
}

void Biblioteka::dodajKsiazke()
{
    std::cout << "\nPodaj kolejne wartosci oddzielone '/' " << std::endl;
    std::cout << "Tytul/Autor/Gatunek/Rok wydania/Liczba nagrod literackich/Ilosc stron/Ocena czytelnikow" << std::endl;
   
    std::vector<std::string> wiersz;
    std::string line, slowo, temp;

    wiersz.clear();
    getline(std::cin, line);
    std::stringstream s(line);

    while (getline(s, slowo, '/'))
    {
        wiersz.push_back(slowo);
    }

    int liczbaNagrod;
    float iloscStron, ocena;

    try
    {
        liczbaNagrod = stoi(wiersz[4]);
        iloscStron = stof(wiersz[5]);
        ocena = stof(wiersz[6]);

        Ksiazka ksiazka = Ksiazka(wiersz[0],
            wiersz[1],
            wiersz[2],
            wiersz[3],
            liczbaNagrod,
            iloscStron,
            ocena);
        Biblioteka::zbiorKsiazek.push_back(ksiazka);
        std::cout << "\nKsiazke dodano pomyslnie!\n";

    }

    catch (std::exception exception)
    {
        throw "Dodawanie ksiazki nie powiodlo sie!\n";
    }
}

void Biblioteka::wyszukajKsiazke() // regex - wyrazenie regularne - wzorzec do ktorego da sie dopasowac tylko pewien tekst
{
    std::string fraza;
    std::cout << "\nWyszukiwarka fraz. Mozesz wyszukac jednoczesnie w tytulach, autorach i gatunkach!\n";
    std::cout << "\nPodaj fraze, ktora chcesz wyszukac: ";
    getline(std::cin, fraza);

    std::regex wzorzec; //"Tworzymy wzorzec, ktorego klasa ma taka sama nazwe jak jego biblioteka"
    wzorzec = fraza;
    std::smatch wynik; //tutaj bedzie zapisany wynik

    for (int i = 0; i < Biblioteka::zbiorKsiazek.size(); i++)
    {
        if (regex_search(Biblioteka::zbiorKsiazek[i].getTytul(), wynik, wzorzec)) //regex_search( string &, smatch &, regex & );
        {
            std::cout << "Podana fraze znaleziono w tytule:\n";
            std::cout << i << ". " << Biblioteka::zbiorKsiazek[i].getTytul();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getAutor();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getGatunek();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getRokWydania();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getLiczbaNagrod();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getIloscStron();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getOcena() << "\n\n";
        }

        else if (regex_search(Biblioteka::zbiorKsiazek[i].getAutor(), wynik, wzorzec)) {
            std::cout << "Podana fraze znaleziono w autorze:\n";
            std::cout << i << ". " << Biblioteka::zbiorKsiazek[i].getTytul();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getAutor();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getGatunek();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getRokWydania();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getLiczbaNagrod();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getIloscStron();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getOcena() << "\n\n";
        }

        else if (regex_search(Biblioteka::zbiorKsiazek[i].getGatunek(), wynik, wzorzec)) {
            std::cout << "Podana fraze znaleziono w gatunku:\n";
            std::cout << i << ". " << Biblioteka::zbiorKsiazek[i].getTytul();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getAutor();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getGatunek();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getRokWydania();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getLiczbaNagrod();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getIloscStron();
            std::cout << " | " << Biblioteka::zbiorKsiazek[i].getOcena() << "\n\n";
        }

        else
        {
            std::cout << "Nie znaleziono podanej frazy.\n";
        }
    }
}

void Biblioteka::zmienDaneKsiazki()
{
    std::cout << "\nPodaj index ksiazki do zmiany z listy ponizej:\n";
    wypiszWszystkieKsiazki();

    std::string indexS;
    std::getline(std::cin, indexS);

    try
    {
        int index = stoi(indexS);
        std::cout << "\n0. Tytul\n";
        std::cout << "1. Autor\n";
        std::cout << "2. Gatunek\n";
        std::cout << "3. Rok wydania\n";
        std::cout << "4. Liczba nagrod literackich\n";
        std::cout << "5. Ilosc stron\n";
        std::cout << "6. Ocena czytelnikow\n";
        std::cout << "Ktora wartosc chcesz zmienic: ";

        std::string opcjaS;
        std::getline(std::cin, opcjaS);
        int opcja = stoi(opcjaS);

        switch (opcja)
        {
        case 0:
        {
            std::cout << "Podaj nowy tytul: ";
            std::string nowaWartosc;
            std::getline(std::cin, nowaWartosc);
            Biblioteka::zbiorKsiazek[index].setTytul(nowaWartosc);
            break;
        }

        case 1:
        {
            std::cout << "Podaj nowego autora: ";
            std::string nowaWartosc;
            std::getline(std::cin, nowaWartosc);
            Biblioteka::zbiorKsiazek[index].setAutor(nowaWartosc);
            break;
        }

        case 2:
        {
            std::cout << "Podaj nowy gatunek: ";
            std::string nowaWartosc;
            std::getline(std::cin, nowaWartosc);
            Biblioteka::zbiorKsiazek[index].setGatunek(nowaWartosc);
            break;
        }

        case 3:
        {
            std::cout << "Podaj nowy rok wydania: ";
            std::string nowaWartosc;
            std::getline(std::cin, nowaWartosc);
            Biblioteka::zbiorKsiazek[index].setRokWydania(nowaWartosc);
            break;
        }
        case 4:
        {
            std::cout << "Podaj nowa liczbe nagrod: ";
            std::string nowaWartosc;
            std::getline(std::cin, nowaWartosc);
            Biblioteka::zbiorKsiazek[index].setLiczbaNagrod(std::stoi(nowaWartosc));
            break;
        }

        case 5:
        {
            std::cout << "Podaj nowa ilosc stron: ";
            std::string nowaWartosc;
            std::getline(std::cin, nowaWartosc);
            Biblioteka::zbiorKsiazek[index].setIloscStron(std::stof(nowaWartosc));
            break;
        }

        case 6:
        {
            std::cout << "Podaj nowa ocene czytelnikow: ";
            std::string nowaWartosc;
            std::getline(std::cin, nowaWartosc);
            Biblioteka::zbiorKsiazek[index].setOcena(std::stof(nowaWartosc));
            break;
        }
        }
        std::cout << "\n\n";
    }

    catch (std::exception exception)
    {
        throw "Zmiana danych ksiazki nie powiodla sie!\n";
    }
}