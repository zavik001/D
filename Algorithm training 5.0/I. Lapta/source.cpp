#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Player 
{
   double x, y, v;
};

int main() {
   double D;
   int N;
   cin >> D >> N;
   vector<Player> players(N);
   for (int i = 0; i < N; ++i) 
   {
      cin >> players[i].x >> players[i].y >> players[i].v;
   }

   double left = 0, right = D;
   for (int i = 0; i < 100; ++i) 
   {
      double mid = (left + right) / 2;
      double min_time = 1e9;
      for (auto &player : players) 
      {
         double dist = sqrt(player.x * player.x + (player.y - mid) * (player.y - mid));
         min_time = min(min_time, dist / player.v);
      }
      if (min_time * min_time >= mid) 
      {
         right = mid;
      } else {
         left = mid;
      }
   }

   cout << fixed << setprecision(5) << sqrt(left) << "\n";
   cout << "0.00000 " << fixed << setprecision(5) << left << "\n";

   return 0;
}
