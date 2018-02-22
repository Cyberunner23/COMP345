


//refs: https://stackoverflow.com/questions/671714/modifying-vertex-properties-in-a-boostgraph
//https://stackoverflow.com/questions/19360643/how-to-access-boost-subgraph-graph-properties



#include <QtCore>
#include <QtWidgets>
#include <QtSvg/QtSvg>
#include <QHBoxLayout>

#include "GraphView.hpp"
#include "Map.hpp"

//! driver for the game, to be implemented later.
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Map map;
    GraphView* view = new GraphView;

    map.importMap("TestData/2player.map");


    QWidget* w = new QWidget;
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(view);

    w->setLayout(hLayout);
    w->show();

    view->updateGraph(map.exportMapGraphViz());




    app.exec();
}
