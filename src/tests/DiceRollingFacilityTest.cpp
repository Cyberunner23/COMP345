
#include <iostream>

#include "../DiceRollingFacility.hpp"


int main(int argc, char** argv)
{



    //Check #1 Check if user can roll a dice
    {
        DiceRollingFacility drf;
        std::cout << "Rolling a dice, got value " << drf.getDiceValue(1)[0] << std::endl;
        std::cout << std::endl;
    }

    { //Check #2 Check if the container returns the right number of values.
        DiceRollingFacility drf;

        std::cout << "Testing if the container return the right amount of numbers..." << std::endl;

        bool passes = drf.getDiceValue(1).size() == 1;
        passes &= drf.getDiceValue(2).size() == 2;
        passes &= drf.getDiceValue(3).size() == 3;

        std::cout << (passes ? "PASS" : "FAIL") << std::endl;
        std::cout << std::endl;
    }

    {//Check #3 Check if no value is outside 1 to 6

        DiceRollingFacility drf;

        std::cout << "Checking if the generated values are all in between 0 and 3" << std::endl;

        std::vector<unsigned int> values;
        for (unsigned int i = 0; i < 1000; i++)
        {
            auto value = drf.getDiceValue(10);
            values.insert(values.end(), value.begin(), value.end());
        }

        bool passes = true;
        for (unsigned int value : values)
        {
            passes &= value >=0 && value <= 3;
        }

        std::cout << (passes ? "PASS" : "FAIL") <<std::endl;
        std::cout << std::endl;

    }

    {//Check #4 and #5 There should be an equal share of of 1-6 values returned

        DiceRollingFacility drf;

        drf.getDiceValue(10000);

        std::cout << "The following is the percentage that each value showed up, they should be roughly the same except 0 values since there are three 0's on the dice." << std::endl;
        std::vector<float> percentages = drf.getRollPercentage();
        for (unsigned int i = 0; i <= 3; i++)
        {
            std::cout << "[" << i << "]: " << percentages[i] << "%" << std::endl;
        }
        std::cout << std::endl;

    }


}
