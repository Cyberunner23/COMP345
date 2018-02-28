
#pragma once

#include <QTextStream>

#include "Tokens.hpp"

enum class EVictoryCoin
{
    VAL_1,
    VAL_3,
    VAL_5,
    VAL_10
};

typedef Token<EVictoryCoin> VictoryCoin;

inline QTextStream &operator<<(QTextStream &os, const Token<EVictoryCoin>& token)
{

    switch (token.kind)
    {
        case EVictoryCoin::VAL_1:
            os << "1";
            break;
        case EVictoryCoin::VAL_3:
            os << "3";
            break;
        case EVictoryCoin::VAL_5:
            os << "5";
            break;
        case EVictoryCoin::VAL_10:
            os << "10";
            break;
    }

    return os;
}

/*inline std::ostream &operator<<(std::ostream &os, const Token<EVictoryCoin>& token)
{
}*/
