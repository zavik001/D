#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line); // Считываем строку из стандартного ввода

    std::istringstream iss(line); // Создаем поток для чтения строки
    std::string team1, team2, score;

    std::getline(iss, team1, '-'); // Читаем первую часть строки до "-"
    std::getline(iss, team2, '-'); // Читаем вторую часть строки до "-"
    std::getline(iss, score);      // Читаем третью часть строки до конца

    // Удаляем лишние пробелы, если они есть
    team1.erase(std::remove_if(team1.begin(), team1.end(), ::isspace), team1.end());
    team2.erase(std::remove_if(team2.begin(), team2.end(), ::isspace), team2.end());

    // Выводим результат
    std::cout << "Team 1: " << team1 << std::endl;
    std::cout << "Team 2: " << team2 << std::endl;
    std::cout << "Score: " << score << std::endl;

    return 0;
}
