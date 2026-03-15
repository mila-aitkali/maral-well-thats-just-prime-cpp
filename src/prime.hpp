#pragma once
#include <vector>
#include <string>
 
class Factorizer
{
public:
    std::vector<int> primeFactors(int n) const;
    bool isPrime(int n) const;
    bool isComposite(int n) const;
    std::string reduce(int numerator, int denominator) const;
};