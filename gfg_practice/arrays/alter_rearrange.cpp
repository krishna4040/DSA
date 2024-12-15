/*Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively 
i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.*/

//* Approach: two pointer approach

# include <iostream>
using namespace std;

void rearrange(int arr[] , int n)
{
    int *temp = new int[n];

    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    
    int low = 0 , high = n-1;
    while (low < n)
    {
        arr[low] = temp[high];
        low+=2;
        high--;
    }
    high = 1;
    low = 0;
    while (high < n)
    {
        arr[high] = temp[low];
        high += 2;
        low++;
    }
    delete[] temp;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,30,40,50,60,70,80,90,100,110};
    rearrange(arr,11);
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
