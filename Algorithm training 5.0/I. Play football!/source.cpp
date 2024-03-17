#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct Team
{
   int goals = 0;
   int game = 0;
   int scored = 0;
};

struct Name
{
   int goals = 0;
   int scored = 0;
   string teem = "";
};

int extractNumber(const std::string& str) {
   int number = 0;
   size_t startIndex = str.find_first_of("0123456789");

   if (startIndex != std::string::npos) {
      std::string numberStr = str.substr(startIndex);

      try {
         number = std::stoi(numberStr);
      }
      catch (const std::invalid_argument&) {
         // Если не удалось преобразовать в число, оставляем number равным 0
      }
   }

   return number;
}

class FootballStats
{
private:
   map<string, Team> K;
   map<string, Name> P;
   map<string, map<int, int>> TP;
   vector<double> ANS;

public:
   void process_match(const string& match_info)
   {
      stringstream ss(match_info);
      string team1, team2, word;
      string player1, player2;
      int score1, score2;

      ss >> team1;
      bool flag = true;
      for (;flag;)
      {
         if (team1.back() != '"')
         {
            ss >> word;
            team1 += " " + word;
         }
         if (team1.back() == '"')
            flag = false;
      }

      ss.ignore(3);
      ss >> team2;
      flag = true;
      for (; flag;)
      {
         if (team2.back() != '"')
         {
            ss >> word;
            team2 += " " + word;
         }
         if (team2.back() == '"')
            flag = false;
      }

      ss >> score1;
      ss.ignore(1);
      ss >> score2;

      K[team1].goals += score1;
      K[team2].goals += score2;
      K[team1].game++;
      K[team2].game++;
      int t1 = 10000;
      int t2 = 10000;

      string line;
      for (int i = 0; i < score1; i++)
      {
         getline(cin, line);
         stringstream rr(line);
         string p, w;
         int t = 0;

         rr >> p >> w;
         flag = true;
         for (; flag;)
         {
            if (w.back() != '\'')
            {
               p += " " + w;
               rr >> w;
            }
            else 
            {
               flag = false;
               t = extractNumber(w);
            }
         }

         P[p].goals++;
         P[p].teem = team1;
         TP[p][t]++;

         if (i == 0)
         {
            t1 = t;
            player1 = p;
         }
      }
      for (int i = 0; i < score2; i++)
      {
         getline(cin, line);
         stringstream rr(line);
         string p, w;
         int t = 0;

         rr >> p >> w;
         flag = true;
         for (; flag;)
         {
            if (w.back() != '\'')
            {
               p += " " + w;
               rr >> w;
            }
            else
            {
               flag = false;
               t = extractNumber(w);
            }
         }

         P[p].goals++;
         P[p].teem = team2;
         TP[p][t]++;


         if (i == 0)
         {
            t2 = t;
            player2 = p;
         }
      }
      if (t1 < t2)
      {
         P[player1].scored++;
         K[team1].scored++;
      }
      if (t2 < t1)
      {
         P[player2].scored++;
         K[team2].scored++;
      }
   }

   void process_query(const string& query)
   {
      stringstream ss(query);
      string word;
      ss >> word;

      if (word == "Total")
      {
         ss >> word >> word;
         if (word == "for")
         {
            ss.ignore();
            getline(ss, word, '\0');
            if (K.find(word) != K.end())
               ANS.push_back(K[word].goals);
            else
               ANS.push_back(0);
         }
         else
         {
            ss.ignore();
            getline(ss, word, '\0');
            if (P.find(word) != P.end())
               ANS.push_back(P[word].goals);
            else
               ANS.push_back(0);
         }
      }
      else if (word == "Mean")
      {
         ss >> word >> word >> word >> word;
         if (word == "for")
         {
            ss.ignore();
            getline(ss, word, '\0');
            ANS.push_back(static_cast<double>(K[word].goals) / static_cast<double>(K[word].game));
         }
         else
         {
            ss.ignore();
            getline(ss, word, '\0');
            ANS.push_back(static_cast<double>(P[word].goals) / static_cast<double>(K[P[word].teem].game));
         }
      }
      else if (word == "Goals")
      {
         ss >> word >> word;
         int time;
         string player;

         if (word == "minute")
         {
            ss >> time >> player;
            ss.ignore();
            getline(ss, player, '\0');
            ANS.push_back(TP[player][time]);
         }
         else if (word == "first")
         {
            ss >> time >> player >> player;
            ss.ignore();
            getline(ss, player, '\0');
            int kol = 0;

            for (const auto& m : TP[player])
               if (m.first <= time)
                  kol += m.second;

            ANS.push_back(kol);
         }
         else
         {
            ss >> time >> player >> player;
            ss.ignore();
            getline(ss, player, '\0');
            int kol = 0;

            for (const auto& m : TP[player])
               if (m.first >= 91 - time)
                  kol += m.second;

            ANS.push_back(kol);
         }
      }
      else
      {
         ss >> word >> word;
         ss.ignore();
         getline(ss, word, '\0');
         bool flag = false;

         if (word.find('"') != std::string::npos)
            flag = true;
         else
            flag = false;

         if (K.find(word) != K.end() && flag)
            ANS.push_back(K[word].scored);
         else
         {
            if (P.find(word) != P.end())
               ANS.push_back(P[word].scored);
            else
               ANS.push_back(0);
         }
      }
   }

   void print()
   {
      for (int i = 0; i < ANS.size(); i++)
         cout << ANS[i] << endl;

   }
   void printData() {
      /*// Печать данных из контейнера K
      cout << "Teams:\n";
      for (const auto& item : K) {
         cout << endl << item.first << ": " << item.second.goals << ", " << item.second.game << ", " << item.second.scored << endl;
      }

      // Печать данных из контейнера P
      cout << "Players:\n";
      for (const auto& item : P) {
         cout << item.first << ": " << item.second.goals << ", " << item.second.scored << ", " << item.second.teem << endl;
      }

      // Печать данных из контейнера TP
      cout << "Team-Player mapping:\n";
      for (const auto& item : TP) {
         cout << item.first << ":\n";
         for (const auto& innerItem : item.second) {
            cout << "  " << innerItem.first << ": " << innerItem.second << endl;
         }
      }

      */// Печать данных из контейнера ANS
      //cout << "Answers:\n";
      for (const auto& item : ANS) {
         cout << item << endl;
      }
   }
};

int main()
{
   FootballStats stats;
   string line;

   for (; getline(cin, line); )
   {
      if (line.empty()) break;
      if (line.front() == '"')
         stats.process_match(line);
      else
         stats.process_query(line);
   }

   stats.printData();

   return 0;
}