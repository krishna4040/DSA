/*Given an integer array representing the heights of N buildings, the task is to delete N-2 buildings such that the water that can be trapped
between the remaining two building is maximum.
Note: The total water trapped between two buildings is gap between them (number of buildings removed) multiplied by height of the smaller
building.*/
# include "bits/stdc++.h"
using namespace std;

int getwater(int arr[] , int n)
{
    int res = 0;
    for (int gap = n-2; gap >= 1; gap--)
        for (int i = 0; i < n-gap-1; i++)
            res = max(res , gap*arr[i]);

    return res;
}

int main(int argc, char const *argv[])
{
    int height[] = {2,1,3,4,6,5};
    cout << getwater(height , 6);
    return 0;
}