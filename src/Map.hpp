
/*
 * This answer on stackoverflow helped me understand property maps that BGL uses.
 * https://stackoverflow.com/questions/671714/modifying-vertex-properties-in-a-boostgraph
 * */

#pragma once

#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/connected_components.hpp"
#include "boost/graph/graph_traits.hpp"
#include "boost/graph/graphml.hpp"
#include "boost/graph/graphviz.hpp"
#include "boost/graph/subgraph.hpp"
#include "boost/graph/properties.hpp"

#include "boost/archive/xml_iarchive.hpp"
#include "boost/archive/xml_oarchive.hpp"
#include "boost/serialization/list.hpp"
#include "boost/serialization/string.hpp"

#include "MapProperties.hpp"
#include "RegionNode.hpp"


//! Custom property for vertex data
enum vertex_data_t
{
    vertex_data
};

//! Custom property for the display text.
//! Will be used to display text in the cells in the graphviz export
enum vertex_displaytxt_t
{
    vertex_displaytxt
};

enum graph_info_t
{
    graph_info
};

enum graph_info2_t
{
    graph_info2
};

// Registering the new properties
namespace boost
{
    BOOST_INSTALL_PROPERTY(vertex, data);
    BOOST_INSTALL_PROPERTY(vertex, displaytxt);
    BOOST_INSTALL_PROPERTY(graph, info);
    BOOST_INSTALL_PROPERTY(graph, info2);
}

//! The graph. Uses BGL.
//! Created a graph with an adjacency list implementation.
//! It includes the custom properties I defined above.
typedef boost::subgraph<
        boost::adjacency_list<
                boost::vecS,
                boost::vecS,
                boost::undirectedS,

                boost::property<boost::vertex_index_t, int,
                boost::property<vertex_data_t, RegionNode,
                boost::property<vertex_displaytxt_t, std::string>>>,

                boost::property<boost::edge_index_t, int>,

                boost::property<graph_info_t, MapProperties>
        >> SGraph;

//! Type for the vertices
typedef typename boost::graph_traits<SGraph>::vertex_descriptor Vertex;
//! Type for the edges
typedef typename boost::graph_traits<SGraph>::edge_descriptor Edge;

//! Type for the vertex iterator, used to go through the list of vertices
typedef typename boost::graph_traits<SGraph>::vertex_iterator VertexIterator;

//! Type for the PropertyMap of the vertex data.
//! Used to extract the node data.
typedef typename boost::property_map<SGraph, vertex_data_t>::type VertexDataPropertyMap;
//! Type for the PropertyMap of the displaytxt, used to get/set the data to be displlayed in the graphVis output.
typedef typename boost::property_map<SGraph, vertex_displaytxt_t>::type VertexDisplaytxtPropertyMap;


//! Main map class
class Map
{

public:

    //! Map constructor
    Map() = default;
    explicit Map(unsigned int numTurns);


    //! \brief Loads a map

    //! Load a map from the provided file. Exceptions will occurr if the file
    //! does not follow the format.
    //! \param fileName Path of the file to be loaded
    //! \return Result of the connectivity validation, true is a pass.
    bool importMap(std::string fileName);

    //! \brief Exports a map

    //! Saves a map to the provided file. This is used when
    //! generating maps from code.
    //! \param fileName Path of the file to be saved.
    void exportMap(std::string fileName);

    std::string exportMapGraphViz();

    //! \bfief Exports a map in GraphViz format.

    //! Saves a map to the provided file. This is used when
    //! generating maps from code in order to visualize the final result.
    //! \param fileName Path of the file to be saved.
    void exportMapGraphViz(std::string fileName);


    //! \brief Get the graph
    SGraph* getGraph()
    {
        return &_mainGraph;
    }

    //! \brief Gets the number of turns for the map
    unsigned int getMapNumTurns();
    //! \brief Incerments the current turn counter and returns the new value
    unsigned int incrementCurrentTurn();


    //! \brief Creates a subgraph

    //! Creates a subgraph from the main graph.
    //! \return A subgraph object.
    SGraph& createSubGraph();

    //! \brief Creates a subgraph

    //! Creates a subgraph from the the provided subgraph.
    //! \param subGraph Subgraph containing the subgraph to be generated.
    //! \return A subgraph object.
    SGraph& createSubGraph(SGraph& subGraph);


    //! \brief Adds a region to the graph

    //! Adds a RegionNode to the main graph.
    //! \param region Region to be added to the main graph.
    //! \return The resulting Vertex object.
    Vertex addRegion(const RegionNode& region);

    //! \brief Adds a region to the provided subgraph

    //! Adds a RegionNode to the provided subgraph.
    //! \param region Region to be added to the subgraph.
    //! \param subGraph Subgraph that will contain region.
    //! \return The resulting Vertex object.
    Vertex addRegion(const Vertex& regionVertex, SGraph& subGraph);

    //! \brief Adds an edge between the provided region vertices

    //! Creates an edge between the provided region vertices from the main graph.
    //! Used when generating maps from code.
    //! \param v1 Vertex of a region
    //! \param v2 Vertex of a region
    //! \return The resulting edge
    Edge connectRegion(const Vertex& v1, const Vertex& v2);

    //! \brief Adds an edge between the provided region vertices

    //! Creates an edge between the provided region vertices from a subgraph.
    //! Used when generating maps from code.
    //! \param v1 Vertex of a region in the subgraph
    //! \param v2 Vertex of a region  in the subgraph
    //! \param subGraph the subgraph to add the edge in
    //! \return The resulting edge
    Edge connectRegion(const Vertex& v1, const Vertex& v2, SGraph& subGraph);


    //! \brief Connection verification

    //! Verifies whether the main graph is connected or not
    //! \return true if the graph is connected, false otherwise.
    bool isConnected();

    //! \brief Connection verification

    //! Verifies whether the provided subgraph is connected or not.
    //! \param subGraph Subgraph to be verified
    //! \return true if the subgraph is connected, false otherwise.
    bool isConnected(SGraph &subGraph);

private:

    SGraph _mainGraph;
};
