//
// Created by cyberunner23 on 2/23/18.
//

#include "RemovebleStorageTray.hpp"

RemovableStorageTray::RemovableStorageTray()
{

    for (unsigned int i = 0; i < 15; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::AMAZON, 6)));
    }

    for (unsigned int i = 0; i < 8; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::DWARVE, 3)));
    }

    for (unsigned int i = 0; i < 11; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::ELVE, 6)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::GHOUL, 5)));
    }

    for (unsigned int i = 0; i < 13; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::RATMEN, 8)));
    }

    for (unsigned int i = 0; i < 20; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::SKELETON, 6)));
    }

    for (unsigned int i = 0; i < 18; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::SORCERER, 5)));
    }

    for (unsigned int i = 0; i < 11; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::TRITON, 6)));
    }

    for (unsigned int i = 0; i < 11; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::GIANT, 6)));
    }

    for (unsigned int i = 0; i < 11; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::HALFLING, 6)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::HUMAN, 5)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::ORC, 5)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::TROLL, 5)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::WIZARD, 5)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::LOST_TRIBE)));
    }

}

bool RemovableStorageTray::takeRaceToken(const RaceToken& valueKind, std::unique_ptr<RaceToken>& value)
{
    bool found = false;
    unsigned int foundIndex = 0;
    for (unsigned int i = 0; i < _raceTokens.size(); i++)
    {
        if (*_raceTokens[i] == valueKind)
        {
            found = true;
            foundIndex = i;
            break;
        }
    }

    if (!found)
    {
        return false;
    }

    value = std::move(_raceTokens[foundIndex]);
    _raceTokens.erase(_raceTokens.begin() + foundIndex);
    std::vector<std::unique_ptr<RaceToken>>(std::move_iterator(_raceTokens.begin()), std::move_iterator(_raceTokens.end())).swap(_raceTokens);

    return true;
}

void RemovableStorageTray::takeRaceToken(const RaceToken& valueKind, std::vector<std::unique_ptr<RaceToken>>& value)
{
    std::unique_ptr<RaceToken> token;
    while (takeRaceToken(valueKind, token))
    {
        value.push_back(std::move(token));
    }
}

void RemovableStorageTray::placeRaceToken(std::unique_ptr<RaceToken>&& value)
{
    value->isFaceUp = true;
    _raceTokens.push_back(std::move(value));
}
