
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
#include "Tokens/RemovebleStorageTray.hpp"
#include "Tokens/VacuumTray.hpp"

namespace fs = boost::filesystem;

class Game : public QThread
{

Q_OBJECT

public:

    Game() : _map(std::make_shared<Map>())
           , _vacuumTray(std::make_shared<VacuumTray>())
           , _storageTray(std::make_shared<RemovableStorageTray>())
    {}

    void run();

signals:

    void updateUI(Map *map,
                  std::vector<std::unique_ptr<RaceBanner>> *selectionRaceBanners,
                  std::stack<std::unique_ptr<RaceBanner>> *remainingRaceBanners,
                  std::vector<std::unique_ptr<SpecialPower>> *selectionSpecialPowers,
                  std::stack<std::unique_ptr<SpecialPower>> *remainingSpecialPowers);

private:

    std::shared_ptr<Map> _map;
    std::shared_ptr<RemovableStorageTray> _storageTray;
    std::shared_ptr<VacuumTray> _vacuumTray;

    std::vector<std::shared_ptr<Player>> _players;

    std::vector<std::unique_ptr<RaceBanner>> _selectionRaceBanners;
    std::stack<std::unique_ptr<RaceBanner>> _remainingRaceBanners;
    std::vector<std::unique_ptr<SpecialPower>> _selectionSpecialPowers;
    std::stack<std::unique_ptr<SpecialPower>> _remainingSpecialPowers;
    //Coins places on the combos during the selection
    std::vector<std::vector<std::unique_ptr<VictoryCoin>>> _comboCoins;

    std::vector<std::unique_ptr<VictoryCoin>> _coinStash;

    void setup();
    void startup();
    void playerSetupTurn(std::shared_ptr<Player> player);
    void playerTurn(std::shared_ptr<Player> player);
    void showWinner();

    std::vector<std::string> getFileList(std::string directory, std::string ext);

    template<const unsigned int minVal>
    unsigned int getUserInput(unsigned int maxVal)
    {
        static_assert(minVal > 0);

        std::cout << "Please enter a number between " << minVal << " and " << maxVal << "." << std::endl;

        bool isValid = false;
        unsigned int selection = 0;
        do
        {

            while(!(std::cin >> selection)) {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please enter a number between " << minVal << " and " << maxVal << "." << std::endl;
                continue;
            }

            if (selection >= minVal && selection <= maxVal)
            {
                isValid = true;
            }
            else
            {
                std::cout << "Please enter a number in between "<< minVal << "and " << maxVal << std::endl;
            }
        }
        while(!isValid);

        return selection;
    }

};
