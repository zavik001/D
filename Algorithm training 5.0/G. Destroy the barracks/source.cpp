#include <iostream>
using namespace std;

int  hh(int x, int y, int round) 
{
  int f = 0;

  for ( ; x > 0 && y > 0 ;) 
  {
    f++;
    y -= x;
    x -= y;
  }
  if (x>0) 
    return round + f;
  return -1;
}

int main() 
{
  int x, y, p, mv = 0, kol = 0, round = 0;
  cin >> x >> y >> p;

  for ( ; true; ) 
  {
    round++; 

    if (kol > 0) 
    {
      if (kol >= x and y >= x) 
      {
        cout << "-1";
        return 0;
      }

      if (kol >= x) 
      {
        if (y > 0) 
        {
          kol -= (x - y);
          x -= kol;
          y = 0;
        }
        else 
        {
          kol -= x;
          x -= kol;
        }
      }
      else 
      {
        if (kol < x and y < x  ) 
        {
          int h = hh(x, kol + y, round - 1 );

          if (h > 0 and h < mv) 
            mv = h;

          if (mv == 0 and h > 0) 
            mv = h;
        }
          y -= (x - kol);
          kol = 0;
      }
    }
    else 
      y -= x;

    if (y > 0) 
      kol += p;
    
    if (kol <= 0 and y <= 0)
    {
      if (mv > 0 and mv < round) 
        cout << mv;
      
      else 
        cout<<round;
      
      return 0;
    }
    
    if (x <= 0) 
    {
      cout << "-1";
      return 0;
    }
  }

  return 0;
}
