
#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "boost/archive/xml_iarchive.hpp"
#include "boost/archive/xml_oarchive.hpp"
#include "boost/serialization/list.hpp"
#include "boost/serialization/string.hpp"

enum RegionType
{
    CAVE,
    FARM,
    FOREST,
    HILL,
    LOST_TRIBE,
    MAGIC,
    MINE,
    MOUNTAIN,
    SEA,
    SWAMP
};

struct RegionNode
{
    //Serialization is my friend
    friend class boost::serialization::access;
    friend class boost::archive::save_access;
    friend inline std::ostream &operator<<(std::ostream &oStream, const RegionNode &regionNode);
    friend inline std::istream &operator>>(std::istream &iStream, RegionNode &regionNode);

public:

    std::string _name;

    //! \brief Default constructor

    //! Constructor used when deserializing map files. The friend classes
    //! will populate the member functions.
    RegionNode() : _type(SEA)
    {}

    //! \brief Parameterized constructor

    //! Constructor for a region allowing to set the member variables
    //! in order to create regions inside code, in the case where
    //! the code generates map files.
    //! \param name Name of the region
    //! \param owner Owner of the region
    //! \param tokens Tokens placed on the region
    RegionNode(std::string name, std::string owner, std::list<int> tokens)
            : _type(SEA)
            , _name(std::move(name))
            , _owner(std::move(owner))
            , _tokens(std::move(tokens))
    {}

private:

    RegionType _type;

    std::string _owner;
    std::list<int> _tokens;

    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & boost::serialization::make_nvp("Type", _type);
        ar & boost::serialization::make_nvp("Name", _name);
        ar & boost::serialization::make_nvp("Owner", _owner);
        ar & boost::serialization::make_nvp("Tokens", _tokens);
    }
};


std::ostream &operator<<(std::ostream &oStream, const RegionNode &regionNode)
{
    boost::archive::xml_oarchive oArchive(oStream);
    oArchive << boost::serialization::make_nvp("RegionNode", regionNode);

    return oStream;
}

std::istream &operator>>(std::istream &iStream, RegionNode &regionNode)
{
    boost::archive::xml_iarchive iArchive(iStream);
    iArchive >> boost::serialization::make_nvp("RegionNode", regionNode);

    return iStream;
}

