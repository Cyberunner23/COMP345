
#pragma once

#include <memory>

#include <QByteArray>
#include <QtSvg/QtSvg>
#include "gvc.h"

class GraphView : public QSvgWidget
{

public slots:
    void updateGraph(std::string graphVizStr);

};
