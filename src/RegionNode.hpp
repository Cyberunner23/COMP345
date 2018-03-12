
#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "boost/archive/xml_iarchive.hpp"
#include "boost/archive/xml_oarchive.hpp"
#include "boost/serialization/list.hpp"
#include "boost/serialization/string.hpp"

#include "Tokens/EMapToken.hpp"
#include "Tokens/ERaceToken.hpp"

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
    RegionType _type;//
    MapToken* _token;//
    std::list<RegionFeature> _features;//
    bool _isLostTribe;//
    bool _isEdge;//
    int ownerID;//

    std::vector<RaceToken*> _raceTokens;

    std::string getDisplayText()
    {
        std::string regionID = std::to_string(_vertexIndex);
        std::string regionType = std::string(_isEdge ? "[E] ": "") + std::string(_isLostTribe ? "[L]" : "") + regionTypeStr(_type);

        std::string mapToken;
        if (_token != nullptr)
        {
            mapToken = "Map Token: " + mapTokenStr(*_token);
            mapToken.append("\n");
        }


        std::string features;
        for (RegionFeature& feature : _features)
        {
            features.append(regionFeatureStr(feature));
            features.append(" ");
        }

        if (!features.empty())
        {
            features.append("\n");
        }


        std::string owner;
        if (ownerID > 0)
        {
            owner = "Owned by player #" + std::to_string(ownerID) + "\n";
        }


        std::string raceTokens;
        for (auto token : _raceTokens)
        {
            QString str;
            QTextStream stream(&str);

            stream << *token;
            raceTokens.append(str.toStdString());
            raceTokens.append("\n");
        }

        return regionID + "\n" + regionType + "\n" + mapToken + features + owner + raceTokens;
    }


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
            , _token(nullptr)
            , _features(std::list<RegionFeature>{RegionFeature::NONE})
            , _isLostTribe(false)
            , _isEdge(false)
            , ownerID(-1)
    {}

    //! \brief Parameterized constructor

    //! Constructor for a region allowing to set the member variables
    //! in order to create regions inside code, in the case where
    //! the code generates map files.
    //! \param name Name of the region
    //! \param owner Owner of the region
    //! \param tokens Tokens placed on the region
    RegionNode(RegionType type, std::list<RegionFeature> feature, bool isLostTribe, bool isEdge)
            : _type(type)
            , _features(feature)
            , _isLostTribe(isLostTribe)
            , _isEdge(isEdge)
            , ownerID(-1)
    {}

    //! Sets the vertex index, mirrors the value in BGL
    void setVertexID(int index)
    {
        _vertexIndex = index;
    }

    //! Helper to know if the region has a certain modifier
    bool hasFeature(RegionFeature feature)
    {
        auto it = std::find(_features.begin(), _features.end(), feature);
        return it != _features.end();
    }

private:

    int _vertexIndex;

    //! Serialization function
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & boost::serialization::make_nvp("RegionType", _type);
        ar & boost::serialization::make_nvp("RegionFeature", _features);
        ar & boost::serialization::make_nvp("IsLostTribe", _isLostTribe);
        ar & boost::serialization::make_nvp("IsEdge", _isEdge);
    }

    //! Stringification for RegionType
    std::string regionTypeStr(RegionType regionType)
    {
        switch (regionType)
        {
            case RegionType::FARM:
                return "FARM";
            case RegionType::FOREST:
                return "FOREST";
            case RegionType::HILL:
                return "HILL";
            case RegionType::MARSH:
                return "MARSH";
            case RegionType::MOUNTAIN:
                return "MOUNTAIN";
            case RegionType::SEA:
                return "SEA";
        }
    }

    //! Stringification for RegionFeature
    std::string regionFeatureStr(RegionFeature regionFeature)
    {
        switch (regionFeature)
        {
            case RegionFeature::CAVERN:
                return "CAVERN";
            case RegionFeature::MAGIC_SOURCE:
                return "MAGIC_SOURCE";
            case RegionFeature::MINE:
                return "MINE";
            case RegionFeature::NONE:
                return "";
        }
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
