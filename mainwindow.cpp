#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->setupUi(this);
    setFixedSize(600, 360);

    this->label = new QLabel();
    this->label->setGeometry(390,10,200, 100);
    this->label->setParent(this);

    this->btn = new QPushButton;

//    this->btn->setGeometry(350, 10, 200,100);
//    this->btn->setText("START GAME");
//    this->btn->setParent(this);

    this->f(this);
    this->f.generate();
    for(int i = 0; i < 64; i++)
         connect(f[i], SIGNAL(clicked()), this, SLOT(buttonClick()));
    //connect(this->btn, SIGNAL(clicked()), this, SLOT(newGame()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGame(){

    this->btn->setText("");
}

void MainWindow::buttonClick(){
    QPushButton *tmp = qobject_cast<QPushButton*>(this->sender());
    int i = tmp->objectName().toInt();
    f.uncolorizLastCell();
    //проверяем что тут есть шашка
    if(tmp->icon().isNull() == true){
        int last = f.getLastIndex();
        //и что квадратик черный (ходить можно только по черным)
        if(f[i]->palette().background().color().name().contains("#000000")){
            f.moveChecker(last, i);
            this->label->setText(f.getStatistics());
        }
    }
    f[tmp->objectName().toInt()]->setStyleSheet("background-color: red");
    this->update();
}
