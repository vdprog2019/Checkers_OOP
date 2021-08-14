#ifndef CHECKER_BLACK_H
#define CHECKER_BLACK_H
#include "checker_abstract.h"

class checker_black : public checker_abstract
{
public:
    checker_black(int pos_x) ;
    checker_black() : checker_abstract(){}

    void setAsCrown() override{
        checker_abstract::setAsCrown();
        this->icon = QIcon(":/damka.png");
    }
};

#endif // CHECKER_BLACK_H
