#include <iostream>
#include <algorithm>
using namespace std;

int maxDiff(int arr[], int n)
{
    int l = 0 , h = n-1;
    while (l <= h)
    {
        if (arr[h] >= arr[l])
        {
            return h-l;
        }
        else
        {
            return maxDiff(arr,n-1);
        }
    }
}

int main() {
    int arr[] = {1,2,3,4};
    cout << maxDiff(arr,4);
    return 0;
}
