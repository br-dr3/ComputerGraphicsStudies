#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include "dragoncurve.h"

#include <QtOpenGL>
#include <memory>

class OpenGLWidget : public QOpenGLWidget , protected QOpenGLExtraFunctions
{
    Q_OBJECT

    GLsizei viewportWidth;
    GLsizei viewportHeight;

    public:
        OpenGLWidget();
        ~OpenGLWidget() override;
        DragonCurve dc;

    protected:
        void initializeGL() override;
        void resizeGL(int width, int height) override;
        void paintGL() override;
};

#endif // OPENGLWIDGET_H
