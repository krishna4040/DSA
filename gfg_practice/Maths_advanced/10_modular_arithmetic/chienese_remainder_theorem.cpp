#include <iostream>
#include <vector>
using namespace std;
// Function to calculate the modular inverse of 'a' modulo 'm'
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

// Function to apply the Chinese Remainder Theorem
int chineseRemainderTheorem(const vector<int>& num, const vector<int>& rem) {
    int n = num.size();

    // Compute the product of all moduli
    int M = 1;
    for (int i = 0; i < n; i++) {
        M *= num[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        // Calculate M_i and N_i
        int Mi = M / num[i];
        int Ni = modInverse(Mi, num[i]);

        // Apply the CRT formula
        result += rem[i] * Mi * Ni;
    }

    // Take the result modulo M to obtain the unique solution
    result %= M;

    return result;
}

int main() {
    // Example usage
    vector<int> num = {3, 5, 7};
    vector<int> rem = {2, 3, 2};

    int solution = chineseRemainderTheorem(num, rem);

    cout << "The solution is: " << solution << endl;

    return 0;
}