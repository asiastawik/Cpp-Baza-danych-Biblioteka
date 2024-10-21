#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "Ksiazka.h"
#include "Biblioteka.h"
#include "Egzemplarz.h"

void zapisz(std::vector<Ksiazka>& zbior); //zapis danych
void odczyt(std::vector<Ksiazka>& zbior); //odczyt danych z bazy

int main()
{
    Biblioteka biblioteka = Biblioteka();
    odczyt(biblioteka.getzbiorKsiazek());

    std::cout << "                                                 WITAMY W BIBLIOTECE!\n";

    while (true)
    {
        std::cout << "Wybierz, co chcesz zrobic i zatwierdz klawiszem 'enter'." << std::endl;
        std::cout << "0. Dodaj nowa ksiazke.\n";
        std::cout << "1. Usun ksiazke.\n";
        std::cout << "2. Zmien dane ksiazki.\n";
        std::cout << "3. Wyszukaj.\n";
        std::cout << "4. Wyswietl wszystkie ksiazki.\n";
        std::cout << "5. Wyswietl statystyki.\n";
        std::cout << "6. Zamknij program i zapisz dane.\n";

        std::string opcja;
        getline(std::cin, opcja);

        try
        {
            int wybor = stoi(opcja); //stoi konwertuje do inta
            switch (wybor)
            {
            case 0:
            {
                biblioteka.dodajKsiazke();
                break;
            }

            case 1:
            {
                biblioteka.usunKsiazke();
                break;
            }

            case 2:
            {
                biblioteka.zmienDaneKsiazki();
                break;
            }

            case 3:
            {
                biblioteka.wyszukajKsiazke();
                break;
            }

            case 4:
            {
                biblioteka.wypiszWszystkieKsiazki();
                biblioteka.wypiszWszystkieKsiazki();
                break;
            }

            case 5:
            {
                std::cout << "\nStatystyki:" << std::endl;
                std::cout << "Srednia liczba nagrod literackich na ksiazke: " << biblioteka.getSredniaLiczbaNagrod() << std::endl;
                std::cout << "Srednia ilosc stron ksiazki: " << biblioteka.getSredniaIloscStron() << std::endl;
                std::cout << "Srednia ocena czytelnikow: " << biblioteka.getSredniaOcen() << std::endl;
                std::cout << "\n";
                std::cout << "Ksiazka, ktora zdobya najwiecej nagrod: " << biblioteka.getKsiazkaMaxNagrod().getTytul() << std::endl;
                std::cout << "Ksiazka, ktora ma najwiecej stron: " << biblioteka.getKsiazkaMaxIloscStron().getTytul() << std::endl;
                std::cout << "Ksiazka, ktora jest najlepiej oceniona: " << biblioteka.getKsiazkaMaxOcena().getTytul() << std::endl;
                std::cout << "\n\n";
                break;
            }

            case 6:
            {
                zapisz(biblioteka.getzbiorKsiazek());
                exit(0);
                break;
            }

            default:
            {
                std::cout << "Nieprawidlowa wartosc! Prosze wprowadz prawidlowa wartosc!\n" << std::endl;
                break;
            }
            }
        }

        catch (std::exception exception)
        {
            throw "Bledna wartosc! Prosze podac prawidlowa wartosc!\n";
        }
    }
    return 0;
}

void odczyt(std::vector<Ksiazka>& zbior)
{
    std::ifstream plik;

    plik.open("baza.txt", std::ios::in);
    if (plik.is_open()) 
    {
        std::vector<std::string> wiersz;
        std::string linia, slowo , temp;

        while (plik) 
        {
            wiersz.clear();

            std::getline(plik, linia);
            std::stringstream s(linia);

            while (getline(s, slowo, ';')) 
            {
                wiersz.push_back(slowo);
            }

            Ksiazka ksiazka = Ksiazka(wiersz[0],
                wiersz[1],
                wiersz[2],
                wiersz[3],
                stoi(wiersz[4]), //bo int
                stof(wiersz[5]), //bo float
                stof(wiersz[6]));

            if (plik.eof()) 
                break;

            zbior.push_back(ksiazka);
        }
    }
    else 
        std::cout << "Blad otwierania bazy danych!" << std::endl;
}

void zapisz(std::vector<Ksiazka>& zbior)
{
    std::ofstream plik;

    plik.open("Ksiazki.txt", std::ifstream::out);

    if (plik.good())
    {
        for (int i = 0; i < zbior.size(); i++)
        {
            plik << zbior[i].getTytul() << ";";
            plik << zbior[i].getAutor() << ";";
            plik << zbior[i].getGatunek() << ";";
            plik << zbior[i].getRokWydania() << ";";
            plik << zbior[i].getLiczbaNagrod() << ";";
            plik << zbior[i].getIloscStron() << ";";
            plik << zbior[i].getOcena() << std::endl;
        }

        std::cout << "Wyniki poprawnie zapisano do pliku Ksiazki.txt.\n";
    }

    else
    {
        throw "Niestety, nie udalo sie otworzyc pliku.\n";
    }

    plik.close();
}
