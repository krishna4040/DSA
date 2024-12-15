# include <iostream>
using namespace std;

// Naive approach
int maxevenoddSubarray(int arr[] , int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1; j < n; j++)
        {
            if ((arr[j]%2==0 && arr[j-1]%2!=0) || (arr[j]%2!=0 && arr[j-1]%2==0))
                count++;
            else
                break;
        }
        res = max(res , count);
    }
    return res;
}

// Efficient approach
int mxeveod(int arr[] , int n)
{
    int res = 1 , curr = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i]%2==0 && arr[i-1]%2!=0) || (arr[i]%2!=0 && arr[i-1]%2==0))
        {
            curr++;
            res = max(res , curr);
        }
        else
            curr = 0;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,12,14,7,8};
    cout << maxevenoddSubarray(arr,5);
    return 0;
}
