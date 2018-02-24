
#pragma once

#include "Tokens.hpp"

enum class EMapToken
{
    TROLL_LAIR,
    FORTRESS,
    MOUNTAIN,
    ENCAMPMENT,
    HOLES_IN_GROUND,
    HERO,
    DRAGON,
    NONE
};

typedef Token<EMapToken> MapToken;

inline std::ostream &operator<<(std::ostream &os, const Token<EMapToken>& token) {
    switch (token.kind)
    {
        case EMapToken::TROLL_LAIR:
            os << "TROLL_LAIR";
            break;
        case EMapToken::FORTRESS:
            os << "FORTRESS";
            break;
        case EMapToken::MOUNTAIN:
            os << "MOUNTAIN";
            break;
        case EMapToken::ENCAMPMENT:
            os << "ENCAMPMENT";
            break;
        case EMapToken::HOLES_IN_GROUND:
            os << "HOLES_IN_GROUND";
            break;
        case EMapToken::HERO:
            os << "HERO";
            break;
        case EMapToken::DRAGON:
            os << "DRAGON";
            break;
        case EMapToken::NONE:
            os << "NONE";
            break;
    }

    return os;
}