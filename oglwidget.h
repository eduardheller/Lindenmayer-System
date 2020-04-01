#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLTexture>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLFrameBufferObject>
#include <QVector>
#include <vector>
#include <camerasystem.h>
#include <slsystem.h>
#include <turtlesystem.h>
#include <QTime>
#include "turtlesystem.h"

class OGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();

	void resetCamera();
	QVector<QVector3D> getBranchData();
	QVector<QVector3D> getPlaneData();
	QVector<QVector3D> getLeafData();
	QVector<int> getBranchIndices();
	QVector<int> getPlaneIndices();
	QVector<int> getLeafIndices();
	void setTextures(const QString &branchTexture, const QString &leafTexture);
	void setShadow(bool shad);
	void setAnimation(bool anim);
	void setWireframe(bool wire);

public slots:
	void generate(std::vector<SRules> rules, std::string axiom, int iterations, 
		float angle, float length, float thickness, float decrease, float leafscalex,
		float leafscaley, float bending, float decleaf, float tangent, float tangent2, 
		int hermitesteps, int cylinderaprox, float mindist);


protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent* event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);


/// PRIVATE FUNCTIONS
private:
    void initFormats();
	void createLeafObjects();
	void createPlaneObject();
	void createBranchObjects();
	void attachVAO(QOpenGLShaderProgram& shader);


/// MEMBER
private:

	// Plant buffert quad 
	QOpenGLBuffer vboBufferQuad;
	QOpenGLVertexArrayObject vaoBufferQuad;

    // Plant branches objects
    QOpenGLBuffer vbo;
    QOpenGLBuffer ibo;
    QOpenGLVertexArrayObject vao;

	// Plant leaf objects
	QOpenGLBuffer vboLeaf;
	QOpenGLBuffer iboLeaf;
	QOpenGLVertexArrayObject vaoLeaf;

    // Ground object
    QOpenGLBuffer vboPlane;
    QOpenGLBuffer iboPlane;
    QOpenGLVertexArrayObject vaoPlane;

    // shader for basic lightning and texturing
    QOpenGLShaderProgram shader;
	QOpenGLShaderProgram shaderFrameBuffer;
	QOpenGLShaderProgram shaderDepthBuffer;
	QOpenGLFramebufferObject* fBuffer;
	QOpenGLFramebufferObjectFormat* fBufferFormat;


	QOpenGLTexture* bufferTexture;
    QOpenGLTexture* texture;
    QOpenGLTexture* texturePlane;
	QOpenGLTexture* textureLeaf;
    CameraSystem camera;
    SLSystem* lsystem;
    TurtleSystem* turtle;
    S_DRAW_ELEMENTS drawElements;

    QTime timer;
    int oldTime;
    int deltaTime;

	QMatrix4x4 model;

	QVector<QVector3D> cylinder;
	QVector<QVector3D> plane;
	QVector<QVector3D> leafs;
	QVector<int> planeIndices;
	QVector<int> leafIndices;
	QVector<int> branchIndices;

	QString textureBranchFile;
	QString textureLeafFile;

    bool rightMousePressed;
    bool keys[1024];

	bool shadow;
	bool animation;
	bool wireframe;
};



#endif // OGLWIDGET_H
