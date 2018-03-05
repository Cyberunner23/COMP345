
#include "GraphView.hpp"

GraphView::GraphView()
{
    _exitShortcut = std::make_unique<QShortcut>(QKeySequence(Qt::CTRL + Qt::Key_Q), this);
    QObject::connect(_exitShortcut.get(), &QShortcut::activated,
                     this,                &GraphView::exit);

    _mainVLayout = std::make_unique<QVBoxLayout>();
    _turnCounter = std::make_unique<QLabel>();

    _mainHLayout = std::make_unique<QHBoxLayout>();
    _specialPowerLayout = std::make_unique<QVBoxLayout>();
    _raceBannerLayout = std::make_unique<QVBoxLayout>();
    _svgViewer = std::make_unique<QSvgWidget>();



    _turnCounter->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    _mainVLayout->addWidget(_turnCounter.get());
    _mainVLayout->addLayout(_mainHLayout.get());

    _mainHLayout->addLayout(_specialPowerLayout.get());
    _mainHLayout->addLayout(_raceBannerLayout.get());
    _mainHLayout->addWidget(_svgViewer.get());



    {
        //Setup special power layout
        _specialPowersLabel = std::make_unique<QLabel>(QString("SPECIAL POWERS"));
        _specialPowersStackLabel = std::make_unique<QLabel>(QString("STACK"));
        _specialPowersLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        _specialPowersStackLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        _specialPowerLayout->addWidget(_specialPowersLabel.get());

        for (unsigned int i = 0; i < 6; ++i)
        {
            //Create label and keep track of it.
            std::unique_ptr<QLabel> power = std::make_unique<QLabel>(QString(""));
            power->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
            _specialPowers.push_back(std::move(power));
        }

        for (unsigned int i = 0; i < 5; ++i)
        {
            //Add 5 labels to layout
            _specialPowerLayout->addWidget(_specialPowers[i].get());
        }
        //Add stack label
        _specialPowerLayout->addWidget(_specialPowersStackLabel.get());
        //Add last label, used as top of the stack view
        _specialPowerLayout->addWidget(_specialPowers[5].get());
    }

    {
        //Setup race banner layout
        _raceBannersLabel = std::make_unique<QLabel>(QString("RACES"));
        _raceBannersStackLabel = std::make_unique<QLabel>(QString("STACK"));
        _raceBannersLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        _raceBannersStackLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        _raceBannerLayout->addWidget(_raceBannersLabel.get());
        for (unsigned int i = 0; i < 6; ++i)
        {
            std::unique_ptr<QLabel> banner = std::make_unique<QLabel>();
            banner->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
            _raceBanners.push_back(std::move(banner));
        }

        for(unsigned int i = 0; i < 5; ++i)
        {
            //Add 5 labels to layout
            _raceBannerLayout->addWidget(_raceBanners[i].get());
        }
        //Add stack label
        _raceBannerLayout->addWidget(_raceBannersStackLabel.get());
        //Add last label, used as top of the stack view
        _raceBannerLayout->addWidget(_raceBanners[5].get());
    }


    this->setLayout(_mainVLayout.get());
}

void GraphView::updateGraph(Map* map,
                            std::vector<std::unique_ptr<RaceBanner>> *selectionRaceBanners,
                            std::stack<std::unique_ptr<RaceBanner>> *remainingRaceBanners,
                            std::vector<std::unique_ptr<SpecialPower>> *selectionSpecialPowers,
                            std::stack<std::unique_ptr<SpecialPower>> *remainingSpecialPowers)
{



    if (!this->isVisible())
    {
        this->show();
    }

    {
        //Update turn counter
        unsigned int numTurns = map->getMapNumTurns();
        unsigned int currentTurn = map->getCurrentTurn();

        QString string;
        QTextStream displayStr(&string);
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

        _turnCounter->setText(string);
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
        gvFreeContext(ctx);
    }


    {
        //Update Special Power layout
        for(unsigned int i = 0; i < 5; ++i)
        {
            QString string;
            QTextStream stream(&string);
            stream << *((*selectionSpecialPowers)[i]);
            _specialPowers[i]->setText(string);
        }

        {
            QString string;
            QTextStream stream(&string);
            stream << *(*remainingSpecialPowers).top();
            _specialPowers[5]->setText(string);
        }


        for(unsigned int i = 0; i < 5; ++i)
        {
            QString string;
            QTextStream stream(&string);
            stream << *(*selectionRaceBanners)[i];
            _raceBanners[i]->setText(string);
        }

        {
            QString string;
            QTextStream stream(&string);
            stream << *(*remainingRaceBanners).top();
            _raceBanners[5]->setText(string);
        }
    }
}

void GraphView::exit()
{
    QApplication::exit(0);
}
