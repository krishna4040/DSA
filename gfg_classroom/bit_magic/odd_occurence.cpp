# include <iostream>
using namespace std;

int findodd(int arr[] , int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {8, 7 , 7 , 8 , 8};
    cout << findodd(arr , 5);
    return 0;
}
