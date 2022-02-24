#include<stdio.h>

//macro
#define MAX 100

//function declaration
void strncopy(char *s,char *t,int n);
void strncatc(char *s,char *t,int n);
int  strncmpc( char *s, char*t,int n);

int main(void)
{
  char a1[MAX]="YYYY";
  char  a2[MAX]="XXX";
  strncopy(a1,a2,3);//copying n characters from a2 into a1;
  printf("\nsecond array:%s",a2);
  strncatc(a1,a2,2);
  printf("\nfirst array :%s",a1);
  printf("\n%d",strncmpc(a1,a2,3));//comparingtwo arrays if 0 botheual , if negative second array is greater , if positive first array is greater
  return 0;
}

void strncopy(char *s,char *t,int n)
{
 while(*t!='\0') //loop over  end of t
 {
 t++;
 }
  while((n--)&&(*t++=*s++)); //copying the character
  *t='\0';
}
 
void strncatc(char *s,char *t,int n)
{
 while(*s!='\0') //loop over end of s
 {
 s++;
 }
 //printf("\nfg:%s",s);
 while((n--)&&(*s++=*t++))
;
}

int  strncmpc(char *s,char* t,int n)
{
for(;(*s==*t)&&n--;s++,t++)
{
 if (n==0) //both are equal in n characters
{
 return 0;
}
}
return (*s-*t);//their differences

} 
