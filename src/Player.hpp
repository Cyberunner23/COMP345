
#pragma once

#include <iostream>
#include <memory>

#include "DiceRollingFacility.hpp"
#include "Map.hpp"
#include "Utils.hpp"
#include "Tokens/RemovebleStorageTray.hpp"
#include "Tokens/TokenStack.hpp"
#include "Tokens/TokenVec.hpp"
#include "Tokens/VacuumTray.hpp"

class Player
{

public:

    std::vector<std::unique_ptr<VictoryCoin>> coins;

    //! Contructor for the player
    //! \param map A pointer to the map
    //! \param gameDeck A poointer to the Game Deck
    Player(std::shared_ptr<Map> map,
           std::shared_ptr<RemovableStorageTray> storageTray,
           std::shared_ptr<VacuumTray> vacuumTray,
           std::shared_ptr<std::vector<std::shared_ptr<Player>>> players,
           int playerID)
            : _ownedRegions(map->createSubGraph())
            , _map(std::move(map))
            , _storageTray(storageTray)
            , _vacuumTray(vacuumTray)
            , _players(players)
            , _playerID(playerID)
            , _currentRace(nullptr)
            , _currentSpecialPower(nullptr)
    {}

    //! Lets user pick a race.
    void picks_race(
            TokenVec<RaceBanner>&               banners,
            TokenStack<RaceBanner>&             bannerStack,
            TokenVec<SpecialPower>&             specialPowers,
            TokenStack<SpecialPower>&           specialPowerStack,
            std::vector<TokenVec<VictoryCoin>>& comboCoins,
            TokenVec<VictoryCoin>&              coinStash
    );

    void switchRace(std::unique_ptr<RaceBanner>&& banner, std::unique_ptr<SpecialPower>&& power);
    void declineCurrentRace();

    bool isValidRegion(const Vertex& v)
    {
        if (_isFirstTurn)
        {
            return _map->isRegionOnEdge(v) || _map->isRegionConnectedToSea(v);
        }
        else
        {
            return _map->areRegionsAdjacent(_ownedRegions, v, _currentSpecialPower);
        }
    }

    //void firstConquer();

    //! Lets the user conquer a region.
    void conquers();

    //! Gets the user's score.
    void scores();

    void redeploy(unsigned int count);
    void redeploy();

    void giveBackRaceToken(std::unique_ptr<RaceToken> && token);

    int numTokensRequiredToConquer(const Vertex& v);


private:

    SGraph& _ownedRegions;

    std::shared_ptr<std::vector<std::shared_ptr<Player>>> _players;

    std::shared_ptr<Map> _map;

    std::shared_ptr<RemovableStorageTray> _storageTray;
    std::shared_ptr<VacuumTray> _vacuumTray;

    TokenVec<RaceToken> _raceTokens;
    std::unique_ptr<RaceBanner> _currentRace;
    std::unique_ptr<SpecialPower> _currentSpecialPower;

    std::string _summarySheet = "sw_help_en.pdf";

    DiceRollingFacility _dice;

    bool _isFirstTurn = true;

    int _playerID;

};
