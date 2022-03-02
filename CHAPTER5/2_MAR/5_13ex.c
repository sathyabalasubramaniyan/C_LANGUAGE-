//header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//macros
#define MAXLINES 5000 //maximum no of lines it hold in pointer array
#define ALLOCSIZE 10000 //maximum size for storing characters
#define MAXLEN 1000 // maximum  characters in each line
#define  TAIL 10 //Define default value of tail to print 10 last lines

//global variables
static char allocbuf[ALLOCSIZE];//char array of size 10000
static char *allocp = allocbuf;//char pointer it points to starting address of char array
char *lineptr[MAXLINES]; // array of pointers 


//function prototype
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines,int r);
int getline1(char *, int);
char *alloc(int);

int main(int argc, char *argv[])
{
    int nlines; // number of input lines 
    int r;    
     if( argc == 2 &&(*(++argv))[0]=='-') //if  -n
     {
        r = atoi(argv[0]+1);
     }
     else // default  10
     {
        r = TAIL;
     }
     if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
     {     
           writelines(lineptr, nlines,r); //print r last lines in lineptr
     }
     else 
     {
        printf("input too big to sort\n");
     }
     return 0;
}

int  readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline1(line, MAXLEN)) > 1)// length of the line is greater than 1 ( for enter key , it is 1)
    {
     if (nlines >= maxlines || (p = alloc(len)) == NULL)//if space is not available
     {
         return -1;
     } 
    else 
    {
         line[len-1] = '\0'; //replace new line with string terminator
         strcpy(p, line);  //copy the content of char array into  char pointer
  //       printf("\np : %s",p); 
         lineptr[nlines++] = p; //make  pointer of array points to char pointer 
     }
     }
    return nlines; //total no of pointers used in pointer array
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines,int r)
{
    int i;
    printf("\n last %d lines of the input \n",r);
    for (i = nlines-r; i < nlines; i++)//print nth  line  till end
    {
     printf("%s\n", lineptr[i]);
    }
    return ;
}


int getline1(char *s, int lim) //to get each line 
{
    int i,c;
   for(i = 0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
   {
     s[i] = c;
   // printf("another");
   }
   if (c == '\n') {
     s[i] = c;
     ++i;
    }
    s[i] = '\0';
   // printf("%d",i);
    return i;//length of each line
}

char *alloc(int n) /* return starting addres of  n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) // if  n characters are available  
    { 
        allocp += n;  // it increments to n characters 
        return allocp - n; // return the starting address of n characters
    } else
     return 0;
}
