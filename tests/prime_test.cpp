#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/prime.hpp"

Factorizer f;

// ── primeFactors ──────────────────────────────────────────────

TEST_CASE("Numbers <= 1 return empty list", "[primeFactors]")
{
    REQUIRE(f.primeFactors(1).empty());
    REQUIRE(f.primeFactors(0).empty());
    REQUIRE(f.primeFactors(-5).empty());
}

TEST_CASE("Prime number returns only itself", "[primeFactors]")
{
    REQUIRE(f.primeFactors(2)  == std::vector<int>{2});
    REQUIRE(f.primeFactors(17) == std::vector<int>{17});
}

TEST_CASE("Composite numbers return correct factors", "[primeFactors]")
{
    REQUIRE(f.primeFactors(9)   == std::vector<int>{3, 3});
    REQUIRE(f.primeFactors(10)  == std::vector<int>{2, 5});
    REQUIRE(f.primeFactors(24)  == std::vector<int>{2, 2, 2, 3});
    REQUIRE(f.primeFactors(35)  == std::vector<int>{5, 7});
    REQUIRE(f.primeFactors(100) == std::vector<int>{2, 2, 5, 5});
}

// ── isPrime ───────────────────────────────────────────────────

TEST_CASE("isPrime returns correct results", "[isPrime]")
{
    REQUIRE(f.isPrime(2)  == true);
    REQUIRE(f.isPrime(7)  == true);
    REQUIRE(f.isPrime(17) == true);
    REQUIRE(f.isPrime(1)  == false);
    REQUIRE(f.isPrime(9)  == false);
    REQUIRE(f.isPrime(18) == false);
}

// ── isComposite ───────────────────────────────────────────────

TEST_CASE("isComposite returns correct results", "[isComposite]")
{
    REQUIRE(f.isComposite(9)  == true);
    REQUIRE(f.isComposite(24) == true);
    REQUIRE(f.isComposite(1)  == false);
    REQUIRE(f.isComposite(7)  == false);
}

// ── reduce ────────────────────────────────────────────────────

TEST_CASE("reduce simplifies fractions correctly", "[reduce]")
{
    REQUIRE(f.reduce(12, 26)  == "6/13");
    REQUIRE(f.reduce(100, 75) == "4/3");
    REQUIRE(f.reduce(3, 7)    == "3/7");
}

TEST_CASE("reduce handles zero denominator", "[reduce]")
{
    REQUIRE(f.reduce(5, 0) == "undefined");
}