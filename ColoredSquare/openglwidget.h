#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtOpenGL>

#include <memory>

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT

    GLuint vboVertices = 0;
    GLuint vboColors = 0;
    GLuint vboIndices = 0;

    GLuint vao = 0;

    std::unique_ptr<QVector4D[]> vertices = nullptr;
    std::unique_ptr<QVector4D[]> colors = nullptr;
    std::unique_ptr<unsigned int[]> indices = nullptr;

    GLuint shaderProgram;

    GLsizei viewportWidth;
    GLsizei viewportHeight;

public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget() override;

    void createVBOs();
    void createShaders();

    void destroyVBOs();
    void destroyShaders();

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

signals:

public slots:
    void toggleBackgroundColor(bool toogle);
};
#endif
