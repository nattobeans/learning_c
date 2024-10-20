#include <stdio.h>

static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
  int i, *p, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  p = day_tab[leap];

  for (; month > 0; month--)
    day += *p++;

  return (day);
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; yearday > day_tab[leap][i]; i++)
    yearday -= day_tab[leap][i];
  *pmonth = i;
  *pday = yearday;
}


int main() {
    int i, year = 1999, month = 11, day = 15, yearday;
    printf("day of year = %d\n", yearday = day_of_year(year, month, day));
    int *pmonth, *pday;
    month_day(year, yearday, pmonth, pday);
    printf("month_day = %d, %d\n", *pmonth, *pday);



    return 0;
}