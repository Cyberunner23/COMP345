//
// Created by cyberunner23 on 2/23/18.
//

#include "RemovebleStorageTray.hpp"

RemovableStorageTray::RemovableStorageTray()
{

    for (unsigned int i = 0; i < 15; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::AMAZON)));
    }

    for (unsigned int i = 0; i < 8; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::DWARVE)));
    }

    for (unsigned int i = 0; i < 11; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::ELVE)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::GHOUL)));
    }

    for (unsigned int i = 0; i < 13; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::RATMEN)));
    }

    for (unsigned int i = 0; i < 20; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::SKELETON)));
    }

    for (unsigned int i = 0; i < 18; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::SORCERER)));
    }

    for (unsigned int i = 0; i < 11; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::TRITON)));
    }

    for (unsigned int i = 0; i < 11; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::GIANT)));
    }

    for (unsigned int i = 0; i < 11; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::HALFLING)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::HUMAN)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::ORC)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::TROLL)));
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        _raceTokens.push_back(std::move(std::make_unique<RaceToken>(ERaceToken::WIZARD)));
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

void RemovableStorageTray::placeRaceToken(std::unique_ptr<RaceToken>&& value)
{
    value->isFaceUp = true;
    _raceTokens.push_back(std::move(value));
}
