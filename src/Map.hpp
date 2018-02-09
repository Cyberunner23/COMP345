
#pragma once

#include <memory>
#include <string>
#include <vector>

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/subgraph.hpp"
#include "boost/graph/adjacency_list.hpp"

template <class PlayerType>
struct RegionNode
{
    std::string regionName;
    std::vector<int> tokens;
    std::shared_ptr<PlayerType> owner;
};

typedef RegionNode<std::string> Vertex;
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, Vertex> Graph;

class Map
{

};
