
#include "GameDeck.hpp"

bool GameDeck::takeToken(const SpecialPower& valueKind, SpecialPower& value)
{
    TakeTokenImpl(valueKind, value, _specialPowers);
}

bool GameDeck::takeToken(const MapToken& valueKind, MapToken& value)
{
    TakeTokenImpl(valueKind, value, _mapTokens);
}

bool GameDeck::takeToken(const RaceBanner& valueKind, RaceBanner& value)
{
    TakeTokenImpl(valueKind, value, _raceBanners);
}

bool GameDeck::takeToken(const RaceToken& valueKind, RaceToken& value)
{
    TakeTokenImpl(valueKind, value, _raceTokens);
}

bool GameDeck::takeToken(const VictoryCoin& valueKind, VictoryCoin& value)
{
    TakeTokenImpl(valueKind, value, _coins);
}


bool GameDeck::placeToken(SpecialPower& value)
{
    PlaceTokenImpl(value, _specialPowers);
}

bool GameDeck::placeToken(MapToken& value)
{
    PlaceTokenImpl(value, _mapTokens);
}

bool GameDeck::placeToken(RaceBanner& value)
{
    PlaceTokenImpl(value, _raceBanners);
}

bool GameDeck::placeToken(RaceToken& value)
{
    PlaceTokenImpl(value, _raceTokens);
}

bool GameDeck::placeToken(VictoryCoin& value)
{
    PlaceTokenImpl(value, _coins);
}


unsigned int GameDeck::getSpecialPowersTokenListSize() const
{
    return (unsigned int)_specialPowers.size();
}

unsigned int GameDeck::getMapTokensTokenListSize() const
{
    return (unsigned int)_mapTokens.size();
}

unsigned int GameDeck::getRaceBannersTokenListSize() const
{
    return (unsigned int)_raceBanners.size();
}

unsigned int GameDeck::getRaceTokensTokenListSize() const
{
    return (unsigned int)_raceTokens.size();
}

unsigned int GameDeck::getCoinsTokenListSize() const
{
    return (unsigned int)_coins.size();
}


std::vector<SpecialPower>* GameDeck::getSpecialPowersTokenList()
{
    return &_specialPowers;
}

std::vector<MapToken>* GameDeck::getMapTokensTokenList()
{
    return &_mapTokens;
}

std::vector<RaceBanner>* GameDeck::getRaceBannersTokenList()
{
    return &_raceBanners;
}

std::vector<RaceToken>* GameDeck::getRaceTokensTokenList()
{
    return &_raceTokens;
}

std::vector<VictoryCoin>* GameDeck::getCoinsTokenList()
{
    return &_coins;
}


void GameDeck::removeMapTokensAlreadyInMap(Map& map)
{
    SGraph* graph = map.getGraph();
    VertexDataPropertyMap dataMap = boost::get(vertex_data, *graph);

    std::pair<VertexIterator, VertexIterator> vp;

    for (vp = boost::vertices(*graph); vp.first != vp.second; ++vp.first)
    {
        MapToken token;
        takeToken(dataMap[*vp.first]._token, token);
    }
}

