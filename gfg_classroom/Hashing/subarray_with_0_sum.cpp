# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

// bool issumZero(int *arr , int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int sum = arr[i];
//         for (int j = i+1; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum == 0)
//                 return 1;
//         }
//     }
//     return 0;
// }

bool issumZero(int *arr , int n)
{
    int pre_sum = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (s.find(pre_sum) != s.end())
            return 1;
        if (pre_sum == 0)
            return 1;
        s.insert(pre_sum);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,4,13,-3,-10,5};
    cout << issumZero(arr,6);
    return 0;
}