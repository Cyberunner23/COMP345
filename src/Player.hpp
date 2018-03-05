
#pragma once

#include <iostream>
#include <memory>

#include "DiceRollingFacility.hpp"
#include "Map.hpp"
#include "Utils.hpp"
#include "Tokens/RemovebleStorageTray.hpp"
#include "Tokens/VacuumTray.hpp"

class Player
{

public:

    std::vector<std::unique_ptr<VictoryCoin>> coins;

    //! Contructor for the player
    //! \param map A pointer to the map
    //! \param gameDeck A poointer to the Game Deck
    Player(std::shared_ptr<Map> map, std::shared_ptr<RemovableStorageTray> storageTray, std::shared_ptr<VacuumTray> vacuumTray)
            : _ownedRegions(map->createSubGraph())
            , _map(std::move(map))
            , _storageTray(storageTray)
            , _vacuumTray(vacuumTray)
            , _currentRace(nullptr)
            , _currentSpecialPower(nullptr)
    {}

    //! Lets user pick a race.
    void picks_race(
            std::vector<std::unique_ptr<RaceBanner>>& banners,
            std::stack<std::unique_ptr<RaceBanner>>& bannerStack,
            std::vector<std::unique_ptr<SpecialPower>>& specialPowers,
            std::stack<std::unique_ptr<SpecialPower>>& specialPowerStack,
            std::vector<std::vector<std::unique_ptr<VictoryCoin>>>& comboCoins,
            std::vector<std::unique_ptr<VictoryCoin>>& coinStash
    );

    void switchRace(std::unique_ptr<RaceBanner>&& banner, std::unique_ptr<SpecialPower>&& power);
    void declineCurrentRace();

    //! Lets the user conquer a region.
    void conquers();

    //! Gets the user's score.
    void scores();


    /*//! Gets a pointer to the player's race token vector.
    std::vector<std::unique_ptr<RaceToken>>* getRaceTokens();

    //! Gets a pointher to the player's current race banner.
    RaceBanner* getRaceBanner();

    //!Gets a pointer to the player's current special power.
    SpecialPower* getSpecialPower();


    //! Get number of regions that the player owns
    unsigned int getOwnedRegionCount();*/


private:

    SGraph& _ownedRegions;

    std::shared_ptr<Map> _map;

    std::shared_ptr<RemovableStorageTray> _storageTray;
    std::shared_ptr<VacuumTray> _vacuumTray;

    std::vector<std::unique_ptr<RaceToken>> _raceTokens;
    //std::vector<std::unique_ptr<VictoryCoin>> _coins;
    std::unique_ptr<RaceBanner> _currentRace;
    std::unique_ptr<SpecialPower> _currentSpecialPower;

    std::string _summarySheet = "sw_help_en.pdf";

    DiceRollingFacility _dice;


};
