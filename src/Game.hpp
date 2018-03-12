
#pragma once

#include <cassert>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <vector>


#include "boost/filesystem.hpp"
#include <QApplication>
#include <QThread>

#include "Map.hpp"
#include "Player.hpp"
#include "Utils.hpp"
#include "Tokens/RemovebleStorageTray.hpp"
#include "Tokens/TokenStack.hpp"
#include "Tokens/TokenVec.hpp"
#include "Tokens/VacuumTray.hpp"

namespace fs = boost::filesystem;

class Game : public QThread
{

Q_OBJECT

public:

    Game() : _map(std::make_shared<Map>())
           , _vacuumTray(std::make_shared<VacuumTray>())
           , _storageTray(std::make_shared<RemovableStorageTray>())
    {
        _comboCoins.resize(6);
        _players = std::make_shared<std::vector<std::shared_ptr<Player>>>();
    }

    void run();

signals:

    void updateUI(Map *map,
                  const TokenVec<RaceBanner> *selectionRaceBanners,
                  const TokenStack<RaceBanner> *remainingRaceBanners,
                  const TokenVec<SpecialPower> *selectionSpecialPowers,
                  const TokenStack<SpecialPower> *remainingSpecialPowers);

private:

    std::shared_ptr<Map> _map;
    std::shared_ptr<RemovableStorageTray> _storageTray;
    std::shared_ptr<VacuumTray> _vacuumTray;

    std::shared_ptr<std::vector<std::shared_ptr<Player>>> _players;

    TokenVec<RaceBanner>     _selectionRaceBanners;
    TokenStack<RaceBanner>   _remainingRaceBanners;
    TokenVec<SpecialPower>   _selectionSpecialPowers;
    TokenStack<SpecialPower> _remainingSpecialPowers;
    //Coins places on the combos during the selection
    std::vector<TokenVec<VictoryCoin>> _comboCoins;

    TokenVec<VictoryCoin> _coinStash;

    void setup();
    void startup();
    void playerSetupTurn(std::shared_ptr<Player> player);
    void playerTurn(std::shared_ptr<Player> player);
    void showWinner();

    std::vector<std::string> getFileList(std::string directory, std::string ext);

};
