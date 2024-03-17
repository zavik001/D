#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Table
{
   unordered_map<string, unordered_set<int>> data;

   void add(const string& song, int index) {
      if (data.find(song) != data.end()) {
         data[song].insert(index);
      } else {
         unordered_set<int> indices;
         indices.insert(index);
         data[song] = indices;
      }
   }

   void printSongsWithAllIndices(int n) {
      vector<string> songsWithAllIndices;
      for (const auto& entry : data) {
         const unordered_set<int>& indices = entry.second;
         if (indices.size() == static_cast<size_t>(n)) {
               songsWithAllIndices.push_back(entry.first);
         }
      }

      sort(songsWithAllIndices.begin(), songsWithAllIndices.end());

      cout << songsWithAllIndices.size() << endl;
      for (const string& song : songsWithAllIndices) {
         cout << song << " ";
      }
   }
};

int main() {
   int n;
   cin >> n;
   Table T;

   for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
         string song;
         cin >> song;
         T.add(song, i + 1);
      }
   }

   T.printSongsWithAllIndices(n);

   return 0;
}
