//Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.  
//header files
#include<stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);

int buf[BUFSIZE]; //buf array
int bufp = 0;     //array index

int main(void)
{
    int c;
    c = EOF;
    ungetch('c');
    ungetch(c);
    ungetch('a');
    ungetch('b');
    while((c=getch())!=EOF)
   {
        putchar(c);//print  character until EOF
   }
   putchar(c);//print eof character
   return 0;
}

int getch(void)
{
    if(bufp >=0)//buffer array has some characters
    {
      //printf("%d\n",bufp);
      return buf[--bufp];//return last character in buf array and decrement the index 
    }
    else//buffer array has no element , get input from stdin
    {
    return getchar();
    }
}

void ungetch(int c)//store the character in buffer
{
    if(bufp >=BUFSIZE)//greater than bufsize
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++]=c;
       //printf("%d\n",bufp);
    }
}
