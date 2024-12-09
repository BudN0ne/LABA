//#include <iostream>
//#include <iomanip>
//#include <clocale>
//#include <cmath>
//
//using namespace std;
//
//const double PI = 3.14; //Dla uproszczenia zaokr¹gli³em PI do dwóch miejsc po przecinku
//
//// Funkcja do obliczania objêtoœci kuli
//double obliczObjetoscKuli(double promien) {
//    return (4.0 / 3.0) * PI * pow(promien, 3);
//}
//
//// Funkcja do konwersji objêtoœci
//double konwertujObjetosc(double objetosc, const string& jednostka) {
//    if (jednostka == "m3") {
//        return objetosc; // Domyœlnie w metrach szeœciennych
//    }
//    else if (jednostka == "cm3") {
//        return objetosc * 1e6; // Konwersja na centymetry szeœcienne
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
//    cout << "Podaj promieñ kuli: ";
//    cin >> promien;
//
//    double objetosc = obliczObjetoscKuli(promien);
//    cout << fixed << setprecision(2); // Dla uproszczenia wynik zaokr¹gli³em do dwóch miejsc po przecinku
//    cout << "Objêtoœæ kuli w metrach szeœciennych: " << objetosc << " m^3" << endl;
//
//    string jednostka;
//    cout << "Podaj jednostkê docelow¹ (m3, cm3, l): ";
//    cin >> jednostka;
//
//    double objetoscWJednostkach = konwertujObjetosc(objetosc, jednostka);
//    if (objetoscWJednostkach != -1) {
//        cout << "Objêtoœæ kuli w " << jednostka << ": " << objetoscWJednostkach << endl;
//    }
//
//    return 0;
//}