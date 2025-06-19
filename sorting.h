#ifndef SORTING_H
#define SORTING_H

#include <vector>

// Выполняет сортировку с замером времени
// Возвращает: время сортировки в миллисекундах
double performSorting(std::vector<int>& numbers, int sortMethod);

// Битонная сортировка
void bitonicSort(std::vector<int>& arr);

// LSD Radix сортировка
void lsdRadixSort(std::vector<int>& arr);

// Вспомогательные функции для битонной сортировки
void bitonicSortRecursive(std::vector<int>& arr, int low, int cnt, bool dir);
void bitonicMerge(std::vector<int>& arr, int low, int cnt, bool dir);
void compareAndSwap(std::vector<int>& arr, int i, int j, bool dir);

// Вспомогательные функции для LSD Radix сортировки
void countingSort(std::vector<int>& arr, int exp);
int getMax(const std::vector<int>& arr);

// Функция для подготовки массива к битонной сортировке (размер степень двойки)
void prepareForBitonicSort(std::vector<int>& arr);

#endif