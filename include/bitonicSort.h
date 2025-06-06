#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

std::vector<long int> intBitonicSortRecursion(std::vector<long int> vector);
void bitonicMerge(std::vector<long int>& arr, int low, int cnt, bool dir);
void bitonicSortRec(std::vector<long int>& arr, int low, int cnt, bool dir);

std::vector<long double> doubleBitonicSort(std::vector<long double> vector);