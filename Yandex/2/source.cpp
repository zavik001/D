#include <bits/stdc++.h>
using namespace std;

struct TrieNode 
{
   map<char, TrieNode*> child;
   vector<int> words;
};

TrieNode *getNode() 
{
   TrieNode* newNode = new TrieNode;
   return newNode;
}

void insert(TrieNode *root, const string &str, int index) 
{
   TrieNode *temp = root;
   for (char c : str) 
   {
      if (!temp->child.count(c)) 
         temp->child[c] = getNode();

      temp = temp->child[c];
      temp->words.push_back(index);
   }
}

int main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int N, Q;
   cin >> N >> Q;
   vector<string> dict(N);
   TrieNode* root = getNode();
   for (int i = 0; i < N; ++i) 
   {
      cin >> dict[i];
      insert(root, dict[i], i + 1);
   }

   string prefix;
   int k;
   while (Q--) 
   {
      cin >> k >> prefix;
      TrieNode* temp = root;
      bool flag = true;
      for (char c : prefix) 
      {
         if (!temp->child.count(c))
         {
            flag = false;
            break;
         }
         temp = temp->child[c];
      }
      if (!flag || k > temp->words.size())
         cout << -1 << "\n";

      else 
         cout << temp->words[k - 1] << "\n";
   }

   return 0;
}
