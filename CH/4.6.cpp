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
void getline(char t[]);
int number(char s[],int k);

//global variables
double val[MAXVAL];//stack
int sp = 0;//stack index  


int main(void)
{
    int j=0,in;
    int f,e;
    double op1,op2,d,u;
    char s[MAX];
	double arr[26];
    getline(s); // reads a string 
    while(s[j]!='\0') //until string terminator
    {
        switch(s[j])
        {
                case '+': //addition
                	    f=pop();
                	    e=pop();
                	    push(arr[f]+arr[e]); //push the result
                        break;
                case '*'://multiplication
                         f=pop();
                	    e=pop();
                	    push(arr[f]*arr[e]); //push the result
                        break;//push the result
                        break;
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
                            printf("error:zero divisor\n");
                        break;
                case '\t': //tab
                         break;
                case ' ': //whitespaces
                         break;
                case '=': //assign     
                	   op2=pop(); //pop the variable  example     op2=2.000     op2=3.0000
					   in=int(op2); //convert double into integer  in=2         in=3
					  // printf("\nin:%d",in);
					   arr[in]=pop();//pop the number and assign into the variable arr[2]=10   arr[3]=20
					 //  printf("\nARR%f",arr[in]);
                	   break;
                default :
                	if(isdigit(s[j]))  //if it is a number
                	{
                	  j= number(s,j);//push the number
                        break;
                    }
                    else if(isupper(s[j])) // if it is a uppercase letter
                    {
                       u=s[j]-'A';     //convert character into double    u='B'-'A'=1
					   push(u);	       //push the double value into stack 
					}
                    else
                    {
                        printf("error: unknown command %c\n",s[j]);
                        break;
                    }
        }
        j++;//increment next character

    }
    d=pop(); //result 
    printf("\nresult=%f",d);
    return 0;
}
int number(char s[],int k)
{
	double a,va=0;
	while(isdigit(s[k])&&s[k]!='\t') //checks if it is a number
    {
                	//    printf("\%c",s[j]);	
                	     a=s[k]-'0'; //converting  char to double;
                	     va=va*10+a;
                	    //   printf("\nvl:\%f",va);
                	     k++;
    }
                     	
 //   printf("\nval:\%f",va);
	if(!isdigit(s[k])) //other than number
	{
		k--;
	}
    push((va));	//push the number
    
	va=0.0;
// printf("\nvalUE:\%f",va);
//	printf("\nk=%d",k);
    return k;
}

void push(double f)
{
	printf("\npush :%f",f);
	if(sp < MAXVAL) 
	{//less than stack size
        val[sp++]=f;
    }
    else
        printf("error:stack full, cant push %g\n",f);
}
double pop(void)
{ 
    double b;
    if(sp>0) 
    {
        b=val[--sp];
        printf("\npop :%f",b);
        return b;
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
void getline(char t[])
{
    int i,c;
    for(i=0;i<MAX-1 && (c=getchar())!=EOF&&c!='\n';++i)
    {
        t[i]=c;
    }
  if(t[i]=='\n') //if it is a newline
  {
  	t[i]='\n';
    t[i]='\0';    	
  }
   printf("char array:%s",t);
}

// 10 B = 20 C = BC+
// B=10 C=20 B+C= 30;
