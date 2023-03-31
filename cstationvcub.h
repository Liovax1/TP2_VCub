#ifndef CSTATIONVCUB_H
#define CSTATIONVCUB_H

///
/// \file       cstationvcub.h
/// \authors
///     Professeur  : Patrice Speziali
///     Etudiant    : Liova Hovakimyan
/// \date      31/03/2023
/// \version    1.0
///
/// \brief      Classe pour de stockage des infos d'une station de VCub
///

#include <QObject>
#include <QDate>
#include <QString>
///
/// \class  CStationVCub
/// \brief  stockage des infos d'une station de VCub
///
class CStationVCub
{
public:
    CStationVCub();
    CStationVCub(int gid, QString nom, int nbVeloDispo, int nbPlaceDispo, bool connect, QString dateMaj, float latitude, float longitude);

    int gidStation() const;
    void setGIDStation(int gidStation);

    QString nom() const;
    void setNom(const QString &nom);

    int nbVeloDispo() const;
    void setNbVeloDispo(int nbVeloDispo);

    int nbPlaceDispo() const;
    void setNbPlaceDispo(int nbPlaceDispo);

    bool connect() const;
    void setConnect(bool connect);

    QString dateMaj() const;
    void setDateMaj(const QString &dateMaj);

    float latitude() const;
    void setLatitude(float latitude);

    float longitude() const;
    void setLongitude(float longitude);

    int nbVeloClassiqDispo() const;
    void setNbVeloClassiqDispo(int nbVeloClassiqDispo);

    int nbVeloElecDispo() const;
    void setNbVeloElecDispo(int nbVeloElecDispo);

private:
    int mGID ; //GID de la station
    QString mNom ;
    int mNbVeloDispo ;
    int mNbPlaceDispo ;

    int mNbVeloClassiqDispo ;
    int mNbVeloElecDispo ;

    QString mDateMaj ;
    bool mConnect = false ;

    float mLatitude ;
    float mLongitude ;
};

#endif // CSTATIONVCUB_H
