#pragma once

#include <QtWidgets/QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include "ui_qtOpenGL.h"
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>

class qtOpenGL : public QOpenGLWidget, QOpenGLExtraFunctions
{
    Q_OBJECT

public:
    qtOpenGL(QWidget *parent = nullptr);
    ~qtOpenGL();
protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w,int n) override;
    virtual void paintGL() override;

private:
    Ui::qtOpenGLClass ui;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLShaderProgram *m_program;
};
