#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "modelt.h"
#include <QMainWindow>
#include <QMenu>
#include <QStyle>
#include <QIcon>
#include <phonon>
#include <QFileDialog>
#include <QMessageBox>
 #include <QList>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QMenu *controlMenu;
    Modelt *mod;
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::SeekSlider *seekSlider;
    Phonon::VolumeSlider *volumeSlider;
    Phonon::MediaObject *metaInformationResolver;
public slots:
    void slotPlay();
    void slotPrev();
    void slotNext();
    void slotPath();
    void openPlay();
    void openList();
    void openLib();
    void slotSelect();
    void slotDeselect();
};

#endif // MAINWINDOW_H
