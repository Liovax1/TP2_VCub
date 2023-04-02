#ifndef DIALOGCSEUILALARME_H
#define DIALOGCSEUILALARME_H

#include <QDialog>
#include <QColor>
#include <QColorDialog>


namespace Ui {
class DialogCSeuilAlarme;
}

class DialogCSeuilAlarme : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCSeuilAlarme(QWidget *parent = nullptr);
    DialogCSeuilAlarme(Ui::DialogCSeuilAlarme *ui);
    DialogCSeuilAlarme(Ui::DialogCSeuilAlarme *ui);
    ~DialogCSeuilAlarme();

    Ui::DialogCSeuilAlarme *getUi() const;
    void setUi(Ui::DialogCSeuilAlarme *newUi);


    const QColor &getPCouleurAlarme() const;
    void setPCouleurAlarme(const QColor &newPCouleurAlarme);

    const QColor &getPCouleurHorsAlarme() const;
    void setPCouleurHorsAlarme(const QColor &newPCouleurHorsAlarme);

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::DialogCSeuilAlarme *ui;
    QColor pCouleurAlarme;
    QColor pCouleurHorsAlarme;
    CSeuilAlarme *pSeuilAlarme;
    CSeuilAlarme *pSeuilHorsAlarme;


};

#endif // DIALOGCSEUILALARME_H
