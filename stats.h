#include <vector>
#include <cmath>

struct Stats
{
    double average;
    double max;
    double min;
};
namespace Statistics {
    Stats ComputeStatistics(const std::vector<double> &);
}
