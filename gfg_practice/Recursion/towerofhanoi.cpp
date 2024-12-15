# include <iostream>
using namespace std;

int toh(int n , int from , int to , int aux)
{
    static int count = 0;
    if (n == 0)
    {
        return count;
    }
    count++;
    toh(n-1 , 1 , 2 , 3);
    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
    toh(n-1 , 2 , 3 , 1);
}

int main(int argc, char const *argv[])
{
    cout << toh(3,1,3,2);
    return 0;
}