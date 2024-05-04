#include <bits/stdc++.h>
using namespace std;

int main ()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   string s;
   getline(cin, s); // Используйте getline для чтения всей строки, а не только одного слова

   size_t n = s.size();
   int left = -1, right = -1;

   for (int i = 0; i <= n; i ++)
   {
      if (i == n || s[i] == ' ') // Если мы достигли конца строки или пробела
      {
         if (left != -1) // Если мы нашли начало слова ранее
         {
            reverse(s.begin() + left, s.begin() + right + 1); // Переворачиваем слово
            left = -1; // Сбрасываем указатели
         }
      }
      else if (left == -1) // Если мы нашли начало слова
      {
         left = i;
         right = i;
      }
      else // Если мы находимся внутри слова
      {
         right = i;
      }
   }

   cout << s << endl; // Выводим итоговую строку

   return 0;
}
