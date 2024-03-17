#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string query = "we we we er rt";
    std::stringstream ss(query);
    std::string word;

    // Считываем первые два слова
    ss >> word;
    ss >> word;

    // Считываем оставшуюся часть строки до конца
    std::getline(ss, word, '\0'); // '\0' - символ конца строки

    std::cout << "Оставшаяся часть строки: " << word << std::endl;

    return 0;
}
