
#pragma once

#include <iostream>
#include <memory>

#include <QByteArray>
#include <QHBoxLayout>
#include <QShortcut>
#include <QtSvg/QtSvg>
#include "gvc.h"

class GraphView : public QWidget
{

Q_OBJECT

public:
    GraphView();

public slots:
    void updateGraph(std::string graphVizStr);
    void exit();

private:

    std::unique_ptr<QShortcut> _exitShortcut;

    std::unique_ptr<QHBoxLayout> _layout;
    std::unique_ptr<QSvgWidget> _svgViewer;

};
