# include <iostream>
using namespace std;

int subsetsum(int arr[] , int n , int sum)
{
    if (sum < 0)
        return 0;

    if (n == 0)
        return (sum == 0) ? 1 : 0;

    return subsetsum(arr,n-1,sum) + subsetsum(arr,n-1,sum-arr[n-1]); 
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,5,2,3,6};
    cout << subsetsum(arr , 5 , 8);
    return 0;
}
