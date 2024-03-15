#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;

   double r1 = hypot(y1, x1);
   double r2 = hypot(y2, x2);

   double L1 = r1 + r2;
   double h = atan2(y1, x1);
   double k = atan2(y2, x2);
   double _min = min(abs(h - k), abs(k - h));

   double r = abs(r1 - r2);
   double r_mX = (r1 + r2 - r) / 2;
   double L2 = r_mX * _min + r;

   cout << fixed << setprecision(12) << min(L1, L2) << endl;

   return 0;
}
