# include <iostream>
using namespace std;

/*Given a number N. The task is to check whether it is sparse or not.
A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation*/
bool issparse(int n){return !(n & (n >> 1));}

int main(int argc, char const *argv[])
{
    int n = 5;
    cout << issparse(n);
    return 0;
}
