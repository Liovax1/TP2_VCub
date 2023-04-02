#include "dialogcseuilalarme.h"
#include "ui_dialogcseuilalarme.h"
#include "cseuilalarme.h"

DialogCSeuilAlarme::DialogCSeuilAlarme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCSeuilAlarme)
{
    ui->setupUi(this);
    pSeuilAlarme = cSeuilAlarme;
    ui->frame->setStyleSheet("background-color:" + pSeuilAlarme->getCseuilAlarme().name() + ";");
    ui->frame_2->setStyleSheet("background-color:" + pSeuilAlarme->getCseuilHorsAlarme().name() + ";");
}

DialogCSeuilAlarme::~DialogCSeuilAlarme()
{
    delete ui;
}
//Ui::DialogCSeuilAlarme *DialogCSeuilAlarme::getUi() const
//{
//    return ui;
//}

DialogCSeuilAlarme::DialogCSeuilAlarme(Ui::DialogCSeuilAlarme *ui) : ui(ui)
{

}


DialogCSeuilAlarme::~DialogCSeuilAlarme()
{
    delete ui;
}

Ui::DialogCSeuilAlarme *DialogCSeuilAlarme::getUi() const
{
    return ui;
}

void DialogCSeuilAlarme::setUi(Ui::DialogCSeuilAlarme *newUi)
{
    ui = newUi;
}

void DialogCSeuilAlarme::on_pushButton_released()
{
    QColor couleur = QColorDialog::getColor();
    if (couleur.isValid()){
        pCouleurAlarme = couleur;
    ui-> frame->setStyleSheet("background-color:" + pSeuilAlarme-> getCseuilAlarme().name() + ";");
}
}



void DialogCSeuilAlarme::on_pushButton_2_released()
{
    QColor couleur2 = QColorDialog::getColor();
    if (couleur2.isValid()){
        pCouleurHorsAlarme = couleur2;
    ui-> frame_2->setStyleSheet("background-color:" + pSeuilHorsAlarme-> getCseuilHorsAlarme().name() + ";");
}
}



