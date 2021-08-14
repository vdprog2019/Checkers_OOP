#ifndef CHECKER_WHITE_H
#define CHECKER_WHITE_H
#include "checker_abstract.h"

class checker_white : public checker_abstract
{
public:
    checker_white(int pos_x);
    checker_white() : checker_abstract(){}
    void setAsCrown() override{
        checker_abstract::setAsCrown();
        this->icon = QIcon(":/damka_white.png");
    }
};

#endif // CHECKER_WHITE_H
