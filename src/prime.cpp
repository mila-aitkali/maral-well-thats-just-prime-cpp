#include "prime.hpp"

std::vector<int> Factorizer::primeFactors(int n)
{
    std::vector<int> factors;

    // Return empty list for numbers <= 1
    if (n <= 1)
        return factors;

    // Divide out all 2s first
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    // Check odd numbers from 3 up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is still > 1, it is a prime factor itself
    if (n > 1)
        factors.push_back(n);

    return factors;
}

bool Factorizer::isPrime(int n)
{
    if (n <= 1) return false;
    std::vector<int> factors = primeFactors(n);
    return factors.size() == 1 && factors[0] == n;
}

bool Factorizer::isComposite(int n)
{
    if (n <= 1) return false;
    return !isPrime(n);
}

std::string Factorizer::reduce(int numerator, int denominator)
{
    if (denominator == 0)
        return "undefined";

    std::vector<int> numFactors = primeFactors(numerator);
    std::vector<int> denFactors = primeFactors(denominator);

    for (int factor : numFactors)
    {
        for (int i = 0; i < (int)denFactors.size(); i++)
        {
            if (denFactors[i] == factor)
            {
                numerator   /= factor;
                denominator /= factor;
                denFactors.erase(denFactors.begin() + i);
                break;
            }
        }
    }

    return std::to_string(numerator) + "/" + std::to_string(denominator);
}