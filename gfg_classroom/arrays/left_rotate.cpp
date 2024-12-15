# include <iostream>
using namespace std;

void reverse(int arr[] , int n , int low , int high)
{
    while (low < high)
    {
        swap(arr[low] , arr[high]);
        low++;
        high--;
    }
}

void leftRotate(int arr[] , int n , int d)
{
    // Reverse Algorithm
    reverse(arr,n,0,d-1);
    reverse(arr,n,d,n-1);
    reverse(arr,n,0,n-1);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};
    leftRotate(arr,5,2);
    return 0;
}
