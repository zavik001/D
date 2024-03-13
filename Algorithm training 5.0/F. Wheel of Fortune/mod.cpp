#include <iostream>

using namespace std;

int main ()
{
   int a = 10, b = 3;
   cout <<" "<< a << "  " << b << "\t " << a % b << endl;

   a = -10;
   b = 3;
   cout << a << "  " << b << "\t" << a % b << endl;

   a = 10;
   b = -3;
   cout <<" "<<a << " " << b << "\t " << a % b << endl;
   a = -10;
   b = -3;
   cout << a << " " << b << "\t" << a % b << endl;

   return 0;
}