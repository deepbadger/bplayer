#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    fileMenu = new QMenu(this);
    QAction *openPlayAction = fileMenu->addAction(tr("GoTo Player..."));
    QAction *openListAction = fileMenu->addAction(tr("GoTo PlayList..."));
    QAction *openLibAction = fileMenu->addAction(tr("GoTo Library..."));
    connect(openPlayAction, SIGNAL(triggered(bool)), this, SLOT(openPlay()));
    connect(openListAction, SIGNAL(triggered(bool)), this, SLOT(openList()));
    connect(openLibAction, SIGNAL(triggered(bool)), this, SLOT(openLib()));
    ui->toolButton_2->setMenu(fileMenu);
    ui->toolButton_4->setMenu(fileMenu);
    ui->toolButton_5->setMenu(fileMenu);

    controlMenu = new QMenu(this);
    QAction *contSelAction = controlMenu->addAction(tr("Select all"));
    QAction *contDeSelAction = controlMenu->addAction(tr("Deselect all"));
    controlMenu->addSeparator();
    QAction *contAddAction = controlMenu->addAction(tr("Add into playlist"));
    QAction *contRepAction = controlMenu->addAction(tr("Replace playlist"));
    connect(contSelAction, SIGNAL(triggered(bool)), this, SLOT(slotSelect()));
    connect(contDeSelAction, SIGNAL(triggered(bool)), this, SLOT(slotDeselect()));
    ui->toolButton->setMenu(controlMenu);

    ui->pushButton_2->setText("");
    ui->pushButton->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_2->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    ui->pushButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_3->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

    mod = new Modelt(this);
    ui->tableView->setModel(mod);
    metaInformationResolver = new Phonon::MediaObject(this);
    mediaObject = new Phonon::MediaObject(this);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(mediaObject, audioOutput);
   // mediaObject->setTickInterval(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::slotPlay()
{
    //QMessageBox::information(this,"Sound","Press Play");
    mediaObject->setCurrentSource(QString("e:\\Sounds\\Muzik\\DISKO\\Ata Kak - Daa Nyinaa.mp3"));

    mediaObject->play();

}

void MainWindow::slotPrev()
{

    QMessageBox::information(this,"Sound","Press Prev");
     mediaObject->stop();
}

void MainWindow::slotNext()
{
    QString st;
    metaInformationResolver->setCurrentSource(QString("e:\\Sounds\\Muzik\\DISKO\\Ata Kak - Daa Nyinaa.mp3"));
    QMap<QString, QString> metaData = metaInformationResolver->metaData();
    foreach (QString value, metaData)
    {
     st = st + value +";" ;
  }
    QMessageBox::information(this,"Sound",st);
    ui->label->setText(st);
}

void MainWindow::slotPath()
{
    QString PathDir = QFileDialog::getExistingDirectory(this
                                          , "Directory"
                                          ,""
                                          , QFileDialog::ReadOnly);//QFileDialog::ShowDirsOnly  |
    if(!PathDir.isEmpty()) {
        ui->listWidget->clear();
        ui->listWidget->addItems(QDir(PathDir).entryList(QStringList("*.mp3"),QDir::Files,QDir::Name));
    }


}

void MainWindow::openPlay()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::openList()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::openLib()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::slotSelect()
{
    ui->listWidget->selectAll();
}


void MainWindow::slotDeselect()
{
    ui->listWidget->clearSelection();
}
