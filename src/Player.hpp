
#pragma once

#include <iostream>
#include <memory>

#include "DiceRollingFacility.hpp"
#include "GameDeck.hpp"
#include "Map.hpp"

class Player
{

public:

    Player(std::shared_ptr<Map> map, std::shared_ptr<GameDeck> gameDeck)
            : _ownedRegions(map->createSubGraph())
            , _map(std::move(map))
            , _gameDeck(std::move(gameDeck))
            , _currentRace(RaceBanner::EMPTY)
            , _currentSpecialPower(SpecialPower::EMPTY)
    {}

    void picks_race(){std::cout << "called: picks_race(), here is a value of the dice " << _dice.getDiceValue(1)[0] << std::endl;}
    void conquers(){std::cout << "called: conquers()" << std::endl;}
    void scores(){std::cout << "called: scores()" << std::endl;}

    std::vector<RaceToken>* getRaceTokens() {return &_raceTokens;}
    std::vector<VictoryCoin>* getCoins() {return &_coins;}
    RaceBanner* getRaceBanner() {return &_currentRace;}
    SpecialPower* getSpecialPower() {return &_currentSpecialPower;}

    unsigned int getOwnedRegionCount()
    {
        return (unsigned int)boost::num_vertices(_ownedRegions);
    }


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
