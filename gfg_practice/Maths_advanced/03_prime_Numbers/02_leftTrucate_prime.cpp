# include "bits/stdc++.h"
using namespace std;

// Left-Trucate prime: a prime num not containg 0 and remains prime when the leading digit are successively removed EX: 317
vector<bool> seive(int n)
{
    vector<bool> prime(n+1,true);
    for (int i = 2; i*i <= n; i++)
        if (prime[i])
            for (int j = i*i; j <= n; j+=i)
                prime[j] = false;
    return prime;
}
bool istrucableprime(int n)
{
    string s = to_string(n);
    int d = s.length(); 
    if(binary_search(s.begin(),s.end(),'0')){return 0;}
    vector<bool> prime = seive(n);
    for (int i = d; i > 0; i--)
    {
        int m = pow(10,i); // m = 1000,100,10  n%m = 113,13,3 
        if (prime[n%m] == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    string s = to_string(102);
    cout << s.length();
    return 0;
}