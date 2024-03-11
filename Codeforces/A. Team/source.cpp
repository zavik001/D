#include <iostream>

using namespace std;

int main()
{
   int n;
   cin >> n;

   int problems_to_implement = 0;

   for (int i = 0; i < n; ++i)
   {
      int petya, vasya, tonya;
      cin >> petya >> vasya >> tonya;

      if (petya + vasya + tonya >= 2) 
            ++problems_to_implement;
   }

   cout << problems_to_implement << endl;

   return 0;
}
