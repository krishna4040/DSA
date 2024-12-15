#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    string current_player = "Jon";

    cout << "Enter the starting number: ";
    cin >> N;

    while (N > 1) {
        bool valid_move = false;

        while (!valid_move) {
            int move;   // 2 or 3 or 4 or 5
            cout << current_player << ", make a move: ";
            cin >> move;

            if (N - move == 1) {
                cout << current_player << " loses!" << endl;
                return 0;
            } else if (move == 2 || move == 3 || move == 4 || move == 5) {
                N -= move;
                valid_move = true;
            } else if (N % move == 0 && move >= 2 && move <= 5) {
                N /= move;
                valid_move = true;
            } else {
                cout << "Invalid move. Please choose a number between 2 and 5 that divides N or a number between 2 and 5 to subtract from N." << endl;
            }
        }

        if (N == 1) {
            cout << current_player << " loses!" << endl;
            return 0;
        }

        if (current_player == "Jon") {
            current_player = "Arya";
        } else {
            current_player = "Jon";
        }
    }

    cout << "No moves left. " << current_player << " loses!" << endl;

    return 0;
}
