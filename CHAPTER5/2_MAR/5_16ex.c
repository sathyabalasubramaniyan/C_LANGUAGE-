//Add the -d (directory order) option, which makes comparisons only on letters, numbers and blanks. Make sure it works in conjunction with -f.
//heaader files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//macros
#define MAXLINES 5000 //maximum no of lines it hold in pointer array
#define ALLOCSIZE 10000 //maximum size for storing characters
#define MAXLEN 1000 // maximum  characters in each line

//global variables
static char allocbuf[ALLOCSIZE];//char array of size 10000
static char *allocp = allocbuf;//char pointer it points to starting address of char array
char *lineptr[MAXLINES]; // array of pointers 
int numeric = 0,rev=0,alpha=0,direc=0; 

//function prototype
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines,int r);
int getline1(char *, int);
char *alloc(int);
void quicksort(void *lineptr[], int start, int end,int (*comp) (void *, void *));
int numcmp(const char *, const char *);  //const char * as argument  to pass same datatype of argument  as stmcmp
int casecmp(const char *s1,const char *s2);


int main(int argc, char *argv[])
{
    int nlines; // number of input lines 
    while(--argc)
    {
    char *p,ch;
    p=(*(++argv)); //passing the string into p 
    //printf("%s",p);
    ch=p[1];//second character
    switch(ch)
    {
    case 'n'://numeric sort
     numeric=1;
     break;
    case 'r'://reverse
     rev=1;
     break;
    case 'f'://ignore case
     alpha=1;
     break;
    case 'd': //direc
      direc=1;
     break;
    } 
   } 
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
    {     if(numeric==1)//SORT NUMERICALLY
          {
          quicksort((void**) lineptr, 0, nlines-1,(int (*)(void*, void *)) (numcmp));
          }
          else if(direc==1||alpha==1)// IGNORE CASE , SORT IN ORDER OR BOTH
          {
          quicksort((void**) lineptr, 0, nlines-1,(int (*)(void*, void *)) (casecmp));
          }
          else//DEFAULT
          {
          quicksort((void**) lineptr, 0, nlines-1,(int (*)(void*, void *)) (strcmp)); //the fouth parameter is a function pointer that returns int and takes two arguments as void pointer
          }
           writelines(lineptr, nlines,rev);                             
         return 0;
    }
   else 
   {
        printf("input too big to sort\n");
        return 1;
    }
}
 
void quicksort(void *v[], int start, int end , int (*comp)(void *, void *))//comp is a function pointer that points to numeric or stmcmp function that accepts two argument as void pointer and returns int
{
    int c, last;
    void swap(void *v[], int, int);
    if (start>= end)
    {
     return;
    }
    swap (v, start,(start+end)/2);//swap middle element with first element
    last=start;
    for (c = start+1; c <= end; c++)
    {
       if ((*comp)(v[c], v[start]) < 0)//compare pivot element v[start] with v[c]   // numeric =1 comp points to numcmp function  or alpha =1 it points to casecmp default it points to strcmp
     {
      swap(v, ++last, c); //if v[c] is less than pivot element  swap v[c] with element pointed by incremented last
     }
    }
    swap(v,start, last);//swap pivot element with element pointed by last
    quicksort(v, start, last-1, comp);//left half 
    quicksort(v, last+1, end, comp);// right half
}

//swap: interchage tow elements 
void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}



/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
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
    if(r==1)
    {
    printf("\n sorted in descending order\n");

     for(i=nlines-1;i>=0;i--)
     { 
      
      printf("%s\n",lineptr[i]);
     }
    }
    else
   {
    printf("\n sorted in ascending order\n");

    for (i = 0; i < nlines; i++)//print each line
    {
     printf("%s\n", lineptr[i]);
    }
   }
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

// numcmp: sort numerical strings
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;
   //  printf("numcmp");
    v1 = atof(s1);
    v2 = atof(s2);
//    printf("\n%s :%f , %s :%f",s1,v1,s2,v2);
    if (v1 < v2)
     return -1;
    else if (v1 > v2)
     return 1;
    else
     return 0;
}
int casecmp(const char *s1,const char *s2)
{
  if(direc==1) //only compare number, character ,space
  {  
    if(alpha==1) //ignore case
    {
     while(*s1!='\0' && *s2!='\0') //till string terminator
     {
     for(;(isalnum(*s1)||*s1==' ') &&(isalnum(*s2)||*s2==' ');s1++,s2++) //check for number , character , space
     { 
     if(tolower(*s1) != tolower(*s2))//convert both into lowercase and compare  them 
     {
      return tolower(*s1)-tolower(*s2);
     }
     if( *s1== '\0'||*s2=='\0')
       return 0;
//     }
     }//for loop ends
     if(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1))//ignore remaining character
     {				++s1;     } 
     if(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2))//ignore remaining character
     {				++s2;    }
    }//while end
   }//if end
   else if(alpha==0) //case is considered 
   {
     while(*s1!='\0' && *s2!='\0')//till string terminator
     {
     for(;(isalnum(*s1)||*s1==' ') &&(isalnum(*s2)||*s2==' ');s1++,s2++)//check for number ,character,space
     { 
     if((*s1) !=(*s2))// compare value
     {
      return (*s1)-(*s2);
     }
     if( *s1== '\0')
       return 0;
     }
     if(!isdigit(*s1) && !isalpha(*s1) && !isspace(*s1))//ignore  remaining character
     {                          ++s1;     } 
     if(!isdigit(*s2) && !isalpha(*s2) && !isspace(*s2))
     { 
      ++s2;
      }
     }//while loop end
  }//else if end
  }//if end
  else//if alpha==0
  {
   for(;tolower(*s1) == tolower(*s2);s1++,s2++)//convert uppercase into lowercase , compare them 
       if(*s1 == '\0')
       {            
        return 0;
       }
  
      return tolower(*s1) - tolower(*s2);
  }
}
