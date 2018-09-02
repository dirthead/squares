#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "scene.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * parent = 0);

protected:
    void resizeEvent( QResizeEvent * event );

private:
    QVBoxLayout * _mainLayout;
    QWidget * _centralWidget;
    Scene * _scene;
};

#endif // MAINWINDOW_H
