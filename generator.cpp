#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>

class BigIntGenerator {
private:
    std::mt19937_64 rng;
    std::uniform_int_distribution<int> digit_dist;
    
public:
    BigIntGenerator() : rng(std::chrono::steady_clock::now().time_since_epoch().count()),
                       digit_dist(0, 9) {}
    
    // Generate a random big integer as string with specified number of digits
    std::string generateBigInt(int numDigits) {
        if (numDigits <= 0) return "0";
        
        std::string result;
        result.reserve(numDigits);
        
        // First digit shouldn't be 0 (except for single digit numbers)
        if (numDigits == 1) {
            result += std::to_string(digit_dist(rng));
        } else {
            std::uniform_int_distribution<int> first_digit_dist(1, 9);
            result += std::to_string(first_digit_dist(rng));
            
            // Generate remaining digits
            for (int i = 1; i < numDigits; ++i) {
                result += std::to_string(digit_dist(rng));
            }
        }
        
        return result;
    }
    
    // Generate big integers using mathematical operations (powers, factorials, etc.)
    std::string generatePowerBigInt(int base, int exponent) {
        if (exponent == 0) return "1";
        if (exponent == 1) return std::to_string(base);
        
        // Simple string multiplication for demonstration
        std::string result = "1";
        for (int i = 0; i < exponent; ++i) {
            result = multiplyByInt(result, base);
        }
        return result;
    }
    
private:
    // Helper function to multiply a big integer (as string) by a regular integer
    std::string multiplyByInt(const std::string& num, int multiplier) {
        if (multiplier == 0) return "0";
        
        std::string result;
        int carry = 0;
        
        for (int i = num.length() - 1; i >= 0; --i) {
            int digit = (num[i] - '0') * multiplier + carry;
            result = std::to_string(digit % 10) + result;
            carry = digit / 10;
        }
        
        while (carry > 0) {
            result = std::to_string(carry % 10) + result;
            carry /= 10;
        }
        
        return result;
    }
};

void generateMassiveBigIntegers(const std::string& filename, 
                               long long count = 1000000,  // 1 million numbers
                               int minDigits = 50,         // minimum 50 digits
                               int maxDigits = 1000) {     // up to 1000 digits
    
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    BigIntGenerator generator;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> size_dist(minDigits, maxDigits);
    
    std::cout << "Generating " << count << " big integers..." << std::endl;
    std::cout << "Digit range: " << minDigits << " - " << maxDigits << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (long long i = 0; i < count; ++i) {
        int numDigits = size_dist(gen);
        std::string bigInt;
        
        // Mix different generation methods
        if (i % 5 == 0) {
            // Generate powers (every 5th number)
            int base = 2 + (i % 97);  // Use various bases
            int exp = 10 + (i % 500); // Various exponents
            bigInt = generator.generatePowerBigInt(base, exp);
        } else {
            // Generate random big integers
            bigInt = generator.generateBigInt(numDigits);
        }
        
        // Write to file with newline
        file << bigInt << '\n';
        
        // Progress indicator
        if (i % 10 == 0) {
            std::cout << "Generated: " << i << " numbers" << std::endl;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    
    file.close();
    
    std::cout << "Completed! Generated " << count << " big integers in " 
              << duration.count() << " seconds" << std::endl;
    std::cout << "File: " << filename << std::endl;
}

// Alternative function for generating REALLY massive integers
void generateExtremelyBigIntegers(const std::string& filename,
                                 long long count = 100000,    // 100k numbers  
                                 int minDigits = 1000,        // minimum 1000 digits
                                 int maxDigits = 100000) {    // up to 100k digits each!
    
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    BigIntGenerator generator;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> size_dist(minDigits, maxDigits);
    
    std::cout << "Generating " << count << " EXTREMELY big integers..." << std::endl;
    std::cout << "Digit range: " << minDigits << " - " << maxDigits << std::endl;
    std::cout << "WARNING: This will create a VERY large file!" << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (long long i = 0; i < count; ++i) {
        int numDigits = size_dist(gen);
        std::string bigInt = generator.generateBigInt(numDigits);
        
        file << bigInt << '\n';
        
        if (i % 1000 == 0) {
            std::cout << "Generated: " << i << " numbers" << std::endl;
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    
    file.close();
    
    std::cout << "Completed! Generated " << count << " extremely big integers in " 
              << duration.count() << " seconds" << std::endl;
}

int main() {
    std::cout << "Big Integer Generator\n" << std::endl;
    
    // Option 1: Generate a lot of moderately big integers
    std::cout << "=== Option 1: Many moderately big integers ===" << std::endl;
    generateMassiveBigIntegers("big_integers.txt", 100000, 5, 10);
    
    std::cout << "\n=== Option 2: Fewer but extremely big integers ===" << std::endl;
    char choice;
    std::cout << "Generate extremely big integers (up to 100k digits each)? (y/n): ";
    std::cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        generateExtremelyBigIntegers("extreme_big_integers.txt", 10000, 5000, 50000);
    }
    
    return 0;
}