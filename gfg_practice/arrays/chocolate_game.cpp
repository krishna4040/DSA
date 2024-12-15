#include <iostream>
using namespace std;

int main() {
    int A, B, L;
    cout << "Enter the number of chocolates in Box A: ";
    cin >> A;
    cout << "Enter the number of chocolates in Box B: ";
    cin >> B;
    cout << "Enter the number of chocolates that can be eaten in one move (L): ";
    cin >> L;

    // Determine who plays first
    bool buntyPlaysFirst = false;
    if (A != B){
        buntyPlaysFirst = true;
    }

    // Game loop
    bool buntyTurn = buntyPlaysFirst;
    while (A > 0 || B > 0) {
        // Print the current state of the game
        cout << "Box A: " << A << ", Box B: " << B << endl;

        // Determine the move for the current player
        int move = -1;
        if (buntyTurn) {
            // Bunty's turn
            if ((A - B) % L == 0) {
                // No winning move, eat L chocolates from one box
                if (A >= L) {
                    move = L;
                    A -= L;
                } else if (B >= L) {
                    move = L;
                    B -= L;
                } else {
                    // No valid moves left, Bunty loses
                    cout << "Bunty loses!" << endl;
                    return 0;
                }
            } else {
                // Winning move available, eat L chocolates from both boxes
                move = L;
                A -= L;
                B -= L;
            }
        } else {
            // Dolly's turn
            if ((B - A) % L == 0) {
                // No winning move, eat L chocolates from one box
                if (A >= L) {
                    move = L;
                    A -= L;
                } else if (B >= L) {
                    move = L;
                    B -= L;
                } else {
                    // No valid moves left, Dolly loses
                    cout << "Dolly loses!" << endl;
                    return 0;
                }
            } else {
                // Winning move available, eat L chocolates from both boxes
                move = L;
                A -= L;
                B -= L;
            }
        }

        // Print the current move
        if (buntyTurn) {
            cout << "Bunty eats " << move << " chocolates." << endl;
        } else {
            cout << "Dolly eats " << move << " chocolates." << endl;
        }

        // Switch turns
        buntyTurn = !buntyTurn;
    }

    // Both boxes are empty, the last player loses
    if (buntyTurn) {
        cout << "Dolly loses!" << endl;
    } else {
        cout << "Bunty loses!" << endl;
    }

    return 0;
}