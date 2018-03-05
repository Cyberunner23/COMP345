
#include <spandsp.h>
#include "Player.hpp"

void Player::picks_race(std::vector<std::unique_ptr<RaceBanner>>& banners,
                        std::stack<std::unique_ptr<RaceBanner>>& bannerStack,
                        std::vector<std::unique_ptr<SpecialPower>>& specialPowers,
                        std::stack<std::unique_ptr<SpecialPower>>& specialPowerStack,
                        std::vector<std::vector<std::unique_ptr<VictoryCoin>>>& comboCoins,
                        std::vector<std::unique_ptr<VictoryCoin>>& coinStash)
{
    assert(banners.size() == 5);
    assert(specialPowers.size() == 5);

    bool isSuccess = false;

    while (!isSuccess)
    {
        std::cout << "Select a special power and race combo" << std::endl;
        for (unsigned int i = 0; i < 5; ++i )
        {
            std::cout << "[" << i << "] " << *specialPowers[i] << " " << *banners[i] << std::endl;
        }

        std::cout << "[5] " << *specialPowerStack.top() << " " << *bannerStack.top() << std::endl;

        unsigned int selection = getUserInput<1>(6);


        //Take care of the coin situation
        unsigned int numOneCoin = 0;
        for (auto& coin : coins)
        {
            if (coin->kind == EVictoryCoin::VAL_1)
            {
                ++numOneCoin;
            }
        }

        if (numOneCoin < selection)
        {
            std::cout << "Sorry, you don't have enough \"1\" coins to take this race!" << std::endl;
            isSuccess = false;
            continue;
        }

        //Put coins in skipped combos
        unsigned int cost = 0;
        for (unsigned int i = 0; i < selection; ++i)
        {
            //Look for a "1" coin
            std::unique_ptr<VictoryCoin> vCoin;
            for (unsigned int c = 0; c < coins.size(); ++c)
            {
                if (coins[i]->kind == EVictoryCoin::VAL_1)
                {
                    ++cost;
                    moveOutToken<VictoryCoin>(vCoin, coins, i);
                    break;
                }
            }

            //Put it in the combo
            comboCoins[i].push_back(std::move(vCoin));
        }
        std::cout << "Put down " << cost << " coins to get the combo" << std::endl;

        //Grab coins that are already in the chosen combo
        std::cout << "Got " << comboCoins[selection].size() << " victory tokens from the selected combo" << std::endl;
        for (unsigned int i = 0; i < comboCoins[selection].size(); ++i)
        {
            std::unique_ptr<VictoryCoin> coin;
            moveOutToken<VictoryCoin>(coin, comboCoins[selection], i);
            coins.push_back(std::move(coin));

            //Move up the comboCoins
            // take out the slot for that selection
            eraseAndShrink(comboCoins, selection);
            // resize back to a size of 6
            comboCoins.resize(6);
        }


        //Get the combo
        //Case 1: selected top of the stack
        if (selection == 6)
        {
            //Take the selected combo from the stack
            if (_currentRace != nullptr)
            {
                declineCurrentRace();
            }

            _currentRace = std::move(stackRealPop(bannerStack));
            _currentSpecialPower = std::move(stackRealPop(specialPowerStack));

        }
        else //Case 2, not in the stack
        {
            //Take the selected combo
            if (_currentRace != nullptr)
            {
                declineCurrentRace();
            }

            /*for(auto& banner : banners)
            {
                std::cout << banner->value << std::endl;
            }*/

            std::unique_ptr<RaceBanner> banner;
            std::unique_ptr<SpecialPower> power;
            moveOutToken(banner, banners, selection);
            moveOutToken(power, specialPowers, selection);
            _currentRace = std::move(banner);
            _currentSpecialPower = std::move(power);

            std::cout << "race: " << _currentRace->value << std::endl;
            std::cout << "power: " << _currentSpecialPower->value << std::endl;

            assert(_currentRace != nullptr);
            assert(_currentSpecialPower != nullptr);

            //Replenish the combos
            banners.push_back(std::move(stackRealPop(bannerStack)));
            specialPowers.push_back(std::move(stackRealPop(specialPowerStack)));
        }

        //Handle wealthy special power case
        if (_currentSpecialPower->kind == ESpecialPower::WEALTHY)
        {
            std::unique_ptr<VictoryCoin> coin1;
            std::unique_ptr<VictoryCoin> coin2;
            std::unique_ptr<VictoryCoin> coin3;
            _vacuumTray->takeToken(VictoryCoin(EVictoryCoin::VAL_1), coin1);
            _vacuumTray->takeToken(VictoryCoin(EVictoryCoin::VAL_1), coin2);
            _vacuumTray->takeToken(VictoryCoin(EVictoryCoin::VAL_3), coin3);
            coins.push_back(std::move(coin1));
            coins.push_back(std::move(coin2));
            coins.push_back(std::move(coin3));
        }

        std::cout << "HIT" << std::endl;

        assert(_currentRace != nullptr);
        assert(_currentSpecialPower != nullptr);

        //Take care of the race token situation
        std::cout << "Setting race: " << *_currentRace << " with a value of: " << _currentRace->value
                  << " and special: " << *_currentSpecialPower << " with a value of: " << _currentSpecialPower->value << std::endl;
        unsigned int numRaceTokens = _currentRace->value + _currentSpecialPower->value;
        ERaceToken tokenType = raceBannerToRaceTokenType(_currentRace->kind);

        std::cout << "HEY! " << numRaceTokens << std::endl;
        for (unsigned int i = 0; i < numRaceTokens; ++i)
        {
            //std::cout << "HIT2" << std::endl;
            std::unique_ptr<RaceToken> token;
            _storageTray->takeRaceToken(RaceToken(tokenType), token);
            _raceTokens.push_back(std::move(token));
            //std::cout << "HIT3" << std::endl;
        }

        std::cout << "TODO: TAKE CARE OF _raceTokens WHEN PUT IN DECLINE" << std::endl;

        isSuccess = true;
    }
}

void Player::switchRace(std::unique_ptr<RaceBanner> &&banner, std::unique_ptr<SpecialPower> &&power)
{
    if (_currentRace != nullptr)
    {
        declineCurrentRace();
    }



    _currentRace = std::move(banner);
    _currentSpecialPower = std::make_unique<SpecialPower>(ESpecialPower::WEALTHY);

    if (_currentSpecialPower == nullptr)
    {
        std::cout << "RIPERINOS" << std::endl;
    }
}

void Player::declineCurrentRace()
{
    //Decline Race
    std::cout << "UNIMPLEMENTED: declineCurrentRace" << std::endl;
}

void Player::conquers()
{
    std::cout << "called: conquers()" << std::endl;
}

void Player::scores()
{
    std::cout << "called: scores()" << std::endl;
}

/*std::vector<std::unique_ptr<RaceToken>>* Player::getRaceTokens()
{
    return &_raceTokens;
}

RaceBanner* Player::getRaceBanner()
{
    return _currentRace.get();
}

SpecialPower* Player::getSpecialPower()
{
    return _currentSpecialPower.get();
}

unsigned int Player::getOwnedRegionCount()
{
    return (unsigned int)boost::num_vertices(_ownedRegions);
}*/
