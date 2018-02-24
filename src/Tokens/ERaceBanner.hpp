
#pragma once

#include <string>

#include "Tokens.hpp"

enum class ERaceBanner
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
    TRITON
};

typedef Token<ERaceBanner> RaceBanner;

inline std::ostream &operator<<(std::ostream &os, const Token<ERaceBanner>& token) {

    std::string status = token.isFaceUp ? "[U]" : "[D]";
    os << status;

    switch (token.kind)
    {
        case ERaceBanner::AMAZON:
            os << "AMAZON";
            break;
        case ERaceBanner::DWARVE:
            os << "DWARVE";
            break;
        case ERaceBanner::WIZARD:
            os << "WIZARD";
            break;
        case ERaceBanner::SKELETON:
            os << "SKELETON";
            break;
        case ERaceBanner::HALFLING:
            os << "HALFLING";
            break;
        case ERaceBanner::GHOUL:
            os << "GHOUL";
            break;
        case ERaceBanner::ELVE:
            os << "ELVE";
            break;
        case ERaceBanner::RATMEN:
            os << "RATMEN";
            break;
        case ERaceBanner::GIANT:
            os << "GIANT";
            break;
        case ERaceBanner::SORCERER:
            os << "SORCERER";
            break;
        case ERaceBanner::HUMAN:
            os << "HUMAN";
            break;
        case ERaceBanner::ORC:
            os << "ORC";
            break;
        case ERaceBanner::TROLL:
            os << "TROLL";
            break;
        case ERaceBanner::TRITON:
            os << "TRITON";
            break;
    }

    return os;
}
