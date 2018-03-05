
#pragma once

#include <algorithm>
#include <memory>
#include <random>
#include <vector>

#include "ERaceBanner.hpp"
#include "ESpecialPower.hpp"
#include "EVictoryCoin.hpp"
#include "EMapToken.hpp"
#include "Tokens.hpp"

class VacuumTray
{

public:

    VacuumTray();

    bool takeToken(const MapToken& valueKind, std::unique_ptr<MapToken>& value);
    bool takeToken(const SpecialPower& valueKind, std::unique_ptr<SpecialPower>& value);
    bool takeToken(const RaceBanner& valueKind, std::unique_ptr<RaceBanner>& value);
    bool takeToken(const VictoryCoin& valueKind, std::unique_ptr<VictoryCoin>& value);

    bool takeRandomRaceBanner(std::unique_ptr<RaceBanner>& value);
    bool takeRandomSpecialPower(std::unique_ptr<SpecialPower>& value);

    void placeToken(std::unique_ptr<MapToken>&& value);
    void placeToken(std::unique_ptr<SpecialPower>&& value);
    void placeToken(std::unique_ptr<RaceBanner>&& value);
    void placeToken(std::unique_ptr<VictoryCoin>&& value);

private:

    std::vector<std::unique_ptr<MapToken>> _mapTokens;
    std::vector<std::unique_ptr<SpecialPower>> _specialPowers;
    std::vector<std::unique_ptr<RaceBanner>> _raceBanners;
    std::vector<std::unique_ptr<VictoryCoin>> _coins;


    template<typename TokenType>
    bool TakeTokenImpl(const TokenType& valueKind, std::unique_ptr<TokenType>& value, std::vector<std::unique_ptr<TokenType>>& var)
    {

        bool found = false;
        unsigned int foundIndex = 0;
        for (unsigned int i = 0; i < var.size(); i++)
        {
            if (*var[i] == valueKind)
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

        value = std::move(var[foundIndex]);
        var.erase(var.begin() + foundIndex);
        std::vector<std::unique_ptr<TokenType>>(std::move_iterator(var.begin()), std::move_iterator(var.end())).swap(var);

        return true;
    }

    template<typename TokenType>
    void PlaceTokenImpl(std::unique_ptr<TokenType>&& value, std::vector<std::unique_ptr<TokenType>>& var)
    {
        value->isFaceUp = true;
        var.push_back(std::move(value));
    }

};
