//
// Created by cyberunner23 on 2/21/18.
//

#include "GraphView.hpp"

void GraphView::updateGraph(std::string graphVizStr)
{
    Agraph_t* graph = agmemread(graphVizStr.data());
    GVC_t*    ctx   = gvContext();

    gvLayout(ctx, graph, "dot");


    char* data;
    unsigned int length;
    gvRenderData (ctx, graph, "svg", &data, &length);

    QByteArray svgData(data, length);
    this->load(svgData);
}
