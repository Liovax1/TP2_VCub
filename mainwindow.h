#ifndef MAINWINDOW_H
#define MAINWINDOW_H
///
/// \file       mainwindow.h
/// \authors
///     Professeur  : Patrice Speziali
///     Etudiant    :
/// \date      23/02/2018
/// \version    1.0
///
/// \brief      Programme permettant d'afficher les information d'une sation de
///             VCub de la métropole de Bordeaux.
///             Les données sont extraites via le web service de l'open data de la métropole de Bordeaux
///             Pour fonctionner il faut posséder un clé d'interrogation à demander via le site de l'open data de la métropole de Bordeaux
///
///
#include <QMainWindow>
#include <QMessageBox>
#include <QWebEngineView>


#include "cstationvcub.h"
#include "cstationvcubmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pbDemandeInfos_released();

    void on_listHisto_clicked(const QModelIndex &index);
    void on_pbSupprimer_released();
    void on_pbToutSupprimer_released();
    void on_ReceptionInfo (CStationVCub *ptrStVCub) ;

    void on_spinBoxZoom_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QWebEngineView *mView = nullptr ;

    CStationVCub *ptrStVCub = nullptr ;
    CStationVCubManager *mPtrVCubManager = nullptr ;

    const QString cssCouleur_Normale = "background-color: green ;";
    const QString cssCouleurAlarme = "background-color: red ;}";

    const int mAlerteNbVeloDispo = 5 ;  //constante pour faire evoluer la couleur des QFrame
    const int mAlerteNbPlaceDispo = 4 ; //constante pour faire evoluer la couleur des QFrame

    int IDSTATION;

    void majHisto(CStationVCub *ptrStVCub) ;
    void AfficherStationVCubSurCarte(const CStationVCub *ptrStVCub, int zoom);
};

#endif // MAINWINDOW_H
