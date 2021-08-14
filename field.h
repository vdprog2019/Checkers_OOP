#ifndef FIELD_H
#define FIELD_H
#include "checker_white.h"
#include "checker_black.h"
#include <QObject>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include <QLabel>


class field

{
public:
    const static int START_COUNT_OF_CHEKERS = 12;
    const static int SIZE_ARR = 64;
    int count_black = 12;
    int count_white = 12;
    int number_from = -1;
    int number_to = -1;
    bool isWhite = true;
    bool isBtnSelected = false;
    int lastIndex;
    QPushButton *fiel[SIZE_ARR];
    checker_white *white_cheker;
    checker_black *black_checker;
    QWidget *parrent;

public:
    field();


    QPushButton* operator[](int index){
        this->lastIndex = index;
        return this->fiel[index];
    }
    void operator()(QWidget *parrent){
        this->parrent = parrent;
    }
    int getLastIndex(){
        return this->lastIndex;
    }

    const char* getColorOfWhiteCell(){
        return "background-color: yellow; border:2px solid #ff0000;";
    }
    const char* getColorOfBlackCell(){
        return "background-color: black; border:2px solid #ff0000;";
    }

    QString getStatistics(){
        QString s("Статистика по игре:\nШашек черных - ");
        s.append(QString::number(count_black));
        s.append("\nШашек белых - ");
        s.append(QString::number(count_white));
        return s;
    }

    void moveChecker(int index_field,int index_move_to){
        checker_abstract *a = nullptr;
        QMessageBox m;
        bool isBlack = false;
        int pos = getIndexByPosition_White(index_field);
        int killed_pos = -1;
        if(pos != -1){
            this->isWhite = true;
            a = &this->white_cheker[pos];
            if(a->getisCrown() == false &&
                    (index_move_to - index_field != 7 && index_move_to - index_field != 9) &&
                    (getIndexByPosition_Black(index_move_to - 7) == -1 && getIndexByPosition_Black(index_move_to - 9) == -1))
                        return;
            else{

                    if(index_move_to - index_field == 18){
                        killed_pos = getIndexByPosition_Black(index_move_to - 9);
                        if(killed_pos > 0){
                            fiel[black_checker[killed_pos].getX()]->setIcon(QIcon());
                            black_checker[killed_pos].Dead();
                            count_black --;
                        }
                    }
                        if(index_move_to - index_field == 14) {
                            killed_pos = getIndexByPosition_Black(index_move_to - 7);

                            if(killed_pos != -1 ){
                                fiel[black_checker[killed_pos].getX()]->setIcon(QIcon());
                                black_checker[killed_pos].Dead();
                                count_black --;
                            }
                        }


                if(a->getisCrown() == true){
                        if(index_move_to - index_field == -18){
                            killed_pos = getIndexByPosition_Black(index_move_to + 9);
                            if(killed_pos > 0){
                                fiel[black_checker[killed_pos].getX()]->setIcon(QIcon());
                                black_checker[killed_pos].Dead();
                                count_black --;
                        }
                        }
                         if(index_move_to - index_field == -14){
                            killed_pos = getIndexByPosition_Black(index_move_to + 7);
                            if(killed_pos != -1 ){
                                fiel[black_checker[killed_pos].getX()]->setIcon(QIcon());
                                black_checker[killed_pos].Dead();
                                count_black --;
                            }
                        }
                    }

            }

        }
        else
        {
            pos = getIndexByPosition_Black(index_field);
            this->isWhite = false;
            if(pos != -1){
              a = &this->black_checker[pos];

              //тут логика геноцида белых
            if(a->getisCrown() == false &&
                    (index_move_to - index_field != -7 && index_move_to - index_field != -9)&&
                        (getIndexByPosition_White(index_move_to + 7) == -1 && getIndexByPosition_White(index_move_to + 9) == -1))
                            return;
            else{

                        if(index_move_to - index_field == -18){
                            killed_pos = getIndexByPosition_White(index_move_to + 9);
                            m.setText(QString::number(killed_pos));
                            m.exec();
                            if(killed_pos > -1){
                                fiel[white_cheker[killed_pos].getX()]->setIcon(QIcon());
                                white_cheker[killed_pos].Dead();
                                count_white --;
                        }
                        }
                         if(index_move_to - index_field == -14){
                            killed_pos = getIndexByPosition_White(index_move_to + 7);
                            if(killed_pos != -1 ){
                                fiel[white_cheker[killed_pos].getX()]->setIcon(QIcon());
                                white_cheker[killed_pos].Dead();
                                count_white --;
                            }
                        }
                         if(a->getisCrown() == true){
                             if(index_move_to - index_field == 18){
                                 killed_pos = getIndexByPosition_White(index_move_to - 9);
                                 m.setText(QString::number(killed_pos));
                                 m.exec();
                                 if(killed_pos > -1){
                                     fiel[white_cheker[killed_pos].getX()]->setIcon(QIcon());
                                     white_cheker[killed_pos].Dead();
                                     count_white --;
                             }
                             }
                              if(index_move_to - index_field == 14){
                                 killed_pos = getIndexByPosition_White(index_move_to - 7);
                                 if(killed_pos != -1 ){
                                     fiel[white_cheker[killed_pos].getX()]->setIcon(QIcon());
                                     white_cheker[killed_pos].Dead();
                                     count_white --;
                                 }
                             }
                         }

            }
            isBlack =true;
            }
        }
        if(a != nullptr){
            this->fiel[index_field]->setIcon(QIcon());
            a->moveNext(index_move_to);
            //если это белая шашка и она пришла на последний ряд
            if(isWhite == true && a->getX() >= 56)
                a->setAsCrown();
            //если это черная шашка и она пришла на первый ряд
            if(isWhite == false && a->getX() <= 7)
                a->setAsCrown();
            this->fiel[index_move_to]->setIcon(a->getIcon());
        }
        this->win();
    }
    void uncolorizLastCell();

    bool isCellWhite(int index);
    int getIndexByPosition_White(int position);
    int getIndexByPosition_Black(int position);
    bool isCellBlack(int index);

    void win(){
        if(this->count_black == 0){
            QMessageBox m;
            m.setText("WHITE WIN!");
            m.exec();
        }
        if(this->count_white == 0){
            QMessageBox m;
            m.setText("Black WIN!");
            m.exec();
        }
    }

    void generate();
    void moveBtns();
};

#endif // FIELD_H
