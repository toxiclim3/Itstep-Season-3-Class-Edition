// CL23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
/*
    Асоціативні контейнери

    Сет - це классичне бінарне дерево. Містить конкретне унікальне значення
*/
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

// Функция для очистки слова от знаков препинания
std::string cleanWord(const std::string& word) {
    std::string cleaned;
    for (char c : word) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            cleaned += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return cleaned;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordFrequency;
    std::string line;

    // Чтение файла и формирование частотного словаря
    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        std::string word;
        while (lineStream >> word) {
            word = cleanWord(word);
            if (!word.empty()) {
                ++wordFrequency[word];
            }
        }
    }

    inputFile.close();

    // Вывод всех слов и их частоты
    std::cout << "Частотный словарь:\n";
    for (const auto& [word, frequency] : wordFrequency) {
        std::cout << word << ": " << frequency << std::endl;
    }

    // Поиск наиболее часто встречающегося слова
    auto mostFrequent = std::max_element(wordFrequency.begin(), wordFrequency.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

    if (mostFrequent != wordFrequency.end()) {
        std::cout << "\nНаиболее часто встречающееся слово: "
            << mostFrequent->first << " (" << mostFrequent->second << " раз)" << std::endl;
    }

    // Запись результата в файл
    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла output.txt" << std::endl;
        return 1;
    }

    outputFile << "Частотный словарь:\n";
    for (const auto& [word, frequency] : wordFrequency) {
        outputFile << word << ": " << frequency << std::endl;
    }

    if (mostFrequent != wordFrequency.end()) {
        outputFile << "\nНаиболее часто встречающееся слово: "
            << mostFrequent->first << " (" << mostFrequent->second << " раз)";
    }

    outputFile.close();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
