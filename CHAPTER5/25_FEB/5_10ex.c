//write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument.



//header files

#include<stdio.h>
#include<ctype.h>

//macros

#define MAX 100
#define MAXVAL 100


//function declaration
void push(double  );
double pop(void);
void number(char s[]);

//global variables 
double val[MAXVAL];//stack
int sp=0;//stack index

int main(int argc ,char *argv[])
{
  int i=0,j=0,l=0;
  double op2;
  printf("\nargc : %d",argc);
  for(int i=0;i<argc;++i)
  {
  printf("\nargv : %s:",argv[i]);
  }
  char *s[MAX];
  char *p;
  while(--argc)
  {
  *(s+l)=*(++argv); //copy the array of pointers into another array of pointers without first  index(program name)
  l++;
  }
  *(s+l)='\0'; 
//  printf("\nargc:%d l:%d",argc,l);
 /* for(int i=0;i<l;++i)
  { 
  printf("\ns:%s:",s[i]);
  }*/
  while(*(s+j)) //loop over each pointer
  {
  p=*(s+j); //copy the string which is pointed by  each pointer array into  char pointer
  printf("\n p: %s",p);
   switch(*p)
   {
    case '+':
      // printf("\nadd");
       push(pop()+pop()); //pop the two values, add them  and push the result  
       break;
    case '*':
       push(pop()*pop()); //pop the two vales ,multiply them and push the result
      break;
   case '-':
      op2=pop(); //pop the second  value
      push(pop()-op2); //pop  the first value , subtract it from second value as stack first in last out
      break;
  case  '/':
     op2=pop(); // pop the second value
     if(op2 !=0.0) // pop the first value , divide it by second value
     {
     push(pop()/op2);
     }
     else
     {
     printf("error :zero division");
     }
  case '\t'://tab 
      break;
  case ' '://spaces
     break;
   default :
    //  printf("\ndefault");
      if(isdigit(*p)) //check it is a number
      {
  //     printf("\nis:%s",p);
       number(s[j]); //it converts the string into number and push the number into stack
       break;
      }
      else
      {
       printf("\n error:%s is invalid operator",s[j]);
       break;
      } 
 }
 j++;
 }
if(sp==1)
{
  printf("\nanswer=%f",val[--sp]); //retreive the result
}
else
{
 printf("invalid");
}
return 0;
}


void number(char t[])
{
// printf("\nt[] =%s",t);
 double res,va;
 int k=0;
 while(t[k])
 {
 res=t[k]-'0';// separate each character  , convert into integer
 va=va*10+res;//convert string into number
 k++;
 }
// printf("\n val:%f",va);
 push(va);//push the number
 va=0;
}

void push(double f)
{
// printf("\npush:%f",f);
 if(sp<MAXVAL) //if stack index is less than maxval
 {
 val[sp++]=f; //initialise , increment stack index
 }
 else
 {
 printf("\nerror:stack is full");
 }
}

double pop(void)
{
 double b;
 if(sp>0)
 {
 b=val[--sp]; //assigning last value in stack to b and decrementing stack pointer 
// printf("\npop:%f",b);
 return b;
 }
 else
 {
 printf("\nerror: stack is empty ");
 }
}

