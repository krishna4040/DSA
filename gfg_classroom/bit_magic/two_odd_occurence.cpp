# include <iostream>
using namespace std;

void findodd(int arr[] , int n)
{
    int x = arr[0];
    for (int i = 1; i < n; i++)
        x ^= arr[i];
    int k = x & (~(x-1));
    int res1 = 0 , res2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & k)
            res1 ^= arr[i];
        else
            res2 ^= arr[i];
    }
    cout << res1 << " " << res2;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,3,2,3,3,1};
    findodd(arr,6);
    return 0;
}
