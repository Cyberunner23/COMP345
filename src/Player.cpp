
#include <spandsp.h>
#include "Player.hpp"

void Player::picks_race(TokenVec<RaceBanner>&               banners,
                        TokenStack<RaceBanner>&             bannerStack,
                        TokenVec<SpecialPower>&             specialPowers,
                        TokenStack<SpecialPower>&           specialPowerStack,
                        std::vector<TokenVec<VictoryCoin>>& comboCoins,
                        TokenVec<VictoryCoin>&              coinStash)
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

        unsigned int selection = getUserInput<0>(5);

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
            comboCoins[i].place_back(std::move(vCoin));
        }
        std::cout << "Put down " << cost << " coins to get the combo" << std::endl;

        //Grab coins that are already in the chosen combo
        std::cout << "Got " << comboCoins[selection].size() << " victory tokens from the selected combo" << std::endl;

        std::unique_ptr<VictoryCoin> coin;
        while(comboCoins[selection].take(0, coin))
        {
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

            std::unique_ptr<RaceBanner> banner;
            std::unique_ptr<SpecialPower> power;

            bannerStack.pop(banner);
            specialPowerStack.pop(power);
            _currentRace = std::move(banner);
            _currentSpecialPower = std::move(power);

        }
        else //Case 2, not in the stack
        {
            //Take the selected combo
            if (_currentRace != nullptr)
            {
                declineCurrentRace();
            }

            std::unique_ptr<RaceBanner> banner;
            std::unique_ptr<SpecialPower> power;

            banners.take(selection, banner);
            specialPowers.take(selection, power);
            _currentRace = std::move(banner);
            _currentSpecialPower = std::move(power);

            assert(_currentRace != nullptr);
            assert(_currentSpecialPower != nullptr);

            //Replenish the combos
            bannerStack.pop(banner);
            specialPowerStack.pop(power);
            std::cout << "Replenishing with " << *banner << " " << *power << std::endl;
            banners.place_back(std::move(banner));
            specialPowers.place_back(std::move(power));
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

        assert(_currentRace != nullptr);
        assert(_currentSpecialPower != nullptr);

        //Take care of the race token situation
        std::cout << "Setting race: " << *_currentRace << " with a value of: " << _currentRace->value
                  << " and special: " << *_currentSpecialPower << " with a value of: " << _currentSpecialPower->value << std::endl;
        unsigned int numRaceTokens = _currentRace->value + _currentSpecialPower->value;
        ERaceToken tokenType = raceBannerToRaceTokenType(_currentRace->kind);

        for (unsigned int i = 0; i < numRaceTokens; ++i)
        {
            std::unique_ptr<RaceToken> token;
            _storageTray->takeRaceToken(RaceToken(tokenType), token);
            _raceTokens.place_back(std::move(token));
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

    bool regionConquered = false;
    do {

        Vertex regionVertex;
        bool isValidRegion = false;

        std::cout << "Select a region by its ID:" << std::endl;
        unsigned int selectedRegion = getUserInput<0>(_map->getNumRegions() - 1);
        _map->findVertex(selectedRegion, regionVertex);

        if (this->isValidRegion(regionVertex))
        {
            //DO conquering
            std::cout << "How many race tokens do you want to deploy in this region? Select 0 to skip and select a new region" << std::endl;
            unsigned int selection = getUserInput<0>(_raceTokens.size());
            if (selection == 0)
            {
                regionConquered = false;
                continue;
            }
            else
            {
                int numTokensRequiredToConquer = this->numTokensRequiredToConquer(regionVertex);

                if (numTokensRequiredToConquer > _raceTokens.size())
                {
                    unsigned int diceValue = _dice.getDiceValue(1)[0];
                    std::cout << "Not enough tokens... rolling dice..." << std::endl;
                    std::cout << "Got a value of " << diceValue << std::endl;
                    numTokensRequiredToConquer -= diceValue;
                }

                if (numTokensRequiredToConquer > _raceTokens.size())
                {
                    std::cout << "You don't have enough tokens to conquer this region, redeploy them somewhere else..." << std::endl;
                    redeploy(_raceTokens.size());
                    regionConquered = true;
                    continue;
                }
                else if (numTokensRequiredToConquer > selection)
                {
                    std::cout << "You need to put more tokens to conquer it..." << std::endl;
                    regionConquered = false;
                    continue;
                }
                else if (numTokensRequiredToConquer < 0)
                {
                    std::cout << "This region is invulnerable to conquering..." << std::endl;
                    regionConquered = false;
                    continue;
                }
                else
                {
                    //Ok we can do the conquering for real now


                    TokenVec<RaceToken> tokensFromRegion;
                    _map->takeRaceTokensFromRegion(regionVertex, tokensFromRegion);

                    //take the tokens from the region, put on back in tray, give rest to conquered player, let conquered player redeploy
                    int regionOwner = _map->currentRegionOwner(regionVertex);
                    if (tokensFromRegion.size() > 0 && regionOwner > 0)
                    {

                        //Take out one token and put it in the tray
                        std::unique_ptr<RaceToken> token;
                        tokensFromRegion.take(0, token);
                        _storageTray->placeRaceToken(std::move(token));

                        //Give back the remaining race tokens to the conquered player
                        unsigned int i = 0;
                        for (; i < tokensFromRegion.size(); ++i)
                        {
                            tokensFromRegion.take(0, token);
                            (*_players)[regionOwner]->giveBackRaceToken(std::move(token));
                        }

                        (*_players)[regionOwner]->redeploy(i);
                    }
                    else if (tokensFromRegion.size() > 0 && regionOwner < 0)
                    {
                        //remove the lost tribe
                        std::unique_ptr<RaceToken> token;
                        tokensFromRegion.take(0, token);
                        _storageTray->placeRaceToken(std::move(token));
                    }

                    //deploy to the conquered region
                    for (unsigned int i = 0; i < selection; ++i)
                    {
                        std::unique_ptr<RaceToken> token;
                        _raceTokens.take(0, token);
                        _map->putRaceTokenInRegion(regionVertex, std::move(token));
                    }

                    //we now own the region
                    _map->setRegionOwner(regionVertex, _playerID);

                    regionConquered = true;
                    continue;
                }
            }
        }
        else
        {
            std::cout << "An invalid region was selected!" << std::endl;
            regionConquered = false;
            continue;
        }

    } while (!regionConquered);

    _isFirstTurn = false;
}

void Player::scores()
{

    //Base number of coins
    unsigned int numOwnedRegions = boost::num_vertices(_ownedRegions);

    //Apply modifiers

    //Transfer coins ot player

    std::cout << "TODO: CALC SCORE" << std::endl;
}

/*void Player::firstConquer()
{
    Vertex regionVertex;
    bool isValidRegion = false;
    do
    {
        std::cout << "FIRST CONQUEST" << std::endl;
        std::cout << "Select a region by its ID:" << std::endl;
        unsigned int selectedRegion = getUserInput<0>(_map->getNumRegions() - 1);
        _map->findVertex(selectedRegion, regionVertex);
        if (_map->isRegionOnEdge(regionVertex) || _map->isRegionConnectedToSea(regionVertex))
        {
            isValidRegion = true;
            std::cout << "HANDLE CASE WHEN ANOTHER PLAYE IS ALREADY THERE" << std::endl;
        }
        else
        {
            std::cout << "This is not a valid region for first conquest!" << std::endl;
        }
    } while (!isValidRegion);
    //We have our region to do the initial conquering
    bool hasMapToken = _map->regionHasMapToken(regionVertex);
    std::cout << "How many token do you want to put on this region?" << std::endl;
    unsigned int count = (hasMapToken ? getUserInput<3>(_raceTokens.size()) : getUserInput<2>(_raceTokens.size()));
    //Move token to region.
    for (unsigned int i = 0; i < count; ++i)
    {
        std::unique_ptr<RaceToken> token;
        _raceTokens.take(0, token);
        _map->addRaceTokenToRegion(regionVertex, token);
    }
    _isFirstTurn = false;
}*/

void Player::redeploy(unsigned int count)
{

    //place count tokens on owned regions
    std::cout << "Redeploy " << count << " tokens for player: " << _playerID << std::endl;

    bool isDone = false;

    do {
        std::cout << "Ender a region ID you own to redistribute tokens, select -1 to end redeploy." << std::endl;
        int selection = getUserInput<-1>(_map->getNumRegions() - 1);

        if (selection == -1)
        {
            isDone = true;
            continue;
        }

        Vertex regionVertex;
        _map->findVertex(selection, regionVertex);

        if (_map->currentRegionOwner(regionVertex) != _playerID && _map->currentRegionOwner(regionVertex) != -1)
        {
            std::cout << "You do not own this region!!" << std::endl;
            isDone = false;
            continue;
        }

        //TODO: check if region has the same race

        std::cout << "How many tokens do you want to place here?" << std::endl;
        selection = getUserInput<0>(count);
        count -= selection;

        for (unsigned int i = 0; i < selection; ++i)
        {
            std::unique_ptr<RaceToken> token;
            _raceTokens.take(0, token);
            _map->putRaceTokenInRegion(regionVertex, std::move(token));
        }

    } while (!isDone);





}

void Player::giveBackRaceToken(std::unique_ptr<RaceToken> &&token)
{
    _raceTokens.place_back(std::move(token));
}

int Player::numTokensRequiredToConquer(const Vertex &v)
{
    int num = 2;

    VertexDataPropertyMap dataMap = boost::get(vertex_data, *_map->getGraph());

    //Has a token (mountain)
    if (dataMap[v]._token != nullptr)
    {
        ++num;
    }

    //Cavern power
    if (_currentSpecialPower->kind == ESpecialPower::UNDERWORLD && dataMap[v].hasFeature(RegionFeature::CAVERN))
    {
        --num;
    }

    //Mounted power
    if (_currentSpecialPower->kind == ESpecialPower::MOUNTED
        && (dataMap[v]._type == RegionType::HILL
        || dataMap[v]._type == RegionType::FARM))
    {
        --num;
    }

    //Commando power
    if (_currentSpecialPower->kind == ESpecialPower::COMMANDO)
    {
        --num;
    }

    //Berserk power
    if (_currentSpecialPower->kind == ESpecialPower::BERSERK)
    {
        std::cout << "BERSERK: Do you want to roll the dice? Select 0 for no and 1 for yes" << std::endl;
        unsigned int selection = getUserInput<0>(1);
        if (selection == 1)
        {
            unsigned int diceVal = _dice.getDiceValue(1)[0];
            std::cout << "Got value " << diceVal << std::endl;
            num -= diceVal;
        }

    }

    //Minumum of 1
    if (num < 1)
    {
        num = 1;
    }

    return num;
}

void Player::redeploy()
{

    //TODO: Take tokens
    unsigned int numTokenTaken = 0;

    redeploy(numTokenTaken);
}
