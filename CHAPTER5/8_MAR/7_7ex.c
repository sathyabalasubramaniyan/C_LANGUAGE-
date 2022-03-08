//Modify the pattern finding program of Chapter 5 to take its input from a set of named files or, if no files are named as arguments, from the standard input. 
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE 1000

int getlinec(char *line,int max);
int strindex(char *,char*);

char pattern[] = "ould"; /* pattern to search for */

/* find all the matching patterns */

int main(int argc,char *argv[])
{
    char line[MAXLINE];
    FILE *fp;
    int found=0;
    if(argc==1)
    {
     while(1)
     {
      found=getlinec(line,MAXLINE);
      if(found>2)
      {
      if(strindex(line,pattern) >= 0)//if the matching pattern is available
      {
            printf("%s\n",line);//print that line
            found++;
      }
      }
      else
      {
       return 0;
      }
     }
    }
    else if(argc==2)
    {
     if((fp=fopen(*++argv,"r"))==NULL)
     {
     printf("not open");
     }
     else
     {
     // fp=fopen(*argv,"r");
      while(1)
     {
      if(fgets(line,MAXLINE,fp)==NULL)
      {
       return 0;
      }
      else
      {
       if(strindex(line,pattern) >= 0)//if the matching pattern is available
        {
        printf("%s",line);
        }
       }
      }
     }
    }


    return 0;

}



int getlinec(char *s,int lim)
{
    int c;
    char *t=s;

    while(--lim > 0 && (c=getchar())!=EOF && c!='\n')
    {
     *s++=c;
    }
    if(c=='\n')//NEWLINE 
    {
    *s++=c;
    }
    *s='\0';//string terminator
    return s-t;
}


int strindex(char *s,char *t)
{
    char *b=s;
    char *p,*r;//input string

    for(;*s!='\0';s++)
    {
        for(p=s,r=t;*r!='\0' && *p==*r;p++,r++)//check both string are equal 
        {
        }
        if(*r == '\0')//if all characters are in *p 
        {
        return s-b;//b is initial address of the input string s is the address where pattern string starts
        }
    }
    return -1;//not matching
}
