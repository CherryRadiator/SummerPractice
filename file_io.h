#ifndef FILE_IO_H
#define FILE_IO_H

#include <vector>
#include <string>

// Читает целые числа из файла
// Возвращает: true при успехе, false при ошибке
bool readNumbersFromFile(const std::string& filename, std::vector<int>& numbers);

// Записывает числа в файл
// Возвращает: true при успехе, false при ошибке
bool writeNumbersToFile(const std::string& filename, const std::vector<int>& numbers);

// Проверяет возможность чтения файла
bool canReadFile(const std::string& filename);

// Проверяет возможность записи в файл
bool canWriteFile(const std::string& filename);

#endif