// Extend entab and detab to accept the shorthand entab -m +n to mean tab stops every n columns; starting at column m. choose convenient size for the default behaviour 


#include<stdio.h>
#include<stdlib.h>

//macros
#define MAXLEN 100
#define TAB 8

//function declaration
void detab(char a[],char t[],int tb,int pos);
void entab(char a[],char b[],int tb,int pos);
void getlinec(char s[],int len);

int main(int argc,char *argv[])
{
  int i,start;
  if(argc==3) //input as -5 +3
  {
    //tab stop as argument
     start=atoi(&(*(++argv))[1]); //5 denotes the start of the string to check tap stops
     i=atoi(&(*(++argv))[1]); //3 tapstop
     //convert char *pointer into int
  }
  else if (argc==1)
  {
   start=1;
   i=TAB;//no argument default
  }
  else if(argc==2) //tapstop only
  {
   start =1;
   i=atoi(&(*(++argv))[1]);
  }
 // printf("\n%d,%d,%d",argc,i,start);
  char p[MAXLEN],t[MAXLEN],u[MAXLEN];
  getlinec(p,MAXLEN);//getting input
  printf("\nbefore detab :\n%s",p);
  detab(p,t,i,start); //convert tab into series of blanks
  printf("\nafter detab :\n%s",t);
  entab(t,u,i,start);//converting  series of blanks into tab
  printf("\nafter entab :\n%s",u);
  return 0;
}

void detab(char a[],char t[],int tb,int pos)
{
  int res,i=0,val=1,j=0;
  printf("\nblanks are represented as dots");
  while(a[i]!='\0')
  {
  //  printf("\n%d",val);
    if(a[i]=='\t'&& i>=pos)
    {
     res=tb-((val-1)%tb);
     while(res--)
     {
     t[j]='.';//spaces indicated by dot
     j++;
     val++;
    // printf("sp");
     }
     res=0;
    val--;
    }
    else
    {
     t[j]=a[i];
     j++;
   // printf("%c",a[i]);
    }
   i++;
   val++;
  }
  t[j]='\0';
//  printf("\ntarrray:%s",t);
}


void entab(char a[],char b[] ,int tb,int pos)
{
  //printf("\nentab%s",a);
  int i=0,ns=0,nt=0,val=1,j=0;
  while(a[i]!='\0')
  {
    if(a[i]=='.'&&i>=pos) //dot as space 
    {
     if(val%tb==0)
     {
     nt++;
     ns=0;
     }
     else
     {
     ns++;
     }
    }
    else
    {
     for(;nt!=0;nt--)
     {
      b[j]='\t';
      j++;
      //printf("t");
     }
     for(;ns!=0;ns--)
     {
     b[j]='\b';
      j++;
      //printf("b");
     }
     b[j]=a[i];
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
 
void getlinec(char s[], int l)
{
 int i=0;
 int c;
 printf("enter input\n");
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

