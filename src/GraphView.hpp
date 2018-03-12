
#pragma once

#include <iostream>
#include <memory>
#include <fstream>

#include <QByteArray>
#include <QVBoxLayout>
#include <QShortcut>
#include <QtSvg/QtSvg>
#include "gvc.h"

#include "Map.hpp"
#include "Tokens/TokenStack.hpp"
#include "Tokens/TokenVec.hpp"

class GraphView : public QWidget
{

Q_OBJECT

public:
    GraphView();

public slots:

    //! Qt slot that updates the UI
    void updateGraph(Map* map,
                     const TokenVec<RaceBanner> *selectionRaceBanners,
                     const TokenStack<RaceBanner> *remainingRaceBanners,
                     const TokenVec<SpecialPower> *selectionSpecialPowers,
                     const TokenStack<SpecialPower> *remainingSpecialPowers);

    //! Qt slot that closes the game through the Ctrl+Q keybinding
    // TODO: fix the crash on shutdown
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
