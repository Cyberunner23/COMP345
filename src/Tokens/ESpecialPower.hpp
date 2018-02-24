
#pragma once

#include <string>

#include "Tokens.hpp"

enum class ESpecialPower
{
    ALCHEMIST,
    BERSERK,
    BIVOUACKING,
    COMMANDO,
    DIPLOMAT,
    DRAGON_MASTER,
    FLYING,
    FOREST,
    FORTIFIED,
    HEROIC,
    HILL,
    MERCHANT,
    MOUNTED,
    PILLAGING,
    SEAFARING,
    SPIRIT,
    STOUT,
    SWAMP,
    UNDERWORLD,
    WEALTHY,
    BLANK
};

typedef Token<ESpecialPower> SpecialPower;

inline std::ostream &operator<<(std::ostream &os, const Token<ESpecialPower>& token)
{
    std::string status = token.isFaceUp ? "[U]" : "[D]";
    os << status;

    switch (token.kind)
    {
        case ESpecialPower::ALCHEMIST:
            os << "ALCHEMIST";
            break;
        case ESpecialPower::BERSERK:
            os << "BERSERK";
            break;
        case ESpecialPower::BIVOUACKING:
            os << "BIVOUACKING";
            break;
        case ESpecialPower::COMMANDO:
            os << "COMMANDO";
            break;
        case ESpecialPower::DIPLOMAT:
            os << "DIPLOMAT";
            break;
        case ESpecialPower::DRAGON_MASTER:
            os << "DRAGON_MASTER";
            break;
        case ESpecialPower::FLYING:
            os << "FLYING";
            break;
        case ESpecialPower::FOREST:
            os << "FOREST";
            break;
        case ESpecialPower::FORTIFIED:
            os << "FORTIFIED";
            break;
        case ESpecialPower::HEROIC:
            os << "HEROIC";
            break;
        case ESpecialPower::HILL:
            os << "HILL";
            break;
        case ESpecialPower::MERCHANT:
            os << "MERCHANT";
            break;
        case ESpecialPower::MOUNTED:
            os << "MOUNTED";
            break;
        case ESpecialPower::PILLAGING:
            os << "PILLAGING";
            break;
        case ESpecialPower::SEAFARING:
            os << "SEAFARING";
            break;
        case ESpecialPower::SPIRIT:
            os << "SPIRIT";
            break;
        case ESpecialPower::STOUT:
            os << "STOUT";
            break;
        case ESpecialPower::SWAMP:
            os << "SWAMP";
            break;
        case ESpecialPower::UNDERWORLD:
            os << "UNDERWORLD";
            break;
        case ESpecialPower::WEALTHY:
            os << "WEALTHY";
            break;
        case ESpecialPower::BLANK:
            os << "BLANK";
            break;
    }

    return os;
}

