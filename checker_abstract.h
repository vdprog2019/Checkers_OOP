#ifndef CHECKER_ABSTRACT_H
#define CHECKER_ABSTRACT_H

#include <QIcon>

class checker_abstract
{
public:
    int position_X;
    bool isCrown;
    QIcon icon;
public:
    checker_abstract(int pos_x);
    checker_abstract();
    virtual void moveNext(int to);
    virtual void Dead();

        int getX(){
                return this->position_X;
        }

        bool getisCrown(){
            return this->isCrown;
        }
        virtual void setAsCrown(){
            this->isCrown = true;
        }

        QIcon& getIcon(){
            return this->icon;
        }

};

#endif // CHECKER_ABSTRACT_H
