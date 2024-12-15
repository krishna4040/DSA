# include <iostream>
using namespace std;

void toh(int n , char a , char b , char c)
{
    if (n == 0)
    {
        return;
    }
    toh(n-1 , a , c , b);
    cout << "move disk " << n << " from " << a << " to " << c << endl;
    toh(n-1 , b , a , c);
    cout << "move disk " << n << " from " << a << " to " << c << endl;
}

int main(int argc, char const *argv[])
{
    toh(4,'A','B','C');
    return 0;
}