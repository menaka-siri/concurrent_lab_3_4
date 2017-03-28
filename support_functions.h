//
// Created by Siri on 3/29/2017.
//
//Source: http://www.softwareandfinance.com/CPP/MeanVarianceStdDevi.html

#include <iostream>
#include <algorithm>
#include <time.h>

class StatisticCalc
{

private:

    int max = 100000;
    double *value ;
    double mean ;

public:

    int setValues(double *p, int count)
    {
        value = new double[count];

        if(count > max)
            return -1;

        max = count;

        for(int i = 0; i < count; i++)
            value[i] = p[i];
        return 0;
    }

    double calculateMean()
    {
        double sum = 0;
        for(int i = 0; i < max; i++)
            sum += value[i];
        return (sum / max);
    }

    double calculateSum()
    {
        double sum = 0;
        for(int i = 0; i < max; i++)
            sum += value[i];
        return (sum);
    }

    double calculateVariane()
    {
        mean = calculateMean();

        double temp = 0;
        for(int i = 0; i < max; i++)
        {
            temp += (value[i] - mean) * (value[i] - mean) ;
        }
        return temp / max;
    }

    double calculateSampleVariane()
    {
        mean = calculateMean();

        double temp = 0;
        for(int i = 0; i < max; i++)
        {
            temp += (value[i] - mean) * (value[i] - mean) ;
        }
        return temp / (max - 1);
    }


    double getStandardDeviation()
    {
        return sqrt(calculateVariane());
    }

    double getSampleStandardDeviation()
    {
        return sqrt(calculateSampleVariane());
    }

};
