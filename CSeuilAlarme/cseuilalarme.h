#ifndef CSEUILALARME_H
#define CSEUILALARME_H

#include <QColor>
#include <QObject>

class CSeuilAlarme : public QObject
{
    Q_OBJECT

public:
    CSeuilAlarme();
    CSeuilAlarme(int seuilAlarme, QColor couleurAlarme, QColor couleurHorsAlarme);
    int getPSeuilAlarme() const;
    void setPSeuilAlarme(int newPSeuilAlarme);

    const QColor &getPCouleurAlarme() const;
    void setPCouleurAlarme(const QColor &newPCouleurAlarme);

    const QColor &getPCouleurHorsAlarme() const;
    void setPCouleurHorsAlarme(const QColor &newPCouleurHorsAlarme);

private :

    int pSeuilAlarme;
    QColor pCouleurAlarme;
    QColor pCouleurHorsAlarme;


};

#endif // CSEUILALARME_H
