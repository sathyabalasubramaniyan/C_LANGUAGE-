// Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.

#include<stdio.h>
#include<ctype.h>

#define MAX 100

void getlineC(char str[],int max);
double myatof(char s[]);

int main(void)
{
char str[MAX];
double num;
getlineC(str,MAX);//get the input line
num=myatof(str);//string into double
printf("%f",num);
return 0;
}

double myatof(char s[])
{
double val,pow;
int sign,i,esign,exp;
int power(int base,int exp);
for(i=0;isspace(s[i]);i++);//ignore white spaces

sign=(s[i]=='-')?-1:1;
if(s[i]=='+'|| s[i] =='-')//if first character is  - or + increment the i
{
i++;
}
for(val=0.0;isdigit(s[i]);i++)//whole no
{
val = 10.0*val+(s[i]-'0');
}
if(s[i]=='.')//decimal point
{
i++;
}
for(pow=1.0;isdigit(s[i]);i++)//decimal part
{
val = 10.0 * val +(s[i]-'0');
pow *= 10.0;
}
if(s[i]=='e' || s[i] =='E')//exponent 
{
i++;
}
if(s[i]=='+'||s[i]=='-')//exponent sign
{
esign=s[i];
i++;
}
for(exp=0;isdigit(s[i]);i++)//exponent part
{
exp=10.0 * exp + (s[i]-'0');
}
if( esign =='-')
{
return sign * (val / pow) / power(10,exp);
}
else
{
return sign * (val / pow) * power(10,exp);
}

}

void getlineC(char s[],int lim)
{
int i,c;
for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
{
s[i] = c;
}
if(c=='\n')
{
s[i++]=c;
}
s[i]='\0';
}

int power(int base,int exp)
{
int power;
power=1;
while(exp)
{
power *=base;
exp--;
}
return power;
}

