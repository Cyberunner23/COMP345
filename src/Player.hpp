
#pragma once

#include <iostream>
#include <memory>

#include "DiceRollingFacility.hpp"
#include "GameDeck.hpp"
#include "Map.hpp"

class Player
{

public:

    //! Contructor for the player
    //! \param map A pointer to the map
    //! \param gameDeck A poointer to the Game Deck
    Player(std::shared_ptr<Map> map, std::shared_ptr<GameDeck> gameDeck)
            : _ownedRegions(map->createSubGraph())
            , _map(std::move(map))
            , _gameDeck(std::move(gameDeck))
            , _currentRace(RaceBanner::EMPTY)
            , _currentSpecialPower(SpecialPower::EMPTY)
    {}

    //! Lets user pick a race.
    void picks_race();

    //! Lets the user conquer a region.
    void conquers();

    //! Gets the user's score.
    void scores();


    //! Gets a pointer to the player's race token vector.
    std::vector<RaceToken>* getRaceTokens();

    //! Gets a pointer to the player's vicotry token vector.
    std::vector<VictoryCoin>* getCoins();

    //! Gets a pointher to the player's current race banner.
    RaceBanner* getRaceBanner();

    //!Gets a pointer to the player's current special power.
    SpecialPower* getSpecialPower();


    //! Get number of regions that the player owns
    unsigned int getOwnedRegionCount();


private:

    SGraph& _ownedRegions;

    std::shared_ptr<Map> _map;
    std::shared_ptr<GameDeck> _gameDeck;

    std::vector<RaceToken> _raceTokens;
    std::vector<VictoryCoin> _coins;
    RaceBanner _currentRace;
    SpecialPower _currentSpecialPower;

    std::string _summarySheet = "sw_help_en.pdf";

    DiceRollingFacility _dice;
};
