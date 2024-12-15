# include <iostream>
using namespace std;

int maxsubarraySum(int arr[] , int n)
{
    int res = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        res = max(sum , res);
        for (int j = i+1; j < n; j++)
        {
            sum += arr[j];
            res = max(sum , res);
        }
    }
    return res;
}

// Kadane algorithm
int mxsubarraySum(int arr[] , int n)
{
    int res = arr[0];
    int prev_maxSum = arr[0];
    for (int i = 1; i < n; i++)
    {
        prev_maxSum = max(prev_maxSum + arr[i] , arr[i]);
        res = max(res , prev_maxSum);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2,3,-8,7,-1,2,3};
    cout << mxsubarraySum(arr,7);
    return 0;
}
