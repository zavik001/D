#include <bits/stdc++.h>
using namespace std;

const int SIZE = 26;

struct Node
{
   Node *child[SIZE], *par;
   int maxPopL, maxPopR;
   bool isEnd;

   Node()
   {
      maxPopL = -1;
      maxPopR = -1;
      isEnd = false;
      for (int i = 0; i < SIZE; i++)
         child[i] = nullptr;
      par = nullptr;
   }
};

class Trie
{
public:
   int len = 0;

   Trie()
   {
      root = new Node();
      curNode = root; 
   }

   void insert(const string &str, int popL, int popR)
   {
      Node *node = root;
      for (char c : str)
      {
         int idx = c - 'a';
         if (node->child[idx] == nullptr)
         {
            node->child[idx] = new Node();
            node->child[idx]->par = node;
         }

         node = node->child[idx];
         if (popL > node->maxPopL || (popL == node->maxPopL && popR < node->maxPopR))
         {
            node->maxPopL = popL;
            node->maxPopR = popR;
         }
         
         if (popL > maxPop)
         {
            maxPop = popL;
            maxPopR = popR;
         }
      }
   }

   void updateRoot()
   {
      root->maxPopR = maxPopR;
   }

   int autocomplete(const string &prefix)
   {
      size_t n = prefix.size();
      if (n > len)
      {
         int idx = prefix[n-1] - 'a';
         if (curNode->child[idx] == nullptr)
         {
            curNode->child[idx] = new Node();
            curNode->child[idx]->par = curNode;
         }

         curNode = curNode->child[idx];
         len++;
      }
      else
      {
         curNode = curNode->par;
         len--;
      }

      if (curNode == nullptr)
         return -1; 

      return curNode->maxPopR;
   }

private:
   Node *root, *curNode;
   int maxPopR = 0, maxPop = INT_MIN;
};

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);

   int N = 0, Q = 0;
   cin >> N >> Q;
   Trie trie;

   for (int i = 0; i < N; ++i)
   {
      string s;
      int popL;
      int popR = i + 1;
      cin >> s >> popL;
      trie.insert(s, popL, popR);
   }

   trie.updateRoot();

   string curStr = "";
   for (int i = 0; i < Q; i++)
   {
      char op;
      cin >> op;
      if (op == '+')
      {
         char c;
         cin >> c;
         curStr += c;
      }
      else
         curStr.pop_back();

      cout << trie.autocomplete(curStr) << endl;
   }

   return 0;
}