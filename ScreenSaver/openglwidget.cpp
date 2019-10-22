#include "openglwidget.h"
#include <QPainter>

OpenGLWidget::OpenGLWidget(){
    dc.generateCurve(14);
}

OpenGLWidget::~OpenGLWidget()
{   }

void OpenGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 0);
}

void OpenGLWidget::resizeGL(int width, int height) {
    viewportWidth = width;
    viewportHeight = height;
}

void OpenGLWidget::paintGL() {
    glViewport(0, 0, viewportWidth, viewportHeight);
    glClear(GL_COLOR_BUFFER_BIT);
   std::vector<std::pair<ComplexNumber, int>>
           vertexes = dc.getResumedVertexes();

   ComplexNumber last(vertexes[0].first);
   for(std::pair<ComplexNumber, int> point : vertexes) {

       double x1 = 2*last.getRealPart() / viewportWidth -1;
       double y1 = 2*last.getImaginaryPart() / viewportHeight -1;

       double x2 = 2*point.first.getRealPart() / viewportWidth -1;
       double y2 = 2*point.first.getImaginaryPart() / viewportHeight -1;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glColor3f(0.5f, 0.0f, 1.0f);
       glBegin(GL_LINES);
           glVertex2f(x1, y1);
           glVertex2f(x2, y2);
       glEnd();

       last = point.first;

   }
}


