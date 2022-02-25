//Rewrite the routines day_of_year and month_day with pointers instead of indexing.

#include<stdio.h>
static char daytab[2][13]={
   { 0,31,28,31,30,31,30,31,31,30,31,30,31},
   { 0,31,29,31,30,31,30,31,31,30,31,30,31}
  
};
// function declarations
int day_of_year(int year,int month,int day);
void month_day(int year, int yearday, int *pmonth,int *pday);

int main(void)
{
    int date;
    int a,b;
    int year =1988;
    date=day_of_year(year,3,1);
    printf("\ndateof year :%d/%d",date,year);
    month_day(year,date,&a,&b);
    printf("\nmonth:%d,date:%d",a,b);
    return 0;
}

void month_day(int year,int yearday,int *p,int *t)
{
  int i,leap;
  char *r; //character pointer
  if(year<0 || yearday<0) // both inputs are less than zero
  {
    *p=-1;
    *t=-1;
  }
  leap=((year%4==0)&&(year%100!=0))||(year%400==0); //check for leap year
  r=&daytab[leap][0];//assigning the first index of leap row
  for(i=0;yearday>*r;i++)
  {
      yearday=yearday-(*r++);//subracting the yearday with  all days in each month until yearday less than all  days in that month
//     printf("year:%d",yearday); 
  };
  if(i>12 || yearday>*(r+12)) //yearday is out of bound
  {
    *p=-1;
    *t=-1;
  }
  *p=i;//month
  *t=yearday;//remaining day 
  //printf("\npt=%d %d",*p,*t);
}

int day_of_year(int year ,int month,int day)
{
  int i, leap;
  char *p; //character pointer
  if(year<0 || month<0 || month>12 || day<0 ||day>31) //out of range
  {
  return 0;
  }
  leap=((year%4==0) &&(year%100 !=0)) || (year%400==0); //check for leap year
  p=&daytab[leap][0]; //point ot first index of leap row ; 
  if(day>*(p+month)) // day is greater than day of that month 
   {
    return -1;
    }
  for(i=0;i<month;i++)
  {
     day=day+(*p++); //adding days in each month until  specified month
  }
 return day;
}

