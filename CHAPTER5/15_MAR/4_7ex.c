//Write a routine ungets(s) that will push back an entire string onto the input. Should ungets(s) know about buf and bufp or  should it handle it to ungetch()
 
//header files
#include<stdio.h>
#include<string.h>

//macros
#define BUFSIZE 100
#define MAXLINE 100

//GLOBAL variables
int bufp=0;//index pf buffer array
int buf[BUFSIZE]; //buffer array

//function declaration
int getch(void); 
void ungetch(int c);
void ungets(char s[]);
int getlineC(char line[],int maxline);


int main(void)
{
    char line[MAXLINE];//CHAR ARRAY FOR INPUT
    int c;
    getlineC(line,MAXLINE);//get the string into line
    ungets(line);//it copies the string into buffer
    while((c=getch()) != EOF)//to get back the string call getch() , get each character and assigned it to c and print it
    {
        putchar(c);
    }
    return 0;
}

int getlineC(char s[],int maxline)
{
    int i,c;
    for(i=0;i<maxline-1 && (c=getchar())!=EOF && c!='\n';++i)
    {   
     s[i]=c;
    }
    if(c=='\n')
     { 
      s[i++]=c;
     }
    s[i]='\0';
}

void ungets(char s[])
{
    int i;
    i = strlen(s);//length of string
    while(i>0)
    {
        ungetch(s[--i]);//it stores the string reversely
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
    }
}

int getch(void)
{
    if(bufp > 0)//buffer array has some characters
    {
      return buf[bufp--];//return last character in buf array and decrement the index 
    }
    else//buffer array has no element , get input from stdin
    {
    return getchar();
    }
}
