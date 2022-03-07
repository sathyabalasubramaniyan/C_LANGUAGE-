// Exercise 7-2 Write a program that will print arbitrary input in a sensible way. As a  minimum, it should print non-graphic characters in octal or hexadecimal  according to local custom, and break long text lines.
 

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define HEXA 16
#define OCTAL 8
#define MAX 100

int main(int argc, char *argv[])
{
    int c;
    int pos;
    char *format;

    if(argc==2 && (*(++argv))[0] == '-')
    {
            c =( *argv)[1];
            printf("%c",c);
            switch (c)//store the format according to the format
            {
                case 'o': 
                    format = "\\\\%03o";//maximum octal value is three digit
                    break;
                case 'x': 
                    format = "\\\\%02x";//maximum hexa value is two digit
                    break;
                default:
                    printf("unknown command option");
                    break;
            }
    }

    pos=0;
    while ((c = getchar()) != EOF)
    {
        if(iscntrl(c)||c==' ')//it checks the character is control character or not ( non-graphic character)
        {
          if(!strcmp("\\\\%03o",format))
          {
          //  printf("octal conversion\n");
            if(pos+OCTAL<=MAX)
            {
            pos=pos+OCTAL;
            }
            else//pos=8
            {
            pos=OCTAL;
            }
            printf(format,c);//print c as octal value
            if(c=='\n')//newline
            {
              putchar(c);
            }
             printf("\n");//break long texts
          }
          else if(!strcmp("\\\\%02x",format))
          {
          //  printf("hexadecimal conversion\n");
            if(pos+HEXA<=MAX)//less than max,pos increments by HEXA
            {
            pos=pos+HEXA;
            }
            else//pos=16;
            {
            pos=HEXA;
            }
            printf(format,c);//print c as hexa value
            if(c=='\n') //if it is a newline
            {
              putchar(c);
            }
             printf("\n");//break long texts
          }

        }
        else//graphic characters
        {
        if(pos+1<MAX)//less than max 
        {
          pos=pos+1;
        }
        else//newline and initialise pos as initial position
        {
        printf("\n");
        pos=1;
        }
        printf("%c",c);//print as such
        }
   }


return 0;
}
