# include "bits/stdc++.h"
using namespace std;

/*smith num: A Smith Number is a composite number whose sum of digits is equal to the sum of digits in its prime factorization.
EX: 666 = 2x3x3x37 =>  (6+6+6) == (2+3+3+3+7) == 18*/

// TC: O(n)
bool isprime(int n)
{
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i*i <= n; i+=6)
        if (n % i == 0 || n % (i+2) == 0)
            return 0;
    return 1;
}
vector<int> seive(int n)
{
    vector<bool> v(n+1,true);
    for (int i = 2; i*i <= n; i++)
        if (v[i])
            for (int j = i*i; j <= n; j+=i)
                v[j] = false;
    vector<int> res;
    for (int i = 2; i < v.size(); i++)
        if (v[i])
            res.push_back(i);
    return res;
}
int digitsum(int n)
{
    int sum = 0;
    while (n)
    {
        int lsd = n % 10;
        sum += lsd;
        n /= 10;
    }
    return sum;
}
bool issmith(int n)
{
    if (isprime(n))
        return 0;
    int sum_digit = digitsum(n);
    vector<int> prime = seive(n);
    int sum_prime_factor = 0;
    for (int i = 0; i < prime.size(); i++)
        while (n % prime[i] == 0)
        {
            sum_prime_factor += digitsum(prime[i]);
            n /= prime[i];
        }
    return (sum_digit == sum_prime_factor);
}

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 500; i++)
        if (issmith(i))
            cout << i << " ";
    return 0;
}