#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>
//All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
TEST_CASE("reports average, minimum and maximum") 
{
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    double epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") 
{
    auto computedStats = Statistics::ComputeStatistics({});
    REQUIRE(std::isnan(computedStats.average));
    REQUIRE(std::isnan(computedStats.max));
    REQUIRE(std::isnan(computedStats.min));   
}

TEST_CASE("reports average, minimum and maximum for array containing NaN input") 
{
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9,nan(""), 3.2, 4.5,nan("")});
    double epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for an array containing NaN input greater than or equal to numbers") 
{
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9,nan(""), nan(""), 4.5,nan(""),nan(""),nan("")});
    REQUIRE(std::isnan(computedStats.average));
    REQUIRE(std::isnan(computedStats.max));
    REQUIRE(std::isnan(computedStats.min));   
}
