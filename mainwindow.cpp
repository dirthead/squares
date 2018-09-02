#include "mainwindow.h"


MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
    , _scene( new Scene( this ) )
{
    setCentralWidget( new QWidget() );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget( _scene );
    centralWidget()->setLayout( layout );

    statusBar();
}


void
MainWindow::resizeEvent( QResizeEvent * event )
{
    _scene->Fit();
}

