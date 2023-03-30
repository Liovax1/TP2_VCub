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
