# include "bits/stdc++.h"
using namespace std;

// DNF
void sort012(int arr[] , int n)
{
    int l = 0 , h = n-1 , m = 0;
    while (m <= h)
    {
        if (arr[m] == 0)
        {
            swap(arr[l] , arr[m]);
            l++;
            m++;
        }
        else if (arr[m] == 1)
            m++;
        else
        {
            swap(arr[m],arr[h]);
            h--;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2,2,2,1,1,1,0,0,0,2,1,1,2,0};
    sort012(arr,14);
    for (int i = 0; i < 14; i++)
        cout << arr[i] << " ";
    
    return 0;
}