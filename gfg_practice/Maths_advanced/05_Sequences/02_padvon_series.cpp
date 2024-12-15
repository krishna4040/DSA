# include "bits/stdc++.h"
using namespace std;

// Padvon series: Spiral of equilateral triangles with side lengths which follow the Padovan sequence. 
int padvon(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return 1;
    return padvon(n-2)+padvon(n-3);
}

void printPadvon(int n)
{
    int t1 = 1;
    int t2 = 1;
    int t3 = 1;
    while (n)
    {
        int nextterm = t2+t3;
        cout << t1 << " ";
        t1 = t2;
        t2 = t3;
        t3 = nextterm;
        n--;
    }
}

int main(int argc, char const *argv[])
{
    printPadvon(10);
    return 0;
}