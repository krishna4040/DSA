# include <iostream>
using namespace std;

void selection(int arr[] , int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[i],arr[min_idx]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    selection(arr,5);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}