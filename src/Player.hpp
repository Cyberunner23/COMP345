
#pragma once

#include <memory>

#include "DiceRollingFacility.hpp"
#include "GameDeck.hpp"
#include "Map.hpp"

class Player
{

public:

    Player(const std::shared_ptr<Map>& map, const std::shared_ptr<GameDeck>& gameDeck)
            : _ownedRegions(map->createSubGraph())
            , _map(map)
            , _gameDeck(gameDeck)
    {}

    void picks_race();
    void conquers();
    void scores();

private:

    SGraph& _ownedRegions;

    std::shared_ptr<Map> _map;
    std::shared_ptr<GameDeck> _gameDeck;

    DiceRollingFacility _dice;


};
