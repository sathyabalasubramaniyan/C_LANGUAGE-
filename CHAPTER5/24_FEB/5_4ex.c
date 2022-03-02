#include<stdio.h>

//macros
#define MAX 100

//function declaration
void strendc(char *s,char *t);

int main(void)
{
  char a1[MAX]="SATHYyA";
  char a2[MAX]="YA";
  printf("\nfirst array :%s",a1);
  printf("\nsecond array :%s",a2);
  strendc(a1,a2);  //Passing address of both arrays
  return 0;
}

void strendc(char *s,char *t)
{
  int count=1;
  while(*s!='\0') //looping until s points to string terminator
  {
   s++;
  } 
  while(*t!='\0')// looping until t points to string terminator
  {
   t++;
   count++; //to get length of t
  }
 while(*s--==*t--&&(count>0))  // comparing the last character of both aaray if it is equal , then decrementing  the array 
 {
   // printf("\ns:%s,t:%s",s,t);
    count--; //decrementing the length of t;
   //printf("%d",count);
  }
   if(*s!=*t&& count!=0) //if s and t are not same and count is not equal to 0
   {
  
    printf("\nSECOND STRING IS NOT AT THE END OF FIRST STRING");
    return ;
    }
   else if(count==0)//the length of t =0 , then all the characters in t are at end of s;
   {
   printf("\nSECOND STRING IS AT THE END OF THE FIRST STRING");
   }
   return ; 
}
