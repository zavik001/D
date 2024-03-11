#include <iostream>
#include <vector>

using namespace std;

int main() 
{
   int N;
   cin >> N;

   vector<vector<bool>> board(8, vector<bool>(8, false));

   for (int i = 0; i < N; ++i) 
   {
      int row, col;
      cin >> row >> col;
      board[row - 1][col - 1] = true;
   }

   int perimeter = 0;

   
   for (int i = 0; i < 8; ++i) 
   {
      for (int j = 0; j < 8; ++j) 
      {
         if (board[i][j]) 
         { 
            
            if (i == 0 || !board[i - 1][j]) perimeter++; 
            if (i == 7 || !board[i + 1][j]) perimeter++; 
            if (j == 0 || !board[i][j - 1]) perimeter++; x  
            if (j == 7 || !board[i][j + 1]) perimeter++; 
         }
      }
   }

   cout << perimeter << endl;
   return 0;
}
