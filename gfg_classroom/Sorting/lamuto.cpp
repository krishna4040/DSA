# include <iostream>
using namespace std;

int lamuto(int arr[] , int l , int h , int p)
{
    swap(arr[p] , arr[h]);
    int pivot = arr[p];
    int i = l-1;
    for (int j = 0; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    lamuto(arr,0,5,1);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    return 0;
}
