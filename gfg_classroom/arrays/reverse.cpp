# include <iostream>
using namespace std;

void reverse(int arr[] , int n)
{
    int low = 0 , high = n-1;
    while (low < high)
    {
        int temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;
        low++;
        high--;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5};
    reverse(arr,5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}
