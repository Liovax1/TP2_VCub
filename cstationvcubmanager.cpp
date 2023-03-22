///
/// \file       cstationvcubManager.cpp
/// \authors
///     Professeur  : Patrice Speziali
///     Etudiant    :
/// \date      23/02/2018
/// \version    1.0
///
/// \brief      Interrogation du web service open data de bordeaux métropole pour récupérer
///     les infos d'une station de VCub
///
///
///
#include "cstationvcubmanager.h"
#include <QDebug>
#include <QStringList>

///
/// \brief CStationVCubManager::CStationVCubManager
/// \param cle : Clé d'interrogation du web service (https://data.bordeaux-metropole.fr/contact)
/// \param parent
///
CStationVCubManager::CStationVCubManager(QString cle, QObject *parent) : QObject(parent)
{
    mCle = cle ;
    //Instanciation d'un objet CStationVCub pour stocker les infos d'une station VCub
    mptrStation = new CStationVCub () ;

    //Mise en place de l'évenement permettant de récupérer les infos renvoyées par le web service
    connect(&mNetworkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(reponseVCubGestion(QNetworkReply*)));
}

///
/// \brief  envoie d'une requête au web service pour obtenir les informations d'une station de VCub
///         La réponse est obtenu par le slot reponseVCubGestion
///
/// \param  idStation : numéro de la station
///
void CStationVCubManager::LireStation(int idStation)
{

    //Url d'interrogation du web service avec un filtre sur le GID de la station
    //  et Géolocalisaation au format WGS84 (SRSNAME=EPSG:4326)
    // exemple interrogation station 16 : galin
    // http://data.bordeaux-metropole.fr/wfs?key=STUT1MR9RC&REQUEST=GetFeature&SERVICE=WFS&VERSION=1.1.0&TYPENAME=bm:CI_VCUB_P&SRSNAME=EPSG:4326&FILTER=%3CFilter%3E%3CPropertyIsEqualTo%3E%3CPropertyName%3EGID%3C/PropertyName%3E%3CLiteral%3E16%3C/Literal%3E%3C/PropertyIsEqualTo%3E%3C/Filter%3E&MAXFEATURES=1000
    QUrl urlCStation("http://data.bordeaux-metropole.fr/wfs?key="+mCle+"&REQUEST=GetFeature&SERVICE=WFS&VERSION=1.1.0&TYPENAME=bm:CI_VCUB_P&SRSNAME=EPSG:4326&FILTER=%3CFilter%3E%3CPropertyIsEqualTo%3E%3CPropertyName%3EGID%3C/PropertyName%3E%3CLiteral%3E"+QString::number(idStation)+"%3C/Literal%3E%3C/PropertyIsEqualTo%3E%3C/Filter%3E&MAXFEATURES=1000");

    mRequest.setUrl(urlCStation);
    mCurrentReply = mNetworkManager.get(mRequest);  // GET
}

///
/// \brief  Récupération des données de la station de VCub dans une réponse XML
///         Initialisation d'un objet de type CStationVCub
///
/// \param reponse : information de la station au format XML
///
void CStationVCubManager::reponseVCubGestion(QNetworkReply *reponse)
{
    qDebug() << "reponseVCubGestion " ;
    //  if (reponse->error() != QNetworkReply::NoError)
    //        return;

    //Récupération des données fournies par la web service au format XML
    QString qsData = (QString) reponse->readAll();
    QXmlStreamReader xmlRep (qsData);

    bool convFloat ;
    //Parcours des données au format XML pour extraction des données
    while (!xmlRep.atEnd())
    {
        xmlRep.readNext() ;
        qDebug() << xmlRep.name() ;

        if (xmlRep.name() == "NOM")
            mptrStation->setNom(xmlRep.readElementText());
        if (xmlRep.name() == "MDATE")
            mptrStation->setDateMaj(xmlRep.readElementText());
        if (xmlRep.name() == "NBVELOS")
            mptrStation->setNbVeloDispo(xmlRep.readElementText().toInt());
        if (xmlRep.name() == "NBPLACES")
            mptrStation->setNbPlaceDispo(xmlRep.readElementText().toInt());
        if (xmlRep.name() == "NBELEC")
            mptrStation->setNbVeloElecDispo(xmlRep.readElementText().toInt());
        if (xmlRep.name() == "NBCLASSIQ")
            mptrStation->setNbVeloClassiqDispo(xmlRep.readElementText().toInt());
        if (xmlRep.name() == "GID")
            mptrStation->setGIDStation(xmlRep.readElementText().toInt());
        if (xmlRep.name() == "ETAT")
        {
            if (xmlRep.readElementText() == "CONNECTEE")
                mptrStation->setConnect(true);
            else
                mptrStation->setConnect(false);
        }

        if (xmlRep.name() == "pos")
        {
            QString geoloc =  xmlRep.readElementText() ;
            QStringList listGeoloc = geoloc.split(' ') ;
            QString qsLat = listGeoloc.at(0) ;
            QString qsLong = listGeoloc.at(1);
            mptrStation->setLatitude(qsLat.toFloat(&convFloat)) ;
            mptrStation->setLongitude(qsLong.toFloat(&convFloat));
        }
    }
    //envoi du signal on_LectureBalise avec en paramétre un objetCStationVCub
    emit on_LectureBalise (mptrStation) ;

}


