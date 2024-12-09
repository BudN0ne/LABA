//#include <iostream>
//#include <clocale>
//#include <vector>
//#include <iomanip> 
//#include <limits>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//using namespace std;
//
//// Funkcja do wyœwietlania planszy z numerami wspó³rzêdnych
//void displayBoard(const vector<vector<char>>& board) {
//    int size = board.size();
//    cout << "   ";
//    for (int i = 0; i < size; ++i) {
//        cout << setw(2) << i << " ";
//    }
//    cout << " y" << endl;
//
//    for (int i = 0; i < size; ++i) {
//        cout << setw(2) << i << " ";
//        for (char cell : board[i]) {
//            cout << setw(2) << cell << " ";
//        }
//        cout << endl;
//    }
//    cout << " x" << endl;
//}
//
//// Funkcja do sprawdzania, czy ktoœ wygra³
//bool checkWin(const vector<vector<char>>& board, char player, int winCondition) {
//    int size = board.size();
//    // Sprawdzanie wierszy i kolumn
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j <= size - winCondition; ++j) {
//            if (count(board[i].begin() + j, board[i].begin() + j + winCondition, player) == winCondition ||
//                count_if(board.begin() + j, board.begin() + j + winCondition, [i, player](const vector<char>& row) { return row[i] == player; }) == winCondition) {
//                return true;
//            }
//        }
//    }
//    // Sprawdzanie przek¹tnych
//    for (int i = 0; i <= size - winCondition; ++i) {
//        for (int j = 0; j <= size - winCondition; ++j) {
//            bool diag1 = true, diag2 = true;
//            for (int k = 0; k < winCondition; ++k) {
//                if (board[i + k][j + k] != player) diag1 = false;
//                if (board[i + k][j + winCondition - k - 1] != player) diag2 = false;
//            }
//            if (diag1 || diag2) return true;
//        }
//    }
//    return false;
//}
//
//// Funkcja do sprawdzania, czy plansza jest pe³na
//bool isBoardFull(const vector<vector<char>>& board) {
//    for (const auto& row : board) {
//        if (count(row.begin(), row.end(), ' ') > 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// Funkcja do wykonania ruchu komputera na poziomie ³atwym
//void easyComputerMove(vector<vector<char>>& board, char computer) {
//    int size = board.size();
//    srand(time(0));
//    int x, y;
//    do {
//        x = rand() % size;
//        y = rand() % size;
//    } while (board[x][y] != ' ');
//    board[x][y] = computer;
//}
//
//// Funkcja do wykonania ruchu komputera na poziomie œrednim
//void mediumComputerMove(vector<vector<char>>& board, char computer, char human) {
//    int size = board.size();
//
//    // Najpierw spróbuj znaleŸæ ruch wygrywaj¹cy dla komputera
//    for (int x = 0; x < size; ++x) {
//        for (int y = 0; y < size; ++y) {
//            if (board[x][y] == ' ') {
//                board[x][y] = computer;
//                if (checkWin(board, computer, 3)) return;
//                board[x][y] = ' ';
//            }
//        }
//    }
//
//    // Nastêpnie spróbuj zablokowaæ wygrywaj¹cy ruch gracza
//    for (int x = 0; x < size; ++x) {
//        for (int y = 0; y < size; ++y) {
//            if (board[x][y] == ' ') {
//                board[x][y] = human;
//                if (checkWin(board, human, 3)) {
//                    board[x][y] = computer;
//                    return;
//                }
//                board[x][y] = ' ';
//            }
//        }
//    }
//
//    // Wykonaj losowy ruch
//    easyComputerMove(board, computer);
//}
//
//// Funkcja oceny dla algorytmu minimax
//int evaluate(const vector<vector<char>>& board, char computer, char human, int winCondition) {
//    if (checkWin(board, computer, winCondition)) return +10;
//    if (checkWin(board, human, winCondition)) return -10;
//    return 0;
//}
//
//// Implementacja algorytmu minimax
//int minimax(vector<vector<char>>& board, int depth, bool isMaximizingPlayer, char computer, char human, int winCondition) {
//    int score = evaluate(board, computer, human, winCondition);
//
//    if (score == 10 || score == -10)
//        return score;
//
//    if (isBoardFull(board))
//        return 0;
//
//    int best;
//
//    if (isMaximizingPlayer) {
//        best = -1000;
//
//        for (int x = 0; x < board.size(); ++x) {
//            for (int y = 0; y < board.size(); ++y) {
//                if (board[x][y] == ' ') {
//                    board[x][y] = computer;
//
//                    best = max(best,
//                        minimax(board, depth + 1, !isMaximizingPlayer,
//                            computer, human, winCondition));
//
//                    board[x][y] = ' ';
//                }
//            }
//        }
//    }
//    else {
//        best = 1000;
//
//        for (int x = 0; x < board.size(); ++x) {
//            for (int y = 0; y < board.size(); ++y) {
//                if (board[x][y] == ' ') {
//                    board[x][y] = human;
//
//                    best = min(best,
//                        minimax(board, depth + 1, !isMaximizingPlayer,
//                            computer, human, winCondition));
//
//                    board[x][y] = ' ';
//                }
//            }
//        }
//    }
//
//    return best;
//}
//
//// Funkcja do wykonania ruchu komputera na poziomie trudnym
//void hardComputerMove(vector<vector<char>>& board, char computer, char human, int winCondition) {
//    int bestVal = -1000;
//    int bestMoveX = -1;
//    int bestMoveY = -1;
//
//    for (int x = 0; x < board.size(); ++x) {
//        for (int y = 0; y < board.size(); ++y) {
//            if (board[x][y] == ' ') {
//
//                board[x][y] = computer;
//
//                int moveVal =
//                    minimax(board, 0, false,
//                        computer, human, winCondition);
//
//                board[x][y] = ' ';
//
//                if (moveVal > bestVal) {
//                    bestMoveX = x;
//                    bestMoveY = y;
//                    bestVal = moveVal;
//                }
//            }
//        }
//    }
//
//    if (bestMoveX != -1 && bestMoveY != -1)
//        board[bestMoveX][bestMoveY] = computer;
//}
//
//int main() {
//    setlocale(LC_ALL, "Polish");
//
//    int size;
//    cout << "Podaj rozmiar planszy (od 3 do 12): ";
//    cin >> size;
//
//    if (size < 3 || size > 12) {
//        cout << "Nieprawid³owy rozmiar planszy!" << endl;
//        return 1;
//    }
//
//    int winCondition = 3;
//
//    if (size > 3) {
//        cout << "Wybierz warunek zwyciêstwa: 1 - Trzy w linii lub po skosie,"
//            << "2 - Ca³a linia lub skos: ";
//        int conditionChoice;
//        cin >> conditionChoice;
//
//        if (conditionChoice == 2)
//            winCondition = size;
//
//    }
//
//    vector<vector<char>>board(size, vector<char>(size, ' '));
//
//    char human = 'X', computer = 'O';
//
//    int gameMode;
//    cout << "Wybierz tryb gry: 1-Dwóch graczy, 2-Gra z komputerem: ";
//    cin >> gameMode;
//
//    string playerOneName = gameMode == 1 ? "Player One" : "Human Player";
//    string playerTwoName = gameMode == 1 ? "Player Two" : "Computer";
//
//    bool humanTurn = true;
//
//    int difficultyLevel = 1;
//
//    if (gameMode == 2) {
//        cout << "Wybierz poziom trudnoœci: 1-£atwy, 2-Œredni, 3-Trudny: ";
//        cin >> difficultyLevel;
//
//    }
//    while (true) {
//        displayBoard(board);
//
//        if (humanTurn || gameMode == 1) {
//            int x, y;
//            string currentPlayerName = humanTurn ? playerOneName : playerTwoName;
//            cout << currentPlayerName << ", podaj wspó³rzêdne x: ";
//            cin >> x;
//            cout << "Podaj wspó³rzêdne y: ";
//            cin >> y;
//
//            if (x < 0 || x >= size || y < 0 || y >= size || board[x][y] != ' ') {
//                cout << "Nieprawid³owy ruch. Spróbuj ponownie ." << endl;
//                continue;
//
//            }
//
//            board[x][y] = humanTurn ? human : computer;
//
//            if (checkWin(board, humanTurn ? human : computer, winCondition)) {
//                displayBoard(board);
//                cout << currentPlayerName << " wygrywa!" << endl;
//                break;
//
//            }
//            if (isBoardFull(board)) {
//                displayBoard(board);
//                cout << "Remis!" << endl;
//                break;
//
//            }
//
//            humanTurn = !humanTurn;
//        }
//        else {
//            cout << "Ruch komputera ..." << endl;
//
//            switch (difficultyLevel) {
//            case 1:
//                easyComputerMove(board, computer);
//                break;
//
//            case 2:
//                mediumComputerMove(board, computer, human);
//                break;
//
//            case 3:
//                hardComputerMove(board, computer, human, winCondition);
//                break;
//            }
//
//            if (checkWin(board, computer, winCondition)) {
//                displayBoard(board);
//                cout << playerTwoName << " wygrywa!" << endl;
//                break;
//
//            }
//
//            if (isBoardFull(board)) {
//                displayBoard(board);
//                cout << "Remis!" << endl;
//                break;
//            }
//
//            humanTurn = !humanTurn;
//        }
//    }
//    return 0;
//}