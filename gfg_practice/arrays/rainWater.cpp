# include <iostream>
using namespace std;

int getwater(int arr[] , int n)
{
    int lmax[n];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
        lmax[i] = max(arr[i],lmax[i-1]);

    int rmax[n];
    rmax[n-1] = arr[n-1];
    for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(arr[i],rmax[i+1]);

    int total = 0;
    for (int i = 0; i < n; i++)
        total += min(lmax[i] , rmax[i]) - arr[i];

    return total;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
