#include <bits/stdc++.h>
using namespace std;

double d;
int n;
vector<double> x, y, v;

bool pointincircle(double x0, double y0, double r0, double xp, double yp) 
{
   return pow(xp - x0, 2) + pow(yp - y0, 2) - pow(r0, 2) < 0.000001;
}

pair<bool, pair<double, double>> checkrect(double xll, double yll, double xru, double yru, double time) 
{
   if (!pointincircle(0, 0, d, xll, yll) &&
      !pointincircle(0, 0, d, xll, yru) &&
      !pointincircle(0, 0, d, xru, yll) &&
      !pointincircle(0, 0, d, xru, yru))
      return make_pair(false, make_pair(0, 0));

   if (xru - xll < 0.000001)
      return make_pair(true, make_pair((xll + xru) / 2, (yll + yru) / 2));

   for (int i = 0; i < n; i++) 
   {
      if (pointincircle(x[i], y[i], v[i] * time, xll, yll) &&
         pointincircle(x[i], y[i], v[i] * time, xll, yru) &&
         pointincircle(x[i], y[i], v[i] * time, xru, yll) &&
         pointincircle(x[i], y[i], v[i] * time, xru, yru))
         return make_pair(false, make_pair(0, 0));
   }

   vector<double> xs = {xll, (xll + xru) / 2, xru};
   vector<double> ys = {yll, (yll + yru) / 2, yru};
   for (int i = 0; i < 2; i++) 
   {
      for (int j = 0; j < 2; j++) 
      {
         pair<bool, pair<double, double>> quarter = checkrect(xs[i], ys[j], xs[i + 1], ys[j + 1], time);
         if (quarter.first)
               return quarter;
      }
   }
   return make_pair(false, make_pair(0, 0));
}

pair<bool, pair<double, double>> check(double time) 
{
   return checkrect(-d, 0, d, d, time);
}

int main() {
   cin >> d >> n;
   x.resize(n);
   y.resize(n);
   v.resize(n);
   for (int i = 0; i < n; i++) 
      cin >> x[i] >> y[i] >> v[i];

   double l = 0;
   double r = 4 * d;
   while (r - l > 0.000001) 
   {
      double m = (l + r) / 2;
      if (check(m).first)
         l = m;
      else
         r = m;
   }

   pair<bool, pair<double, double>> now = check(l);
   cout << l << endl;
   cout << now.second.first << " " << now.second.second << endl;

   return 0;
}
