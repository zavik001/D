#include <bits/stdc++.h>
using namespace std;

string convertTo12HourFormat(string time24) 
{
   int hour = stoi(time24.substr(0, 2));
   int minute = stoi(time24.substr(3, 2));
   
   string period = (hour < 12) ? "AM" : "PM";
   
   if (hour == 0)
   {
      hour = 12;
   } else if (hour > 12) 
   {
      hour -= 12;
   }
   
   string hour_str = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
   
   return hour_str + ":" + (minute < 10 ? "0" : "") + to_string(minute) + " " + period;
}


int main ()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 0; 
   cin >> t;
   
   vector<string> inputTimes(t); 

   for (int i = 0; i < t; ++i)
      cin >> inputTimes[i];


   for (const string& time24 : inputTimes) {
      string time12 = convertTo12HourFormat(time24);
      cout << time12 << endl;
   }

   return 0;
}
