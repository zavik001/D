#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   // Считываем три списка чисел
   int n;
   cin >> n;
   
   vector<int> list1(n);
   unordered_set<int> set1;
   
   for (int i = 0; i < n; ++i) 
   {
      cin >> list1[i];
      set1.insert(list1[i]);
   }
   
   cin >> n;
   
   vector<int> list2(n);
   unordered_set<int> set2;
   
   for (int i = 0; i < n; ++i) 
   {
      cin >> list2[i];
      set2.insert(list2[i]);
   }
   
   cin >> n;
   
   vector<int> list3(n);
   unordered_set<int> set3;
   
   for (int i = 0; i < n; ++i) 
   {
      cin >> list3[i];
      set3.insert(list3[i]);
   }
   
   unordered_set<int> result_set;
   
   for (int num : list1) 
   {
      if ((set2.count(num) || set3.count(num)) && result_set.count(num) == 0)
         result_set.insert(num);
   }
   
   for (int num : list2) 
   {
      if ((set1.count(num) || set3.count(num)) && result_set.count(num) == 0)
         result_set.insert(num);
   }
   
   for (int num : list3) 
   {
      if ((set1.count(num) || set2.count(num)) && result_set.count(num) == 0)
         result_set.insert(num);
   }
   
   vector<int> result;
   for (int num : result_set) 
   {
      result.push_back(num);
   }
   
   sort(result.begin(), result.end());
   
   for (int num : result) 
   {
      cout << num << " ";
   }
   cout << endl;
   
   return 0;
}
