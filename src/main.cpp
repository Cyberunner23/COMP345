


//refs: https://stackoverflow.com/questions/671714/modifying-vertex-properties-in-a-boostgraph
//https://stackoverflow.com/questions/19360643/how-to-access-boost-subgraph-graph-properties

#include <memory>
#include <string>

#include <QtCore>
#include <QtWidgets>

#include "Game.hpp"
#include "GraphView.hpp"

#include "Tokens/VacuumTray.hpp"

void initUI(std::string graphVizStr);

std::unique_ptr<GraphView> view;
std::unique_ptr<Game> game;

//! driver for the game, to be implemented later.
int main(int argc, char** argv)
{
    qRegisterMetaType<std::shared_ptr<Map>>("std::shared_ptr<Map>");

    QApplication app(argc, argv);

    view = std::make_unique<GraphView>();
    game = std::make_unique<Game>();

    QObject::connect(&*game, SIGNAL(updateUI(std::shared_ptr<Map>)), &*view, SLOT(updateGraph(std::shared_ptr<Map>)));

    game->start();

    return app.exec();
}

