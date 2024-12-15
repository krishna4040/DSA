# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

// bool ispair(int *arr , int n , int x)
// {

//     int i = 0 , j = n-1;
//     while (i < j)
//     {
//         if (arr[i] + arr[j] == x)
//             return 1;
//         else if (arr[i] + arr[j] > x)
//             j--;
//         else
//             i++;
//     }
//     return 0;
// }

bool ispair(int *arr, int n , int x)
{
    unordered_set<int> s(arr,arr+n);

    for (int i = 0; i < n; i++)
        if (s.find(x-arr[i]) != s.end() && arr[i] != x - arr[i])
            return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout << ispair(arr,10,14);
    return 0;
}