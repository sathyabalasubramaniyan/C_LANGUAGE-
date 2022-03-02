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
    date=day_of_year(year,3,32);
    printf("\ndateof year :%d/%d",date,year);
    month_day(160,date,&a,&b);
    printf("\nmonth:%d,date:%d",a,b);
    return 0;
}
void month_day(int year,int yearday,int *p,int *t)
{
  int i,leap;
  if(year<0 || yearday<0) // both inputs are less than zero
  {
    *p=-1;
    *t=-1;
  }
  leap=((year%4==0)&&(year%100!=0))||(year%400==0); //check for leap year
  for(i=1;yearday>daytab[leap][i];i++)
  {
     yearday=yearday-daytab[leap][i]; //subracting the yearday with  all days in each month until yearday less than all  days in that month
  };
  if(i>12 || yearday>daytab[leap][12]) //yearday is out of bound
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
  if(year<0 || month<0 || month>12 || day<0 ||day>31) //out of range
  {
  return 0;
  }
  leap=((year%4==0) &&(year%100 !=0)) || (year%400==0); //check for leap year
  if(day>daytab[leap][month]) // day is greater than day of that month 
   {
    return -1;
    }
  for(i=1;i<month;i++)
  {
     day +=daytab[leap][i]; //adding days in each month until  specified month
  }
 return day;
}

