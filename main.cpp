#include "menu.h"
#include "file_io.h"
#include "sorting.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Приветствие
    showWelcome();
    
    // Выбор метода сортировки
    int sortMethod = chooseSortingMethod();
    if (sortMethod == -1) {
        return 0; // Пользователь выбрал выход
    }
    
    // Выбор входного файла
    std::string inputFile = chooseInputFile();
    if (inputFile.empty()) {
        return 0; // Пользователь выбрал выход
    }
    
    // Выбор выходного файла
    std::string outputFile = chooseOutputFile();
    if (outputFile.empty()) {
        return 0; // Пользователь выбрал выход
    }
    
    // Чтение данных из файла
    std::vector<int> numbers;
    if (!readNumbersFromFile(inputFile, numbers)) {
        std::cout << "Ошибка при чтении файла. Программа завершена.\n";
        return 1;
    }
    
    // Проверка на пустой файл
    if (numbers.empty()) {
        std::cout << "Файл пуст или не содержит чисел.\n";
        return 1;
    }
    
    // Подтверждение перед сортировкой
    if (!confirmAction("Начать сортировку")) {
        return 0;
    }
    
    // Сортировка с замером времени
    double sortTime = performSorting(numbers, sortMethod);
    
    // Сохранение результата
    if (!writeNumbersToFile(outputFile, numbers)) {
        std::cout << "Ошибка при записи в файл. Программа завершена.\n";
        return 1;
    }
    
    // Показ результатов
    showResults(numbers.size(), sortTime, outputFile);
    
    return 0;
}