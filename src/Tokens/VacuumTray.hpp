
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
#include "TokenVec.hpp"

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

    TokenVec<MapToken>     _mapTokens;
    TokenVec<SpecialPower> _specialPowers;
    TokenVec<RaceBanner>   _raceBanners;
    TokenVec<VictoryCoin>  _coins;

};
