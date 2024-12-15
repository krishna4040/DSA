# include <iostream>
using namespace std;

void insertionSort(int arr[] , int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}