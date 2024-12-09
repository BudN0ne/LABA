//#include <iostream>
//#include <iomanip>
//#include <clocale>
//#include <cmath>
//
//using namespace std;
//
//const double PI = 3.14; //Dla uproszczenia zaokr�gli�em PI do dw�ch miejsc po przecinku
//
//// Funkcja do obliczania obj�to�ci kuli
//double obliczObjetoscKuli(double promien) {
//    return (4.0 / 3.0) * PI * pow(promien, 3);
//}
//
//// Funkcja do konwersji obj�to�ci
//double konwertujObjetosc(double objetosc, const string& jednostka) {
//    if (jednostka == "m3") {
//        return objetosc; // Domy�lnie w metrach sze�ciennych
//    }
//    else if (jednostka == "cm3") {
//        return objetosc * 1e6; // Konwersja na centymetry sze�cienne
//    }
//    else if (jednostka == "l") {
//        return objetosc * 1e3; // Konwersja na litry
//    }
//    else {
//        cerr << "Nieznana jednostka: " << jednostka << endl;
//        return -1;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Polish");
//
//    double promien;
//    cout << "Podaj promie� kuli: ";
//    cin >> promien;
//
//    double objetosc = obliczObjetoscKuli(promien);
//    cout << fixed << setprecision(2); // Dla uproszczenia wynik zaokr�gli�em do dw�ch miejsc po przecinku
//    cout << "Obj�to�� kuli w metrach sze�ciennych: " << objetosc << " m^3" << endl;
//
//    string jednostka;
//    cout << "Podaj jednostk� docelow� (m3, cm3, l): ";
//    cin >> jednostka;
//
//    double objetoscWJednostkach = konwertujObjetosc(objetosc, jednostka);
//    if (objetoscWJednostkach != -1) {
//        cout << "Obj�to�� kuli w " << jednostka << ": " << objetoscWJednostkach << endl;
//    }
//
//    return 0;
//}