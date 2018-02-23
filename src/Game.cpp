//
// Created by cyberunner23 on 2/22/18.
//

#include "Game.hpp"

void Game::run()
{

    setup();

    emit updateUI(_map);


}


void Game::setup()
{

    std::vector<std::string> files = getFileList("data", ".map");
    std::vector<std::string> validFiles;

    //Validate map files
    for(auto& file : files)
    {
        Map map;

        try {
            if (map.importMap("data/" + file))
            {
                validFiles.push_back(file);
            }
            else
            {
                std::cout << "[WARN] Map file \"" << file << "\" does not describe a valid map!" << std::endl;
                continue;
            }
        }
        catch (std::exception e)
        {
            std::cout << "[WARN] Map file \"" << file <<"\" could not be loaded: " << e.what() << std::endl;
            continue;
        }
    }


    //Print map selection
    std::cout << "Please select a map." << std::endl;
    for (unsigned int i = 0; i < validFiles.size(); i++)
    {
        Map map;
        map.importMap("data/" + validFiles[i]);
        std::cout << "[" << i + 1 << "]: " << validFiles[i] << " (Ideal: " << map.getNumPlayers() << " Players)" << std::endl;
    }
    std::cout << "[" << validFiles.size() + 1 <<"]: Exit" << std::endl;


    //Handle user selection
    unsigned int selection = getUserInput<1>(validFiles.size() + 1);

    //Exit if requested
    if (selection == validFiles.size() + 1)
    {
        QApplication::exit(0);
        return;
    }

    //Should not cause an exception at this point since the maps were previously validated.
    std::string fileName = validFiles[selection - 1];
    assert(_map->importMap("data/" + fileName));
    std::cout << "[INFO] Loaded map: " << fileName << std::endl;


    //Set number pf players
    std::cout << "How many players re playing?" << std::endl;
    unsigned int numPlayers = getUserInput<2>(5);
    for (unsigned int i = 0; i < numPlayers; i++)
    {
        _players.push_back(std::make_shared<Player>(_map, _deck));
    }

    std::cout << "[INFO]: created " << numPlayers << " players." << std::endl;
}

void Game::startup()
{
    //Shuffle race banners, draw 5

}

std::vector<std::string> Game::getFileList(std::string directory, std::string ext)
{
    fs::path dir(directory);
    assert(fs::exists(dir) && fs::is_directory(dir));

    std::vector<std::string> files;
    for(auto& file : fs::recursive_directory_iterator(dir))
    {
        if (fs::is_regular_file(file) && file.path().extension() == ext)
        {
            files.push_back(file.path().filename().string());
        }
    }

    return files;
}
