#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent) : QOpenGLWidget(parent)
{
    blinkingFlag = false;
}

OpenGLWidget::~OpenGLWidget()
{   }

void OpenGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(200);
}

void OpenGLWidget::resizeGL(int width, int height) {
    viewportWidth = width;
    viewportHeight = height;
}

void OpenGLWidget::paintGL() {
    blinkingFlag = !blinkingFlag;

    if (blinkingFlag) {
        glClearColor(0, 0, 0, 1);
    } else {
        glClearColor(1, 1, 1, 1);
    }

    glClear(GL_COLOR_BUFFER_BIT);
}
