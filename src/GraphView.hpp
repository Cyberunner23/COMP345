
#pragma once

#include <iostream>
#include <memory>
#include <strstream>

#include <QByteArray>
#include <QVBoxLayout>
#include <QShortcut>
#include <QtSvg/QtSvg>
#include "gvc.h"

#include "Map.hpp"

class GraphView : public QWidget
{

Q_OBJECT

public:
    GraphView();

public slots:
    void updateGraph(std::shared_ptr<Map> map);
    void exit();

private:

    std::unique_ptr<QShortcut> _exitShortcut;

    std::unique_ptr<QVBoxLayout> _mainVLayout;
    std::unique_ptr<QLabel> _turnCounter;

    std::unique_ptr<QHBoxLayout> _mainHLayout;
    std::unique_ptr<QSvgWidget> _svgViewer;

    std::unique_ptr<QVBoxLayout> _specialPowerLayout;
    std::unique_ptr<QVBoxLayout> _raceBannerLayout;
    std::vector<std::unique_ptr<QLabel>> _specialPowers;
    std::vector<std::unique_ptr<QLabel>> _raceBanners;

    //Labels
    std::unique_ptr<QLabel> _specialPowersLabel;
    std::unique_ptr<QLabel> _specialPowersStackLabel;

    std::unique_ptr<QLabel> _raceBannersLabel;
    std::unique_ptr<QLabel> _raceBannersStackLabel;

};
