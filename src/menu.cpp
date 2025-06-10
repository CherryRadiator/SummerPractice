#include <iostream>
#include <limits>
#include "bitonicSort.h"
#include "lsdSort.h"
#include "fileIO.h"



void menu() {
  while (true) {
    std::cout << "Welcome to the (Almost) Best Program in the World!" << std::endl;
    std::cout << "Please choose an option:" << std::endl;
    std::cout << "1. Bitonic sort" << std::endl;
    std::cout << "2. LSD-sort" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    int sortChoice;
    std::cin >> sortChoice;
    while (std::cin.fail() || sortChoice < 1 || sortChoice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 3: ";
        std::cin >> sortChoice;
    }
    switch (sortChoice) {
        case 1:
            bitonicSortConfiguration();
            break;
        case 2:
            lsdSortConfiguration();
            break;
        case 3:
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            exit(0);
    }
  }
}

void bitonicSortConfiguration() {
  std::cout << "Bitonic sort selected." << std::endl;
  std::string inputFileName, outputFileName;
  std::cout << "Enter the input file name: ";
  std::cin >> inputFileName;
  // TODO: Implement file reading logic here (see fileIO.h)
  std::cout << "Enter the output file name: ";
  std::cin >> outputFileName;
  // TODO: Implement file writing logic here (see fileIO.h)
  std::cout << "Sorting using Bitonic sort..." << std::endl;
  // TODO: Call the sorting and file IO functions here
  output();
}

void lsdSortConfiguration() {
  std::cout << "LSD-sort selected." << std::endl;
  std::string inputFileName, outputFileName;
  std::cout << "Enter the input file name: ";
  std::cin >> inputFileName;
  // TODO: Implement file reading logic here (see fileIO.h)
  std::cout << "Enter the output file name: ";
  std::cin >> outputFileName;
  // TODO: Implement file writing logic here (see fileIO.h)
  std::cout << "Sorting using LSD-sort..." << std::endl;
  // TODO: Call the sorting and file IO functions here
  output();
}

void output() {
  // TODO: Implement result display logic here
}