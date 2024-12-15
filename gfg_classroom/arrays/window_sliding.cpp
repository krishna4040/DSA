# include <iostream>
using namespace std;

int maxsubKsum(int arr[] , int n , int k)
{
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
        curr_sum += arr[i];
    int res = curr_sum;
    for (int i = k; i < n; i++)
    {
        curr_sum = curr_sum + arr[i] - arr[i-k];
        res = max(res , curr_sum);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,8,30,-5,20,7};
    cout << maxsubKsum(arr,6,3);
    return 0;
}