#include <iostream>

using namespace std;

int main()
{
   int P = 0, V = 0, Q = 0, M = 0;
   long long Ans = 0;
   cin >> P >> V >> Q >> M;

   Ans = V * 2 + M * 2 + 2;

   if (P + V >= Q - M && P - V < Q - M && P + V < Q + M) Ans -= P + V - Q + M + 1;

   if (Q + M >= P - V && Q - V < P - V && Q + M < P + V) Ans -= Q + M - P + V + 1;

   if (P + V >= Q + M && P - V <= Q - M) Ans -= M * 2 + 1;

   if (Q + M >= P + V && Q - M <= P - V) Ans -= V * 2 + 1;

   cout << Ans;

   return 0;
}