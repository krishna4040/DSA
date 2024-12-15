# include <iostream>
using namespace std;

bool issorted(int arr[] , int n)
{
    bool flag = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i-1] > arr[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,10,20,50};
    cout << issorted(arr,5);
    return 0;
}
