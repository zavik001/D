#include <iostream>
#include <climits>

using namespace std;

int main()
{
   int N = 0, M = 0;
   cin >> N >> M;

   int *A = new int[N];
   for (int i = 0; i < N; i++) cin >> A[i];

   int **B = new int *[M];
   for (int i = 0; i < M; i++) B[i] = new int[2];
   for (int i = 0; i < M; i++) cin >> B[i][0] >> B[i][1];
   
   for (int i = 0; i < M; i++)
   {
      int min = INT_MAX;
      for (int j = B[i][0]; j < B[i][1] + 1; j++)
         if (A[j] < min) min = A[j];
      
      bool flag = 0;
      for (int j = B[i][0]; j < B[i][1] + 1; j++)
         if (A[j] > min)
         {
            flag = 1;
            cout << A[j] << endl;
            break;
         }

      if (flag == 0) cout << "NOT FOUND" << endl;
   }

   return 0;
}