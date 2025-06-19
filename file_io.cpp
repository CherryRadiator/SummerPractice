#include "file_io.h"
#include <fstream>
#include <iostream>
#include <sstream>

bool readNumbersFromFile(const std::string& filename, std::vector<int>& numbers) {
    if (!canReadFile(filename)) {
        return false;
    }
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл для чтения: " << filename << "\n";
        return false;
    }
    
    numbers.clear();
    std::string line;
    int totalNumbers = 0;
    
    std::cout << "Чтение чисел из файла...\n";
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        
        while (iss >> number) {
            numbers.push_back(number);
            totalNumbers++;
        }
    }
    
    file.close();
    
    std::cout << "Успешно прочитано " << totalNumbers << " чисел из файла.\n\n";
    return true;
}

bool writeNumbersToFile(const std::string& filename, const std::vector<int>& numbers) {
    if (!canWriteFile(filename)) {
        return false;
    }
    
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл для записи: " << filename << "\n";
        return false;
    }
    
    std::cout << "Сохранение результата в файл...\n";
    
    for (size_t i = 0; i < numbers.size(); ++i) {
        file << numbers[i];
        if (i < numbers.size() - 1) {
            file << "\n";
        }
    }
    file << "\n";
    
    file.close();
    
    std::cout << "Данные успешно сохранены.\n";
    return true;
}

bool canReadFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: Не удается открыть файл для чтения: " << filename << "\n";
        std::cout << "Проверьте, что файл существует и у вас есть права на чтение.\n";
        return false;
    }
    file.close();
    return true;
}

bool canWriteFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cout << "Ошибка: Не удается открыть файл для записи: " << filename << "\n";
        std::cout << "Проверьте права доступа к папке и имя файла.\n";
        return false;
    }
    file.close();
    return true;
}