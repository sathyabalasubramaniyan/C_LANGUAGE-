// Functions like isupper can be implemented to save space or to save time. Explore both possibilities.

#include <stdio.h>
int isupper(int c);

int main(void) 
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c =='\n')
        {
            continue;//continue with other character
        }
        if (isupper(c) == 1)
        {
            printf("UPPERCASE\n");
        }
        else
        {
        printf("LOWERCASE\n");
        }
    }
    return 0;
}

int isupper(int c) //it checks each character  as upper case
{
    return (c >= 'A' && c <= 'Z')?1:0;
}

