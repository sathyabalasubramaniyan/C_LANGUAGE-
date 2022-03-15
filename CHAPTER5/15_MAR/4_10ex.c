//An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach.

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
int j=0;
double op2,op1,a,d,va;
char s[MAX];
getlinec(s); // reads a string
while(s[j]!='\0') //until string terminator
{
switch(s[j])
{
case '+':
push(pop()+pop()); //push the result
break;
case '*':
push(pop()*pop());//push the result
break;
case '-':
op2 = pop();
push(pop()-op2); //subtract 2nd no from first
break;
case '/':
op2 = pop();
if(op2 != 0.0)
push(pop()/op2); //push the result
else
printf("zero divisor\n");
break;
case '%':
op2 = pop();
if(op2 != 0.0)
push(fmod(pop(),op2)); // values are in double datatype
else
printf("zero modolus\n");
break;
case '\t':
break;
case ' ':
break;
default :
if(isdigit(s[j])) //push the positive number
{
j= number( s, j);
break;
}
else
{
printf("error");
break;
}
}
j++;//increment next character
// printf(&quot;\nval=%c&quot;,s[j]);
}
// printf(&quot;\nressp:%d,%f&quot;,sp,val[0]);
if(sp==1)//result
{
printf("result=%f",val[--sp]);
}
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
t[i]=c;

}
if(t[i]=='\n') //if it is a newline
{
t[i]='\n';
t[i]='\0';
}
}
