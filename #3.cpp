//#include <iostream>
//#include <clocale>
//#include <stdexcept>
//
//class Complex {
//private:
//    double real;
//    double imag;
//
//public:
//    // Konstruktor domy�lny
//    Complex() : real(0), imag(0) {}
//
//    // Konstruktor parametryczny
//    Complex(double r, double i) : real(r), imag(i) {}
//
//    // Konstruktor kopiuj�cy
//    Complex(const Complex& other) : real(other.real), imag(other.imag) {}
//
//    // Destruktor
//    ~Complex() {}
//
//    // Prze�adowanie operatora przypisania
//    Complex& operator=(const Complex& other) {
//        if (this != &other) {
//            real = other.real;
//            imag = other.imag;
//        }
//        return *this;
//    }
//
//    // Prze�adowanie operatora dodawania
//    Complex operator+(const Complex& other) const {
//        return Complex(real + other.real, imag + other.imag);
//    }
//
//    // Prze�adowanie operatora odejmowania
//    Complex operator-(const Complex& other) const {
//        return Complex(real - other.real, imag - other.imag);
//    }
//
//    // Prze�adowanie operatora mno�enia
//    Complex operator*(const Complex& other) const {
//        double newReal = real * other.real - imag * other.imag;
//        double newImag = real * other.imag + imag * other.real;
//        return Complex(newReal, newImag);
//    }
//
//    // Prze�adowanie operatora dzielenia
//    Complex operator/(const Complex& other) const {
//        double denominator = other.real * other.real + other.imag * other.imag;
//        if (denominator == 0) {
//            throw std::runtime_error("Dzielenie przez zero!");
//        }
//        double newReal = (real * other.real + imag * other.imag) / denominator;
//        double newImag = (imag * other.real - real * other.imag) / denominator;
//        return Complex(newReal, newImag);
//    }
//
//    // Metody dost�pu do prywatnych sk�adowych
//    double getReal() const { return real; }
//    double getImag() const { return imag; }
//
//    // Metoda do ustawiania warto�ci liczby zespolonej
//    void setValues(double r, double i) {
//        real = r;
//        imag = i;
//    }
//
//    // Metoda do wy�wietlania liczby zespolonej
//    void Print() const {
//        std::cout << real << " + " << imag << "i" << std::endl;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "Polish");
//
//    try {
//        Complex c1, c2;
//
//        double realPart, imagPart;
//
//        std::cout << "Podaj cz�� rzeczywist� dla c1: ";
//        std::cin >> realPart;
//        std::cout << "Podaj cz�� urojon� dla c1: ";
//        std::cin >> imagPart;
//        c1.setValues(realPart, imagPart);
//
//        std::cout << "Podaj cz�� rzeczywist� dla c2: ";
//        std::cin >> realPart;
//        std::cout << "Podaj cz�� urojon� dla c2: ";
//        std::cin >> imagPart;
//        c2.setValues(realPart, imagPart);
//
//        std::cout << "Liczby zespolone:" << std::endl;
//
//        std::cout << "c1: ";
//        c1.Print();
//
//        std::cout << "c2: ";
//        c2.Print();
//
//        // Testowanie operator�w
//        Complex sum = c1 + c2;
//        std::cout << "Suma (c1 + c2): ";
//        sum.Print();
//
//        Complex diff = c1 - c2;
//        std::cout << "R�nica (c1 - c2): ";
//        diff.Print();
//
//        Complex prod = c1 * c2;
//        std::cout << "Iloczyn (c1 * c2): ";
//        prod.Print();
//
//        if (c2.getReal() != 0 || c2.getImag() != 0) {  // Unikanie dzielenia przez zero
//            Complex quot = c1 / c2;
//            std::cout << "Iloraz (c1 / c2): ";
//            quot.Print();
//        }
//        else {
//            std::cout << "Nie mo�na dzieli� przez zero." << std::endl;
//        }
//
//    }
//    catch (const std::runtime_error& e) {
//        std::cerr << "B��d: " << e.what() << std::endl;
//    }
//
//    return 0;
//}