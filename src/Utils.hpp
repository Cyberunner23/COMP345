
#pragma once

#include <iostream>
#include <memory>
#include <stack>
#include <vector>


//! Gets user input in numerical form.
template<const int minVal>
int getUserInput(int maxVal)
{
    std::cout << "Please enter a number between " << minVal << " and " << maxVal << "." << std::endl;

    bool isValid = false;
    int selection = 0;
    do
    {

        while(!(std::cin >> selection)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a number between " << minVal << " and " << maxVal << "." << std::endl;
            continue;
        }

        if (selection >= minVal && selection <= maxVal)
        {
            isValid = true;
        }
        else
        {
            std::cout << "Please enter a number in between "<< minVal << " and " << maxVal << std::endl;
        }
    }
    while(!isValid);

    return selection;
}


template <typename Type>
void eraseAndShrink(std::vector<Type>& vec, unsigned int index)
{
    vec.erase(vec.begin() + index);
    std::vector<Type>(std::move_iterator(vec.begin()), std::move_iterator(vec.end())).swap(vec);
}

template <typename TokenType>
void moveOutToken(std::unique_ptr<TokenType>& val, std::vector<std::unique_ptr<TokenType>>& vec, unsigned int index)
{
    //Move out
    val = std::move(vec[index]);

    //Shrink
    eraseAndShrink(vec, index);
}
