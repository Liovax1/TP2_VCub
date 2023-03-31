#include "cseuilalarme.h"

CSeuilAlarme::CSeuilAlarme()
{

}

int CSeuilAlarme::getPSeuilAlarme() const
{
    return pSeuilAlarme;
}

void CSeuilAlarme::setPSeuilAlarme(int newPSeuilAlarme)
{
    pSeuilAlarme = newPSeuilAlarme;
}

const QColor &CSeuilAlarme::getPCouleurAlarme() const
{
    return pCouleurAlarme;
}

void CSeuilAlarme::setPCouleurAlarme(const QColor &newPCouleurAlarme)
{
    pCouleurAlarme = newPCouleurAlarme;
}

const QColor &CSeuilAlarme::getPCouleurHorsAlarme() const
{
    return pCouleurHorsAlarme;
}

void CSeuilAlarme::setPCouleurHorsAlarme(const QColor &newPCouleurHorsAlarme)
{
    pCouleurHorsAlarme = newPCouleurHorsAlarme;
}

CSeuilAlarme::CSeuilAlarme(int pSeuilAlarme, QColor pCouleurAlarme, QColor pCouleurHorsAlarme, QDialog *parent)
{

}


