#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWheelEvent>
#include <QWidget>


class Scene
    : public QOpenGLWidget
    , protected QOpenGLFunctions
{
public:
    Scene(QWidget * parent);

public:
    void Fit();

protected:
    void initializeGL() override;
    void paintGL() override;

private:
    const double _sceneSize;
    const uint64_t _boxCount;
    double _sceneWidth;
    double _sceneHeight;

    friend class MainWindow;
};

#endif // SCENE_H

