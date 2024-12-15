# include <iostream>
using namespace std;

int kadane(int arr[] , int n)
{
    int res = arr[0];
    int maxending = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxending = max(maxending+arr[i],arr[i]);
        res = max(res,maxending);
    }
    return res;
}

int circular(int arr[] , int n)
{
    int maxnormal = kadane(arr,n);
    int arrr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arrr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int maxcircular = arrr_sum + kadane(arr,n);
    return max(maxcircular,maxnormal);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
