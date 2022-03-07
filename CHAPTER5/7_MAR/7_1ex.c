//Write a program that converts uppercase to lower or lowercase or upper depending on the mame it is invoked with as found in argv[1]

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
  int c;
  if(argc==2) 
  {
  if(!strcmp(*(++argv),"lower"))//compare the name of argv as lower
  {
   printf("lower case to upper case\n");
   while((c=getchar())!=EOF)
   {
   putchar(toupper(c));//convert lower to upper
   }
  }
  else if(!strcmp(*argv,"upper"))//compare the name of argv as upper
  {
  printf("upper case to lower case\n");
  while((c=getchar())!=EOF)
  {
  putchar(tolower(c));//conver upper to lower
  }
  }
  else
  {
   printf("unknown command");
  }
  }
  else
  {
   printf("error");//doesnot have the  proper command 
  } 
 return 0;
}
