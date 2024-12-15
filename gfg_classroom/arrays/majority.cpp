# include <iostream>
using namespace std;

int majority(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i+1; j < n; j++)
            if (arr[i] == arr[j])
                count++;
        if (count >= n/2)
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {20,30,40,50,50,50,50};
    cout << majority(arr,7);
    return 0;
}
