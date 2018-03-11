//
// Created by cyberunner23 on 2/23/18.
//

#include "VacuumTray.hpp"

VacuumTray::VacuumTray()
{

    //Setup map tokens
    for (unsigned int i = 0; i < 10; i++)
    {
        _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::TROLL_LAIR)));
    }

    for (unsigned int i = 0; i < 6; i++)
    {
        _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::FORTRESS)));
    }

    for (unsigned int i = 0; i < 9; i++)
    {
        _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::MOUNTAIN)));
    }

    for (unsigned int i = 0; i < 5; i++)
    {
        _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::ENCAMPMENT)));
    }

    _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::HOLES_IN_GROUND)));
    _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::HOLES_IN_GROUND)));
    _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::HERO)));
    _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::HERO)));
    _mapTokens.place_back(std::move(std::make_unique<MapToken>(EMapToken::DRAGON)));


    //Setup Special Powers
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::ALCHEMIST,     4)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::BERSERK,       4)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::BIVOUACKING,   5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::BLANK,         0)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::COMMANDO,      4)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::DIPLOMAT,      5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::DRAGON_MASTER, 5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::FLYING,        5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::FOREST,        4)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::FORTIFIED,     3)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::HEROIC,        5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::HILL,          4)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::MERCHANT,      2)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::MOUNTED,       5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::PILLAGING,     5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::SEAFARING,     5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::SPIRIT,        5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::STOUT,         4)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::SWAMP,         4)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::UNDERWORLD,    5)));
    _specialPowers.place_back(std::move(std::make_unique<SpecialPower>(ESpecialPower::WEALTHY,       4)));

    //Setup Race Banners
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::AMAZON,   6)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::DWARVE,   3)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::GIANT,    6)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::ELVE,     6)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::GHOUL,    5)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::RATMEN,   8)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::SKELETON, 6)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::SORCERER, 5)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::TRITON,   6)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::HALFLING, 6)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::HUMAN,    5)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::ORC,      5)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::WIZARD,   5)));
    _raceBanners.place_back(std::move(std::make_unique<RaceBanner>(ERaceBanner::TROLL,    5)));

    //Setup Coins
    for (unsigned int i = 0; i < 35; i++)
    {
        _coins.place_back(std::move(std::make_unique<VictoryCoin>(EVictoryCoin::VAL_1)));
    }

    for (unsigned int i = 0; i < 20; i++)
    {
        _coins.place_back(std::move(std::make_unique<VictoryCoin>(EVictoryCoin::VAL_3)));
    }

    for (unsigned int i = 0; i < 24; i++)
    {
        _coins.place_back(std::move(std::make_unique<VictoryCoin>(EVictoryCoin::VAL_5)));
    }

    for (unsigned int i = 0; i < 30; i++)
    {
        _coins.place_back(std::move(std::make_unique<VictoryCoin>(EVictoryCoin::VAL_10)));
    }
}

bool VacuumTray::takeToken(const MapToken &valueKind, std::unique_ptr<MapToken> &value)
{
    return _mapTokens.take(valueKind, value);
}

bool VacuumTray::takeToken(const SpecialPower& valueKind, std::unique_ptr<SpecialPower>& value)
{
    return _specialPowers.take(valueKind, value);
}

bool VacuumTray::takeToken(const RaceBanner& valueKind, std::unique_ptr<RaceBanner>& value)
{
    return _raceBanners.take(valueKind, value);
}

bool VacuumTray::takeToken(const VictoryCoin& valueKind, std::unique_ptr<VictoryCoin>& value)
{
    return _coins.take(valueKind, value);
}


bool VacuumTray::takeRandomRaceBanner(std::unique_ptr<RaceBanner> &value)
{
    _raceBanners.randomize();
    return _raceBanners.take(0, value);
}

bool VacuumTray::takeRandomSpecialPower(std::unique_ptr<SpecialPower> &value)
{
    _specialPowers.randomize();
    return _specialPowers.take(0, value);
}


void VacuumTray::placeToken(std::unique_ptr<MapToken> &&value)
{
    _mapTokens.place_back(std::move(value));
}

void VacuumTray::placeToken(std::unique_ptr<SpecialPower>&& value)
{
    _specialPowers.place_back(std::move(value));
}

void VacuumTray::placeToken(std::unique_ptr<RaceBanner>&& value)
{
    _raceBanners.place_back(std::move(value));
}

void VacuumTray::placeToken(std::unique_ptr<VictoryCoin>&& value)
{
    _coins.place_back(std::move(value));
}
