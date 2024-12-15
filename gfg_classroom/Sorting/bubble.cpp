# include <iostream>
using namespace std;

void bubbleSort(int arr[] , int n)
{
    for (int i = 0; i < n-1; i++)
    {
        bool swapped = 0;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j+1] < arr[j])
            {
                swap(arr[j],arr[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {6,6,6,8,1,1,2,3};
    bubbleSort(arr,8);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    return 0;
}