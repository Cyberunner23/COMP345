
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "boost/filesystem.hpp"
#include <QApplication>
#include <QThread>

#include "GameDeck.hpp"
#include "Map.hpp"
#include "Player.hpp"

namespace fs = boost::filesystem;

class Game : public QThread
{

Q_OBJECT

public:

    void run();

signals:

    void initUI(std::string graphVizStr);
    void updateUI(std::string graphVizStr);

private:

    std::shared_ptr<Map> _map;
    std::shared_ptr<GameDeck> _deck;
    std::vector<std::shared_ptr<Player>> _players;


    void setup();

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
