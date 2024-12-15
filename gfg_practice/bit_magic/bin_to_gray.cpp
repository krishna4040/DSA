# include <iostream>
using namespace std;

int grayconverter(int n){return (n ^ (n >> 1));}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << grayconverter(n);
    return 0;
}
