# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

int distinctElements(int *arr , int n)
{
    unordered_set<int> s(arr,arr+n);
    return s.size();
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,3,2,2,1,5};
    cout << distinctElements(arr,8);
    return 0;
}