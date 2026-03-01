#include <iostream>
#include <vector>
#include "src/prime.hpp"
#include <iostream>
#include <vector>


void printFactors(const std::vector<int>& factors)
{
    std::cout << "[";
    for (int i = 0; i < (int)factors.size(); i++)
        std::cout << factors[i] << (i + 1 < (int)factors.size() ? ", " : "");
    std::cout << "]";
}

int main()
{
    Factorizer factorizer;
    int number;

    // --- Prime Factors ---
    std::cout << "Enter a number to find its prime factors: ";
    std::cin >> number;
    std::cout << "factorizer.primeFactors(" << number << "); // will return the Vector ";
    printFactors(factorizer.primeFactors(number));
    std::cout << "\n";

    // --- Is It Prime? ---
    std::cout << "\nEnter a number to check if it is prime: ";
    std::cin >> number;
    std::cout << "factorizer.isPrime(" << number << "); // will return "
              << (factorizer.isPrime(number) ? "true" : "false") << "\n";

    // --- Is It Composite? ---
    std::cout << "\nEnter a number to check if it is composite: ";
    std::cin >> number;
    std::cout << "factorizer.isComposite(" << number << "); // will return "
              << (factorizer.isComposite(number) ? "true" : "false") << "\n";

    // --- Reduce ---
    int numerator, denominator;
    std::cout << "\nEnter a numerator: ";
    std::cin >> numerator;
    std::cout << "Enter a denominator: ";
    std::cin >> denominator;
    std::cout << "factorizer.reduce(" << numerator << ", " << denominator << "); // will return "
              << factorizer.reduce(numerator, denominator) << "\n";

    return 0;
}