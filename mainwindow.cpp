///
/// \file       mainwindow.cpp
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

#include "mainwindow.h"
#include "ui_mainwindow.h"

///
/// \brief MainWindow::MainWindow
/// \param parent
///
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Infos VCub");
    qApp->setStyleSheet("QGroupBox { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\
                            stop: 0 #E0E0E0, stop: 1 #FFFFFF);\
                            border: 2px solid gray;\
                            border-radius: 5px;\
                            margin-top: 1ex; /* leave space at the top for the title */\
                        }");


    mView = new QWebEngineView(ui->tabWidgetGeoloc );
    ui->tabWidgetGeoloc->addTab(mView, "carte :");

    //instanciation d'un objet de la Classe CStationVCubManager
    mPtrVCubManager = new CStationVCubManager("STUT1MR9RC") ;

    // A COMMENTER
    connect(mPtrVCubManager, SIGNAL(on_LectureBalise(CStationVCub*)), this, SLOT(on_ReceptionInfo(CStationVCub *))) ;

    ui->listHisto->setSelectionMode(QAbstractItemView::MultiSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

///
/// \brief Requête au web service d'une demande d'info spour une station via la classe CStationVCubManager
///
void MainWindow::on_pbDemandeInfos_released()
{
   mPtrVCubManager->LireStation(ui->spinBoxIdStation->value()) ;
}

/*!
 * \brief Met à jour :
 *  - les infos de la sation (nom, nb velo dispo, nb place dispo, date maj
 *  - les couleur (rouge ou vert ) des indicateurs d'avertissement par rapport aux variables  :
 *          . mAlerteNbVeloDispo
 *          . mAlerteNbPlaceDispo
 *  - l'indicateur de connexion (rouge ou vert)
 *  - Historise la demande
 */
void MainWindow::on_ReceptionInfo (CStationVCub *ptrStVCub)
{
        ui->lbNom->setText(ptrStVCub->nom());
        ui->lbNbVeloClassiqDispo->setText(QString::number(ptrStVCub->nbVeloClassiqDispo()));
        ui->lbNbVeloElecDispo->setText(QString::number(ptrStVCub->nbVeloElecDispo()));

        ui->lbNbPlaceDispo->setText(QString::number(ptrStVCub->nbPlaceDispo()));
        ui->lbDateMaj->setText(ptrStVCub->dateMaj());

        if(ptrStVCub->nbVeloClassiqDispo() >= mAlerteNbVeloDispo){
            ui->frmNbVeloClassiqDispo->setStyleSheet("background-color:green");
        }
        else{
            ui->frmNbVeloClassiqDispo->setStyleSheet("background-color:red");
        }

        if(ptrStVCub->nbVeloElecDispo() >= mAlerteNbVeloDispo){
            ui->frmNbVeloElecDispo->setStyleSheet("background-color:green");
        }
        else{
            ui->frmNbVeloElecDispo->setStyleSheet("background-color:red");
        }

        if(ptrStVCub->nbPlaceDispo() >= mAlerteNbPlaceDispo){
            ui->frmNbPlaceDispo->setStyleSheet("background-color:green");
        }
        else{
            ui->frmNbPlaceDispo->setStyleSheet("background-color:red");
        }
        if(ptrStVCub->connect() == true){
            ui->frmConnexion->setStyleSheet("background-color:green");
        }
        else{
            ui->frmConnexion->setStyleSheet("background-color:red");
        }

        ui->lbLatitude->setText(QString::number(ptrStVCub->latitude()));
        ui->lbLongitude->setText(QString::number(ptrStVCub->longitude()));

        majHisto(ptrStVCub) ;
        AfficherStationVCubSurCarte(ptrStVCub, ui->spinBoxZoom->value()) ;
}

/*!
 * \brief Met à jour :
 *  - le nombre d'élément dans l'historique
 *  - le nombre d'élément sélectionnée dans l'historique
 *  - ajoute un enregistrement dans l'historique
 */
void MainWindow::majHisto(CStationVCub *ptrStVCub = nullptr)
{

    if (ptrStVCub != nullptr)
        ui->listHisto->addItem(ptrStVCub->dateMaj() + " "+ ptrStVCub->nom()+ "(" + QString::number(ptrStVCub->gidStation()) + ") VeloDispo : " + QString::number(ptrStVCub->nbVeloDispo()) + " PlaceDispo : " + QString::number(ptrStVCub->nbPlaceDispo()));

    ui->lbNbEltHisto->setText(QString::number(ui->listHisto->count()));
    int a=0;
    for(int i=0; i!=ui->listHisto->count(); i++)
    {
        if(ui->listHisto->item(i)->isSelected() == true)
        {
            a++;
        }
    }
    ui->lbNbEltHistoSelect->setText(QString::number(a));
}

void MainWindow::on_listHisto_clicked(const QModelIndex &index)
{
    majHisto();
}
/*!
 * \brief Supprime tout les éléménts sélectionnés de l'historique
 */
void MainWindow::on_pbSupprimer_released()
{
        for(int i=0 ; i<ui->listHisto->count() ; i++)
        {
            int indexitemselect= ui->listHisto->item(i)->isSelected();
            if(indexitemselect==true){
                ui->listHisto->takeItem(i);
                i--;
    }

    }

    majHisto() ;
}

/*!
 * \brief Supprime tout les éléménts de l'historique
 *  message avertissement (voir copie écran)
 */
void MainWindow::on_pbToutSupprimer_released()
{
    int retour = QMessageBox::warning(this, "suppression Historique","Voulez vous supprimer tous les elements de l'historique",QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Ok);
    if(retour == QMessageBox::Ok){
        ui->listHisto->clear();

    majHisto() ;

}
}

///
/// \brief Géolocalisation d'une station VCub sur une carte
/// \param ptrStVCub : station à géolocaliser
/// \param zoom : valeur du zoom
///
void MainWindow::AfficherStationVCubSurCarte(const CStationVCub *ptrStVCub, int zoom)
{
   if (ptrStVCub != nullptr)
   {
       QString urlMaps = ("https://www.openstreetmap.org?mlat=" + QString::number(ptrStVCub->latitude()) + "&mlon=") +
                         QString::number(ptrStVCub->longitude()) + "#map=" + QString::number(zoom) + "/" + QString::number(ptrStVCub->latitude()) + "/" +  QString::number(ptrStVCub->longitude());


//    QString urlMaps = ("https://maps.googleapis.com/maps/api/staticmap?&zoom=" + QString::number(zoom) + "&size=1200x1000&maptype=roadmap&markers=color:blue%7Clabel:P%7C") +
//            QString::number(ptrStVCub->latitude()) + "," +
//            QString::number(ptrStVCub->longitude()) ;

    mView->load(QUrl(urlMaps));
    mView->show();
   }
}
///
/// \brief Change le zoom de la carte
/// \param arg1
///
void MainWindow::on_spinBoxZoom_valueChanged(int arg1)
{
     AfficherStationVCubSurCarte(ptrStVCub, arg1) ;
}
