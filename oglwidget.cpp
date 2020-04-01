#include "oglwidget.h"
#include <QDebug>
#include <QVector3D>
#include <QFileInfo>
#include <QVector2D>
#include "srules.h"
#include "slsystem.h"
#include "turtlesystem.h"
#include <QDebug>
#include <QVector>
#include <QMouseEvent>
#include <QElapsedTimer>
#include <QCursor>
#include <QTime>
#include <cmath>
#include <primitives.h>
#include <cstdlib>
#include <ctime>
#include "Logger.h"
#include <QTime>

QVector<QVector2D> quadVertices;
GLuint depthMap;
GLuint depthMapFBO;
QMatrix4x4 depthCamera;
QMatrix4x4 lightView;
QMatrix4x4 lightSpaceMatrix;

bool generated = false;

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      iboPlane(QOpenGLBuffer::IndexBuffer),
	  iboLeaf(QOpenGLBuffer::IndexBuffer),
	  ibo(QOpenGLBuffer::IndexBuffer),
      camera(QVector3D(-6.0f,5.0f,6.0f),QVector3D(0.5f,-0.2f,-0.5f),1920,1080),shadow(true),animation(true),wireframe(false)
{
    initFormats();
    srand (static_cast <unsigned> (time(0)));
	for (int i = 0; i < 1024; i++) {
		keys[i] = false;
	}
	rightMousePressed = false;
}

OGLWidget::~OGLWidget()
{

}

void OGLWidget::resetCamera()
{
	
	camera.setDirection(QVector3D(0.5f, -0.2f, -0.5f));
	camera.setPosition(QVector3D(-6.0f, 5.0f, 6.0f));
}

QVector<QVector3D> OGLWidget::getBranchData()
{
	return cylinder;
}

QVector<QVector3D> OGLWidget::getPlaneData()
{
	return plane;
}

QVector<QVector3D> OGLWidget::getLeafData()
{
	return leafs;
}

QVector<int> OGLWidget::getBranchIndices()
{
	return branchIndices;
}

QVector<int> OGLWidget::getPlaneIndices()
{
	return planeIndices;
}

QVector<int> OGLWidget::getLeafIndices()
{
	return leafIndices;
}

void OGLWidget::setTextures(const QString & branchTexture, const QString & leafTexture)
{
	textureLeafFile = leafTexture;
	textureBranchFile = branchTexture;

	texture = new QOpenGLTexture(QImage(textureBranchFile));
	texture->create();
	texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	texture->setMagnificationFilter(QOpenGLTexture::Linear);
	texture->setWrapMode(QOpenGLTexture::Repeat);
	texture->setMaximumAnisotropy(16);


	textureLeaf = new QOpenGLTexture(QImage(textureLeafFile));
	textureLeaf->create();
	textureLeaf->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	textureLeaf->setMagnificationFilter(QOpenGLTexture::Linear);
	textureLeaf->setMaximumAnisotropy(16);
	textureLeaf->setWrapMode(QOpenGLTexture::Repeat);

}

void OGLWidget::setShadow(bool shad)
{
	shadow = shad;
}

void OGLWidget::setAnimation(bool anim)
{
	animation = anim;
}

void OGLWidget::setWireframe(bool wire) {

	wireframe = wire;

}

