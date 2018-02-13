
#include <iostream>

#include "DiceRollingFacility.hpp"

DiceRollingFacility::DiceRollingFacility()
        : _counts(4)
        , _randAlgo(_randomDevice())
        , _uniformDistribution(0, 5)
{}

std::vector<unsigned int> DiceRollingFacility::getDiceValue (unsigned int numVals)
{
    std::vector<unsigned int> values;
    for (unsigned int i = 0; i < numVals; i++)
    {
        unsigned int val = faces[_uniformDistribution(_randAlgo)];
        values.push_back(val);
        ++_counts[val];
    }

    return values;
}

std::vector<float> DiceRollingFacility::getRollPercentage()
{
    unsigned int totalRolls = 0;
    for (unsigned int count : _counts)
    {
        totalRolls += count;
    }

    std::vector<float> percentages;
    for (unsigned int count : _counts)
    {
        percentages.push_back((float)count / totalRolls * 100);
    }

    return percentages;
}

