
#pragma once

#include <iostream>
#include <memory>
#include <stack>
#include <vector>

template<const unsigned int minVal>
unsigned int getUserInput(unsigned int maxVal)
{
    static_assert(minVal > 0);

    std::cout << "Please enter a number between " << minVal << " and " << maxVal << "." << std::endl;

    bool isValid = false;
    unsigned int selection = 0;
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
            std::cout << "Please enter a number in between "<< minVal << "and " << maxVal << std::endl;
        }
    }
    while(!isValid);

    return selection;
}


template <typename TokenType>
std::unique_ptr<TokenType>&& stackRealPop(std::stack<std::unique_ptr<TokenType>>& stack)
{
    std::unique_ptr<TokenType> token = std::move(stack.top());
    stack.pop();
    return std::move(token);
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
    std::cout << "vec: " << vec[index]->value << std::endl;

    //Move out
    val = std::move(vec[index]);

    std::cout << "token: " << val->value << std::endl;

    //Shrink
    eraseAndShrink(vec, index);
}
