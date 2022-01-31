//Papozegar pokazuje nam ile czasu zosta³o do Papie¿owej (21:37)
//by zbieracz2000
#include <stdio.h>
#include <locale.h>
#include <time.h>

int main ()
{
  setlocale(LC_CTYPE, "Polish");
  time_t rawtime;
  struct tm * timeinfo;
  time( &rawtime );
  timeinfo = localtime( &rawtime );
  int cur_min, cur_hour;
  int rem_min, rem_hour;
  cur_hour=timeinfo->tm_hour;
  cur_min=timeinfo->tm_min;
  int papiezowa = 0;
  int aft37 = 0;
  if(cur_min <= 36)
    {
        rem_min=37-cur_min;
        aft37=0;
    }
  if(cur_min == 37) rem_min=0;
  if(cur_min >= 38)
    {
        rem_min=97-cur_min;
        aft37=1;
    }
  if(cur_hour <= 20)
    {
        rem_hour=21-cur_hour;
    }
  if(cur_hour == 21)
    {
        if(cur_min <=36)
        {
            rem_hour=0;
        }
        else
        {
            rem_hour=23;
        }
    }
  if(cur_hour == 22)
    {
        rem_hour=23;
    }
  if(cur_hour == 23)
    {
        rem_hour=22;
    }
  if(cur_min == 37)
    {
        if (cur_hour == 21)
        {
             papiezowa=1;
        }
    }
  if (aft37 == 1)
  {
    rem_hour--;
  }
  if (papiezowa == 0)
    {
    printf("Do papie¿owej zosta³o: %02d:%02d \n", rem_hour, rem_min);
    }
    if (papiezowa==1) printf("PAPIE¯OWA!!! \n");
  return 0;
}
