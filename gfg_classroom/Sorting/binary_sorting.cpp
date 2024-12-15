# include "bits/stdc++.h"
using namespace std;

void hoare(bool arr[] , int n)
{
    int i = -1 , j = n;
    while (true)
    {
        do{
            i++;
        } while (arr[i] == 0);
        do{
            j--;
        } while (arr[j] == 1);
        if (i >= j)
            return;
        swap(arr[i],arr[j]);
    }
}

int main(int argc, char const *argv[])
{
    bool arr[] = {0,1,1,1,0,0,0,1,0,0};
    hoare(arr,10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    return 0;
}