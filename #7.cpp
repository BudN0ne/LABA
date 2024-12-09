#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Funkcja do wczytania listy s��w z pliku
vector<string> wczytaj_slowa(const string& nazwa_pliku) {
    vector<string> slowa;
    ifstream plik(nazwa_pliku);
    if (plik.is_open()) {
        string linia;
        while (getline(plik, linia)) {
            slowa.push_back(linia);
        }
        plik.close();
    }
    return slowa;
}

// Funkcja do wczytania listy najlepszych wynik�w
vector<pair<string, int>> wczytaj_wyniki(const string& nazwa_pliku) {
    vector<pair<string, int>> wyniki;
    ifstream plik(nazwa_pliku);
    if (plik.is_open()) {
        string linia;
        while (getline(plik, linia)) {
            size_t separator = linia.find(';');
            if (separator != string::npos) {
                string gracz = linia.substr(0, separator);
                int punkty = stoi(linia.substr(separator + 1));
                wyniki.emplace_back(gracz, punkty);
            }
        }
        plik.close();
    }
    return wyniki;
}

// Funkcja do zapisu najlepszych wynik�w
void zapisz_wyniki(const string& nazwa_pliku, const vector<pair<string, int>>& wyniki) {
    ofstream plik(nazwa_pliku);
    if (plik.is_open()) {
        for (const auto& wynik : wyniki) {
            plik << wynik.first << ";" << wynik.second << endl;
        }
        plik.close();
    }
}

// Funkcja wy�wietlaj�ca list� najlepszych wynik�w
void wyswietl_wyniki(const vector<pair<string, int>>& wyniki) {
    cout << "\n=== Najlepsze Wyniki ===" << endl;
    int miejsce = 1;
    for (const auto& wynik : wyniki) {
        cout << miejsce++ << ". " << wynik.first << " - " << wynik.second << " pkt" << endl;
    }
    cout << "========================\n" << endl;
}

// Funkcja do rysowania wisielca w zale�no�ci od liczby pope�nionych b��d�w
void rysuj_wisielca(int bledy) {
    const vector<string> etapy = {
        " +---+\n     |\n     |\n     |\n     |\n     |\n=========",
        " +---+\n |   |\n     |\n     |\n     |\n     |\n=========",
        " +---+\n |   |\n O   |\n     |\n     |\n     |\n=========",
        " +---+\n |   |\n O   |\n |   |\n     |\n     |\n=========",
        " +---+\n |   |\n O   |\n/|   |\n     |\n     |\n=========",
        " +---+\n |   |\n O   |\n/|\\  |\n     |\n     |\n=========",
        " +---+\n |   |\n O   |\n/|\\  |\n/    |\n     |\n=========",
        " +---+\n |   |\n O   |\n/|\\  |\n/ \\  |\n     |\n========="
    };
    cout << etapy[min(bledy, static_cast<int>(etapy.size() - 1))] << endl;
}

// G��wna funkcja gry
void gra_wisielec() {
    vector<string> slowa = wczytaj_slowa("slowa.txt");
    vector<pair<string, int>> wyniki = wczytaj_wyniki("wyniki.txt");

    cout << "Witaj w grze 'Wisielec'!" << endl;
    cout << "Podaj sw�j nick: ";
    string nick;
    cin >> nick;

    srand(static_cast<unsigned>(time(0)));
    string haslo = slowa[rand() % slowa.size()];
    string ukryte_haslo(haslo.size(), '_');
    int pozostale_proby = 6;
    int bledy = 0;

    time_t start_czasu = time(nullptr);

    while (bledy < 7 && ukryte_haslo != haslo) {
        cout << "\nAktualne has�o: " << ukryte_haslo << endl;
        rysuj_wisielca(bledy);

        cout << "Podaj liter�: ";
        char litera;
        cin >> litera;

        if (!isalpha(litera)) {
            cout << "Podaj jedn� liter�!" << endl;
            continue;
        }

        litera = tolower(litera);
        bool trafiona = false;

        for (size_t i = 0; i < haslo.size(); ++i) {
            if (haslo[i] == litera && ukryte_haslo[i] == '_') {
                ukryte_haslo[i] = litera;
                trafiona = true;
            }
        }

        if (!trafiona) {
            ++bledy;
            cout << "Z�a litera!" << endl;
        }
        else {
            cout << "Dobra litera!" << endl;
        }
    }

    time_t czas_gry = time(nullptr) - start_czasu;

    if (ukryte_haslo == haslo) {
        int punkty = (pozostale_proby - bledy) * 10 - static_cast<int>(czas_gry);
        cout << "\nGratulacje! Odgad�e� has�o: " << haslo << endl;
        cout << "Zdoby�e� " << punkty << " punkt�w!" << endl;
        wyniki.emplace_back(nick, punkty);
    }
    else {
        rysuj_wisielca(bledy);
        cout << "\nPrzegra�e�! Has�o to: " << haslo << endl;
    }

    zapisz_wyniki("wyniki.txt", wyniki);
    wyswietl_wyniki(wyniki);
}

int main() {
    gra_wisielec();
    return 0;
}