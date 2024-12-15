#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate all irreducible fractions in the set A
vector<pair<int, int>> generate_irreducible_fractions() {
    vector<pair<int, int>> fractions;

    for (int d = 1; d <= 10000; d++) {
        for (int n = 1; n <= d; n++) {
            if (__gcd(n, d) == 1) {
                fractions.push_back(make_pair(n, d));
            }
        }
    }

    return fractions;
}

// Function to compare two fractions
bool compare_fractions(pair<int, int> f1, pair<int, int> f2) {
    return f1.first * f2.second > f2.first * f1.second;
}

// Function to find the largest fraction less than given fraction
pair<int, int> find_largest_fraction(pair<int, int> given_fraction, vector<pair<int, int>> fractions) {
    sort(fractions.begin(), fractions.end(), compare_fractions);

    for (auto fraction : fractions) {
        if (fraction.first * given_fraction.second < given_fraction.first * fraction.second) {
            return fraction;
        }
    }

    return make_pair(0, 0);
}

int main() {
    int n, d;
    cout << "Enter the numerator and denominator of the fraction (n/d): ";
    cin >> n >> d;

    // Check if given fraction is already in the set A
    if (__gcd(n, d) == 1 && d <= 10000) {
        cout << "Given fraction is already in the set A." << endl;
        return 0;
    }

    pair<int, int> given_fraction = make_pair(n, d);
    vector<pair<int, int>> fractions = generate_irreducible_fractions();
    pair<int, int> largest_fraction = find_largest_fraction(given_fraction, fractions);

    if (largest_fraction.first == 0 && largest_fraction.second == 0) {
        cout << "No fraction less than given fraction found in the set A." << endl;
    } else {
        cout << "Largest fraction less than given fraction in the set A is: " << largest_fraction.first << "/" << largest_fraction.second << endl;
    }

    return 0;
}