
#include "GraphView.hpp"

GraphView::GraphView()
{
    _exitShortcut = std::make_unique<QShortcut>(QKeySequence(Qt::CTRL + Qt::Key_Q), this);
    QObject::connect(_exitShortcut.get(), &QShortcut::activated,
                     this,                &GraphView::exit);

    _layout = std::make_unique<QVBoxLayout>();

    _turnCounter = std::make_unique<QLabel>();
    _turnCounter->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    _svgViewer = std::make_unique<QSvgWidget>();

    _layout->addWidget(_turnCounter.get());
    _layout->addWidget(_svgViewer.get());
    this->setLayout(_layout.get());
}

void GraphView::updateGraph(std::shared_ptr<Map> map)
{



    if (!this->isVisible())
    {
        this->show();
    }

    {
        //Update turn counter
        unsigned int numTurns = map->getMapNumTurns();
        unsigned int currentTurn = map->getCurrentTurn();

        std::strstream displayStr;
        displayStr << "Turn: ";
        for (int i = 1; i <= numTurns; i++)
        {
            if (i == currentTurn)
            {
                displayStr << "X ";
            }
            else
            {
                displayStr << i << " ";
            }
        }

        _turnCounter->setText(QString::fromStdString(displayStr.str()));
    }

    {
        //Update Graph
        std::string graphVizStr = map->exportMapGraphViz();
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


}

void GraphView::exit()
{
    QApplication::exit(0);
}
