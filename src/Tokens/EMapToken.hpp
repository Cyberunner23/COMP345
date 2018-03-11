
#pragma once

#include "Tokens.hpp"

#include <QTextStream>

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

inline std::string mapTokenStr(const Token<EMapToken>& token)
{
    std::string str;

    switch (token.kind)
    {
        case EMapToken::TROLL_LAIR:
            str = "TROLL_LAIR";
            break;
        case EMapToken::FORTRESS:
            str = "FORTRESS";
            break;
        case EMapToken::MOUNTAIN:
            str = "MOUNTAIN";
            break;
        case EMapToken::ENCAMPMENT:
            str = "ENCAMPMENT";
            break;
        case EMapToken::HOLES_IN_GROUND:
            str = "HOLES_IN_GROUND";
            break;
        case EMapToken::HERO:
            str = "HERO";
            break;
        case EMapToken::DRAGON:
            str = "DRAGON";
            break;
        case EMapToken::NONE:
            str = "";
            break;
        default:
            str = "";
            break;
    }

    return str;
}

inline QTextStream &operator<<(QTextStream &os, const Token<EMapToken>& token)
{

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
            os << "";
            break;
    }

    return os;
}
