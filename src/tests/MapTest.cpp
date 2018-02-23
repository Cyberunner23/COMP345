
#include <iostream>

#include "../Map.hpp"

void validateGraph(const std::string& mapName, Map& map, bool expected);
void validateGraph(const std::string& mapName, Map& map, SGraph& sub, bool expected);

//! Map test

//! A simple program that runs various tests for the Map class.
//! Checks whether a map as well as its subgraphs are connected.
//! No checks are needed to see if each region is a node
//! since each vertex/node in the graph contains data of type RegionNode
//! (which represents s region). No other type can be placed in the node,
//! meaning either the node is a region or doesn't exist.
int main(int argc, char** argv)
{

    {
        Map map1;

        Vertex a = map1.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex b = map1.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex c = map1.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex d = map1.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex e = map1.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex f = map1.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));

        map1.connectRegion(a, b);
        map1.connectRegion(b, d);
        map1.connectRegion(b, c);
        map1.connectRegion(c, f);
        map1.connectRegion(f, d);
        map1.connectRegion(e, f);
        map1.connectRegion(f, d);

        std::cout << "---- Map 1 is a connected graph" << std::endl;
        validateGraph("Map 1", map1, true);
    }


    {
        Map map2;

        Vertex a2 = map2.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex b2 = map2.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex c2 = map2.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex d2 = map2.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex e2 = map2.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex f2 = map2.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));

        map2.connectRegion(b2, d2);
        map2.connectRegion(b2, c2);
        map2.connectRegion(c2, f2);
        map2.connectRegion(f2, d2);
        map2.connectRegion(e2, f2);
        map2.connectRegion(f2, d2);

        std::cout << "---- Map 2 is not a connected graph" << std::endl;
        validateGraph("Map 2", map2, false);
    }


    {
        Map map3;
        SGraph &map3Sub1 = map3.createSubGraph();
        SGraph &map3Sub2 = map3.createSubGraph();

        Vertex a3 = map3.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex b3 = map3.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex c3 = map3.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex d3 = map3.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex e3 = map3.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex f3 = map3.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));

        Vertex A1 = map3.addRegion(a3, map3Sub1);
        Vertex B1 = map3.addRegion(b3, map3Sub1);

        Vertex E2 = map3.addRegion(e3, map3Sub2);
        Vertex C2 = map3.addRegion(c3, map3Sub2);
        Vertex F2 = map3.addRegion(f3, map3Sub2);

        map3.connectRegion(A1, B1, map3Sub1);
        map3.connectRegion(E2, F2, map3Sub2);
        map3.connectRegion(C2, F2, map3Sub2);

        map3.connectRegion(e3, b3);
        map3.connectRegion(b3, c3);
        map3.connectRegion(b3, d3);
        map3.connectRegion(f3, d3);

        map3.exportMapGraphViz("map3.viz");

        std::cout << "---- Map 3 is a connected graph with 2 connected subgraphs" << std::endl;
        validateGraph("Map 3", map3, true);
        validateGraph("Map 3 Sub 1", map3, map3Sub1, true);
        validateGraph("Map 3 Sub 2", map3, map3Sub2, true);
    }


    {
        Map map4;
        SGraph &map4Sub1 = map4.createSubGraph();
        SGraph &map4Sub2 = map4.createSubGraph();

        Vertex a3 = map4.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex b3 = map4.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex c3 = map4.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex d3 = map4.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex e3 = map4.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));
        Vertex f3 = map4.addRegion(RegionNode(RegionType::SEA, {RegionFeature::NONE}, false));

        Vertex A1 = map4.addRegion(a3, map4Sub1);
        Vertex B1 = map4.addRegion(b3, map4Sub1);

        Vertex E2 = map4.addRegion(e3, map4Sub2);
        Vertex C2 = map4.addRegion(c3, map4Sub2);
        Vertex F2 = map4.addRegion(f3, map4Sub2);

        map4.connectRegion(A1, B1, map4Sub1);
        map4.connectRegion(E2, F2, map4Sub2);
        map4.connectRegion(C2, F2, map4Sub2);

        std::cout << "---- Map 4 is an unconnected graph with 2 connected subgraphs" << std::endl;
        validateGraph("Map 4", map4, false);
        validateGraph("Map 4 Sub 1", map4, map4Sub1, true);
        validateGraph("Map 4 Sub 2", map4, map4Sub2, true);
    }

    return 0;
}

void validateGraph(const std::string& mapName, Map& map, bool expected)
{
    std::cout << "Checking if map \"" << mapName << "\" is valid, should be " << (expected ? "VALID" : "INVALID") << std::endl;
    std::cout << "RESULT: " << (map.isConnected() ? "VALID" : "INVALID") << std::endl;
    std::cout << std::endl;
}

void validateGraph(const std::string& mapName, Map& map, SGraph& sub, bool expected)
{
    std::cout << "Checking if map \"" << mapName << "\" is valid, should be " << (expected ? "VALID" : "INVALID") << std::endl;
    std::cout << "RESULT: " << (map.isConnected(sub) ? "VALID" : "INVALID") << std::endl;
    std::cout << std::endl;
}
