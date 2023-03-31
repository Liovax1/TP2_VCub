#ifndef CSTATIONVCUBMANAGER_H
#define CSTATIONVCUBMANAGER_H

///
/// \file       CStationVCubManager.h
/// \authors
///     Professeur  : Patrice Speziali
///     Etudiant    : Liova Hovakimyan
/// \date      31/03/2023
/// \version    1.0
///
/// \brief      Interrogationdu web service open data de bordeaux métropole pour récupérer
///     les infos d'une station de VCub
///

#include "cstationvcub.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QXmlStreamReader>
#include <QObject>
///
/// \class      CStationVCubManager
/// \brief      Intérroge le web service open data de bordeaux métropole pour récupérer
///     les infos d'une station de VCub
///
/// \details
///     - site web pour interroger le service openData : http://sig.bordeaux-metropole.fr/apicub/wxsquery/
///     - clé pour interroger le web service : STUT1MR9RC
///     - url d'intérogation du web service : http://data.bordeaux-metropole.fr/wfs?key=[VOTRECLE]&REQUEST=GetFeature&SERVICE=WFS&VERSION=1.1.0&TYPENAME=bm:CI_VCUB_P&SRSNAME=EPSG:4326&FILTER=<Filter><PropertyIsEqualTo><PropertyName>GID</PropertyName><Literal>[GID_STATION]</Literal></PropertyIsEqualTo></Filter>&MAXFEATURES=1000
///
class CStationVCubManager : public QObject
{
    Q_OBJECT
public:
    explicit CStationVCubManager(QString cle, QObject *parent = 0);
    CStationVCub * DemandeInfos (int idStation) ;
    void LireStation (int idStation) ;

signals:
    void on_LectureBalise (CStationVCub * balise) ;

public slots:
    void reponseVCubGestion (QNetworkReply *reponse) ;

private :
    QNetworkAccessManager mNetworkManager ;
    QNetworkRequest mRequest ;
    QNetworkReply *mCurrentReply ;

    CStationVCub *mptrStation;
    QString mCle ;      //Clé pour interroger le web service
};

#endif // CSTATIONVCUBMANAGER_H
