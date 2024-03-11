   #include <iostream>
   #include <vector>
   #include <algorithm>

   using namespace std;

   int main()
   {
      int n = 0;
      cin >> n;
      vector <pair<int, int>> A(n);
      vector <pair<int, int>> B(n);

      for (int i = 0; i < n; i++)
      {
         cin >> A[i].first >> A[i].second;
         B[i].first = A[i].first - A[i].second;
         B[i].second = i + 1;
      }

      sort(B.begin(), B.end(), [](const auto& left, const auto& right) {
         return left.first < right.first;
      });

      long long H = 0, maxH = 0;
      for (int i = n - 1; i >= 0; i --)
      {
         int index = B[i].second - 1;
         H += A[index].first;
         if (maxH < H) maxH = H;

         H -= A[index].second;
      }

      cout << maxH << endl;
      for (int i = n - 1; i >= 0; i --)
         cout << B[i].second << " ";

      return 0;
   }