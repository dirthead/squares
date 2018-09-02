#include "scene.h"


Scene::Scene(QWidget * parent)
    : QOpenGLWidget(parent)
    , _sceneSize(1000000.0)
    , _boxCount(10)
    , _sceneWidth(_sceneSize)
    , _sceneHeight(_sceneSize)
{
}


void
Scene::Fit()
{
    QSizeF designSize = QSizeF( _sceneSize, _sceneSize );
    QSizeF scaledSize = QSizeF( size() );

    scaledSize.scale( designSize, Qt::KeepAspectRatioByExpanding );
    
    _sceneWidth = scaledSize.width();
    _sceneHeight = scaledSize.height();

    update();
}


void
Scene::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void
Scene::paintGL()
{
    glViewport( 0, 0, width(), height() );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, _sceneWidth, 0.0, _sceneHeight, 0.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    double z = -100.0;
    double boxSize = _sceneSize / _boxCount / 2.0;

    for (uint64_t row = 0; row < _boxCount; ++row)
    {
        double y = row * boxSize * 2.0;

        for (uint64_t col = 0; col < _boxCount; ++col)
        {
            double x = col * boxSize * 2.0;
            uint64_t cell = col + ( row % 2 );

            if ( (cell % 2) == 0 )
            {
                glColor3f(0.0f, 0.0f, 1.0f); // blue
            }
            else
            {
                glColor3f(0.0f, 1.0f, 0.0f); // green
            }

            glVertex3d(x, y, z);
            glVertex3d(x + boxSize, y, z);
            glVertex3d(x + boxSize, y + boxSize, z);
            glVertex3d(x, y + boxSize, z);
        }
    }

    glEnd();
    glFlush();
}

