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
    ~DialogCSeuilAlarme();

    const QColor &getPColorAlarme() const;
    void setPColorAlarme(const QColor &newPColorAlarme);

    const QColor &getPColorNoAlarme() const;
    void setPColorNoAlarme(const QColor &newPColorNoAlarme);

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::DialogCSeuilAlarme *ui;
    QColor pColorAlarme;
    QColor pColorNoAlarme;


};

#endif // DIALOGCSEUILALARME_H
