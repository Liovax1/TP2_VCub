#ifndef CSEUILALARME_H
#define CSEUILALARME_H

#include <QColor>
#include <QObject>

class CSeuilAlarme : public QObject
{
    Q_OBJECT

public:
    CSeuilAlarme();

    int getPSeuilAlarme() const;
    void setPSeuilAlarme(int newPSeuilAlarme);

private :

    int pSeuilAlarme;
    QColor pCouleurAlarme;
    QColor pCouleurHorsAlarme;


};

#endif // CSEUILALARME_H
