#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;


int main()
{
   double L, x1, v1, x2, v2, t1 = 0, t2 = 0, t3 = 0, t4 = 0;

   cin >> L >> x1 >> v1 >> x2 >> v2;

   double time = -1;

   if (x1 == x2 || x1 == L - x2 || x2 == L - x1)
   {
      time = 0;
   }
   else if (v1 != 0 && v2 != 0)
   {
      if (v1 != v2)
      {
         if (x1 > x2)
         {
            if (v1 > 0 && v2 > 0)
            {
               if ((x2 + v2 * ((L - x1 - x2) / (v1 + v2))) == (L - (x1 + v1 * ((L - x1 - x2) / (v1 + v2)))))
               {
                  t1 = (2*L - x1 - x2) / (v1 + v2);
                  if (t1 > 0);
                     time = t1;
               }
               if ((x1 + v1*((2*L - x2 - x1) / (v1 + v2)) - L) == (L - x2 - v2 * ((2*L - x2 - x1) / (v1 + v2))))
               {
                  t2 = (2*L - x1 - x2) / (v1 + v2);
                  if (t2 > 0)
                     time = t2;
               }
               t3 = (x2 - x1) / (v1 - v2);
               if (time > 0 && t3 > 0)
                  time = min (time, t3);
               if (time < 0)
                  time = abs(t3);
               t1 = 0, t2 = 0, t3 = 0;
            }
            if (v1 > 0 && v2 < 0 || v1 < 0 && v2 > 0)
            {
               if (v1 + v2 != 0)
                  if ((L - x1 - v1*((L - x1 - x2) / (v1 + v2))) == x2 + v2 *((L - x1 - x2) / (v1 + v2)))
                  {
                     t1 = (L - x1 - x2) / (v1 + v2);
                     if (t1 > 0);
                        time = t1;
                  }
               if (v1 + v2 == 0)
               {
                  if (L - x1 != x2)
                  {
                     t4 = (L+x2 - x1) / (v1 - v2);
                  }
                  else time = 0;
               }
               t3 = (x2 - x1) / (v1 - v2);
               if (time > 0 && t3 > 0)
                  time = min (time, t3);
               if (time < 0)
                  time = abs(t3);
               if (t4 > 0)
                  time = t4;
               t1 = 0, t2 = 0, t3 = 0, t4 = 0;
            }
            if (v1 < 0 && v2 < 0)
            {
               if ((L - x1 - v1 * (L - x1 - x2) / (v1 + v2)) == x2 + v2 * ((L - x1 - x2) / (v1 + v2)))
               {
                  t1 = (L - x1 - x2) / (v1 + v2);
                  if (t1 > 0);
                     time = t1;
               }
               if ((x1 + v1 * ((-x1-x2) / (v1 + v2))) == -(x2 + (v2 * ((-x1-x2) / (v1 + v2)))))
               {
                  t2 = (-x1-x2) / (v1 + v2);
                  if (t2 > 0);
                     time = t2;
               }
               t3 = (x2 - x1) / (v1 - v2);
               if (time > 0 && t3 > 0)
                  time = min (time, t3);
               if (time < 0)
                  time = abs(t3);
               t1 = 0, t2 = 0, t3 = 0;
            }
         }
         else
         {
            if (v1 > 0 && v2 > 0)
            {
               if ((L - x1 - x2) / (v1 + v2) > 0 && (L - x2 + v2*(L - x1 - x2) / (v1 + v2)) == (x1 + v1 * ((L - x1 - x2) / (v1 + v2))))
               {
                  t1 = (2*L - x1 - x2) / (v1 + v2);
                  if (t1 > 0);
                     time = t1;
               }
               if ((x2 + v2 * ((2*L - x2 - x1) / (v1 + v2)) - L) == (L - x1 + v1 * ((2*L - x2 - x1) / (v1 + v2))))
               {
                  t2 = (2*L - x1 - x2) / (v1 + v2);
                  if (t2 > 0);
                     time = t2;
               }
               t3 = (x2 - x1) / (v1 - v2);
               if (time > 0 && t3 > 0)
                  time = min (time, t3);  
               if (time < 0)
                  time = abs(t3);
               t1 = 0, t2 = 0, t3 = 0;
            }
            if (v1 > 0 && v2 < 0 || v1 < 0 && v2 > 0)
            {
               
               if ((L - x2 - v2 * ((L - x1 - x2) / (v1 + v2))) == (x1 + v1 * ((L - x1 - x2) / (v1 + v2))))
               {
                  t1 = (L - x1 - x2) / (v1 + v2);
                  if (t1 > 0);
                     time = t1;
               }
               t3 = (x2 - x1) / (v1 - v2);
               if (x1 + x1*t3 != x2 + x2*t3)
                  t3 = (x1 + L - x2) / (v2 - v1);
               if (time > 0 && t3 > 0)
                  time = min (time, t3);
               if (time < 0)
                  time = abs(t3);
               t1 = 0, t2 = 0, t3 = 0;
            }
            if (v1 < 0 && v2 < 0)
            {
               if ((L - x2 - v2 * ((L - x1 - x2) / (v1 + v2))) == (x1 + v1 * ((L - x1 - x2) / (v1 + v2))))
               {
                  t1 = (L - x1 - x2) / (v1 + v2);
                  if (t1 > 0);
                     time = t1;
               }
               if ((-(x1 + v1*((-x1-x2) / (v2 + v1)))) == (x2 + v2 * ((-x1-x2) / (v2 + v1))))
               {
                  t2 = (-x1-x2) / (v2 + v1);
                  if (t2 > 0);
                     time = t2;
               }
               t3 = (x2 - x1) / (v1 - v2);
               if (time > 0 && t3 > 0)
                  time = min (time, t3);
               if (time < 0)
                  time = abs(t3);
               t1 = 0, t2 = 0, t3 = 0;
            }
         }
      }
      else
      {
         if (v1 > 0)
         {
            if ((L - x1 - x2) / (2*v1) > 0)
               time = min(abs(L - abs(x2 + x1) / 2) / v1, (L - x1 - x2) / (2*v1));
            else
               time = abs(L - abs(x2 + x1) / 2) / v1;
         }
         else
         {
            if ((L - x1 - x2) / (2*v1) > 0)
               time = min((abs(x2 + x1)/2 )/ abs(v1), (L - x1 - x2) / (2*v1));
            else
               time = (abs(x2 + x1)/2 )/ abs(v1);
         }
      }
   }
   else if (v1 == 0 && v2 == 0)
   {
      if (x1 == x2)
      {
         time = 0;
      }
   }
   else
   {
      if (x1 == x2)
      {
         time = 0;
      }
      else
      {
         if (v1 == 0)
         {
            if (x2 > x1)
            {
               if (v2 > 0)
               {
                  time = (L - x2 + x1) / v2;
               }   
               else
               {
                  time = (x1 - x2) / v2;
               }
               t1 = (L - x1 - x2) / v2;
               if (t1 > 0 && t1 < time)time = t1;
               t1 = 0;
            }
            else
            {
               if (v2 > 0)
               {
                  time = (x1 - x2) / v2;
               }
               else
               {
                  time = (x2 + L - x1) / v2;
               }
               t1 = (L - x1 - x2) / v2;
               if (t1 > 0 && t1 < time)time = t1;
               t1 = 0;
            }
         }
         else
         {
            if (x1 > x2)
            {
               if (v1 > 0)
               {
                  time = (L - x1 + x2) / v1;
               }
               else
               {
                  time = (x1 - x2) / v1;
               }
            }
            else
            {
               if (v1 > 0)
               {
                  time = (x2 - x1) / v1;
               }
               else
               {
                  time = (x1 + L - x2) / v1;
               }
            }
            t1 = (L - x1 - x2) / v1;
            if (t1 > 0 && t1 < time)
               time = t1; 
         }
      }
   }

   if (time < 0 || time > L)
   {
      time = -1;
   }

   if (time == -1) {
      cout << "NO" << endl;
   }
   else
   {
      cout << "YES" << endl;
      cout << fixed << setprecision(10) << time << endl;
   }

   return 0;
}
