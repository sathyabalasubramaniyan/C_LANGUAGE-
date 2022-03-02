

#include<ctype.h>
#include<stdio.h>

//macro
#define MAX 100

//function declaration
 
void getlineC(char *s,int n);
int atoi(char *s);
void itoae(int n, char*s);
void  reverse(char* s);
int strindex(char *s,char *p);
void getop(char *s);


int main(void)
{
 
  char arr[MAX],a2[MAX],a3[MAX]="1234",a4[MAX];
  int x=123;
  char s[MAX]="saathya",p[MAX]="at";
  getlineC(arr,MAX); // getline function
  printf("\narr:%s",arr);
  printf("\natoif of a3:%d",atoi(a3));//atoi function
  itoae(x,a2);//itoa function
  printf("\nitoa of a2:%s",a2);
  printf("\n a2==%s",a2);
  reverse(a3); //reverse function 
  printf("\nreverse of a3 :%s",a3);
  printf("\nindex of second array in first array : %d\n",strindex(s,p));//strindex
  getop(a4);    //getop 
  printf("getop of a4:%s",a4);
  return 0;
}
void  getop(char *s)
{
  int ch,i=0;
printf(" type for getop input\n");
  ch=getchar();
  if(!isdigit(ch)) // if it is not a number
  {
   *(s+i)='\0'; //string terminator
  }
  while(isdigit(ch)) //if it is a number
  {

   *(s+i)=ch;// assign
   i++;
   ch=getchar();// next character
   if(ch=='.') // if it is a decimal part
   {
     ch=getchar();// fractional part
   }
   }
   *(s+i)='\0';//string terminator
}

int strindex(char *s, char *t)
{
  int i,j=0;
  for(i=0;*(s+i)!='\0';i++)
 {
  if(*(s+i)==*(t+j)) //check the first character of t is matched with any character of s
  {

  // printf("i=%s %s %d",s,t,i);
    for(int k=i;*(s+k)==*(t+j);k++)//if first matches, then compare all characters in t 
    {
      j++;
    }
    //printf("\ni=%d",i);
  }
  if(*(t+j)=='\0')//if all characters in c
    { return i;}
    j=0;// if not initialize j as 0
  }
   
 return -1;
}
     
void reverse(char *s)
{
  char* p=s;
  int count=0;
int l=0,h;
char temp;
 while(*p)//calculating the length of p
{
 p++;
 count++;
}
h=count-1;// assigning end index to h;
//printf("%d",count);
while(l<h) //swapping
{
 temp=*(s+l);
*(s+l)=*(s+h);
 *(s+h)=temp;
  l++;
 h--;
  //printf("\np:%s",s);
}
}
 

void  getlineC(char *s, int n)
{
  int c,i;
  printf("type the input for getline");
  for(i=0;i<n-1&&(c=getchar())!=EOF&&c!='\n';++i ) //getting each character and comparing that character 
  {
  *(s+i)=c;
  }
  if(c=='\n') // if it is a enter key 
  {
  *(s+i)=c;
  i++;
  }
  *(s+i)='\0'; // string terminator
  return ;
 }

int atoi(char* s)
{
  int n,sign=1;
  while(*s==' ') //if any spaces, ignores it
  {
   ++s;
  }
  if(*s=='+'||*s=='-')//check for sign
  {
  sign=(*s=='+')?1:-1;
  s++;
  }
//  printf("\nsign:%d",sign);
  for(n=0;isdigit(*s);s++) //assigning each character into n 
  {
   n=(n*10)+(*s-'0');
 // printf("%d",n);
  } 
  return sign*n;
}

void  itoae(int n, char*s)
{
  int temp,count=0;
  temp=n; //copy the n into temp 
  while(temp!=0) // calculate the length of n
  {
  temp=temp/10;
  count++;
  }
  //printf("\ncount:%d",count);
  *(s+count)='\0'; //initialize string terminator 
  while(n!=0) 
  { 
  count--;
  *(s+count)=n%10+'0'; ///converting int into char
  n=n/10;
  }
  //printf("\n s:%s",s);  
  return  ;
}
 

