/*Print numbers from 1 to N without the help of loops.*/
# include <iostream>
using namespace std;

void print(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    print(n-1);
    cout << n << " ";
}

int main(int argc, char const *argv[])
{
    print(10);
    return 0;
}
