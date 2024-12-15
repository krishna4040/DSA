# include <iostream>
using namespace std;

// Efficient approach
int normalkadane(int arr[] , int n)
{
    int res = arr[0] , maxending = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxending = max(arr[i] , maxending+arr[i]);
        res = max(res , maxending);
    }
    return res;
}

int circularkadane(int arr[] , int n)
{
    int max_normal = normalkadane(arr,n);
    if (max_normal < 0)
        return max_normal;

    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + normalkadane(arr,n);
    return max(max_normal , max_circular);
}

int main(int argc, char const *argv[])
{
    int arr[] = {-5,1,-2,3,-1,2,-2};
    cout << circularkadane(arr,7);
    return 0;
}