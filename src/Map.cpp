//
// Created by cyberunner23 on 2/8/18.
//

#include "Map.hpp"

bool Map::importMap(std::string fileName)
{

    std::ifstream in(fileName);
    boost::dynamic_properties dp;
    dp.property("node", boost::get(vertex_data, _mainGraph));

    boost::read_graphml(in, _mainGraph, dp);

    return isConnected();
}

void Map::exportMap(std::string fileName)
{
    std::ofstream out(fileName);
    boost::dynamic_properties dp;
    dp.property("node", boost::get(vertex_data, _mainGraph));

    boost::write_graphml(out, _mainGraph, dp, true);
}

void Map::exportMapGraphViz(std::string fileName)
{
    std::ofstream out(fileName);
    boost::dynamic_properties dp;
    dp.property("node_id", boost::get(boost::vertex_index, _mainGraph));
    dp.property("label", boost::get(vertex_displaytxt, _mainGraph));

    boost::write_graphviz_dp(out, _mainGraph, dp);
}


SGraph& Map::createSubGraph()
{
    return _mainGraph.create_subgraph();
}

SGraph& Map::createSubGraph(SGraph &subGraph)
{
    return subGraph.create_subgraph();
}


Vertex Map::addRegion(const RegionNode& region)
{
    Vertex v = boost::add_vertex(_mainGraph);

    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    VertexDisplaytxtPropertyMap displayMap = boost::get(vertex_displaytxt, _mainGraph);

    displayMap[v] = region._name;
    dataMap[v] = std::move(region);

    return v;
}

Vertex Map::addRegion(const Vertex& regionVertex, SGraph& subGraph)
{
    return boost::add_vertex(regionVertex, subGraph);
}

Edge Map::connectRegion(const Vertex& v1, const Vertex& v2)
{
    return connectRegion(v1, v2, _mainGraph);
}

Edge Map::connectRegion(const Vertex& v1, const Vertex& v2, SGraph& subGraph)
{
    return boost::add_edge(v1, v2, subGraph).first;
}

bool Map::isConnected()
{
    return isConnected(_mainGraph);
}

bool Map::isConnected(SGraph &graph)
{
    std::vector<int> component(boost::num_vertices(graph));
    return boost::connected_components(graph, &component[0]) == 1;
}
