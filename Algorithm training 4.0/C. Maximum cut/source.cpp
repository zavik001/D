#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 20;
int adjMatrix[MAXN][MAXN]; // Матрица смежности
int N; // Количество вершин в графе

// Рекурсивная функция для полного перебора
int maxWeight(int mask, int pos) {
   if (pos == N) {
      int sum = 0;
      for (int u = 0; u < N; u++) {
         for (int v = 0; v < N; v++) {
               if ((mask & (1 << u)) && !(mask & (1 << v))) {
                  sum += adjMatrix[u][v];
               }
         }
      }
      return sum;
   }
   
   // Рекурсивно перебираем все возможные комбинации
   return max(maxWeight(mask | (1 << pos), pos + 1), maxWeight(mask, pos + 1));
}

int main() {
   // Ввод матрицы смежности
   cin >> N;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cin >> adjMatrix[i][j];
      }
   }

   int result = maxWeight(0, 0);
   cout << result << endl;

   return 0;
}
