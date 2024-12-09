//#include <iostream>
//#include <queue>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <vector>
//#include <atomic>
//#include <chrono>
//#include <locale>
//
//using namespace std;
//
//// Kolejka wsp�dzielona
//queue<int> buffer;
//const unsigned int bufferSize = 50;
//
//// Mutex i zmienne warunkowe
//mutex mtx;
//condition_variable cv_producer, cv_consumer;
//
//// Statystyki
//atomic<int> producedCount(0);
//atomic<int> consumedCount(0);
//atomic<int> currentBufferSize(0);
//
//// Funkcja producenta
//void producer(int id) {
//    while (true) {
//        unique_lock<mutex> lock(mtx);
//        cv_producer.wait(lock, [] { return currentBufferSize.load() < bufferSize; });
//
//        // Dodaj element do kolejki
//        int item = ++producedCount;
//        buffer.push(item);
//        ++currentBufferSize;
//        cout << "[Producent] Wyprodukowa�: " << item
//            << " (" << currentBufferSize.load() << "/" << bufferSize << ")" << endl;
//
//        lock.unlock();
//        cv_consumer.notify_one();
//
//        this_thread::sleep_for(chrono::milliseconds(100));
//    }
//}
//
//// Funkcja konsumenta
//void consumer(int id) {
//    while (true) {
//        unique_lock<mutex> lock(mtx);
//        cv_consumer.wait(lock, [] { return !buffer.empty(); });
//
//        // Pobierz element z kolejki
//        int item = buffer.front();
//        buffer.pop();
//        ++consumedCount;
//        --currentBufferSize;
//        cout << "[Konsument] Skonsumowa�: " << item
//            << " (" << currentBufferSize.load() << "/" << bufferSize << ")" << endl;
//
//        lock.unlock();
//        cv_producer.notify_one();
//
//        this_thread::sleep_for(chrono::milliseconds(150));
//    }
//}
//
//int main() {
//    // Ustawienie lokalizacji na polsk�
//    setlocale(LC_ALL, "pl_PL.UTF-8");
//
//    vector<thread> producers;
//    vector<thread> consumers;
//
//    // Dodaj pocz�tkowych producent�w i konsument�w
//    for (int i = 0; i < 3; ++i) {
//        producers.emplace_back(producer, i);
//    }
//
//    for (int i = 0; i < 3; ++i) {
//        consumers.emplace_back(consumer, i);
//    }
//
//    // W�tek do monitorowania statystyk
//    thread stats([&]() {
//        while (true) {
//            this_thread::sleep_for(chrono::seconds(2));
//            cout << "Wyprodukowane: " << producedCount.load()
//                << ", Skonsumowane: " << consumedCount.load()
//                << ", Aktualny rozmiar bufora: " << currentBufferSize.load()
//                << "/" << bufferSize << endl;
//        }
//        });
//
//    // Pozw�l na dynamiczne dodawanie/usuwanie producent�w/konsument�w
//    thread manager([&]() {
//        char command;
//        while (true) {
//            cout << "Wprowad� komend� (p - dodaj producenta, c - dodaj konsumenta, q - zako�cz): ";
//            cin >> command;
//            if (command == 'p') {
//                producers.emplace_back(producer, producers.size());
//            }
//            else if (command == 'c') {
//                consumers.emplace_back(consumer, consumers.size());
//            }
//            else if (command == 'q') {
//                break;
//            }
//        }
//        });
//
//    manager.join();
//
//    for (auto& p : producers) p.detach();
//    for (auto& c : consumers) c.detach();
//
//    stats.detach();
//
//    return 0;
//}