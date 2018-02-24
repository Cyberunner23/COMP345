
#pragma once

#include <string>

#include "Tokens.hpp"

enum class ERaceToken
{
    AMAZON,
    DWARVE,
    WIZARD,
    SKELETON,
    HALFLING,
    GHOUL,
    ELVE,
    RATMEN,
    GIANT,
    SORCERER,
    HUMAN,
    ORC,
    TROLL,
    TRITON,
    LOST_TRIBE
};

typedef Token<ERaceToken> RaceToken;

inline std::ostream &operator<<(std::ostream &os, const Token<ERaceToken>& token) {

    std::string status = token.isFaceUp ? "[U]" : "[D]";
    os << status;

    switch (token.kind)
    {
        case ERaceToken::AMAZON:
            os << "AMAZON";
            break;
        case ERaceToken::DWARVE:
            os << "DWARVE";
            break;
        case ERaceToken::WIZARD:
            os << "WIZARD";
            break;
        case ERaceToken::SKELETON:
            os << "SKELETON";
            break;
        case ERaceToken::HALFLING:
            os << "HALFLING";
            break;
        case ERaceToken::GHOUL:
            os << "GHOUL";
            break;
        case ERaceToken::ELVE:
            os << "ELVE";
            break;
        case ERaceToken::RATMEN:
            os << "RATMEN";
            break;
        case ERaceToken::GIANT:
            os << "GIANT";
            break;
        case ERaceToken::SORCERER:
            os << "SORCERER";
            break;
        case ERaceToken::HUMAN:
            os << "HUMAN";
            break;
        case ERaceToken::ORC:
            os << "ORC";
            break;
        case ERaceToken::TROLL:
            os << "TROLL";
            break;
        case ERaceToken::TRITON:
            os << "TRITON";
            break;
        case ERaceToken::LOST_TRIBE:
            os << "LOST TRIBE";
            break;
    }

    return os;
}
