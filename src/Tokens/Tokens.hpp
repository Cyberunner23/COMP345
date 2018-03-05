
#pragma once

#include <iostream>
#include <vector>
#include <memory>

template<typename TokenType>
struct Token
{
    static_assert(std::is_enum<TokenType>::value, "Tokens must be enums!");

    Token() {}
    Token(TokenType kind, unsigned int value = 0, bool isFaceUp = true)
            : kind(kind)
            , isFaceUp(isFaceUp)
            , value(value)
    {}

    bool operator==(const Token<TokenType>& token) const
    {
        return kind == token.kind;
    }

    TokenType kind;
    bool isFaceUp;
    unsigned int value; //Value found on the race banner and the special power token
};
