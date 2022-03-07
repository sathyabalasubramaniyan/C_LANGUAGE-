//Revise minprintf to handle more of the other facilities of printf. 

#include<stdio.h>
#include<stdarg.h>

//function declaration
void minprintf(char *fmt,...);

int main(void)
{
 int a=10;
 float b=1.4;
 char c[7]="sathya"; 
 char d='z';
 minprintf("%d %f",a,b);
 minprintf("%s",c);
 minprintf("%c",d);
 minprintf("%o %X",a,a);
}

void minprintf(char *fmt,...)
{
 
 char *p;
 int val;
 float f;
 char *s;
 char c;
 va_list ap;//argument pointer
 va_start(ap,fmt);//it points to named argument fmt
 for(p=fmt;*p;p++) //loop over fmt
 {
   if(*p!='%')//characters to print
   {
    putchar(*p);
    continue;
   }
   switch(*++p)//conversion specifier
   {
    case 'd'://integer
       val=va_arg(ap,int);//it will increment ap into int bytes get the value 
       printf("%d",val);
       break;
    case 'f':
         f=va_arg(ap,double);//float is defaultly promoted to double in function call
         printf("%f",f);
         break;
    case 's':
          s=va_arg(ap,char *);
          printf("%s",s);
          break;
    case 'c':
           c =va_arg(ap,int);//char is promoted to int during function call  , to get the value of char  the return type should be int
           putchar(c);
           break;
   case 'o':
   case 'O':
           val = va_arg(ap,int);
           printf("%o", val);
           break;
   case 'x':
   case 'X':
           val =va_arg(ap,int);
           printf("%x", val);
           break;
    default :
       putchar(*p);
       break;
   } 
}
printf("\n");
va_end(ap);
}
