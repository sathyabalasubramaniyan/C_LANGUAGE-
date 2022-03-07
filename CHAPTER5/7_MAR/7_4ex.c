// Write a private version of scanf analogous to minprintf from the previous 
 
#include <stdarg.h>
#include <stdio.h>

void minscanf(char *fmt, ...)
{
    va_list ap;//argument pointer
    char *p,*s;
    int *val;
    va_start(ap, fmt);//initiales ap to named argument fmt
    for (p = fmt;*p;p++)//loop over format
    {
        if (*p != '%'||*p=='/')
        { 
         getchar();//to ignore the '/'
         continue;
        }
        switch (*++p)//conversion specifier
        {
            case 'd'://integer 
                val = va_arg(ap, int *);
                scanf("%d", val);
         //       printf("\nval:%d\n",*val);
                break;
           case 's'://string
                s=va_arg(ap,char *);
                scanf("%s",s);
                break;
            default:
                printf("Illegal format");
                break;
        }
    }
   va_end(ap);
}

int main(void)
{
    int day, month, year;
    char *arr;
    minscanf("%s",arr);
    printf("%s",arr);
    minscanf("%d/%d/%d", &day, &month, &year);
    printf("%d %d %d\n", day, month, year);

    return 0;
}
