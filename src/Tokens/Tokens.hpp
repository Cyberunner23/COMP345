
#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "EVictoryCoin.hpp"

template<typename TokenType>
struct Token
{
    static_assert(std::is_enum<TokenType>::value, "Tokens must be enums!");

    Token() {}
    Token(TokenType kind, bool isFaceUp = true)
            : kind(kind)
            , isFaceUp(isFaceUp)
    {}

    bool operator==(const Token<TokenType>& token) const
    {
        return kind == token.kind;
    }

    TokenType kind;
    bool isFaceUp;
};

/*

//! MapToken: Environmental tokens that are initially placed on the map
enum class MapToken
{
    TROLL_LAIR,
    FORTRESS,
    MOUNTAIN,
    ENCAMPMENT,
    HOLES_IN_GROUND,
    HERO,
    DRAGON,
    NONE,
    EMPTY
};

//! RaceBanner: Banners representing the races
enum class RaceBanner
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
    EMPTY
};

//! RaceToken: Tokens Representing the races that can be deployed onto the map
enum class RaceToken
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
    LOST_TRIBE,
    EMPTY
};

//! SpecialPower: Special power that can be added to the race banner.
enum class SpecialPower
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
    BLANK,
    EMPTY
};

//! VictoryCoin: The cins that player can earn
enum class VictoryCoin
{
    VAL_1,
    VAL_3,
    VAL_5,
    VAL_10,
    EMPTY
};

//! \brief Gets the token as a printable string

//! Gets a printable string for a MapToken
//! \param token The token to be printed
//! \return String value of the token
inline std::string getTokenString(const MapToken& token)
{
    switch (token)
    {
        case MapToken::TROLL_LAIR:
            return "TROLL_LAIR";
        case MapToken::FORTRESS:
            return "FORTRESS";
        case MapToken::MOUNTAIN:
            return "MOUNTAIN";
        case MapToken::ENCAMPMENT:
            return "ENCAMPMENT";
        case MapToken::HOLES_IN_GROUND:
            return "HOLES_IN_GROUND";
        case MapToken::HERO:
            return "HERO";
        case MapToken::DRAGON:
            return "DRAGON";
        case MapToken::NONE:
            return "NONE";
        case MapToken::EMPTY:
            return "EMPTY";
    }
}

//! \brief Gets the token as a printable string

//! Gets a printable string for a RaceBanner
//! \param token The token to be printed
//! \return String value of the token
inline std::string getTokenString(const RaceBanner& token)
{
    switch (token)
    {
        case RaceBanner::AMAZON:
            return "AMAZON";
        case RaceBanner::DWARVE:
            return "DWARVE";
        case RaceBanner::WIZARD:
            return "WIZARD";
        case RaceBanner::SKELETON:
            return "SKELETON";
        case RaceBanner::HALFLING:
            return "HALFLING";
        case RaceBanner::GHOUL:
            return "GHOUL";
        case RaceBanner::ELVE:
            return "ELVE";
        case RaceBanner::RATMEN:
            return "RATMEN";
        case RaceBanner::GIANT:
            return "GIANT";
        case RaceBanner::SORCERER:
            return "SORCERER";
        case RaceBanner::HUMAN:
            return "HUMAN";
        case RaceBanner::ORC:
            return "ORC";
        case RaceBanner::TROLL:
            return "TROLL";
        case RaceBanner::TRITON:
            return "TRITON";
        case RaceBanner::EMPTY:
            return "EMPTY";
    }
}

//! \brief Gets the token as a printable string

//! Gets a printable string for a RaceToken
//! \param token The token to be printed
//! \return String value of the token
inline std::string getTokenString(const RaceToken& token)
{
    switch (token)
    {
        case RaceToken::AMAZON:
            return "AMAZON";
        case RaceToken::DWARVE:
            return "DWARVE";
        case RaceToken::WIZARD:
            return "WIZARD";
        case RaceToken::SKELETON:
            return "SKELETON";
        case RaceToken::HALFLING:
            return "HALFLING";
        case RaceToken::GHOUL:
            return "GHOUL";
        case RaceToken::ELVE:
            return "ELVE";
        case RaceToken::RATMEN:
            return "RATMEN";
        case RaceToken::GIANT:
            return "GIANT";
        case RaceToken::SORCERER:
            return "SORCERER";
        case RaceToken::HUMAN:
            return "HUMAN";
        case RaceToken::ORC:
            return "ORC";
        case RaceToken::TROLL:
            return "TROLL";
        case RaceToken::TRITON:
            return "TRITON";
        case RaceToken::LOST_TRIBE:
            return "LOST_TRIBE";
        case RaceToken::EMPTY:
            return "EMPTY";
    }
}

//! \brief Gets the token as a printable string

//! Gets a printable string for a SpecialPower
//! \param token The token to be printed
//! \return String value of the token
inline std::string getTokenString(const SpecialPower& token)
{
    switch (token)
    {
        case SpecialPower::ALCHEMIST:
            return "ALCHEMIST";
        case SpecialPower::BERSERK:
            return "BERSERK";
        case SpecialPower::BIVOUACKING:
            return "BIVOUACKING";
        case SpecialPower::COMMANDO:
            return "COMMANDO";
        case SpecialPower::DIPLOMAT:
            return "DIPLOMAT";
        case SpecialPower::DRAGON_MASTER:
            return "DRAGON_MASTER";
        case SpecialPower::FLYING:
            return "FLYING";
        case SpecialPower::FOREST:
            return "FOREST";
        case SpecialPower::FORTIFIED:
            return "FORTIFIED";
        case SpecialPower::HEROIC:
            return "HEROIC";
        case SpecialPower::HILL:
            return "HILL";
        case SpecialPower::MERCHANT:
            return "MERCHANT";
        case SpecialPower::MOUNTED:
            return "MOUNTED";
        case SpecialPower::PILLAGING:
            return "PILLAGING";
        case SpecialPower::SEAFARING:
            return "SEAFARING";
        case SpecialPower::SPIRIT:
            return "SPIRIT";
        case SpecialPower::STOUT:
            return "STOUT";
        case SpecialPower::SWAMP:
            return "SWAMP";
        case SpecialPower::UNDERWORLD:
            return "UNDERWORLD";
        case SpecialPower::WEALTHY:
            return "WEALTHY";
        case SpecialPower::BLANK:
            return "BLANK";
        case SpecialPower::EMPTY:
            return "EMPTY";
    }
}

//! \brief Gets the token as a printable string

//! Gets a printable string for a VictoryCoin
//! \param token The token to be printed
//! \return String value of the token
inline std::string getTokenString(const VictoryCoin& token)
{
    switch (token)
    {
        case VictoryCoin::VAL_1:
            return "VAL_1";
        case VictoryCoin::VAL_3:
            return "VAL_3";
        case VictoryCoin::VAL_5:
            return "VAL_5";
        case VictoryCoin::VAL_10:
            return "VAL_10";
        case VictoryCoin::EMPTY:
            return "EMPTY";
    }
}
*/
