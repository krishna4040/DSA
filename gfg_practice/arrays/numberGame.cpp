/*Given a number n the task is to find the minimum number which is divisible by all numbers from 1 to n.
Print the answer modulo (109+7).*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100005;
const int MOD = 1e9 + 7;

int primes[MAXN], np = 0;
bool is_prime[MAXN];
int cnt[MAXN], max_pow[MAXN];

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes[np++] = i;
            for (int j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void factorize(int n) {
    for (int i = 0; i < np && primes[i] <= n; i++) {
        int p = primes[i];
        int q = n;
        while (q >= p) {
            cnt[p] += q / p;
            q /= p;
        }
    }
}

void compute_lcm(int n) {
    for (int i = 0; i < np && primes[i] <= n; i++) {
        int p = primes[i];
        int q = n;
        while (q >= p) {
            max_pow[p] = max(max_pow[p], cnt[p]);
            q /= p;
        }
    }
}

int numgame(int n) {
    sieve();
    factorize(n);
    compute_lcm(n);
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            ans = (1LL * ans * max_pow[i]) % MOD;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << numgame(n) << endl;
    return 0;
}