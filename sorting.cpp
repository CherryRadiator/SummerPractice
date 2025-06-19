#include "sorting.h"
#include <chrono>
#include <iostream>
#include <algorithm>

double performSorting(std::vector<int>& numbers, int sortMethod) {
    std::cout << "Начинаем сортировку...\n";
    
    auto start = std::chrono::high_resolution_clock::now();
    
    if (sortMethod == 1) {
        std::cout << "Используется битонная сортировка.\n";
        bitonicSort(numbers);
    } else if (sortMethod == 2) {
        std::cout << "Используется LSD Radix сортировка.\n";
        lsdRadixSort(numbers);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    double timeMs = duration.count() / 1000.0;
    
    std::cout << "Сортировка завершена!\n\n";
    
    return timeMs;
}

void bitonicSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    
    // Подготавливаем массив (дополняем до размера степени двойки)
    prepareForBitonicSort(arr);
    
    // Запускаем битонную сортировку
    bitonicSortRecursive(arr, 0, arr.size(), true);
}

void prepareForBitonicSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Находим ближайшую степень двойки
    int powerOfTwo = 1;
    while (powerOfTwo < n) {
        powerOfTwo *= 2;
    }
    
    // Дополняем массив максимальными значениями
    if (powerOfTwo > n) {
        int maxVal = *std::max_element(arr.begin(), arr.end());
        arr.resize(powerOfTwo, maxVal + 1);
    }
}

void bitonicSortRecursive(std::vector<int>& arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        
        // Сортируем первую половину по возрастанию
        bitonicSortRecursive(arr, low, k, true);
        
        // Сортируем вторую половину по убыванию
        bitonicSortRecursive(arr, low + k, k, false);
        
        // Объединяем всю последовательность в нужном направлении
        bitonicMerge(arr, low, cnt, dir);
    }
}

void bitonicMerge(std::vector<int>& arr, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            compareAndSwap(arr, i, i + k, dir);
        }
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

void compareAndSwap(std::vector<int>& arr, int i, int j, bool dir) {
    if ((arr[i] > arr[j]) == dir) {
        std::swap(arr[i], arr[j]);
    }
}

void lsdRadixSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    
    // Находим максимальное число для определения количества разрядов
    int maxNum = getMax(arr);
    
    // Выполняем counting sort для каждого разряда
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

void countingSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);
    
    // Подсчитываем количество вхождений каждой цифры
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Изменяем count[i] так, чтобы он содержал позицию
    // этой цифры в output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Строим выходной массив
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Копируем выходной массив в arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int getMax(const std::vector<int>& arr) {
    int maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}