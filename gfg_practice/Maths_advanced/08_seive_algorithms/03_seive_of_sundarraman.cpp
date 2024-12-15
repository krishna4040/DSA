#include <bits/stdc++.h>
using namespace std;

// TC: O(NlogN)
vector<int> SieveOfSundaram(int n)
{
	// In general Sieve of Sundaram, produces primes smaller
	// than (2*x + 2) for a number given number x.
	// Since we want primes smaller than n, we reduce n to half
	int nNew = (n-1)/2;
    vector<bool> marked(nNew+1,false);
    // mark all composit as true
    // composite form: i+j+2ij
	for (int i=1; i<=nNew; i++)
		for (int j=i; (i + j + 2*i*j) <= nNew; j++)
			marked[i + j + 2*i*j] = true;
    
    // all unarked elements are ans but with sligth modification
    // all elements as 2x+1
    vector<int> prime;
    for (int i = 0; i < marked.size(); i++)
        if (!marked[i])
            prime.push_back(2*i+1);
    return prime;
}


int main(void)
{
	vector<int> v = SieveOfSundaram(20);
    for (auto &&i : v)
        cout << i << " ";
	return 0;
}
