/*Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array*/
# include "bits/stdc++.h"
using namespace std;

void threeWayPartition(vector<int>& arr,int a, int b)
{
    int n = arr.size();
    int i = -1 , j = n+1;

    while (true)
    {
        do{
            i++;
        } while (arr[i] < a);
        do{
            j--;
        } while (arr[j] > a);
        if (i >= j)
            break;
        swap(arr[i],arr[j]);
    }

    int k = j , p = n+1;
    while (true)
    {
        do{
            k++;
        } while (arr[k] != a && arr[k] < b);
        do{
            p--;
        } while (arr[p] == a || arr[p] > b);
        if (k >= p)
            break;
        swap(arr[k],arr[p]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,3,4};
    threeWayPartition(v,1,2);
    for (auto &&i : v)
        cout << i << " ";

    return 0;
}