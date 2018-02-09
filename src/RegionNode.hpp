
#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "boost/serialization/list.hpp"
#include "boost/serialization/string.hpp"

class RegionNode
{

    friend class boost::serialization::access;
    friend class boost::archive::save_access;
    friend inline std::ostream &operator<<(std::ostream &oStream, const RegionNode &regionNode);
    friend inline std::istream &operator>>(std::istream &iStream, RegionNode &regionNode);

public:
    RegionNode(){}
    RegionNode(std::string name, std::string owner, std::list<int> tokens)
            : _name(name)
            , _owner(owner
            ), _tokens(tokens)
    {}

    void print()
    {
        std::cout << _name << std::endl;
        std::cout << _owner << std::endl;
        for (int i : _tokens)
        {
            std::cout << i << std::endl;
        }
    }

private:
    std::string _name;
    std::string _owner;
    std::list<int> _tokens;



    template <class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & _name;
        ar & _owner;
        ar & _tokens;
    }
};

std::ostream &operator<<(std::ostream &oStream, const RegionNode &regionNode)
{
    boost::archive::text_oarchive oArchive(oStream);
    oArchive << regionNode;

    return oStream;
}

std::istream &operator>>(std::istream &iStream, RegionNode &regionNode)
{
    boost::archive::text_iarchive iArchive(iStream);
    iArchive >> regionNode;

    return iStream;
}
