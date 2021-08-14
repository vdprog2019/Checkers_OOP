#include "field.h"
#include "checker_white.h"
#include "checker_black.h"

field::field()
{
    int pos = 1;
    this->white_cheker = new checker_white[this->START_COUNT_OF_CHEKERS];
    this->black_checker = new checker_black[this->START_COUNT_OF_CHEKERS];

    for (int i=0; i< this->START_COUNT_OF_CHEKERS;i++) {
        if(i == 4) pos --;
        if(i == 8) pos ++;
        this->white_cheker[i] = checker_white(pos);
        pos += 2;
    }
    pos = 40;
    for (int i = 0; i < START_COUNT_OF_CHEKERS ;i++) {
        if(i == 4) pos++;
        if(i == 8) pos--;
        this->black_checker[i] = checker_black(pos);
        pos +=2;
    }
}

void field::generate(){
    const int SIZE_H = 40;
    const int SIZE_W = 40;
    int h = 35;
    int w = 8;

    for (int i=0; i < 64; i++) {
            this->fiel[i] = new QPushButton(QString::number(i) ,parrent);
            this->fiel[i]->setGeometry(h, w, SIZE_H, SIZE_W);

        for (int j = 0; j < this->START_COUNT_OF_CHEKERS; j++) {
            if(i == this->white_cheker[j].getX())
                this->fiel[i]->setIcon(this->white_cheker[j].getIcon());
        }

        for (int z = 0; z < this->START_COUNT_OF_CHEKERS;z++) {
            if(i == this->black_checker[z].getX())
                this->fiel[i]->setIcon(this->black_checker[z].getIcon());
        }

        this->fiel[i]->setObjectName(QString::number(i));
        h += 35;
            this->fiel[i]->setStyleSheet("background-color: black; border:2px solid #ff0000;");


            if(i%2 != 0 ){   // каждый второй шаг
                            if( (w / 40)%2 != 0){
                                fiel[i]->setStyleSheet("background-color: yellow; border:2px solid #ff0000;");

                            }
                            if( (w / 40)%2 == 0)
                                fiel[i - 1]->setStyleSheet(this->getColorOfWhiteCell());
                          }
        if(h > 280){
            h = 35;
            w += SIZE_H;
        }

    }
}

bool field::isCellWhite(int index){
    for (int i=0; i < START_COUNT_OF_CHEKERS; i ++)
        if(this->white_cheker[i].getX() == index)
            return  true;
    return false;
}

bool field::isCellBlack(int index){
    for (int i=0; i < START_COUNT_OF_CHEKERS; i ++)
        if(this->black_checker[i].getX() == index)
            return  true;
    return false;
}
void field::uncolorizLastCell(){
    if(  ( (lastIndex / 8) % 2 == 0 && lastIndex % 2 == 1 ) || ((lastIndex / 8) % 2 == 1 && lastIndex % 2 != 1) ){
        fiel[lastIndex]->setStyleSheet(this->getColorOfBlackCell());
    }
    else {
          fiel[lastIndex]->setStyleSheet(getColorOfWhiteCell());
    }
}

int field::getIndexByPosition_White(int position){
    for (int i=0; i < START_COUNT_OF_CHEKERS; i++)
        if(this->white_cheker[i].getX() == position)
            return i;
    return  -1;
}

int field::getIndexByPosition_Black(int position){
    for (int i=0; i < START_COUNT_OF_CHEKERS; i++)
        if(this->black_checker[i].getX() == position)
            return i;
    return -1;
}
