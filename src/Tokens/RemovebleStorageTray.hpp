
#pragma once

#include <algorithm>
#include <memory>
#include <vector>

#include "ERaceToken.hpp"
#include "Tokens.hpp"

class RemovableStorageTray
{
public:

    RemovableStorageTray();

    bool takeRaceToken(const RaceToken& valueKind, std::unique_ptr<RaceToken>& value);
    void placeRaceToken(std::unique_ptr<RaceToken>&& value);

private:

    std::vector<std::unique_ptr<RaceToken>> _raceTokens;

};
