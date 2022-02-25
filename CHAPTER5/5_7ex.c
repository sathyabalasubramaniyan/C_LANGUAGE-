#include<stdio.h>
#include<string.h>
  
//macros

#define MAXLINES 5000 // maximum no of lines that array of pointers hold 
#define MAXLEN 1000    // maximum character in each line
# define ALLOSIZE 10000 
#define SIZE  10000

//global variable
char * lineptr[MAXLINES];  // array of pointers  : it has 5000 character pointers
static char allocbuf[ALLOSIZE]; // char array 
static char *allocp =allocbuf;  //it points to the last position used by allocbuf 

//function declarations
int readlines(char *lineptr[],int nlines,char* ar);
void writelines (char *lineptr[],int nlines);
void qsort(char *lineptr[],int left,int right);
int getlineC(char *s,int l);
char *alloc(int n);



int main(void)
{
  int nlines; // no of lines in  lineptr (array of pointers)
  char store[SIZE]; // char array  that is used for stoage
  if((nlines=readlines(lineptr,MAXLINES,store))>=0)  //it reads all the input lines upto nlines
  {
   qsort(lineptr ,0,nlines-1); // sort all the lines in lineptr upto nlines
   writelines(lineptr,nlines); // write the sorted lineptr  
   return 0;
  }
  else
  {
    printf("\nerror"); //no nlines
   return 1;
  }
}

void qsort(char *v[], int left,int right)   // quicksort
{
 int i,last;
 void swap(char *v[], int i ,int j);
 if(left>=right)
 {
  return;
 }
 swap(v,left,(right+left)/2); // swap   char array pointed by middle pointer with  char array pointed by first pointer 
 last =left; //make last point to first char array
 for(i=left+1;i<=right;i++) //loop from start to end
 {
  if(strcmp(v[i],v[left])<0)// if v[left] is pivot , if currently pointed char array is less than pivot element , swap   currently pointed char array with  char array pointed by last and increment  last
  {
   swap(v,i,++last);
  }
 }
 swap(v,left,last);//swap pivot pointed char array with last pointed  char array
 qsort(v,left,last-1);// quicksort of left subarray 
 qsort(v,last+1,right);// quicksort of right subarray
} 
void swap (char *v[],int i,int j) //swap the 
{
  char *temp;
  temp=v[i];
  v[i]=v[j];
  v[j]=temp;
}

int readlines(char *lineptr[],int nl,char *ar) //acessing the address of char array by char pointer
{
  int len,nlines; 
  char line[MAXLEN];
  char *endar=ar+SIZE; //assigning the last address of char pointer 
  char *p=ar;        // assiging first address of the char pointer
  nlines=0;
  while((len=getlineC(line,MAXLEN))>1) //getlineC assigns a sentence of length len to line(character array)
  {
  // printf("\nline:%s len:%d",line,len);
   if(nlines>=nl||(p+len>=endar)) //if total no of lines > maxllines  or( current position point by p + no of bytes) it needed is greater than last address of endar  
   {
    return -1;
   }
   else       //total no of lines < maxlines and the needed bytes is availablr
   {
    line[len-1]='\0'; 
    strcpy(p,line); // copy the input character array into char pointer;
    lineptr[nlines++]=p; // assign the  string which is pointed by char pointer  to the  elements of  array of pointers
    p=p+len; // p increments to len 
    }
  }
  return nlines;// no of lines occupied in array of pointer
}
char *alloc(int n) // allocates n bytes
{
  if(ALLOSIZE +allocbuf >= n+allocp) // check  n + current size (allocp) is less than allosize {total size) + starting  of the array 
  {
    allocp +=n;    // allocp increments into n bytes  
    return allocp-n; // it returns the starting address of the allocated bytes
  }
  else // if size not available
  {
    return 0;
  }
}

int getlineC(char *s,int lim)
{
 int c;
 char *p;
 p=s; // assign the starting address to another character pointer
 //printf("welcom");
 while(--lim>0 &&(c=getchar())!=EOF&&(c!='\n'))
 {
//  printf("\n%d",c);
  *s++=c;  // stores the input character until enter key 
  //printf("\neas");
 }
 if(c=='\n') // if it is a enter key
 {
  *s++=c;
 }
 *s='\0';
// printf("\nget:%s",s);
 return (int)(s-p); //length of sentence including string terminator
}

void writelines(char *lineptr[],int nlines)
{
  while (nlines-->0) // total no of lines in array of pointers becomes zero
{
  printf("\noutput :%s",*lineptr++); // print the current value of array of pointer and increments next
}
}