void OGLWidget::generate(std::vector<SRules> rules, std::string axiom, 
	int iterations, float angle, float length, float thickness, 
	float decrease, float leafscalex, float leafscaley, float bending, float decleaf, 
	float tangent,float tangent2, int hermitesteps, int cylinderaprox, float mindist) {

	
	lsystem = new SLSystem(axiom, rules);
	lsystem->iterate(iterations);
	Logger::getInstance()->write("Rewriting LSystem...", true);
	std::string l = lsystem->getLSystem();
	Logger::getInstance()->write("LSystem substituted", true);
	Logger::getInstance()->write("GENERATED L-System: "+ QString(lsystem->getLSystem().c_str()), true);
	turtle = new TurtleSystem(lsystem->getLSystem(), angle, length, thickness, decrease, leafscalex, 
		leafscaley, decleaf,hermitesteps, tangent, tangent2, mindist);
	drawElements = turtle->getDrawData();
	
	leafs.clear();
	cylinder.clear();
	planeIndices.clear();
	leafIndices.clear();
	branchIndices.clear();

	Logger::getInstance()->write("Generating leaf vertex data...", true);
	Primitives prim;
	for (int k = 0; k < drawElements.leafs.length(); k++) {
		leafs.append(prim.createLeafPlanar(drawElements.leafs[k].position, drawElements.leafs[k].orientation, 
			drawElements.leafs[k].sizex, drawElements.leafs[k].sizey, bending));
	}
	Logger::getInstance()->write("Generating leaf vertex data... sdasds", true);


	leafIndices = prim.createLeafIndices(leafs.size()/18);

	Logger::getInstance()->write("DONE!!!", true);

	Logger::getInstance()->write("Generating branches vertex data...", true);

	QVector3D p(drawElements.branches[0].position);
	QVector3D B(drawElements.branches[0].binormal);
	QVector3D N(drawElements.branches[0].normal);
	thickness = drawElements.branches[0].thickness;
	float v = drawElements.branches[0].v;
	cylinder.append(prim.createDisc(p, B, N, thickness, cylinderaprox, v));
	
	for (int k = 1; k<drawElements.indices.length(); k += 2) {
		int index = drawElements.indices.at(k-1);
		int indexPair = drawElements.indices.at(k);
		QVector3D p(drawElements.branches[indexPair].position);
		QVector3D B(drawElements.branches[indexPair].binormal);
		QVector3D N(drawElements.branches[indexPair].normal);
		thickness = drawElements.branches[indexPair].thickness;
		float v = drawElements.branches[indexPair].v;

		cylinder.append(prim.createDisc(p, B, N, thickness, cylinderaprox, v));
		branchIndices.append(prim.createBranchIndices(index,indexPair, cylinderaprox));
	}


	

	Logger::getInstance()->write("Generating plane vertex data...", true);
	plane = prim.createPlane(2, 12.0f, 0.0f);
	planeIndices = prim.createPlaneIndices(2);


	Logger::getInstance()->write("Generating complete, starting to render", true);
	shader.bind();
	createBranchObjects();
	createPlaneObject();
	createLeafObjects();
	shader.release();
	generated = true;
}

void OGLWidget::initializeGL()
{
	
    this->initializeOpenGLFunctions();
    this->glClearColor(1.0f,1.0f,1.0f,1.0f);
    this->glEnable(GL_DEPTH_TEST);
	Logger::getInstance()->write("OpenGL Initialized");

	model.translate(0.0f, 0, 0.0f);
	Primitives prim;
	Logger::getInstance()->write("Creating plane...");
	plane = prim.createPlane(2, 12.0f, 0.0f);
	planeIndices = prim.createPlaneIndices(2);
	Logger::getInstance()->write("Plane created");

    shader.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertex/basic.vsh");
    shader.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/vertex/basic.fsh");
    shader.link();
	
	shaderDepthBuffer.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertex/depth.vsh");
	shaderDepthBuffer.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/vertex/depth.fsh");
	shaderDepthBuffer.link();

	// Vordefinierte Texturen
	Logger::getInstance()->write("Loading Textures...");

	texture = new QOpenGLTexture(QImage(":/images/plantbranch.jpg"));
	texture->create();
	texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	texture->setMagnificationFilter(QOpenGLTexture::Linear);
	texture->setWrapMode(QOpenGLTexture::Repeat);
	texture->setMaximumAnisotropy(16);

    texturePlane = new QOpenGLTexture(QImage(":/images/grass.jpg"));
    texturePlane->create();
    texturePlane->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    texturePlane->setMagnificationFilter(QOpenGLTexture::Linear);
    texturePlane->setMaximumAnisotropy(16);
    texturePlane->setWrapMode(QOpenGLTexture::Repeat);

	textureLeaf = new QOpenGLTexture(QImage(":/images/leaf.jpg"));
	textureLeaf->create();
	textureLeaf->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	textureLeaf->setMagnificationFilter(QOpenGLTexture::Linear);
	textureLeaf->setWrapMode(QOpenGLTexture::Repeat);
	textureLeaf->setMaximumAnisotropy(16);


	Logger::getInstance()->write("Textures loaded");

	glGenFramebuffers(1, &depthMapFBO);
	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
		2048, 2048, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	GLfloat borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindTexture(GL_TEXTURE_2D, 0);

	depthCamera.setToIdentity();
	depthCamera.ortho(-10.0f, 10.0f, -10.0f, 10.0f, 1.0f, 125.5f);
	lightView.setToIdentity();
	lightView.lookAt(QVector3D(5.0f, 25.0f, 0.0f), QVector3D(0.0, 0.0f, 0.0f), QVector3D(0.0, 1.0f, 0.0f));
	lightSpaceMatrix = depthCamera * lightView;


	createBranchObjects();
	createPlaneObject();
	createLeafObjects();
	attachVAO(shader);


    oldTime = 0;
    timer.start();

}

void OGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

    int newTime = timer.elapsed();
    deltaTime = newTime - oldTime;
    oldTime = newTime;

    camera.setMovementSpeed(deltaTime*0.005);
	if (generated) {
		if (shadow) {
			glCullFace(GL_FRONT);
			shaderDepthBuffer.bind();
			{
				glViewport(0, 0, 2048, 2048);
				glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);

				glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glEnable(GL_DEPTH_TEST);

				shaderDepthBuffer.setUniformValue("lightSpaceMatrix", lightSpaceMatrix);
				shaderDepthBuffer.setUniformValue("model", model);
				shaderDepthBuffer.setUniformValue("time", (float)newTime);
				shaderDepthBuffer.setUniformValue("isAnimation", animation);
				attachVAO(shaderDepthBuffer);



				textureLeaf->bind();
				vaoLeaf.bind();
				glDrawElements(GL_TRIANGLES, leafIndices.length(), GL_UNSIGNED_INT, leafIndices.constData());
				vaoLeaf.release();
				textureLeaf->release();

				texture->bind();
				vao.bind();
				glDrawElements(GL_TRIANGLES, branchIndices.length(), GL_UNSIGNED_INT, branchIndices.constData());
				vao.release();
				texture->release();


				texturePlane->bind();
				vaoPlane.bind();
				glDrawElements(GL_TRIANGLES, planeIndices.length(), GL_UNSIGNED_INT, planeIndices.constData());
				vaoPlane.release();
				texturePlane->release();







				glBindFramebuffer(GL_FRAMEBUFFER, 0);
			}
			shaderDepthBuffer.release();
			glCullFace(GL_BACK);
		}


		glViewport(0, 0, this->size().width(), this->size().height());
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.bind();
		{
			shader.setUniformValue("view", camera.getView());
			shader.setUniformValue("time", (float)newTime);
			shader.setUniformValue("isShadow", shadow);
			shader.setUniformValue("isAnimation", animation);
			shader.setUniformValue("projection", camera.getProjection());
			shader.setUniformValue("model", model);
			shader.setUniformValue("lightPos", QVector3D(5.0f, 25.0f, 0.0f));
			shader.setUniformValue("lightColor", QVector3D(1.0f, 1.0f, 1.0f));
			shader.setUniformValue("viewPos", camera.getPosition());
			shader.setUniformValue("lightSpaceMatrix", lightSpaceMatrix);
			shader.setUniformValue("shadowMap", 1);
			attachVAO(shader);

			if (wireframe)
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, depthMap);



			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture->textureId());
			vao.bind();
			glDrawElements(GL_TRIANGLES, branchIndices.length(), GL_UNSIGNED_INT, branchIndices.constData());
			vao.release();


			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, textureLeaf->textureId());
			vaoLeaf.bind();
			glDrawElements(GL_TRIANGLES, leafIndices.length(), GL_UNSIGNED_INT, leafIndices.constData());
			vaoLeaf.release();




			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texturePlane->textureId());
			vaoPlane.bind();
			glDrawElements(GL_TRIANGLES, planeIndices.length(), GL_UNSIGNED_INT, planeIndices.constData());
			vaoPlane.release();


		}
		shader.release();

	}

	
    if(keys[Qt::Key_W]) camera.moveLeft();
    if(keys[Qt::Key_S]) camera.moveRight();
	if(keys[Qt::Key_A]) camera.moveForward();
    if(keys[Qt::Key_D]) camera.moveBackward();

    update();

}

void OGLWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()<1024)  keys[event->key()] = true;

}

void OGLWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()<1024) keys[event->key()] = false;

}

void OGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
	if(rightMousePressed) rightMousePressed = false;
    camera.resetMouse();
}

void OGLWidget::wheelEvent(QWheelEvent * event)
{
	camera.setMovementSpeed(deltaTime*0.025);
	int steps = event->delta();
	if (steps > 0) {
		camera.moveLeft();
	}
	else if (steps < 0) {
		camera.moveRight();
	}
}

void OGLWidget::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton) {
		rightMousePressed = true;
	}
}

void OGLWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (rightMousePressed) {
		camera.handleMouseMovement(QVector2D(event->x(), event->y()), 0.3f);
		update();
	}

}

void OGLWidget::initFormats()
{
    setMouseTracking(true);
    QSurfaceFormat format;
    format.setSwapInterval(1);
    format.setSamples(0);    // Set the number of samples used for multisampling
    setFormat(format);       // Note we set the format on the window...
    create();
}

