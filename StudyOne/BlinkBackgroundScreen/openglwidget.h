#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtOpenGL>

class OpenGLWidget : public QOpenGLWidget,
        protected QOpenGLExtraFunctions
{
    Q_OBJECT

    GLsizei viewportWidth;
    GLsizei viewportHeight;

    QTimer timer;
    bool blinkingFlag;

    public:
        explicit OpenGLWidget(QWidget* parent = nullptr);
        ~OpenGLWidget() override;

    protected:
        void initializeGL() override;
        void resizeGL(int width, int height) override;
        void paintGL() override;
};

#endif // OPENGLWIDGET_H
