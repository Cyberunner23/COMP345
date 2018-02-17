
#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "boost/archive/xml_iarchive.hpp"
#include "boost/archive/xml_oarchive.hpp"
#include "boost/serialization/list.hpp"
#include "boost/serialization/string.hpp"

#include "Tokens.hpp"

enum class RegionType
{
    FARM,
    FOREST,
    HILL,
    MARSH,
    MOUNTAIN,
    SEA
};

enum class RegionFeature
{
    CAVERN,
    MAGIC_SOURCE,
    MINE,
    NONE
};

struct RegionNode
{

    std::string _name;

    RegionType _type;
    MapToken _token;
    std::list<RegionFeature> _feature;
    bool _isLostTribe;

    std::list<RaceToken> _raceTokens;


    //Serialization is my friend
    friend class boost::serialization::access;
    friend class boost::archive::save_access;
    friend inline std::ostream &operator<<(std::ostream &oStream, const RegionNode &regionNode);
    friend inline std::istream &operator>>(std::istream &iStream, RegionNode &regionNode);


    //! \brief Default constructor

    //! Constructor used when deserializing map files. The friend classes
    //! will populate the member functions.
    RegionNode()
            : _type(RegionType::SEA)
            , _token(MapToken::NONE)
            , _feature(std::list<RegionFeature>{RegionFeature::NONE})
            , _isLostTribe(false)
    {}

    //! \brief Parameterized constructor

    //! Constructor for a region allowing to set the member variables
    //! in order to create regions inside code, in the case where
    //! the code generates map files.
    //! \param name Name of the region
    //! \param owner Owner of the region
    //! \param tokens Tokens placed on the region
    RegionNode(RegionType type, MapToken token, std::list<RegionFeature> feature, bool isLostTribe)
            : _type(type)
            , _token(token)
            , _feature(feature)
            , _isLostTribe(isLostTribe)
    {}

private:

    //! Serialization function
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & boost::serialization::make_nvp("RegionType", _type);
        ar & boost::serialization::make_nvp("MapToken", _token);
        ar & boost::serialization::make_nvp("RegionFeature", _feature);
        ar & boost::serialization::make_nvp("IsLostTribe", _isLostTribe);
    }
};


//! Operator overload for ostream
//! \param oStream Stream to sent data to
//! \param regionNode Node to be sent into the stream
//! \return The original ostream
std::ostream &operator<<(std::ostream &oStream, const RegionNode &regionNode)
{
    boost::archive::xml_oarchive oArchive(oStream);
    oArchive << boost::serialization::make_nvp("RegionNode", regionNode);

    return oStream;
}

//! Operator overload for istream
//! \param iStream Stream to get data from
//! \param regionNode Node to put data into
//! \return The original istream
std::istream &operator>>(std::istream &iStream, RegionNode &regionNode)
{
    boost::archive::xml_iarchive iArchive(iStream);
    iArchive >> boost::serialization::make_nvp("RegionNode", regionNode);

    return iStream;
}
