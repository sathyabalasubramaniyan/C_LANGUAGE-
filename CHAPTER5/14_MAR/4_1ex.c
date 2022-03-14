//4.1 Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.
#include<stdio.h>
int strrindex(char s[],char t[]);

int main(void)
{
char line[] ="abcabcde";
char pattern[] ="abcf";
int res;
res=strrindex(line, pattern);
printf("%d\n", res);
return 0;
}

int strrindex(char s[],char t[])
{
int i,j,k, result;
int count=0,m=0,n;
result = -1;
count=1;
for(i=0;s[i]!='\0';i++);//to find length of first string
for(j=0;t[j]!='\0';j++);//to find length of second string
for(k=(i-j);k>=0;k--)
{
 n=k;
 if(s[k]==t[m])//compare  s with first character of m 
 {
 while(s[++k]==t[++m])//increment both
 {
 count++;//keep increment count until both characters are equal
 }
 //printf("%d %d\n",k,count);
 if(count==j)//if count == length of t , all characters are matched
 {
 result=(k-j);//to find starting position of  t
 return result;
 }
 }
 m=0;//initial position of t
 k=n;//to set the initial position of k
}
return result;
}
