#ifndef CSTATIONVCUBGESTIONNAIRE_H
#define CSTATIONVCUBGESTIONNAIRE_H

#include "cstationvcub.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QXmlStreamReader>


#include <QObject>


#include "cstationvcub.h"

class CStationVCubGestionnaire : public QObject
{
    Q_OBJECT
public:
    explicit CStationVCubGestionnaire(QObject *parent = 0);
    CStationVCub * DemandeInfos (int idStation) ;
    void LireStation (int idStation) ;

signals:
    void on_LectureBalise (CStationVCub * balise) ;

public slots:
     void reponseVCubGestion (QNetworkReply *reponse) ;

private :

    QNetworkAccessManager mNetworkManager ;
    QNetworkRequest mRequest ;
    QNetworkReply* mCurrentReply ;
    CStationVCub* mptrStation;



    int findLigneByIdLigne (int id);

};

#endif // CSTATIONVCUBGESTIONNAIRE_H
