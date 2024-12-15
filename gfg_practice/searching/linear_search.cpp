# include <iostream>
using namespace std;

int linersearch(int arr[] , int n , int k)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == k)
            return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}