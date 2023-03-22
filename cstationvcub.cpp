#include "cstationvcub.h"

///
/// \file       cstationvcub.cpp
/// \authors
///     Professeur  : Patrice Speziali
///     Etudiant    :
/// \date      23/02/2018
/// \version    1.0
///
/// \brief      Classe pour de stockage des infos d'une station de VCub
///

CStationVCub::CStationVCub()
{
}
///
/// \brief CStationVCub::CStationVCub
/// \param gid
/// \param nom
/// \param nbVeloDispo
/// \param nbPlaceDispo
/// \param connect
/// \param dateMaj
/// \param latitude
/// \param longitude
///
CStationVCub::CStationVCub(int gid, QString nom, int nbVeloDispo, int nbPlaceDispo, bool connect, QString dateMaj, float latitude, float longitude):mGID(gid), mNom(nom) , mNbVeloDispo(nbVeloDispo), mNbPlaceDispo(nbPlaceDispo), mConnect(connect), mDateMaj (dateMaj)
{
    mGID = gid ; mNom = nom ; mNbVeloDispo = nbVeloDispo ; mNbPlaceDispo = nbPlaceDispo ;
    mConnect = connect ; mDateMaj = dateMaj ; mLatitude = latitude ; mLongitude = longitude ;
}

QString CStationVCub::nom() const
{
    return mNom;
}

void CStationVCub::setNom(const QString &nom)
{
    mNom = nom;
}

bool CStationVCub::connect() const
{
    return mConnect;
}

void CStationVCub::setConnect(bool connect)
{
    mConnect = connect;
}

QString CStationVCub::dateMaj() const
{
    return mDateMaj;
}

void CStationVCub::setDateMaj(const QString &dateMaj)
{
    mDateMaj = dateMaj;
}

float CStationVCub::latitude() const
{
    return mLatitude;
}

void CStationVCub::setLatitude(float lattitude)
{
    mLatitude = lattitude;
}

float CStationVCub::longitude() const
{
    return mLongitude;
}

void CStationVCub::setLongitude(float longitude)
{
    mLongitude = longitude;
}

int CStationVCub::nbVeloClassiqDispo() const
{
    return mNbVeloClassiqDispo;
}

void CStationVCub::setNbVeloClassiqDispo(int nbVeloClassiqDispo)
{
    mNbVeloClassiqDispo = nbVeloClassiqDispo;
}

int CStationVCub::nbVeloElecDispo() const
{
    return mNbVeloElecDispo;
}

void CStationVCub::setNbVeloElecDispo(int nbVeloElecDispo)
{
    mNbVeloElecDispo = nbVeloElecDispo;
}

int CStationVCub::nbVeloDispo() const
{
    return mNbVeloDispo;
}

void CStationVCub::setNbVeloDispo(int nbVeloDispo)
{
    mNbVeloDispo = nbVeloDispo;
}

int CStationVCub::nbPlaceDispo() const
{
    return mNbPlaceDispo;
}

void CStationVCub::setNbPlaceDispo(int nbPlaceDispo)
{
    mNbPlaceDispo = nbPlaceDispo;
}

int CStationVCub::gidStation() const
{
    return mGID;
}

void CStationVCub::setGIDStation(int idStation)
{
    mGID = idStation;
}
