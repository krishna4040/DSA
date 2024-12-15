# include "bits/stdc++.h"
using namespace std;

void hoare(int arr[] , int n)
{
    int i = -1 , j = n;
    while (true)
    {
        do{
            i++;
        } while (arr[i] != 0);
        do{
            j--;
        } while (arr[j] == 0);
        if (i >= j)
            return;
        swap(arr[i],arr[j]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {8,5,0,10,0,20};
    hoare(arr,6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    
    return 0;
}