#ifndef MENU_H
#define MENU_H

#include <string>

// Показывает приветственное сообщение
void showWelcome();

// Предлагает выбор метода сортировки
// Возвращает: 1 - битонная, 2 - LSD radix, -1 - выход
int chooseSortingMethod();

// Запрашивает путь к входному файлу
// Возвращает: путь к файлу или пустую строку при выходе
std::string chooseInputFile();

// Запрашивает путь к выходному файлу
// Возвращает: путь к файлу или пустую строку при выходе
std::string chooseOutputFile();

// Запрашивает подтверждение действия
// Возвращает: true - продолжить, false - выйти
bool confirmAction(const std::string& action);

// Показывает результаты работы программы
void showResults(int numbersCount, double sortTime, const std::string& outputFile);

// Вспомогательная функция для получения ответа да/нет/выход
// Возвращает: 1 - да, 0 - нет, -1 - выход
int getYesNoExit();

#endif