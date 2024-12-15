# include <iostream>
using namespace std;

// Naive approach
void freq(int arr[] , int n)
{
    int count = 1;
    for (int i = 0; i < n; i+=count)
    {
        count = 1;
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
            if (arr[i] < arr[j])
                break;
        }
        cout << "count of " << arr[i] << " is " << count << endl; 
    }
}

// Efficient approach
void frq(int arr[] , int n)
{
    int frq = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i-1])
            frq++;
        else
        {
            cout << "Frq of " << arr[i-1] << " is " << frq << endl;
            frq = 1;
        }
    }
    cout << "frq of " << arr[n-1] << " is " << frq << endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10};
    frq(arr,14);
    return 0;
}