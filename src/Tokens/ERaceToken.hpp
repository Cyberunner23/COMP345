
#pragma once

#include <string>

#include <QTextStream>


#include "Tokens.hpp"
#include "ERaceBanner.hpp"

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

inline ERaceToken raceBannerToRaceTokenType(ERaceBanner banner)
{
    switch(banner)
    {
        case ERaceBanner::AMAZON:
            return ERaceToken::AMAZON;
        case ERaceBanner::DWARVE:
            return ERaceToken::DWARVE;
        case ERaceBanner::WIZARD:
            return ERaceToken::WIZARD;
        case ERaceBanner::SKELETON:
            return ERaceToken::SKELETON;
        case ERaceBanner::HALFLING:
            return ERaceToken::HALFLING;
        case ERaceBanner::GHOUL:
            return ERaceToken::GHOUL;
        case ERaceBanner::ELVE:
            return ERaceToken::ELVE;
        case ERaceBanner::RATMEN:
            return ERaceToken::RATMEN;
        case ERaceBanner::GIANT:
            return ERaceToken::GIANT;
        case ERaceBanner::SORCERER:
            return ERaceToken::SORCERER;
        case ERaceBanner::HUMAN:
            return ERaceToken::HUMAN;
        case ERaceBanner::ORC:
            return ERaceToken::ORC;
        case ERaceBanner::TROLL:
            return ERaceToken::TROLL;
        case ERaceBanner::TRITON:
            return ERaceToken::TRITON;
        default:
            return ERaceToken::LOST_TRIBE;
    }
}

inline QTextStream &operator<<(QTextStream &os, const Token<ERaceToken>& token)
{

    os << (token.isFaceUp ? "[U]" : "[D]");;

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

/*inline std::ostream &operator<<(std::ostream &os, const Token<ERaceToken>& token) {

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
}*/
