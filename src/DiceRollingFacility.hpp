
#pragma once

#include <random>
#include <vector>

static const unsigned int faces[] = {0, 0, 0, 1, 2, 3};

//! Class for the dice rolling facility.
class DiceRollingFacility
{

public:

    //! Constructor for the dice rolling facility.
    DiceRollingFacility();

    //! \brief Get dice values.

    //! Returns a set of numbers from the dice.
    //! \param numVals How many numbers to return.
    //! \return Vector of numbers from the dice.
    std::vector<unsigned int> getDiceValue (unsigned int numVals);

    //! Gets the percentage that each number on the dice shows up.
    //! \return Vector of the percentage values, index = value on the dice
    std::vector<float> getRollPercentage();

private:

    std::vector<unsigned int> _counts;
    std::random_device _randomDevice;
    std::mt19937 _randAlgo;
    std::uniform_int_distribution<unsigned int> _uniformDistribution;
};
