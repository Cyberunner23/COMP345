


//refs: https://stackoverflow.com/questions/671714/modifying-vertex-properties-in-a-boostgraph
//https://stackoverflow.com/questions/19360643/how-to-access-boost-subgraph-graph-properties

#include <iostream>
#include <memory>
#include <vector>

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/subgraph.hpp"
#include "boost/graph/adjacency_list.hpp"
#include <boost/graph/graphml.hpp>

#include "Map.hpp"


int main(int argc, char** argv)
{

    SGraph main;
    SGraph& s1 = main.create_subgraph();
    SGraph& s2 = main.create_subgraph();

    Vertex v = add_vertex(main);

    typename boost::property_map<SGraph, vertex_data_t>::type param = get(vertex_data, main);
    typename boost::property_map<SGraph, vertex_displaytxt_t>::type param2 = get(vertex_displaytxt, main);

    param[v]._name = "hey";
    param2[v] = "ha!\\nblahrg\\n type: eyy";

    boost::dynamic_properties dp;
    dp.property("node_id", boost::get(boost::vertex_index, main));
    dp.property("label", boost::get(vertex_displaytxt, main));

    boost::dynamic_properties dp2;
    dp2.property("node", boost::get(vertex_data, main));


    write_graphviz_dp(std::cout, main, dp);
    //write_graphml(std::cout, main, dp2, true);

    //ref_property_map<Vertex*, VertexData> prop(get_property(v, vertex_data));

    //ref_property_map<SGraph*, vertex_data_t> param(get_property(main, vertex_data));

    return 0;
}


/*int main(int argc, char** argv)
{



    Map map;

    RegionNode region1("sdf", "fds", std::list<int> {5, 4, 3, 6, 7});
    RegionNode region2("asdfsadf", "sfdaasfd", std::list<int> {5, 4, 3, 6, 7});

    auto node1 = map.addRegion(region1);
    auto node2 = map.addRegion(region2);

    auto edge1 = map.connectRegion(node1, node2);

    if (!map.isConnected())
    {
        std::cout << "INVALID" << std::endl;
        return 1;
    }

    //map.exportMap("hello.xml");
    map.importMap("hello.xml");
    map.exportMapGraphViz("hello.grz");

    return 0;
}*/