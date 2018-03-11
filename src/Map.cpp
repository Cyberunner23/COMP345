
#include "Map.hpp"


Map::Map(unsigned int numPlayers, unsigned int numTurns)
{
    boost::get_property(_mainGraph, graph_info).numPlayers = numPlayers;
    boost::get_property(_mainGraph, graph_info).numTurns = numTurns;
    boost::get_property(_mainGraph, graph_info).currentTurn = 1;
}


bool Map::importMap(std::string fileName)
{

    std::ifstream in(fileName);
    boost::dynamic_properties dp;
    boost::ref_property_map<SGraph*, MapProperties> mapProperties(boost::get_property(_mainGraph, graph_info));

    dp.property("node", boost::get(vertex_data, _mainGraph));
    dp.property("info", mapProperties);

    boost::read_graphml(in, _mainGraph, dp);


    //Set node IDs
    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    VertexIndexPropertyMap indexMap = boost::get(boost::vertex_index, _mainGraph);
    std::pair<VertexIterator, VertexIterator> iterPair = boost::vertices(_mainGraph);

    for(; iterPair.first != iterPair.second; ++iterPair.first)
    {
        dataMap[*iterPair.first].setVertexID(indexMap[*iterPair.first]);
    }


    return isConnected();
}

void Map::exportMap(std::string fileName)
{
    std::ofstream out(fileName);
    boost::dynamic_properties dp;
    boost::ref_property_map<SGraph*, MapProperties> mapProperties(boost::get_property(_mainGraph, graph_info));

    dp.property("node", boost::get(vertex_data, _mainGraph));
    dp.property("info", mapProperties);

    boost::write_graphml(out, _mainGraph, dp, true);
}

std::string Map::exportMapGraphViz()
{
    std::ostringstream out;
    boost::dynamic_properties dp;

    updateNodeDisplayText();

    dp.property("node_id", boost::get(boost::vertex_index, _mainGraph));
    dp.property("label", boost::get(vertex_displaytxt, _mainGraph));

    boost::write_graphviz_dp(out, _mainGraph, dp);

    return out.str();
}

void Map::exportMapGraphViz(std::string fileName)
{
    std::ofstream out(fileName);
    boost::dynamic_properties dp;
    dp.property("node_id", boost::get(boost::vertex_index, _mainGraph));
    dp.property("label", boost::get(boost::vertex_index, _mainGraph));

    boost::write_graphviz_dp(out, _mainGraph, dp);
}


unsigned int Map::getNumPlayers()
{
    return boost::get_property(_mainGraph, graph_info).numPlayers;
}

unsigned int Map::getMapNumTurns()
{
    return boost::get_property(_mainGraph, graph_info).numTurns;
}

unsigned int Map::getCurrentTurn()
{
    return boost::get_property(_mainGraph, graph_info).currentTurn;
}

unsigned int Map::incrementCurrentTurn()
{
    return ++boost::get_property(_mainGraph, graph_info).currentTurn;
}


bool Map::addTokensToMap(std::shared_ptr<RemovableStorageTray> storageTray, std::shared_ptr<VacuumTray> vacuumTray)
{
    std::pair<VertexIterator, VertexIterator> iterPair = boost::vertices(_mainGraph);
    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);

    bool isSuccess = true;
    for(; iterPair.first != iterPair.second && isSuccess; ++iterPair.first)
    {

        if (dataMap[*iterPair.first]._isLostTribe)
        {
            std::unique_ptr<RaceToken> lostTribeToken;
            isSuccess &= storageTray->takeRaceToken(RaceToken(ERaceToken::LOST_TRIBE), lostTribeToken);

            if (isSuccess)
            {
                //dataMap[*iterPair.first]._raceTokens.place_back(std::move(lostTribeToken));
            }
        }

        if (dataMap[*iterPair.first]._type == RegionType::MOUNTAIN)
        {
            std::unique_ptr<MapToken> mountainToken;
            isSuccess &= vacuumTray->takeToken(MapToken(EMapToken::MOUNTAIN), mountainToken);

            if (isSuccess)
            {
                dataMap[*iterPair.first]._token = mountainToken.get();
            }
        }
    }

    return isSuccess;
}


SGraph& Map::createSubGraph()
{
    return _mainGraph.create_subgraph();
}

SGraph& Map::createSubGraph(SGraph &subGraph)
{
    return subGraph.create_subgraph();
}


Vertex Map::addRegion(RegionNode region)
{
    Vertex v = boost::add_vertex(_mainGraph);

    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    VertexDisplaytxtPropertyMap displayMap = boost::get(vertex_displaytxt, _mainGraph);
    VertexIndexPropertyMap indexMap = boost::get(boost::vertex_index, _mainGraph);

    region.setVertexID((int)indexMap[v]);
    displayMap[v] = region.getDisplayText();
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


void Map::updateNodeDisplayText()
{
    std::pair<VertexIterator, VertexIterator> iterPair = boost::vertices(_mainGraph);
    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    VertexDisplaytxtPropertyMap displayMap = boost::get(vertex_displaytxt, _mainGraph);

    for(; iterPair.first != iterPair.second; ++iterPair.first)
    {
        displayMap[*iterPair.first] = dataMap[*iterPair.first].getDisplayText();
    }
}

/*
bool Map::findVertex(int index, Vertex& vertex)
{

    std::pair<VertexIterator, VertexIterator> iterPair = boost::vertices(_mainGraph);
    VertexIndexPropertyMap indexMap = boost::get(boost::vertex_index, _mainGraph);

    for(; iterPair.first != iterPair.second; ++iterPair.first)
    {
        if (indexMap[*iterPair.first] == index)
        {
            vertex = *iterPair.first;
            return true;
        }
    }

    return false;
}

bool Map::isRegionOnEdge(const Vertex &vertex)
{
    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    return dataMap[vertex]._isEdge;
}

bool Map::isRegionConnectedToSea(const Vertex &vertex)
{
    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    AdjacencyIterator it, end;
    boost::tie(it, end) = boost::adjacent_vertices(vertex, _mainGraph);

    for(; it != end; ++it)
    {
        if (dataMap[*it]._type == RegionType::SEA && dataMap[*it]._isEdge)
        {
            return true;
        }
    }


    return false;
}

bool Map::regionHasMapToken(const Vertex &vertex)
{
    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    return dataMap[vertex]._token != nullptr;
}

/*void Map::addRaceTokenToRegion(const Vertex &vertex, std::unique_ptr<RaceToken> &token)
{
    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    dataMap[vertex]._raceTokens.place_back(std::move(token));
}*/

/*
bool Map::areRegiongAdjacent(const Vertex &v1, const Vertex &v2, const std::unique_ptr<SpecialPower> &power)
{

    //Are they physically adjacent
    if (boost::edge(v1, v2, _mainGraph).second)
    {
        return true;
    }

    //Test for "fake" adjacency due to special power
    if (power->kind == ESpecialPower::FLYING)
    {
        return true;
    }

    VertexDataPropertyMap dataMap = boost::get(vertex_data, _mainGraph);
    RegionNode region = dataMap[v2];
    auto cavernFeature = std::find(region._features.begin(), region._features.end(), RegionFeature::CAVERN);
    if (power->kind == ESpecialPower::UNDERWORLD && cavernFeature != region._features.end())
    {
        return true;
    }

    return false;
}


unsigned int Map::getNumRegions()
{
    return boost::num_vertices(_mainGraph);
}
*/





