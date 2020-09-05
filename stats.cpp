#include <bits/stdc++.h>
#include "stats.h"
int getNaNcount(const std::vector<double>& numericaldata)
{   int count=0;
    for (auto& ptr : numericaldata) 
        { 
        if(std::isnan(ptr))
            count++;
        }
    return count;
}

std::vector<double> getNaNremoveddata(numericaldata)
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
    double max = INT_MIN;
    for(double itr : data)
    {
        if(itr>max)
            max = itr;
    }
    return max;
}

double findMin(const std::vector<double>& data)
{
    double min = INT_MAX;
    for(double itr : data)
    {
        if(itr<min)
            min = itr;
    }
    return min;
}

Stats Statistics:: ComputeStatistics(const std::vector<double>& numericaldata) 
{
    //Implement statistics here
    Stats stats;
    int nancount=0;
    int numbercount=0;
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

