#include <iostream>
#include <vector>

/*A primitive root of a prime number "p" is an integer "g" such that every positive integer coprime to "p" can be expressed
as a power of "g" modulo "p." In other words, "g" generates the multiplicative group of integers modulo "p."*/

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to calculate power modulo m
int powerMod(int base, int exponent, int m) {
    int result = 1;
    base = base % m;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % m;
        exponent = exponent >> 1;
        base = (base * base) % m;
    }
    return result;
}

// Function to find a primitive root of a prime number
int findPrimitiveRoot(int p) {
    if (!isPrime(p)) {
        std::cout << "Error: " << p << " is not a prime number." << std::endl;
        return -1;
    }

    int phi = p - 1; // Euler's totient function
    std::vector<int> factors; // Vector to store prime factors of phi

    // Factorize phi
    int temp = phi;
    for (int i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            factors.push_back(i);
            while (temp % i == 0)
                temp /= i;
        }
    }
    if (temp > 1)
        factors.push_back(temp);

    // Check for primitive root
    for (int r = 2; r <= p; ++r) {
        bool isPrimitiveRoot = true;
        for (int factor : factors) {
            if (powerMod(r, phi / factor, p) == 1) {
                isPrimitiveRoot = false;
                break;
            }
        }
        if (isPrimitiveRoot)
            return r;
    }

    std::cout << "Error: Primitive root not found for " << p << std::endl;
    return -1;
}

int main() {
    int prime = 7; // Example prime number
    int primitiveRoot = findPrimitiveRoot(prime);
    std::cout << "Primitive root of " << prime << " is: " << primitiveRoot << std::endl;

    return 0;
}