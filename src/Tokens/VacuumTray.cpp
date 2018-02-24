//
// Created by cyberunner23 on 2/23/18.
//

#include "VacuumTray.hpp"

VacuumTray::VacuumTray()
{

    //Setup map tokens
    for (unsigned int i = 0; i < 10; i++)
    {
        _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::TROLL_LAIR)));
    }

    for (unsigned int i = 0; i < 6; i++)
    {
        _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::FORTRESS)));
    }

    for (unsigned int i = 0; i < 9; i++)
    {
        _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::MOUNTAIN)));
    }

    for (unsigned int i = 0; i < 5; i++)
    {
        _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::ENCAMPMENT)));
    }

    _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::HOLES_IN_GROUND)));
    _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::HOLES_IN_GROUND)));
    _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::HERO)));
    _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::HERO)));
    _mapTokens.push_back(std::move(std::make_unique<MapToken>(EMapToken::DRAGON)));


    //Setup Special Powers
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::ALCHEMIST)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::BERSERK)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::BIVOUACKING)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::BLANK)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::COMMANDO)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::DIPLOMAT)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::DRAGON_MASTER)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::FLYING)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::FOREST)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::FORTIFIED)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::HEROIC)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::HILL)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::MERCHANT)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::MOUNTED)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::PILLAGING)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::SEAFARING)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::SPIRIT)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::STOUT)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::SWAMP)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::UNDERWORLD)));
    _specialPowers.push_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::WEALTHY)));

    //Setup Race Banners
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::AMAZON)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::DWARVE)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::GIANT)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::ELVE)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::GHOUL)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::RATMEN)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::SKELETON)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::SORCERER)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::TRITON)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::HALFLING)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::HUMAN)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::ORC)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::WIZARD)));
    _raceBanners.push_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::TROLL)));

    //Setup Coins
    for (unsigned int i = 0; i < 35; i++)
    {
        _coins.push_back(std::move(std::make_unique<VictoryCoin>(EVictoryCoin::VAL_1)));
    }

    for (unsigned int i = 0; i < 20; i++)
    {
        _coins.push_back(std::move(std::make_unique<VictoryCoin>(EVictoryCoin::VAL_3)));
    }

    for (unsigned int i = 0; i < 24; i++)
    {
        _coins.push_back(std::move(std::make_unique<VictoryCoin>(EVictoryCoin::VAL_5)));
    }

    for (unsigned int i = 0; i < 30; i++)
    {
        _coins.push_back(std::move(std::make_unique<VictoryCoin>(EVictoryCoin::VAL_10)));
    }
}

bool VacuumTray::takeToken(const MapToken &valueKind, std::unique_ptr<MapToken> &value)
{
    return TakeTokenImpl(valueKind, value, _mapTokens);
}

bool VacuumTray::takeToken(const SpecialPower& valueKind, std::unique_ptr<SpecialPower>& value)
{
    return TakeTokenImpl(valueKind, value, _specialPowers);
}

bool VacuumTray::takeToken(const RaceBanner& valueKind, std::unique_ptr<RaceBanner>& value)
{
    return TakeTokenImpl(valueKind, value, _raceBanners);
}

bool VacuumTray::takeToken(const VictoryCoin& valueKind, std::unique_ptr<VictoryCoin>& value)
{
    return TakeTokenImpl(valueKind, value, _coins);
}


bool VacuumTray::takeRandomRaceBanner(std::unique_ptr<RaceBanner> &value)
{

    if(_raceBanners.empty())
    {
        return false;
    }

    //Randomize race banner order
    std::random_shuffle(_raceBanners.begin(), _raceBanners.end());

    value = std::move(*_raceBanners.begin());
    _raceBanners.erase(_raceBanners.begin());
    std::vector<std::unique_ptr<RaceBanner>>(std::move_iterator(_raceBanners.begin()), std::move_iterator(_raceBanners.end())).swap(_raceBanners);

    return true;
}

bool VacuumTray::takeRandomSpecialPower(std::unique_ptr<SpecialPower> &value)
{
    if(_specialPowers.empty())
    {
        return false;
    }

    //Randomize race banner order
    std::random_shuffle(_specialPowers.begin(), _specialPowers.end());

    value = std::move(*_specialPowers.begin());
    _specialPowers.erase(_specialPowers.begin());
    std::vector<std::unique_ptr<SpecialPower>>(std::move_iterator(_specialPowers.begin()), std::move_iterator(_specialPowers.end())).swap(_specialPowers);

    return true;
}


void VacuumTray::placeToken(std::unique_ptr<MapToken> &&value)
{
    PlaceTokenImpl(std::move(value), _mapTokens);
}

void VacuumTray::placeToken(std::unique_ptr<SpecialPower>&& value)
{
    PlaceTokenImpl(std::move(value), _specialPowers);
}

void VacuumTray::placeToken(std::unique_ptr<RaceBanner>&& value)
{
    PlaceTokenImpl(std::move(value), _raceBanners);
}

void VacuumTray::placeToken(std::unique_ptr<VictoryCoin>&& value)
{
    PlaceTokenImpl(std::move(value), _coins);
}
