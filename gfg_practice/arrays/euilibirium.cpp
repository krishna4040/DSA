# include <iostream>
using namespace std;

int equilibirium(int arr[] , int n)
{
    int right = 0;
    for (int i = 0; i < n; i++)
        right += arr[i];
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        right -= arr[i];
        if (left == right)
            return i+1;
        left += arr[i];
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
