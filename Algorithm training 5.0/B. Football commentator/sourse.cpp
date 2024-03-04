#include <iostream>
#include <string>

using namespace std;

int main()
{
    string m1, m2;
    int i = 0, x = 0;
    cin >> m1 >> m2 >> i;

    int G1 = m1[0] - '0', G2 = m1[2] - '0', G3 = m2[0] - '0', G4 = m2[2] - '0';
    
    x = G2 + G4 - G1 - G3;
    if (x < 0) 
       x = 0;
    else 
    {
       G3 += x;
       
       if (i == 1)
          x += G3 <= G2;
       else
          x += G1<= G4;
    }
    cout << x;
    
    return 0;
}