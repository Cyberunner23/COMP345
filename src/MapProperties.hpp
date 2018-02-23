
#pragma once

struct MapProperties
{

    friend class boost::serialization::access;
    friend class boost::archive::save_access;
    friend inline std::ostream &operator<<(std::ostream &oStream, const MapProperties &regionNode);
    friend inline std::istream &operator>>(std::istream &iStream, MapProperties &regionNode);

    unsigned int numPlayers;
    unsigned int numTurns;
    unsigned int currentTurn;

private:
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & boost::serialization::make_nvp("numPlayers", numPlayers);
        ar & boost::serialization::make_nvp("numTurns", numTurns);
        ar & boost::serialization::make_nvp("currentTurn", currentTurn);
    }
};

std::ostream &operator<<(std::ostream &oStream, const MapProperties &mapProperties)
{
    boost::archive::xml_oarchive oArchive(oStream);
    oArchive << boost::serialization::make_nvp("MapProperties", mapProperties);

    return oStream;
}

std::istream &operator>>(std::istream &iStream, MapProperties &mapProperties)
{
    boost::archive::xml_iarchive iArchive(iStream);
    iArchive >> boost::serialization::make_nvp("MapProperties", mapProperties);

    return iStream;
}