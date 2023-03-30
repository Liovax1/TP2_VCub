#ifndef DIALOG_SEUILS_ALARMES_H
#define DIALOG_SEUILS_ALARMES_H

#include <QDialog>

namespace Ui {
class Dialog_seuils_alarmes;
}

class Dialog_seuils_alarmes : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_seuils_alarmes(QWidget *parent = nullptr);
    ~Dialog_seuils_alarmes();

private:
    Ui::Dialog_seuils_alarmes *ui;
};

#endif // DIALOG_SEUILS_ALARMES_H
