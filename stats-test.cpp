#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
#include <cmath>
//All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
TEST_CASE("when inputs are not NaN then reports average, minimum and maximum of the data") 
{
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    double epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("when the input is empty array then average, minimum and maximum are all NaN") 
{
    auto computedStats = Statistics::ComputeStatistics({});
    REQUIRE(std::isnan(computedStats.average));
    REQUIRE(std::isnan(computedStats.max));
    REQUIRE(std::isnan(computedStats.min));   
}
/*Having invalid data is acceptable to a certain limit*/
TEST_CASE("when input contains NaN input and count of Nan is less than not NaN count then reports average, minimum and maximum for array removed NaN") 
{
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9,nan(""), 3.2, 4.5,nan("")});
    double epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}
/*Too much of invalid data*/
TEST_CASE("when an array contains NaN input greater than or equal to numbers, then average, minimum and maximum are all NaN") 
{
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9,nan(""), nan(""), 4.5,nan(""),nan(""),nan("")});
    REQUIRE(std::isnan(computedStats.average));
    REQUIRE(std::isnan(computedStats.max));
    REQUIRE(std::isnan(computedStats.min));   
}
