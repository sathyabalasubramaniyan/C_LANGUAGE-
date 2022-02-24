//Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s 


#include<stdio.h>
 //macro
#define MAX 100

//function declarations
void strcatc(char *s, char *t);

int main(void)
{
   char ar1[MAX]="Sathya "; //first array
   char ar2[MAX]="Balasubramaniyan"; //second array
   printf("\nfirst array:%s",ar1);
   printf("\nsecond array:%s",ar2);
   strcatc(ar1,ar2);//passing address of two arrays
   printf("\nconcatenated array:%s",ar1);//printing first array
   return 0;
}
 
//function definition
 void strcatc(char *s,char *t) // accessing the address by pointers
{
   int i=0;
  
   while(*(s+i)!='\0')
   {
    i++;
   }//  incrementing i until s points to  string terminator
   for(int j=0;*(t+j)!='\0';j++) // looping over t pointer 
   {
     *(s+i)=*(t+j); // assigning the  character which points by t to the end of s ;
      i++;  //incrementing the i;
   }
   *(s+i)='\0';
}  
    
