#include <iostream>

using namespace std;

int main ()
{
    int n = 0, a = 0, x = 0;
    long long Ans = 0;
    cin >> n;
    
    for (int i = 0; i < n; i ++)
    {
        cin >> a;

        x = a / 4;
        Ans += x;
        a -= x*4;
        if (a == 2)Ans+=2;
        if (a == 1)Ans+=1;
        if (a == 3)Ans+=2;

        x = 0;
        a = 0; 
    }

    cout << Ans;

    return 0;
}