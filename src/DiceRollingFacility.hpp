
#pragma once

#include <random>
#include <vector>

static const unsigned int faces[] = {0, 0, 0, 1, 2, 3};

class DiceRollingFacility
{

public:

    DiceRollingFacility();

    std::vector<unsigned int> getDiceValue (unsigned int numVals);
    std::vector<float> getRollPercentage();

private:

    std::vector<unsigned int> _counts;
    std::random_device _randomDevice;
    std::mt19937 _randAlgo;
    std::uniform_int_distribution<unsigned int> _uniformDistribution;
};
