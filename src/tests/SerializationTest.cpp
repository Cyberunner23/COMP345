
#include <fstream>
#include <iostream>

#include "../RegionNode.hpp"

int main(int argc, char** argv)
{

    RegionNode node(RegionType::SEA, MapToken::NONE, RegionFeature::NONE, false);
    std::ofstream oStream("test.thing");
    oStream << node;

    std::ifstream iStream("test.thing");
    RegionNode node2;
    iStream >> node2;

    std::cout << node2;
}