//Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file.

#include <stdio.h>
#include <string.h>

#define LINESPERPAGE 2

void page(FILE *, FILE *);

int main(int argc, char *argv[]) {
    FILE *fp;
    char *prog = argv[0];
    int linecount = 0;

    if (argc == 1) //no argument
    {
        fprintf(stderr, "No files given");
        page(stdin, stdout);
    }
    else
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                return 1;
            }
            else
            {
                fprintf(stdout, "\nFile:%s\n", *argv);//print the filename
                page(fp, stdout);//print the content in each page
                fclose(fp);//close the file
            }
        }
    }

    if (ferror(stdout)) //if errors
    {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        return 1;
    }
    return 0;
}
void page(FILE *fp1, FILE *fp2)
{
    int c;
    int line=0;
    int pg=1;

    while ((c = getc(fp1)) != EOF)//get each character from fp1
    {
        putc(c,fp2);//print that character into fp2 stream
        if (c == '\n')//if newline
        {
            line = line + 1;//increment line
            if (line == LINESPERPAGE)//if line is equal to no of lines  required per page
            {
                fprintf(stdout, "\nPage no: %d\n", pg);//print the page no
                pg = pg + 1;//increment the pg
                line = 0;//start with new page
            }
        }

    }
}
