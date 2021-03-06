#include <bits/stdc++.h>
#include "stats.h"
int getNaNcount(const std::vector<double>& numericaldata)
{   
    int count=0;
    for (auto& ptr : numericaldata) 
        { 
        if(std::isnan(ptr))
            count++;
        }
    return count;
}

std::vector<double> getNaNremoveddata(const std::vector<double>& numericaldata)
{
        std::vector<double> nanremoved;
            for(double num : numericaldata)
            {
                if(!std::isnan(num))
                    nanremoved.push_back(num);
            }
    return nanremoved;
}
double calculateAverage(const std::vector<double>& data)
{
    double sum = 0;
    int noofdata = data.size();
    for(double itr : data)
        sum = sum + itr;
    return sum/noofdata;
}

double findMax(const std::vector<double>& data)
{
    return *max_element(data.begin(), data.end());
}

double findMin(const std::vector<double>& data)
{
    return *min_element(data.begin(), data.end());
}

Stats Statistics:: ComputeStatistics(const std::vector<double>& numericaldata) 
{
    //Implement statistics here
    Stats stats;
    if(numericaldata.size()==0)
    {
        stats.average = std::nan("");
        stats.max = std::nan("");
        stats.min = std::nan("");
        return stats;
    }
    else
    {
        int nancount = getNaNcount(numericaldata);
        int numbercount = numericaldata.size() - nancount;
        if(nancount>=numbercount)
        {
            stats.average = std::nan("");
            stats.max = std::nan("");
            stats.min = std::nan("");
        }
        else
        {
            std::vector<double> nanremoveddata = getNaNremoveddata(numericaldata);
            stats.average = calculateAverage(nanremoveddata);
            stats.max = findMax(nanremoveddata);
            stats.min = findMin(nanremoveddata);
        }
        return stats;
    }
    
}

