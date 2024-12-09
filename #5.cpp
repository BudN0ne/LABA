//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//#include <clocale>
//
//using namespace std;
//
//// Klasa Ksiazka reprezentujaca ksiazke
//class Ksiazka {
//private:
//    string tytul;
//    string autor;
//    int id;
//    bool dostepna;
//
//public:
//    // Konstruktor domyslny
//    Ksiazka() : tytul(""), autor(""), id(0), dostepna(true) {}
//
//    // Konstruktor z parametrami
//    Ksiazka(string tytul, string autor, int id) : tytul(tytul), autor(autor), id(id), dostepna(true) {}
//
//    // Metody dostepu do danych ksiazki
//    string getTytul() const { return tytul; }
//    string getAutor() const { return autor; }
//    int getId() const { return id; }
//    bool czyDostepna() const { return dostepna; }
//
//    // Metody do wypozyczania i zwracania ksiazki
//    void wypozycz() { dostepna = false; }
//    void zwroc() { dostepna = true; }
//
//    // Wyswietlanie informacji o ksiazce
//    void wyswietl() const {
//        cout << "ID: " << id << ", Tytul: " << tytul << ", Autor: " << autor
//            << ", Status: " << (dostepna ? "Dostepna" : "Wypozyczona") << endl;
//    }
//};
//
//// Klasa Czytelnik reprezentujaca czytelnika
//class Czytelnik {
//private:
//    string imie;
//    int id;
//    vector<int> wypozyczoneKsiazki;
//
//public:
//    // Konstruktor domyslny
//    Czytelnik() : imie(""), id(0) {}
//
//    // Konstruktor z parametrami
//    Czytelnik(string imie, int id) : imie(imie), id(id) {}
//
//    // Metody dostepu do danych czytelnika
//    string getImie() const { return imie; }
//    int getId() const { return id; }
//
//    // Dodawanie i usuwanie ksiazek z listy wypozyczonych
//    void wypozyczKsiazke(int ksiazkaId) {
//        wypozyczoneKsiazki.push_back(ksiazkaId);
//        cout << imie << " wypozyczyl(a) ksiazke o ID: " << ksiazkaId << endl;
//    }
//
//    void zwrocKsiazke(int ksiazkaId) {
//        auto it = find(wypozyczoneKsiazki.begin(), wypozyczoneKsiazki.end(), ksiazkaId);
//        if (it != wypozyczoneKsiazki.end()) {
//            wypozyczoneKsiazki.erase(it);
//            cout << imie << " zwrocil(a) ksiazke o ID: " << ksiazkaId << endl;
//        }
//        else {
//            cout << "Czytelnik nie posiada tej ksiazki." << endl;
//        }
//    }
//
//};
//
//// Klasa Biblioteka zarzadzajaca zbiorami ksiazek i czytelnikow
//class Biblioteka {
//private:
//    map<int, Ksiazka> ksiazki;
//    map<int, Czytelnik> czytelnicy;
//
//public:
//    // Dodawanie nowej ksiazki do biblioteki
//    void dodajKsiazke(const string& tytul, const string& autor, int id) {
//        if (ksiazki.find(id) == ksiazki.end()) {
//            ksiazki.emplace(id, Ksiazka(tytul, autor, id));
//            cout << "Dodano ksiazke: " << tytul << " (ID: " << id << ")" << endl;
//        }
//        else {
//            cout << "Ksiazka o podanym ID juz istnieje." << endl;
//        }
//    }
//
//    // Usuwanie ksiazki z biblioteki
//    void usunKsiazke(int id) {
//        if (ksiazki.erase(id)) {
//            cout << "Usunieto ksiazke o ID: " << id << endl;
//        }
//        else {
//            cout << "Nie znaleziono ksiazki o podanym ID." << endl;
//        }
//    }
//
//    // Wypozyczanie ksiazki przez czytelnika
//    void wypozyczKsiazke(int czytelnikId, int ksiazkaId) {
//        if (ksiazki.find(ksiazkaId) != ksiazki.end() && czytelnicy.find(czytelnikId) != czytelnicy.end()) {
//            if (ksiazki[ksiazkaId].czyDostepna()) {
//                ksiazki[ksiazkaId].wypozycz();
//                czytelnicy[czytelnikId].wypozyczKsiazke(ksiazkaId);
//            }
//            else {
//                cout << "Ksiazka jest juz wypozyczona." << endl;
//            }
//        }
//        else {
//            cout << "Nie znaleziono czytelnika lub ksiazki." << endl;
//        }
//    }
//
//    // Zwracanie ksiazki przez czytelnika
//    void zwrocKsiazke(int czytelnikId, int ksiazkaId) {
//        if (ksiazki.find(ksiazkaId) != ksiazki.end() && czytelnicy.find(czytelnikId) != czytelnicy.end()) {
//            ksiazki[ksiazkaId].zwroc();
//            czytelnicy[czytelnikId].zwrocKsiazke(ksiazkaId);
//        }
//        else {
//            cout << "Nie znaleziono czytelnika lub ksiazki." << endl;
//        }
//    }
//
//    // Dodawanie nowego czytelnika do systemu
//    void dodajCzytelnika(const string& imie, int id) {
//        if (czytelnicy.find(id) == czytelnicy.end()) {
//            czytelnicy.emplace(id, Czytelnik(imie, id));
//            cout << "Dodano nowego czytelnika: " << imie << " (ID: " << id << ")" << endl;
//        }
//        else {
//            cout << "Czytelnik o podanym ID juz istnieje." << endl;
//        }
//    }
//
//    // Wyswietlanie stanu wszystkich ksiazek w bibliotece
//    void wyswietlStanBiblioteki() const {
//        for (const auto& para : ksiazki) {
//            para.second.wyswietl();
//        }
//    }
//};
//
//// Funkcja menu dla u¿ytkownika
//void menu(Biblioteka& biblioteka) {
//    while (true) {
//        cout << "\nWybierz operacje:\n";
//        cout << "1. Dodaj ksi¹¿kê\n";
//        cout << "2. Usuñ ksi¹¿kê\n";
//        cout << "3. Wypo¿ycz ksi¹¿kê\n";
//        cout << "4. Zwróæ ksi¹¿kê\n";
//        cout << "5. Wyœwietl stan biblioteki\n";
//        cout << "6. Dodaj nowego czytelnika\n";
//        cout << "7. WyjdŸ\n";
//
//        int wybor;
//        cin >> wybor;
//
//        switch (wybor) {
//        case 1: {  // Dodawanie ksi¹¿ki
//            string tytul, autor;
//            int id;
//            cout << "Podaj tytu³ ksi¹¿ki: ";
//            cin.ignore();
//            getline(cin, tytul);
//            cout << "Podaj autora ksi¹¿ki: ";
//            getline(cin, autor);
//            cout << "Podaj ID ksi¹¿ki: ";
//            cin >> id;
//            biblioteka.dodajKsiazke(tytul, autor, id);
//            break;
//        }
//        case 2: {  // Usuwanie ksi¹¿ki
//            int id;
//            cout << "Podaj ID ksi¹¿ki do usuniêcia: ";
//            cin >> id;
//            biblioteka.usunKsiazke(id);  // Poprawiona nazwa funkcji!
//            break;
//        }
//        case 3: {  // Wypo¿yczanie ksi¹¿ki
//            int czytelnik_id, ksia¿ka_id;
//            cout << "Podaj ID czytelnika: ";
//            cin >> czytelnik_id;
//            cout << "Podaj ID ksi¹¿ki do wypo¿yczenia: ";
//            cin >> ksia¿ka_id;
//            biblioteka.wypozyczKsiazke(czytelnik_id, ksia¿ka_id);
//            break;
//        }
//        case 4: {  // Zwracanie ksi¹¿ki
//            int czytelnik_id, ksia¿ka_id;
//            cout << "Podaj ID czytelnika: ";
//            cin >> czytelnik_id;
//            cout << "Podaj ID ksi¹¿ki do zwrotu: ";
//            cin >> ksia¿ka_id;
//            biblioteka.zwrocKsiazke(czytelnik_id, ksia¿ka_id);  // Poprawiona nazwa funkcji!
//            break;
//        }
//        case 5: {  // Wyœwietlanie stanu biblioteki
//            biblioteka.wyswietlStanBiblioteki();
//            break;
//        }
//        case 6: {  // Dodawanie nowego czytelnika
//            string imie;
//            int id_czytelnika;
//            cout << "Podaj imiê i nazwisko nowego czytelnika: ";
//            cin.ignore();
//            getline(cin, imie);
//            cout << "Podaj ID nowego czytelnika: ";
//            cin >> id_czytelnika;
//            biblioteka.dodajCzytelnika(imie, id_czytelnika);
//            break;
//        }
//        case 7:  // Wyjœcie z programu
//            return;
//
//        default:
//            cout << "Niepoprawny wybór. Spróbuj ponownie.\n";
//        }
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Polish");
//
//    Biblioteka biblioteka;
//
//    biblioteka.dodajKsiazke("Pan Tadeusz", "Adam Mickiewicz", 1);
//    biblioteka.dodajKsiazke("Lalka", "Boleslaw Prus", 2);
//    biblioteka.dodajKsiazke("Krzyzacy", "Henryk Sienkiewicz", 3);
//    biblioteka.dodajKsiazke("Ogniem i Mieczem", "Henryk Sienkiewicz", 4);
//    biblioteka.dodajKsiazke("Zbrodnia i kara", "Fiodor Dostojewski", 5);
//    biblioteka.dodajKsiazke("Mistrz i Malgorzata", "Michail Bulhakow", 6);
//    biblioteka.dodajKsiazke("W pustyni i w puszczy", "Henryk Sienkiewicz", 7);
//    biblioteka.dodajKsiazke("Chlopi", "Wladyslaw Reymont", 8);
//    biblioteka.dodajKsiazke("Dziady", "Adam Mickiewicz", 9);
//    biblioteka.dodajKsiazke("Faraon", "Boleslaw Prus", 10);
//
//    // Dodawanie przyk³adowych danych pocz¹tkowych (opcjonalne)
//    biblioteka.dodajCzytelnika("Jan Kowalski", 101);
//
//    menu(biblioteka);  // Uruchomienie menu dla u¿ytkownika
//
//    return 0;
//}