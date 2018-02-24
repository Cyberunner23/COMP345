
#pragma once
/*
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "Map.hpp"
#include "Tokens/Tokens.hpp"


//! Class for the game deck.
//! Simulates an actual deck where a person can take out and place back a card/token
class GameDeck
{

public:

    //! Constructor for the Game Deck, initializes the deck with all the tkens.
    GameDeck()
    {

        //Setup special powers
        _specialPowers.push_back(SpecialPower::ALCHEMIST);
        _specialPowers.push_back(SpecialPower::BERSERK);
        _specialPowers.push_back(SpecialPower::BIVOUACKING);
        _specialPowers.push_back(SpecialPower::BLANK);
        _specialPowers.push_back(SpecialPower::COMMANDO);
        _specialPowers.push_back(SpecialPower::DIPLOMAT);
        _specialPowers.push_back(SpecialPower::DRAGON_MASTER);
        _specialPowers.push_back(SpecialPower::FLYING);
        _specialPowers.push_back(SpecialPower::FOREST);
        _specialPowers.push_back(SpecialPower::FORTIFIED);
        _specialPowers.push_back(SpecialPower::HEROIC);
        _specialPowers.push_back(SpecialPower::HILL);
        _specialPowers.push_back(SpecialPower::MERCHANT);
        _specialPowers.push_back(SpecialPower::MOUNTED);
        _specialPowers.push_back(SpecialPower::PILLAGING);
        _specialPowers.push_back(SpecialPower::SEAFARING);
        _specialPowers.push_back(SpecialPower::SPIRIT);
        _specialPowers.push_back(SpecialPower::STOUT);
        _specialPowers.push_back(SpecialPower::SWAMP);
        _specialPowers.push_back(SpecialPower::UNDERWORLD);
        _specialPowers.push_back(SpecialPower::WEALTHY);


        //Setup the map tokens
        _mapTokens.insert(_mapTokens.end(), 10, MapToken::TROLL_LAIR);
        _mapTokens.insert(_mapTokens.end(), 6,  MapToken::FORTRESS);
        _mapTokens.insert(_mapTokens.end(), 9,  MapToken::MOUNTAIN);
        _mapTokens.insert(_mapTokens.end(), 5,  MapToken::ENCAMPMENT);
        _mapTokens.insert(_mapTokens.end(), 2,  MapToken::HOLES_IN_GROUND);
        _mapTokens.insert(_mapTokens.end(), 2,  MapToken::HERO);
        _mapTokens.insert(_mapTokens.end(), 1,  MapToken::DRAGON);

        //Setup Race banners
        _raceBanners.push_back(RaceBanner::AMAZON);
        _raceBanners.push_back(RaceBanner::DWARVE);
        _raceBanners.push_back(RaceBanner::GIANT);
        _raceBanners.push_back(RaceBanner::ELVE);
        _raceBanners.push_back(RaceBanner::GHOUL);
        _raceBanners.push_back(RaceBanner::RATMEN);
        _raceBanners.push_back(RaceBanner::SKELETON);
        _raceBanners.push_back(RaceBanner::SORCERER);
        _raceBanners.push_back(RaceBanner::TRITON);
        _raceBanners.push_back(RaceBanner::HALFLING);
        _raceBanners.push_back(RaceBanner::HUMAN);
        _raceBanners.push_back(RaceBanner::ORC);
        _raceBanners.push_back(RaceBanner::WIZARD);
        _raceBanners.push_back(RaceBanner::TROLL);

        //Setup Race Tokens
        _raceTokens.insert(_raceTokens.end(), 15, RaceToken::AMAZON);
        _raceTokens.insert(_raceTokens.end(), 8,  RaceToken::DWARVE);
        _raceTokens.insert(_raceTokens.end(), 11, RaceToken::ELVE);
        _raceTokens.insert(_raceTokens.end(), 10, RaceToken::GHOUL);
        _raceTokens.insert(_raceTokens.end(), 13, RaceToken::RATMEN);
        _raceTokens.insert(_raceTokens.end(), 20, RaceToken::SKELETON);
        _raceTokens.insert(_raceTokens.end(), 18, RaceToken::SORCERER);
        _raceTokens.insert(_raceTokens.end(), 11, RaceToken::TRITON);
        _raceTokens.insert(_raceTokens.end(), 11, RaceToken::GIANT);
        _raceTokens.insert(_raceTokens.end(), 11, RaceToken::HALFLING);
        _raceTokens.insert(_raceTokens.end(), 10, RaceToken::HUMAN);
        _raceTokens.insert(_raceTokens.end(), 10, RaceToken::ORC);
        _raceTokens.insert(_raceTokens.end(), 10, RaceToken::TROLL);
        _raceTokens.insert(_raceTokens.end(), 10, RaceToken::WIZARD);
        _raceTokens.insert(_raceTokens.end(), 18, RaceToken::LOST_TRIBE);

        //Setup coin tokens
        _coins.insert(_coins.end(), 35, VictoryCoin::VAL_1);
        _coins.insert(_coins.end(), 20, VictoryCoin::VAL_3);
        _coins.insert(_coins.end(), 24, VictoryCoin::VAL_5);
        _coins.insert(_coins.end(), 30, VictoryCoin::VAL_10);
    }

    //! Takes a token from the deck
    bool takeToken(const SpecialPower& valueKind, SpecialPower& value);
    //! Takes a token from the deck
    bool takeToken(const MapToken& valueKind, MapToken& value);
    //! Takes a token from the deck
    bool takeToken(const RaceBanner& valueKind, RaceBanner& value);
    //! Takes a token from the deck
    bool takeToken(const RaceToken& valueKind, RaceToken& value);
    //! Takes a token from the deck
    bool takeToken(const VictoryCoin& valueKind, VictoryCoin& value);

    //! Place back a token from the deck
    bool placeToken(SpecialPower& value);
    //! Place back a token from the deck
    bool placeToken(MapToken& value);
    //! Place back a token from the deck
    bool placeToken(RaceBanner& value);
    //! Place back a token from the deck
    bool placeToken(RaceToken& value);
    //! Place back a token from the deck
    bool placeToken(VictoryCoin& value);

    //! Gets size / total number of tokens
    unsigned int getSpecialPowersTokenListSize() const;
    //! Gets size / total number of tokens
    unsigned int getMapTokensTokenListSize() const;
    //! Gets size / total number of tokens
    unsigned int getRaceBannersTokenListSize() const;
    //! Gets size / total number of tokens
    unsigned int getRaceTokensTokenListSize() const;
    //! Gets size / total number of tokens
    unsigned int getCoinsTokenListSize() const;

    //! Gets a pointer to the internal vector of tokens
    std::vector<SpecialPower>* getSpecialPowersTokenList();
    //! Gets a pointer to the internal vector of tokens
    std::vector<MapToken>* getMapTokensTokenList();
    //! Gets a pointer to the internal vector of tokens
    std::vector<RaceBanner>* getRaceBannersTokenList();
    //! Gets a pointer to the internal vector of tokens
    std::vector<RaceToken>* getRaceTokensTokenList();
    //! Gets a pointer to the internal vector of tokens
    std::vector<VictoryCoin>* getCoinsTokenList();

private:

    //! Templated implementation of the take token function
    template <typename TokenType>
    bool TakeTokenImpl(const TokenType& valueKind, TokenType& value, std::vector<TokenType>& var)
    {
        static_assert(std::is_enum<TokenType>::value, "Tokens must be enums!");

        if (valueKind == TokenType::EMPTY)
        {
            return false;
        }

        auto it = std::find(var.begin(), var.end(), valueKind);
        if (it == var.end())
        {
            return false;
        }

        value = *it;
        *it = TokenType::EMPTY;

        return true;
    }

    //! Templated implementation of the place back token
    template <typename TokenType>
    bool PlaceTokenImpl(TokenType& value, std::vector<TokenType>& var)
    {
        auto it = std::find(var.begin(), var.end(), TokenType::EMPTY);
        if (it == var.end())
        {
            return false;
        }

        *it = value;
        value = TokenType::EMPTY;

        return true;
    }

    std::vector<SpecialPower> _specialPowers;
    std::vector<MapToken> _mapTokens;
    std::vector<RaceBanner> _raceBanners;
    std::vector<RaceToken> _raceTokens;
    std::vector<VictoryCoin> _coins;

};
*/