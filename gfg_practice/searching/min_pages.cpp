# include <iostream>
# include <cmath>
using namespace std;

bool isfeasible(int arr[] , int n , int k , int ans)
{
    int m = 1 , sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > ans)
        {
            m++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return (m <= k);
}

int minpages(int arr[] , int n , int k)
{
    int arr_sum = 0 , mx = -1;
    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
        mx = max(mx , arr[i]);
    }
    int l = mx , h = arr_sum , res = -1;
    while (l <= h)
    {
        int m = (l+h)/2;
        if (isfeasible(arr,n,k,m))
        {
            res = m;
            h = m-1;
        }
        else
            l = m+1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,10,30,40 ,50,100,20};
    cout << minpages(arr,8,3);
    return 0;
}
