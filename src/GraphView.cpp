//
// Created by cyberunner23 on 2/21/18.
//

#include "GraphView.hpp"

GraphView::GraphView()
{
    _exitShortcut = std::make_unique<QShortcut>(QKeySequence(Qt::CTRL + Qt::Key_Q), this);
    QObject::connect(_exitShortcut.get(), &QShortcut::activated,
                     this,                &GraphView::exit);


    _layout = std::make_unique<QHBoxLayout>();
    _svgViewer = std::make_unique<QSvgWidget>();

    _layout->addWidget(_svgViewer.get());
    this->setLayout(_layout.get());
}

void GraphView::updateGraph(std::string graphVizStr)
{
    Agraph_t* graph = agmemread(graphVizStr.data());
    GVC_t*    ctx   = gvContext();

    gvLayout(ctx, graph, "dot");


    char* data;
    unsigned int length;
    gvRenderData (ctx, graph, "svg", &data, &length);

    QByteArray svgData(data, length);
    _svgViewer->load(svgData);

    delete graph;
    //Not deleting ctx since compiler warns against it...
}

void GraphView::exit()
{
    QApplication::exit(0);
}
