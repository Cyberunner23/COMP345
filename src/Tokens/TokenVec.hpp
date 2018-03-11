
#pragma once

#include <algorithm>
#include <vector>
#include <memory>
#include <random>

template <typename TokenType>
class TokenVec
{

public:

    //modifies value param
    bool take(const TokenType& valueKind, std::unique_ptr<TokenType>& value)
    {
        bool found = false;
        unsigned int foundIndex = 0;

        for (unsigned int i = 0; i < _vec.size(); i++)
        {
            if (*_vec[i] == valueKind)
            {
                found = true;
                foundIndex = i;
                break;
            }
        }

        if (!found)
        {
            return false;
        }

        value = std::move(_vec[foundIndex]);
        eraseAndShrink(foundIndex);

        return true;
    }

    bool take(unsigned int index, std::unique_ptr<TokenType>& value)
    {
        if (index >= _vec.size())
        {
            return false;
        }

        value = std::move(_vec[index]);
        eraseAndShrink(index);

        return true;
    }


    //invalidates value param
    void place_back(std::unique_ptr<TokenType>& value)
    {
        value->isFaceUp = true;
        _vec.push_back(std::move(value));
    }

    void place_back(std::unique_ptr<TokenType>&& value)
    {
        value->isFaceUp = true;
        _vec.push_back(std::move(value));
    }

    unsigned long size()
    {
        return _vec.size();
    }

    void randomize()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(_vec.begin(), _vec.end(), g);
    }


    const std::unique_ptr<TokenType>& operator[](unsigned int index) const
    {
        return _vec[index];
    }

private:

    std::vector<std::unique_ptr<TokenType>> _vec;

    void eraseAndShrink(unsigned int index)
    {
        _vec.erase(_vec.begin() + index);
        std::vector<std::unique_ptr<TokenType>>(std::move_iterator(_vec.begin()), std::move_iterator(_vec.end())).swap(_vec);
    }

};
