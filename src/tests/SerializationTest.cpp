
#include <fstream>
#include <iostream>

#include "../RegionNode.hpp"

int main(int argc, char** argv)
{

    RegionNode node("hello", "peoplekindpeoplekind", std::list<int> {1, 2, 3, 4, 5});
    std::ofstream oStream("test.thing");
    oStream << node;

    std::ifstream iStream("test.thing");
    RegionNode node2;
    iStream >> node2;

    std::cout << node2;
}