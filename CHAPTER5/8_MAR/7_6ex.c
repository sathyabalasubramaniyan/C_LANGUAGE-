//Write a program to compare two files, printing the first line where they differ.
#include<stdio.h>
#include<string.h>

#define MAX 50

void filecmp(FILE *, FILE *); 

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;//file pointers
    if (argc == 1)
    {
        printf("no arguments");
        return 1;//unsucessful termination
    }
    else if(argc==3)//two files to compare
    {
            if ((fp1 = fopen(*++argv, "r")) == NULL)//initialise the first file pointer to first file 
            {  
                printf(" can't open %s\n", *argv);//error
                return 1;
            }
            if ((fp2 = fopen(*++argv, "r")) == NULL)//initialise the decond file pointer to second file
             {
                printf("can't open %s\n", *argv);//error
                return 1;
             }
            filecmp(fp1, fp2);//calling function
            fclose(fp1);//close the first file
            fclose(fp2);//close the second file
    }
    return 0;
}

void filecmp(FILE *fp1, FILE *fp2)
{
    char c1[MAX],c2[MAX];//to store the line 
    while (1) 
    {
      if(fgets(c1,MAX,fp1) == NULL)//store the value into c1
      {
         return ;// if no value in file
      }
     if(fgets(c2,MAX,fp2) == NULL)//store the value into c2
     {
         return ;//if no value to store
     }      
        //compares both lines
        if(strcmp(c1,c2))
         {
            printf("%s",c1); //if not equal print those lines  and return 
            printf("%s",c2);
           break;
        }
    }
}
