# include <iostream>
using namespace std;

// Naive approach
int maxDifference(int arr[] , int n)
{
    int mdiff = INT32_MIN;
    for (int i = n-1; i >= 0; i--)
        for (int j = i-1; j >= 0; j--)
            mdiff = max(arr[i]-arr[j] , mdiff);
    return mdiff;
}

// Efficient method
int mDiff(int arr[] , int n)
{
    int res = arr[1] - arr[0];
    int minval = arr[0];
    for (int i = 0; i < n; i++)
    {
        res = max(res,arr[i]-minval);
        minval = min(minval , arr[i]);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2,3,10,6,4,8,1};
    cout << maxDifference(arr,7);
    return 0;
}