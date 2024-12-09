//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <cstdlib>
//#include <clocale>
//
//// Definicje kolorów i wartoœci kart
//enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
//enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
//
//// Struktura reprezentuj¹ca kartê
//struct Card {
//    Suit suit;
//    Rank rank;
//
//    void print() const {
//        const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
//        const char* ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
//        std::cout << ranks[rank - 2] << " of " << suits[suit] << std::endl;
//    }
//};
//
//// Klasa reprezentuj¹ca taliê kart
//class Deck {
//public:
//    Deck() {
//        for (int suit = HEARTS; suit <= SPADES; ++suit) {
//            for (int rank = TWO; rank <= ACE; ++rank) {
//                cards.push_back(Card{ static_cast<Suit>(suit), static_cast<Rank>(rank) });
//            }
//        }
//        std::srand(std::time(0));
//        std::random_shuffle(cards.begin(), cards.end());
//    }
//
//    Card deal() {
//        Card card = cards.back();
//        cards.pop_back();
//        return card;
//    }
//
//private:
//    std::vector<Card> cards;
//};
//
//// Klasa reprezentuj¹ca gracza
//class Player {
//public:
//    void receiveCard(const Card& card) {
//        hand.push_back(card);
//    }
//
//    void showHand() const {
//        for (const auto& card : hand) {
//            card.print();
//        }
//    }
//
//    void clearHand() {
//        hand.clear();
//    }
//
//    int evaluateHand() const {
//        int value = 0;
//        for (const auto& card : hand) {
//            value += card.rank;
//        }
//        return value;
//    }
//
//private:
//    std::vector<Card> hand;
//};
//
//// Funkcja do przeprowadzenia rundy obstawiania
//void bettingRound(Player& player) {
//    int playerBet;
//
//    std::cout << "\nPodaj swoj¹ stawkê: ";
//    std::cin >> playerBet;
//
//    // Prosta logika obstawiania dla komputera
//    int computerBet = rand() % 100 + 1;
//    std::cout << "Komputer stawia: " << computerBet << std::endl;
//
//    if (playerBet > computerBet) {
//        std::cout << "Gracz podbija stawkê.\n";
//    }
//    else if (playerBet < computerBet) {
//        std::cout << "Komputer podbija stawkê.\n";
//    }
//    else {
//        std::cout << "Stawki s¹ wyrównane.\n";
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Polish");
//
//    Deck deck;
//    Player player;
//    Player computer;
//
//    char playAgain;
//
//    do {
//        player.clearHand();
//        computer.clearHand();
//
//        // Rozdanie dwóch kart ka¿demu graczowi
//        player.receiveCard(deck.deal());
//        player.receiveCard(deck.deal());
//
//        computer.receiveCard(deck.deal());
//        computer.receiveCard(deck.deal());
//
//        // Wyœwietlenie r¹k gracza
//        std::cout << "\nRêka Gracza:" << std::endl;
//        player.showHand();
//
//        // Runda obstawiania
//        bettingRound(player);
//
//        // Flop (3 karty wspólne)
//        std::vector<Card> communityCards;
//        communityCards.push_back(deck.deal());
//        communityCards.push_back(deck.deal());
//        communityCards.push_back(deck.deal());
//
//        // Wyœwietlenie kart wspólnych
//        std::cout << "\nKarty wspólne:" << std::endl;
//        for (const auto& card : communityCards) {
//            card.print();
//        }
//
//        // Kolejna runda obstawiania
//        bettingRound(player);
//
//        // Turn (4 karta wspólna)
//        communityCards.push_back(deck.deal());
//
//        // Wyœwietlenie kart wspólnych
//        std::cout << "\nKarty wspólne po turn:" << std::endl;
//        for (const auto& card : communityCards) {
//            card.print();
//        }
//
//        // Kolejna runda obstawiania
//        bettingRound(player);
//
//        // River (5 karta wspólna)
//        communityCards.push_back(deck.deal());
//
//        // Wyœwietlenie kart wspólnych
//        std::cout << "\nKarty wspólne po river:" << std::endl;
//        for (const auto& card : communityCards) {
//            card.print();
//        }
//
//        // Ostateczna runda obstawiania
//        bettingRound(player);
//
//        // Ocena r¹k graczy z uwzglêdnieniem kart wspólnych
//        int playerScore = player.evaluateHand();
//        int computerScore = computer.evaluateHand();
//
//        // Porównanie wyników i og³oszenie zwyciêzcy
//        if (playerScore > computerScore) {
//            std::cout << "\nGracz wygrywa!" << std::endl;
//        }
//        else if (playerScore < computerScore) {
//            std::cout << "\nKomputer wygrywa!" << std::endl;
//        }
//        else {
//            std::cout << "\nRemis!" << std::endl;
//        }
//
//        // Zapytanie o ponown¹ grê
//        std::cout << "\nCzy chcesz zagraæ ponownie? (y/n): ";
//        std::cin >> playAgain;
//
//    } while (playAgain == 'y');
//
//    return 0;
//}