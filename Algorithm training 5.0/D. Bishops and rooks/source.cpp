#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
   string s;
   int A[9][9]{};
   int Ans = 0;

   for (int i = 1; i <= 8; i++)
   {
      cin >> s;
      for (int j = 1; j <= 8; j ++)
      {
         if (s[j-1] ==  'R') 
         {
            A[i][j] = 1;
         }
         if (s[j-1] == 'B')
         {
            A[i][j] = 2;
         }    
      }
   }
   
   for (int i = 1; i <= 8; i++)
   {
    for (int j = 1; j <= 8; j ++)
    {
        if (A[i][j] == 1)
        {
            for (int g = j + 1; g <= 8; g++)
            {
                if (A[i][g] == 1 || A[i][g] == 2) break;
                A[i][g] = 3;
            }
            for (int g = j - 1; g >=1; g--)
            {
                if (A[i][g] == 1 || A[i][g] == 2)break;
                A[i][g] = 3;
            }
            for (int g = i + 1; g<= 8; g++)
            {
                if (A[g][j] == 1 || A[g][j] == 2)break;
                A[g][j] = 3;
            }
            for (int g = i - 1; g>=1; g --)
            {
                if (A[g][j] == 1 || A[g][j] == 2)break;
                A[g][j] = 3;
            }
        }
        if (A[i][j] == 2)
        {
            for (int s = i - 1, k = 1; s >= 1 && j+k <= 8; s--, k++)
            {
                if (A[s][j + k] == 1 || A[s][j + k] == 2)break;
                A[s][j + k] = 3;
            }
            for (int s = i + 1, k = -1; s <= 8 && j + k >= 1; s++, k--)
            {
                if (A[s][j+k] == 1 || A[s][j+k] == 2)break;
                A[s][j+k] = 3;
            }
            for (int s = i - 1, k = -1; s >= 1 && j+k >= 1; s--, k--)
            {
                if (A[s][j+k] == 1 || A[s][j+k] == 2)break;
                A[s][j+k] = 3;
            }
            for (int s = i + 1, k = 1; s <= 8 && j+k <=8; s++, k++)
            {
                if (A[s][j+k] == 1 || A[s][j+k] == 2)break; 
                A[s][j+k] = 3;
            }
        }
    }
   }

   for (int i = 1; i <= 8; i++)
   {
      for (int g = 1; g <= 8; g++)
      {
          if (A[i][g] == 0) Ans++;
      }     
   }
   
   cout << Ans;
   return 0;
}
/*
********
*R******
********
*****B**
********
********
********
********
*/