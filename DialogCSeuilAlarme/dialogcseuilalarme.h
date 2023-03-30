#ifndef DIALOGCSEUILALARME_H
#define DIALOGCSEUILALARME_H

#include <QDialog>

namespace Ui {
class DialogCSeuilAlarme;
}

class DialogCSeuilAlarme : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCSeuilAlarme(QWidget *parent = nullptr);
    ~DialogCSeuilAlarme();

private:
    Ui::DialogCSeuilAlarme *ui;
};

#endif // DIALOGCSEUILALARME_H
