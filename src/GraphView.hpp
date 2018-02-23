
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

    std::unique_ptr<QVBoxLayout> _layout;
    std::unique_ptr<QLabel> _turnCounter;
    std::unique_ptr<QSvgWidget> _svgViewer;

};
