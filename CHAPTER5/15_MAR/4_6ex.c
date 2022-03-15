//header files
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//macros
#define MAX 100
#define MAXVAL 100

//function declaration
void push(double);
double pop(void);
void getlinec(char s[]);
int number(char s[],int k);

//global variables
double val[MAXVAL];//stack
int sp = 0;//stack index
int type=0;//for negative numbers
int count=0;//for negative numbers

int main(void)
{
int j=0,op3,f,e;
int arr[26];
double op2,op1,a,d,va,u;
char s[MAX];
getlinec(s); // reads a string
while(s[j]!='\0') //until string terminator
{
//printf("\n%s",s);
switch(s[j])
{
case '+':
f=pop();
e=pop();
printf("per");
push(arr[f]+arr[e]); //push the result
break;//push the result
case '*'://multiplication
f=pop();
e=pop();
push(arr[f]*arr[e]); //push the result
break;//push the result
case '-'://subtraction
f=pop();
e=pop();
push(arr[e]-arr[f]); //push the result //subtract 2nd no from first
break;
case '/'://division
f=pop();
e=pop();
if(f != 0)
push(f/e); //push the result
else
printf("error:zero divisor");
break;
case '\t':
break;
case ' ':
case '\n':
break;
case '=':
   op3=pop();
   op1=pop();
   arr[op3]=op1;
   push(op3);
  break;
default :
if(isdigit(s[j])) //push the positive number
{
j= number( s, j);
break;
}
else if(isupper(s[j])) // if it is a uppercase letter
{
//printf("val%c\n",s[j]);
u=s[j]-'A'; //convert character into double 
push(u); //push the double value into stack
}
else
{
if(s[j]=='\0')
printf("error%csat\n",s[j]);
break;
}
}
j++;//increment next character
}
printf("result=%f",val[--sp]);

return 0;
}

int number(char s[],int k)
{
double a,va;
int sign=1;
if(type==1) //if it is a negative number
{
sign=-1;
k++;
type=0;
}
while(isdigit(s[k]) && s[k]!='\t') //checks if it is a number
{
a=s[k]-'0'; //converting char to double;
va=va*10+a;
k++;
}
if(!isdigit(s[k])) //other than number
{
k--;
}
push((va*sign)); //push the number
va=0.0;
return k;
}

void push(double f)
{
if(sp < MAXVAL)
{
//less than stack size
val[sp++]=f;
printf("%f is pushed \n",f);
count++; //increment the count
}
else
printf("OVERFLOW");
}

double pop(void)
{
double b;
if(sp>0)
{
b=val[--sp];
count--;
return b;
}
else
{
printf("UNDERFLOW");
return 0.0;
}
}

void getlinec(char t[])
{
 int i,c;
 for(i=0;i<MAX-1&& (c=getchar())!=EOF&&c!='\n';++i)
 {
// printf("%c\n",c);
 t[i]=c;
 }
 if(t[i]=='\n') //if it is a newline
 {
 t[i]='\0';
// t[i]='\0';
 }
 t[i]='\0';
// printf("%s",t);
 }
