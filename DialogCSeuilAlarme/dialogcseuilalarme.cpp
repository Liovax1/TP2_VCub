#include "dialogcseuilalarme.h"
#include "ui_dialogcseuilalarme.h"

DialogCSeuilAlarme::DialogCSeuilAlarme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCSeuilAlarme)
{
    ui->setupUi(this);
}

DialogCSeuilAlarme::~DialogCSeuilAlarme()
{
    delete ui;
}
//Ui::DialogCSeuilAlarme *DialogCSeuilAlarme::getUi() const
//{
//    return ui;
//}

void DialogCSeuilAlarme::on_pushButton_released()
{
    QColor couleur = QColorDialog::getColor();
    if (couleur.isValid())
        pColorAlarme = couleur;
    ui-> frame->setStyleSheet("background-color:" + couleur.name() + ";");
}




void DialogCSeuilAlarme::on_pushButton_2_released()
{
    QColor couleur2 = QColorDialog::getColor();
    if (couleur2.isValid())
        pColorAlarme = couleur2;
    ui-> frame_2->setStyleSheet("background-color:" + couleur2.name() + ";");
}



