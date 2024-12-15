# include <iostream>
# include <vector>
using namespace std;

void moveZeroes(int arr[] , int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i] , arr[count]);
            count++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {8,5,0,10,0,20};
    moveZeroes(arr,6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
