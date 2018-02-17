
#include "Player.hpp"

void Player::picks_race()
{
    std::cout << "called: picks_race(), here is a value of the dice " << _dice.getDiceValue(1)[0] << std::endl;
}

void Player::conquers()
{
    std::cout << "called: conquers()" << std::endl;
}

void Player::scores()
{
    std::cout << "called: scores()" << std::endl;
}

std::vector<RaceToken>* Player::getRaceTokens()
{
    return &_raceTokens;
}
std::vector<VictoryCoin>* Player::getCoins()
{
    return &_coins;
}
RaceBanner* Player::getRaceBanner()
{
    return &_currentRace;
}
SpecialPower* Player::getSpecialPower()
{
    return &_currentSpecialPower;
}

unsigned int Player::getOwnedRegionCount()
{
    return (unsigned int)boost::num_vertices(_ownedRegions);
}