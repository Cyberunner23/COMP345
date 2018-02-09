
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "boost/graph/graph_traits.hpp"
//#include "boost/graph/subgraph.hpp"
#include "boost/graph/adjacency_list.hpp"
#include <boost/graph/graphml.hpp>


/*struct RegionNode
{
    std::string name;
    std::string owner;
    int tokens[100];
};

RegionNode node1;
RegionNode node2;
RegionNode node3;

RegionNode regions[] = {
        node1,
        node2,
        node3
};

enum ERegions
{
    REGION_1,
    REGION_2,
    REGION_3,
    N
};

typedef std::pair<int, int> Edge;

Edge links[] = {
        Edge(REGION_1, REGION_2),
        Edge(REGION_2, REGION_3),
        Edge(REGION_3, REGION_1)
};

const int NEDGES = sizeof(links) / sizeof(Edge);

typedef boost::adjacency_list< boost::vecS, boost::vecS, boost::directedS,
boost::property< boost::vertex_color_t, RegionNode>
> UGraph;

UGraph gg(links, links + NEDGES, N);

*/


/*
enum files_e { dax_h, yow_h, boz_h, zow_h, foo_cpp,
    foo_o, bar_cpp, bar_o, libfoobar_a,
    zig_cpp, zig_o, zag_cpp, zag_o,
    libzigzag_a, killerapp, N };
const char* name[] = { "dax.h", "yow.h", "boz.h", "zow.h", "foo.cpp",
                       "foo.o", "bar.cpp", "bar.o", "libfoobar.a",
                       "zig.cpp", "zig.o", "zag.cpp", "zag.o",
                       "libzigzag.a", "killerapp" };
Edge used_by[] = {
        Edge(dax_h, foo_cpp), Edge(dax_h, bar_cpp), Edge(dax_h, yow_h),
        Edge(yow_h, bar_cpp), Edge(yow_h, zag_cpp),
        Edge(boz_h, bar_cpp), Edge(boz_h, zig_cpp), Edge(boz_h, zag_cpp),
        Edge(zow_h, foo_cpp),
        Edge(foo_cpp, foo_o),
        Edge(foo_o, libfoobar_a),
        Edge(bar_cpp, bar_o),
        Edge(bar_o, libfoobar_a),
        Edge(libfoobar_a, libzigzag_a),
        Edge(zig_cpp, zig_o),
        Edge(zig_o, libzigzag_a),
        Edge(zag_cpp, zag_o),
        Edge(zag_o, libzigzag_a),
        Edge(libzigzag_a, killerapp)
};

const int nedges = sizeof(used_by)/sizeof(Edge);

typedef boost::adjacency_list< boost::vecS, boost::vecS, boost::directedS,
boost::property< boost::vertex_color_t, std::string >
> Graph;*/


int main(int argc, char** argv)
{

    //boost::dynamic_properties dp;
    //dp.property("rhing", boost::get(boost::vertex_color_t(), gg));

    //boost::write_graphml(std::cout, gg, dp, true);

    return 0;
}