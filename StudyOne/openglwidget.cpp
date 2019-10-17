#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent) : QOpenGLWidget(parent)
{   }

OpenGLWidget::~OpenGLWidget()
{   }

void OpenGLWidget::initializeGL() {
    initializeOpenGLFunctions();
}

void OpenGLWidget::resizeGL(int width, int height) {
    viewportWidth = width;
    viewportHeight = height;
}

void OpenGLWidget::paintGL() {
    glViewport(0, 0, viewportWidth, viewportHeight);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLWidget::toggleBackgroundColor(bool isBoxChecked) {

    makeCurrent();

    if(isBoxChecked) {
        glClearColor(0, 0, 0, 1);
    } else {
        glClearColor(1, 1, 1, 1);
    }

    update();
}
