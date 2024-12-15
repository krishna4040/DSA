# include <iostream>
# include <vector>
using namespace std;

// Another implementation

void rotateLeft(int arr[], int n , int d) {
    d = d % n; // to handle cases where d > n
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++) {
        arr[i-d] = arr[i];
    }
    for (int i = n-d; i < n; i++) {
        arr[i] = temp[i-n+d];
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
