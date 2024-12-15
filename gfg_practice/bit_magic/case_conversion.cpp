# include <iostream>
using namespace std;

char lowertoupper(char c)
{
/*As we can see if we clear 5th bit of lower case characters, it will be converted into upper case character.
We have to prepare a mask having 5th bit 0 and other 1 (11011111). This mask is bit representation of underscore character (‘_‘).
The character ‘ch’ then AND with mask. 
Example- 
ch = ‘a’ (01100001) 
mask = ‘_ ‘ (11011111) 
ch & mask = ‘A’ (01000001) */
    c &= '_';
    return c;
}

char uppertolower(char c)
{
/*As we can see if we set 5th bit of upper case characters, it will be converted into lower case character. 
We have to prepare a mask having 5th bit 1 and other 0 (00100000). This mask is bit representation of space character (‘ ‘). 
The character ‘ch’ then ORed with mask.
Example- 
ch = ‘A’ (01000001) 
mask = ‘ ‘ (00100000) 
ch | mask = ‘a’ (01100001)*/
    c |= ' ';
    return c;
}

int main(int argc, char const *argv[])
{
    char c = getchar();
    cout << lowertoupper(c);

    char d = getchar();
    cout << uppertolower(d);

    return 0;
}