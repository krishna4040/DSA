/*Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,
Take the set of integers
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
First, delete every second number, we get following reduced set.
1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….
Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.*/

// Extension to josephus problem

# include <iostream>
using namespace std;

bool islucky(int n)
{
    static int counter = 2;
    if (counter > 2)
        return 1;
    if (n % counter == 0)
        return 0;
    n -= n/counter; // new position of same number after deleting elements
    counter++;
    islucky(n);
}

int main(int argc, char const *argv[])
{
    cout << islucky(10);
    return 0;
}
