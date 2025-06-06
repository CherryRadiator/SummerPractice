#include "../include/bitonicSort.h"

std::vector<long int> intBitonicSortRecursion(std::vector<long int> inputVector) {
  int originalSize = inputVector.size();
  int nextPowerOfTwo = pow(2, ceil(log2(originalSize)));
  inputVector.resize(nextPowerOfTwo, 0);

  if (inputVector.size() <= 1) {
    return inputVector;
  }

  auto compareAndSwap = [](std::vector<long int>& arr, int index1, int index2, bool direction) {
    if (direction == (arr[index1] > arr[index2])) {
      std::swap(arr[index1], arr[index2]);
    }
  };

  std::function<void(std::vector<long int>&, int, int, bool)> bitonicMerge;
  std::function<void(std::vector<long int>&, int, int, bool)> bitonicSortRecursive;

  bitonicMerge = [&](std::vector<long int>& arr, int startIdx, int count, bool direction) {
    if (count > 1) {
      int half = count / 2;
      for (int i = startIdx; i < startIdx + half; i++) {
        compareAndSwap(arr, i, i + half, direction);
      }
      bitonicMerge(arr, startIdx, half, direction);
      bitonicMerge(arr, startIdx + half, half, direction);
    }
  };

  bitonicSortRecursive = [&](std::vector<long int>& arr, int startIdx, int count, bool direction) {
    if (count > 1) {
      int half = count / 2;
      bitonicSortRecursive(arr, startIdx, half, true);
      bitonicSortRecursive(arr, startIdx + half, half, false);
      bitonicMerge(arr, startIdx, count, direction);
    }
  };

  bitonicSortRecursive(inputVector, 0, inputVector.size(), true);
  return inputVector;
}