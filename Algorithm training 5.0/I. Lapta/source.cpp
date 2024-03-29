#include <bits/stdc++.h>
using namespace std;

struct Player { double x, y, v; };

double distance(double x1, double y1, double x2, double y2) { return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); }

double segment(double x1, double y1, double r1, double x2, double y2, double r2) 
{
   double d = distance(x1, y1, x2, y2);

   if (d <= abs(r1 - r2))
      return M_PI * pow(min(r1, r2), 2);  

   double theta1 = 2 * acos((pow(r1, 2) - pow(r2, 2) + pow(d, 2)) / (2 * r1 * d));
   double theta2 = 2 * acos((pow(r2, 2) - pow(r1, 2) + pow(d, 2)) / (2 * r2 * d));

   double area1 = 0.5 * theta1 * pow(r1, 2) - 0.5 * pow(r1, 2) * sin(theta1);
   double area2 = 0.5 * theta2 * pow(r2, 2) - 0.5 * pow(r2, 2) * sin(theta2);

   double intersection_area = area1 + area2;
   return intersection_area;
}

bool check(const vector<Player>& P, pair<double, double>& A, double m, int D) 
{
   double totalArea = 0; 
   for (const auto& player : P) 
   {
      double d = distance(0, 0, player.x,player.x);
      double r = player.v * m;

      if (d < D + r) 
      {
         double s = segment(0, 0, D, player.x, player.x, r);
         totalArea += s;
      }
      cout << totalArea;
   }
   if (totalArea >= 0)
   {
      A = {0, 0};
      return true;
   }
   else
      return false;
}

int main() 
{
   double D;
   int N;
   cin >> D >> N;
   vector<Player> P(N);
   for (int i = 0; i < N; ++i) 
      cin >> P[i].x >> P[i].y >> P[i].v;

   pair<double, double> A{0, 0};
   double m = 1;
   bool t = check(P, A, m, D);
   cout << endl << t ;

   /*
   double l = 0, r = DBL_MAX, t = DBL_MAX;
   pair<double, double> A{0, 0};
   while (l <= r)
   {
      double m = l + (r - l) / 2;
      if (check(P, A, m, D))
      {
         t = m;
         r = m - 0.00001;
      }
      else
         l = m + 0.00001;
   }
   cout << fixed << setprecision(5) << t << endl << A.first << " " << A.second;
   */
   return 0;
}
