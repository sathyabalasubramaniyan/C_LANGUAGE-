//Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.
 
//header files
#include<stdio.h>
#include<string.h>

//GLOBAL variables
int bufp=0;//index pf buffer array
char  temp; //buffer array

//function declaration
int getch(void); 
void ungetch(int c);


int main(void)
{
    int c='a';
    ungetch(c);//it copies the character  into buffer
    while((c=getch()) != EOF)// get each character and assigned it to c and print it
    {
        putchar(c);
    }
    return 0;
}

void ungetch(int c)//store the character in buffer
{
    if(bufp!=0)//greater than one character
    {
        printf("error: more than one character\n");
    }
    else
    {
        temp=c;
        bufp=1;
    }
}

int getch(void)
{
    if(bufp==1)//it has  one character
   {
      bufp=0;
      return temp;//return one  character from ungetch and set  the bufp as 0 
    }
    else// get input from stdin
    {
    return getchar();
    }
}

