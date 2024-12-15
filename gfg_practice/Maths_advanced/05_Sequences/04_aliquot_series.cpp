# include "bits/stdc++.h"
using namespace std;

// Aliquot sequence : starts with itself, remaining terms of the sequence are sum of proper divisors of immediate previous term
// proper divisors: All divisors except that number
// dec seq
// ends with 0 , perfect number , set of amicable / sociable number
//* Edge cases
//? Perfect numbers: Number with repeating Aliquote seq of length 1 EX: 6
//? Amicable number: Number with repeating Aliquote seq of length 2 EX: 220
//? Sociable number: Number with repeating Aliquote seq of length 3

int getDivisorSum(int n)
{
    int sum = 0;
    for (int i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n/i)
                sum += n/i;
        }
    }
    return sum-n;
}
vector<int> Aliquot(int n)
{
    vector<int> series;
    series.push_back(n);
    while (n)
    {
        n = getDivisorSum(n);
        vector<int> :: iterator i = series.begin() , j = series.end();
        if (binary_search(i,j,n))
            break;
        series.push_back(n);
    }
    return series;
}

int main(int argc, char const *argv[])
{
    vector<int> v = Aliquot(6);
    for (auto &&i : v)
        cout << i << " ";
    return 0;
}