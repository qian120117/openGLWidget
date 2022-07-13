#include "qtOpenGL.h"

qtOpenGL::qtOpenGL(QWidget *parent)
    : QOpenGLWidget(parent)
{
    
}

qtOpenGL::~qtOpenGL()
{}

void qtOpenGL::initializeGL()
{
	initializeOpenGLFunctions();
	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0.5, 0.7, 1);
	m_vao.create();
	m_vbo.create();
	m_program = new QOpenGLShaderProgram();
	m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, u8R"(
#version 330 core
in vec3 vPos;
void main()
{
    gl_Position = vec4(vPos, 1.0);
}
)");
	m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, u8R"(
#version 330 core
void main()
{
    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
} 
)");
	m_program->link();
	float _vertex[] = {
	 0.0,  0.5, 0.0,
	-0.5, -0.5, 0.0,
	 0.5, -0.5, 0.0,
	};
	m_vao.bind();
	m_vbo.bind();
	m_vbo.allocate(_vertex, 9 * sizeof(float));
	// m_vbo.allocate(_vertex, sizeof(_vertex));
	m_program->bind();
	m_program->setAttributeBuffer("vPos", GL_FLOAT, 0, 3, 0);
	m_program->enableAttributeArray("vPos");

	m_program->release();
	m_vao.release();

}

void qtOpenGL::resizeGL(int w, int n)
{

}

void qtOpenGL::paintGL()
{
	m_vao.bind();
	m_program->bind();
	glDrawArrays(GL_TRIANGLE_FAN, 0, 3);
	m_vao.release();
	m_program->release();
}
