#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Table
{
   int a = 0;
};
Table T[7]{};

void day_of_week(int year, string c)
{
   if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) 
      year = 366;
   else 
      year = 365;
   
   string week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

   int index = 0;
   for(int i = 0; i < 7; ++i) 
   {
      if(week[i] == c) 
      {
         index = i;
         break;
      }
   }
   
   for (int i = 0; i < year; i++)
   {
      T[(index + i) % 7].a++;
   }
}

int mon(string s, int year)
{
   int day[] = {31, 28 + (year == 366), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

   int t = 0;
   for (int i = 0; i < 12; ++i)
   {
      if (s == months[i])
         return t;
      t += day[i];
   }
   
   return -1;
}

int hashT(int day, string c)
{
   string week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
   int index = 0;
   for(int i = 0; i < 7; ++i) 
   {
      if(week[i] == c) 
      {
         index = i;
         break;
      }
   }

   int x = (day - 1) % 7;
   int t = (index + x) % 7;

   return t;
}

void add(int x, string s, string c, int year)
   {
      if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
      {
         year = 366;
         int day = mon(s, year) + x;
         T[hashT(day, c)].a --;
      }
      else
      {
         year = 355;
         int day = mon(s, year) + x;
         T[hashT(day, c)].a --;
      }
   }

int minT() 
{
   int minIndex = 0;
   for (int i = 0; i < 7; ++i) 
   {
      if (T[i].a < T[minIndex].a) 
      {
         minIndex = i;
      }
   }
   return minIndex;
}

int maxT()
{
   int maxIndex = 0;
   for (int i = 0; i < 7; ++i)
   {
      if (T[i].a > T[maxIndex].a) 
      {
            maxIndex = i;
      }
   }
   return maxIndex;
}

int main()
{
   Table T[7]{};
   int N = 0, year = 0;
   string c;
   cin >> N >> year;
   vector <string> S (N + 1);
   vector <int> D (N+1);

   for (int i = 0; i < N; i++)
      cin >> D[i] >> S[i];
   cin >> c;

   day_of_week(year, c);

   for (int i = 0; i < N; i++)
      add(D[i], S[i], c, year);

   string week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
   cout << week[maxT()] << " " << week[minT()];

   return 0;
}
