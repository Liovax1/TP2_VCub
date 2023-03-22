#include "cstationvcubGestionnaire.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>


CStationVCubGestionnaire::CStationVCubGestionnaire(QObject *parent) : QObject(parent)
{
    mptrStation = new CStationVCub () ;
    connect(&mNetworkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(reponseVCubGestion(QNetworkReply*)));

}




void CStationVCubGestionnaire::LireStation(int idStation)
{

    QUrl urlCStation("http://data.bordeaux-metropole.fr/wfs?key=STUT1MR9RC&REQUEST=GetFeature&SERVICE=WFS&VERSION=1.1.0&TYPENAME=bm:CI_VCUB_P&SRSNAME=EPSG:900913&FILTER=%3CFilter%3E%3CPropertyIsEqualTo%3E%3CPropertyName%3EGID%3C/PropertyName%3E%3CLiteral%3E"+QString::number(idStation)+"%3C/Literal%3E%3C/PropertyIsEqualTo%3E%3C/Filter%3E&MAXFEATURES=1000");
    urlCStation.setPath(QString("%1%2").arg(urlCStation.path()).arg(QString::number(idStation)));
    mRequest.setUrl(urlCStation);

    mCurrentReply = mNetworkManager.get(mRequest);  // GET
}

void CStationVCubGestionnaire::reponseVCubGestion(QNetworkReply *reponse)
{

    if (reponse->error() != QNetworkReply::NoError)
          return;
      QXmlStreamReader xmlRep (reponse);
//      xml.setDevice(&qfileXml);

//      QXmlStreamAttributes attribs = xml.attributes() ;
//      mptrStation->setIdStation(attribs[1].value().toString());
//      mptrStation->setNom(attribs[0].value().toString());
//      mptrStation->setNbPlaceDispo(attribs[2].value().toString());
//      mptrStation->setNbVeloDispo(attribs[3].value().toString());
//      mptrStation->setConnect(attribs[4].value().toString());
//      mptrStation->setDateMaj(attribs[5].value().toString());

//      //envoi du signal permettant de récupérer un objet de type CPiouPiou
//      emit on_LectureBalise (mptrStation) ;

}

CStationVCub *CStationVCubGestionnaire::DemandeInfos(int idStation)
{

}
