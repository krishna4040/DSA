# include <iostream>
using namespace std;

void asc(int n)
{
    if (n == 0)
        return;
    asc(n-1);
    cout << n << " ";
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
