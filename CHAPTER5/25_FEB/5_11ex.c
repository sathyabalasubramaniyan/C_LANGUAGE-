//Modify the program entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.

//heaader files


#include<stdio.h>
#include<stdlib.h>

//macros
#define MAXLEN 100
#define TAB 4

//function declaration
void detab(char a[],char t[],int tb);
void entab(char a[],char b[],int tb);
void getlinec(char s[],int len);

int main(int argc,char *argv[])
{
  int i;
  if(argc==2)//tab stop as argument
  {
     i=atoi((*(++argv)));//convert char *pointer into int
  }
  else
  {
   i=TAB;//no argument default  tab
  }
//  printf("\n%d,%d",argc,i);
  char p[MAXLEN],t[MAXLEN],u[MAXLEN];
  getlinec(p,MAXLEN);//getting input
  printf("\nbefore detab :\n%s",p);
  detab(p,t,i); //convert tab into series of blanks
  printf("\nafter detab :\n%s",t);
  entab(t,u,i);//converting  series of blanks into tab
  printf("\nafter entab :\n%s",u);
  return 0;
}

void detab(char a[],char t[],int tb)
{
  int res,i=0,val=1,j=0;
//  printf("\ndetab%s",a);
  while(a[i]!='\0')
  {
//    printf("\n%d",val);
    if(a[i]=='\t') //if it is a tab
    {
     res=tb-((val-1)%tb); // find the remaining pos to fill spaces in tab sequence
     while(res--)
     {
     t[j]=' ';//fill spaces
     j++;
     val++; // increment
  //   printf("d");
     }
     res=0;
     val--;
    }
    else
    {
     t[j]=a[i];// any character other than tab 
     j++;
    // printf("%c",a[i]);
    }
   i++;
   val++;
  }
  t[j]='\0';
 // printf("\ntarrray:%s",t);
}


void entab(char a[],char b[] ,int tb)
{
  //printf("\nentab%s",a);
  int i=0,ns=0,nt=0,val=1,j=0;
  while(a[i]!='\0')
  {
    if(a[i]==' ') //if it is a space
    {
     if(val%tb==0) //if  position is equal to TAB
     {
     nt++; //incrementing nt
     ns=0;
     }
     else
     {
     ns++; //if not  , incrementing ns
     }
    }
    else
    {
     for(;nt!=0;nt--)
     {
      b[j]='\t'; //assiging tab character until the count of nt
      j++;
//      printf("\t");
     }
     for(;ns!=0;ns--) //assigning space character until the count of nb
     {
     b[j]=' ';
      j++;
  //   printf(" ");
     }
     b[j]=a[i]; //assigning other character
     j++;
    // printf("%c",a[i]);
     }
   ++val;
   ++i;
  }
  b[j]='\0';
//  printf("\n%s",b);  
 return ;
}
 
void getlinec(char s[], int l) //getting input lineS
{
 int i=0;
 int c;
 printf("\nenter input\n");
 //c=getchar();
 for(i=0;i<l-1&&(c=getchar())!=EOF&&c!='\n';++i)
 {
  s[i]=c;
 }
 if(c=='\n')
 {
   s[i]=c;
   ++i;
  }
 s[i]='\0';//
// printf("\nget %s",s); 
return ;
}


