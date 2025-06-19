#include "menu.h"
#include <iostream>
#include <string>

void showWelcome() {
    std::cout << "===========================================\n";
    std::cout << "  Программа сортировки целых чисел\n";
    std::cout << "===========================================\n";
    std::cout << "Добро пожаловать!\n";
    std::cout << "Эта программа поможет отсортировать числа\n";
    std::cout << "из файла с помощью продвинутых алгоритмов.\n\n";
}

int chooseSortingMethod() {
    std::cout << "Выберите метод сортировки:\n";
    std::cout << "1. Битонная сортировка\n";
    std::cout << "2. LSD Radix сортировка\n";
    std::cout << "3. Выйти из программы\n";
    
    int choice;
    while (true) {
        std::cout << "Ваш выбор (1-3): ";
        std::cin >> choice;
        
        if (choice == 1 || choice == 2) {
            std::cout << "Вы выбрали: " << (choice == 1 ? "Битонная сортировка" : "LSD Radix сортировка") << "\n\n";
            return choice;
        } else if (choice == 3) {
            std::cout << "До свидания!\n";
            return -1;
        } else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n'); // Очистка буфера при ошибке
        }
    }
}

std::string chooseInputFile() {
    while (true) {
        std::cout << "Введите путь к входному файлу:\n";
        std::string filename;
        std::cin.ignore(); // Очистка буфера перед getline
        std::getline(std::cin, filename);
        
        std::cout << "Продолжить с файлом '" << filename << "'?\n";
        std::cout << "1. Да  2. Ввести другой путь  3. Выйти\n";
        
        int choice = getYesNoExit();
        if (choice == 1) {
            return filename;
        } else if (choice == 0) {
            continue; // Повторить ввод
        } else {
            std::cout << "До свидания!\n";
            return "";
        }
    }
}

std::string chooseOutputFile() {
    while (true) {
        std::cout << "Введите путь к выходному файлу:\n";
        std::string filename;
        std::getline(std::cin, filename);
        
        std::cout << "Сохранить результат в файл '" << filename << "'?\n";
        std::cout << "1. Да  2. Ввести другой путь  3. Выйти\n";
        
        int choice = getYesNoExit();
        if (choice == 1) {
            return filename;
        } else if (choice == 0) {
            continue; // Повторить ввод
        } else {
            std::cout << "До свидания!\n";
            return "";
        }
    }
}

bool confirmAction(const std::string& action) {
    std::cout << action << "?\n";
    std::cout << "1. Да  2. Нет (выйти)\n";
    
    int choice;
    while (true) {
        std::cout << "Ваш выбор (1-2): ";
        std::cin >> choice;
        
        if (choice == 1) {
            return true;
        } else if (choice == 2) {
            std::cout << "До свидания!\n";
            return false;
        } else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n'); // Очистка буфера при ошибке
        }
    }
}

void showResults(int numbersCount, double sortTime, const std::string& outputFile) {
    std::cout << "\n===========================================\n";
    std::cout << "           РЕЗУЛЬТАТЫ СОРТИРОВКИ\n";
    std::cout << "===========================================\n";
    std::cout << "Обработано чисел: " << numbersCount << "\n";
    std::cout << "Время сортировки: " << sortTime << " мс\n";
    std::cout << "Результат сохранен в: " << outputFile << "\n";
    std::cout << "Программа успешно завершена!\n";
}

int getYesNoExit() {
    int choice;
    while (true) {
        std::cout << "Ваш выбор (1-3): ";
        std::cin >> choice;
        
        if (choice == 1) {
            std::cin.ignore(); // Очистка буфера
            return 1; // Да
        } else if (choice == 2) {
            std::cin.ignore(); // Очистка буфера
            return 0; // Нет (повторить)
        } else if (choice == 3) {
            std::cin.ignore(); // Очистка буфера
            return -1; // Выйти
        } else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n'); // Очистка всего буфера при ошибке
        }
    }
}