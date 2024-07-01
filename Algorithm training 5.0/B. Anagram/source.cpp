#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

bool areAnagrams(string str1, string str2) 
{
   if (str1.length() != str2.length()) 
      return false;

   sort(str1.begin(), str1.end());
   sort(str2.begin(), str2.end());

   return str1 == str2;
}

int main()
{
   string s1, s2;
   int choice;
   ofstream outputFile("output.txt");
   
   cout << "\n\n========================================\n";
   cout << "Привет! Данная программа проверяет, являются ли две строки анаграммами.\n";
   cout << "========================================\n\n";
   cout << "Выберите: 1 для ввода из файла, 2 для ввода из консоли: ";
   cin >> choice;
   
   if (choice == 1) {
      ifstream inputFile("input.txt");
      if (inputFile.is_open()) {
         inputFile >> s1 >> s2;
         inputFile.close();
      } else {
         cout << "Не удалось открыть файл.";
         outputFile << "Не удалось открыть файл.";
         return 1;
      }
   } else if (choice == 2) {
      cout << "Введите два слова: ";
      cin >> s1 >> s2;
   } else {
      cout << "Неверный выбор.";
      outputFile << "Неверный выбор.";
      return 1;
   }
      
   if (areAnagrams(s1, s2)) {
      cout << "YES\n";
      outputFile << "YES\n";
   } else {
      cout << "NO\n";
      outputFile << "NO\n";
   }

   outputFile.close();
   return 0;
}
