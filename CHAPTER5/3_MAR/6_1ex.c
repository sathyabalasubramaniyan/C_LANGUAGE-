	
//Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version.


#include<stdio.h>
#include<ctype.h>
#include<string.h>

//macro
#define MAXLEN 20
#define STRUCTARRAY 10

struct keyword
{
  char key[MAXLEN];
  int  count;
} keytab[STRUCTARRAY]={ {"auto" ,0},{"break",0},{"case",0},{"casw",0},{"while",0}};



//declarations
int getword(char*,int);
int binarysearchC(char *th,struct keyword tab[],int n);//*,struct keyword *ktab[]);
int flag=0;

int main(void)
{
 int n,index;
 char arr[MAXLEN];
 while((n=getword(arr,MAXLEN))>0)//it calls getword untill n =0 (enter key)
 {
  if(flag==1) //for underscore,comment lines, string constants, preprocessor
  {
   flag=0; //initial value
  }
  else //for characters
 {
  printf("\nword : %s length:%d\n",arr,n);
  index=binarysearchC(arr,keytab,STRUCTARRAY);//search the word in keytab and returns index  of the searched wors or if not it returns -1
  if(index>=0) //if it is greater than 0
  {
   keytab[index].count++; //increment the count
  }
  index=0;//initial value
  }
 }
 for(n=0;n<STRUCTARRAY;n++)//for printing occurences of character
 {
    printf("\n%s %d",keytab[n].key ,keytab[n].count);
  }
 return 0;
}

int binarysearchC(char *th,struct keyword tab[],int n)//search the word in order
 {
  int cond;
  int low=0,high=n-1,mid;
  while(low<=high)
  {
   mid=(low+high)/2;
   if((cond=strcmp(th,tab[mid].key))<0)//less than mid
   {
    high=mid-1;
   }
   else if (cond>0)//greater than mid
   {
    low=mid+1;
   }
   else
      return mid;
   }  
   return -1;;
}

int  getword(char *p,int len)
{
  int i=0,ch;
  ch=getchar();//get first character
  while(ch==' ')//ignore spaces
  {
   ch=getchar();
  }

  if(!isalpha(ch))//not alphabetic character
  {
   if(ch=='/'||ch=='#'||ch=='-'||ch=='"')//if it is a comment line, a preprocessor ,string constant,,underscore
   {
   // printf("\ncomment");
    ch=getchar();//get another character
    for(i=0;ch!='\n';i++)//loop untill newline
    {
    // printf("\nfor");
     ch=getchar();
    }
    if(ch=='\n')//if it is a newline
    {
     flag=1; //change the value of flag
     return i;//length of the word
    }
   }
   else
   {
    return 0;//other than remaining character
   }
   
  }
  else//if it is alphabetic character
  {
    for(;ch!='\n'&&isalpha(ch)&& i<len;i++)
    {
         *p=ch; //store the value in char pointer
          p++;
          ch=getchar();
    }
    if(ch=='\n') //if it is a newline
    {
     *p='\0';//string terminator
     return i;
    }
    else
    {
     printf("invalid");
     return 0;
     } 
   }
}
