#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//---------------------------------
struct cursor 
{
   int x1, y1, x2, y2;

   int hm;

   cursor() : x1(0), y1(0), x2(0), y2(0), hm(0) {}
   cursor(int x1_, int y1_, int x2_, int y2_, int hm_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), hm(hm_) {}
}; 

int DWORD [100000][1000]{};
cursor cur;
vector<pair<int, int>> tringle;
int w = 0, h = 0, c = 0;
//---------------------------------

int pixel(int i)
{
   bool flag = false;

   for (int g = cur.y1; g < cur.y2; g++)
   {
      for (int j = i; j < c; j ++)
      {
         if (DAWN[g][j] == 2)flag = true;
      }
   }

   return flag ? 2 : 0; 
}



//---------------------------------
struct ImageData 
{
   string layout;
   int width;
   int height;
   int dx;
   int dy;
};
ImageData ima;

void image(string s)
{
   istringstream iss(s);
   string token;

   for ( ; iss >> token; ) 
   {
      if (token == "layout") 
         iss >> ima.layout;
      else if (token == "width") 
         iss >> ima.width;
      else if (token == "height") 
         iss >> ima.height;
      else if (token == "dx") 
         iss >> ima.dx;
      else if (token == "dy")
         iss >> ima.dy;
   }

   if (ima.layout == 'embedded')
   {
      bool flag = false;
      if (cur.x1 != 0)
      {
         int rr = 0;
         for ( ;cur.x1 + rr < w && DWORD[cur.y1][cur.x1+rr] == 0; rr++);

         if (rr > ima.width + c)
         {
            flag = true;
            cur = {cur.x1 + ima.width + c, cur.y1, cur.x2 + ima.width + c, cur.y2, ima.height};
         }
         else
         {
            for (int i = cur.x1; i < w; i++)
            {
               if (DWORD[cur.y1][i] == 0 || DWORD[cur.y1][i - 1] == 3)
               {
                  cur = {i, cur.y1, i, cur.y2, ima.height};
               }
            }
         }
      }
      if (!flag)
      {
         for (int i = cur.y1; ; i += h)
         {
            int rr = 0;
            for (;)
         }
      }


      for (int i = 0; i < ima.height; i ++)
            {
               for (int j = cur.x1; j > cur.x1 - ima.width; j --)
                  A[i + cur.y1][j] = 2;
            }
   }

   if (ima.layout == 'surrounded')
   {

   }

   if (ima.layout == 'floating')
   {

   }
}
//---------------------------------


//---------------------------------


cursor find_fragment()
{

}

void word(string s)
{
   int t = s.size();
   bool flag = false;

   if (DAWN[cur.y1][cur.x1 -1] == 1)
   {
      int r = 0;
      for (int i = cur.x1; i < w && pixel(i) == 0; i += c, r++);

      if (t + 1 <= r)
      {
         int j = cur.x1
         for (; j < (t + 1) * c; j ++)
         {
            for (int k = cur.y1; k < cur.y2; k ++)
            {
               DAWN[k][j] = 1;
            }
         }
         cur = {j, cur.y1, j, cur.y2};
      }
      else 
      {
         if (cur.x1 + r * c + c > w)
            cur = {0, cur.y1 + h, 0, cur.y2 + h};
         else 
         {
            for ( ; ; cur.x1++)
            {
               cur.x2++;
               if (DAWN[cur.y1][cur.x1] == 0 && (DAWN[cur.y1][cur.x1 - 1] == 2 || DAWN[cur.y1][cur.x1 - 1] == 3))
                  break;
            }
         }
      }
   }
   
   bool flag = true;
   int r = 0;
   for (;flag;)
   {
      for ()
   }
}
//---------------------------------

//---------------------------------
void paragraph()
{

}
//----------------------------------

bool input()
{
   ifstream file("input.txt");
   if (file.is_open())
   {
      file >> w >> h >> c;
      cur = {0, 0, 0, h, 0};

      string line;
      int flag = false;
      string s1, s2;

      for ( ;getline(file, line); )
      {
         if (line.empty())
         {
            paragraph();
         }
         else
         {
            for (int i = 0; i < line.size(); i ++)
            {
               if (line[i] == '(')
               {
                  flag = true;
                  continue;
               }
               
               if (flag)
               {
                  if (line[i] == ')')
                  {
                     flag = false;

                     image(s1);

                     s1.clear();
                     continue;
                  }
                  s1.push_back(line[i]);
               }

               if (!flag)
               {
                  if (line[i])
                  {
                     s2.push_back(line[i]);
                  }
                  else
                  {
                     if (!s2.empty())
                        word(s2);

                     s2.clear();
                  }
               }
            }
         }
      }

      file.close();
      return true;
   }
   else
      return false;
}

void output()
{
   ofstream file("output.txt");
   if (file.is_open())
   {
      for (int i = 0; i < tringle.size(); i ++)
         file << tringle[i].first << " " << tringle[i].second << "\n";
      file.close();
   }
   else
      return;
}

void output2()
{
   ofstream file("output2.txt");
   if (file.is_open())
   {
      for (int i = 0; i < 100; i ++)
      {
         for (int j = 0; j < 100; j ++)
         {
            file << DWORD[i][j];
         }
         file << "\n";
      }
      
      file.close();
   }
   else
      return;
}


int main ()
{
   if (!input())
      return 1;

   output();
   output2();

   return 0;
}
