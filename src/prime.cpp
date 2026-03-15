#include "prime.hpp"

std::vector<int> Factorizer::primeFactors(int n) const
{
    std::vector<int> factors;

    if (n <= 1)
        return factors;

    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
        factors.push_back(n);

    return factors;
}

bool Factorizer::isPrime(int n) const
{
    if (n <= 1) return false;
    std::vector<int> factors = primeFactors(n);
    return factors.size() == 1 && factors[0] == n;
}

bool Factorizer::isComposite(int n) const
{
    if (n <= 1) return false;
    return !isPrime(n);
}

std::string Factorizer::reduce(int numerator, int denominator) const
{
    if (denominator == 0)
        return "undefined";

    if (numerator == 0)
        return "0";

    // Strip sign, reapply at the end
    bool negative = (numerator < 0) != (denominator < 0);
    if (numerator < 0)   numerator   = -numerator;
    if (denominator < 0) denominator = -denominator;

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

    if (negative) numerator = -numerator;

    if (denominator == 1)
        return std::to_string(numerator);

    return std::to_string(numerator) + "/" + std::to_string(denominator);
}