void OGLWidget::createLeafObjects()
{

	vaoLeaf.create();
	vaoLeaf.bind();
	{
		vboLeaf.create();
		vboLeaf.setUsagePattern(QOpenGLBuffer::StaticDraw);
		vboLeaf.bind();
		vboLeaf.allocate(leafs.constData(), leafs.length() * sizeof(QVector3D));
		vboLeaf.release();

		iboLeaf.create();
		iboLeaf.setUsagePattern(QOpenGLBuffer::StaticDraw);
		iboLeaf.bind();
		iboLeaf.allocate(leafIndices.constData(), leafIndices.length() * sizeof(int));
		iboLeaf.release();
	}
	vaoLeaf.release();
	
}

void OGLWidget::createPlaneObject()
{

	vaoPlane.create();
	vaoPlane.bind();
	{
		vboPlane.create();
		vboPlane.setUsagePattern(QOpenGLBuffer::StaticDraw);
		vboPlane.bind();
		vboPlane.allocate(plane.constData(), plane.length() * sizeof(QVector3D));
		vboPlane.release();

		iboPlane.create();
		iboPlane.setUsagePattern(QOpenGLBuffer::StaticDraw);
		iboPlane.bind();
		iboPlane.allocate(planeIndices.constData(), planeIndices.length() * sizeof(int));
		iboPlane.release();
	}
	vaoPlane.release();
}

void OGLWidget::createBranchObjects()
{
	vao.create();
	vao.bind();
	{
		vbo.create();
		vbo.bind();
		vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
		vbo.allocate(cylinder.constData(), cylinder.length() * sizeof(QVector3D));
		vbo.release();

		ibo.create();
		ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
		ibo.bind();
		ibo.allocate(branchIndices.constData(), branchIndices.length() * sizeof(int));
		ibo.release();
	}
	vao.release();

}

void OGLWidget::attachVAO(QOpenGLShaderProgram &shader)
{
	int vertexLocation = shader.attributeLocation("position");
	int normalLocation = shader.attributeLocation("normal");
	int textureLocation = shader.attributeLocation("textureCoords");

	vaoPlane.bind();
	vboPlane.bind();

	if (vertexLocation >= 0) {
		shader.enableAttributeArray(vertexLocation);
		shader.setAttributeBuffer(vertexLocation, GL_FLOAT, 0, 3, 3 * sizeof(QVector3D));
	}
	if (normalLocation >= 0) {
		shader.enableAttributeArray(normalLocation);
		shader.setAttributeBuffer(normalLocation, GL_FLOAT, sizeof(QVector3D), 3, 3 * sizeof(QVector3D));
	}
	if (textureLocation >= 0) {
		shader.enableAttributeArray(textureLocation);
		shader.setAttributeBuffer(textureLocation, GL_FLOAT, sizeof(QVector3D) * 2, 3, 3 * sizeof(QVector3D));
	}

	vaoPlane.release();
	vboPlane.release();

	vaoLeaf.bind();
	vboLeaf.bind();
	if (vertexLocation >= 0) {
		shader.enableAttributeArray(vertexLocation);
		shader.setAttributeBuffer(vertexLocation, GL_FLOAT, 0, 3, 3 * sizeof(QVector3D));
	}
	if (normalLocation >= 0) {
		shader.enableAttributeArray(normalLocation);
		shader.setAttributeBuffer(normalLocation, GL_FLOAT, sizeof(QVector3D), 3, 3 * sizeof(QVector3D));
	}
	if (textureLocation >= 0) {
		shader.enableAttributeArray(textureLocation);
		shader.setAttributeBuffer(textureLocation, GL_FLOAT, sizeof(QVector3D) * 2, 3, 3 * sizeof(QVector3D));
	}
	vaoLeaf.release();
	vboLeaf.release();

	vao.bind();
	vbo.bind();
	if (vertexLocation >= 0) {
		shader.enableAttributeArray(vertexLocation);
		shader.setAttributeBuffer(vertexLocation, GL_FLOAT, 0, 3, 3 * sizeof(QVector3D));
	}
	if (normalLocation >= 0) {
		shader.enableAttributeArray(normalLocation);
		shader.setAttributeBuffer(normalLocation, GL_FLOAT, sizeof(QVector3D), 3, 3 * sizeof(QVector3D));
	}
	if (textureLocation >= 0) {
		shader.enableAttributeArray(textureLocation);
		shader.setAttributeBuffer(textureLocation, GL_FLOAT, sizeof(QVector3D) * 2, 3, 3 * sizeof(QVector3D));
	}
	vao.release();
	vbo.release();
}


void OGLWidget::resizeGL(int width, int height)
{
	camera.setProjectionSize(this->size().width(), this->size().height());
    glViewport(0, 0, width, height);
}
