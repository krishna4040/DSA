# include <iostream>
using namespace std;

bool ispoint(int arr[] , int n)
{
    int rs = 0;
    for (int i = 0; i < n; i++)
        rs += arr[i];
    
    int ls = 0;
    for (int i = 0; i < n; i++)
    {
        rs -= arr[i];
        if (ls == rs)
            return 1;
        ls += arr[i];
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,2,-2};
    cout << ispoint(arr,3);
    return 0;
}
