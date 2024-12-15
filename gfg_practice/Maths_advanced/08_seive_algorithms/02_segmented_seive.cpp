# include "bits/stdc++.h"
using namespace std;
/*Problems with normal seive:
* not good for large n
* non cache friendly */
//* Segmented seive uses simple seive as a sub routine 

vector<int> seive(int n)
{
    vector<bool> mark(n+1,true);
    for (int i = 2; i*i <= n; i++)
        if (mark[i])
            for (int j = i*i; j <= n; j+=i)
                mark[j] = false;
    vector<int> prime;
    for (int i = 2; i < mark.size(); i++)
        if (mark[i])
            prime.push_back(i);
    return prime;
}

void segmentedSeive(int n)
{
    int root = floor(sqrt(n))+1;
    vector<int> prime = seive(root);

    // dividing range [0....n-1] in segments
    int low = root;
    int high = 2*root;

    while (low < n)
    {
        if (high >= n)
            high = n;
        vector<bool> isprime(n+1,true);
        for (int i = 0; i < prime.size(); i++)
        {
            int lolim = floor(low/prime[i]) * prime[i];
            if (lolim < low)
                lolim += prime[i];
        }
        
    }
    

}



int main(int argc, char const *argv[])
{
    
    return 0;
}