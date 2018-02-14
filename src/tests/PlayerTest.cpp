
#include <iostream>
#include <memory>

#include "../Player.hpp"

int main(int argc, char** argv)
{

    std::shared_ptr<Map> map = std::make_shared<Map>();
    std::shared_ptr<GameDeck> deck = std::make_shared<GameDeck>();

    deck->removeMapTokensAlreadyInMap(*map);

    Player player(map, deck);

    std::cout << "Calling player.picks_race()..." << std::endl;
    player.picks_race();
    std::cout << std::endl;

    std::cout << "Calling player.conquers()..." << std::endl;
    player.conquers();
    std::cout << std::endl;

    std::cout << "Calling player.scores()..." << std::endl;
    player.scores();
    std::cout << std::endl;

    std::cout << "The player currently owns " << player.getOwnedRegionCount() << " regions." << std::endl;
    std::cout << std::endl;

    std::cout << "Here is the player's current race: " << getTokenString(*player.getRaceBanner()) << std::endl;
    std::cout << std::endl;

    std::cout << "Here is the player's special power: " << getTokenString(*player.getSpecialPower()) << std::endl;
    std::cout << std::endl;

    std::cout << "The player has " << player.getCoins()->size() << " coins..." << std::endl;
    std::cout << std::endl;

    std::cout << "The player has " << player.getRaceTokens()->size() << " race tokens..." << std::endl;
    std::cout << std::endl;




}
