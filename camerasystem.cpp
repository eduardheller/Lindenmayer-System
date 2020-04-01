#include "camerasystem.h"
#include <QtMath>

CameraSystem::CameraSystem(const QVector3D& pos, const QVector3D& dir, int w, int h) :
    position(pos),
    direction(dir),
	width(w),
	height(h),
    up(0.0f,1.0f,0.0f),
    movementSpeed(0.01f),
    isSetMouse(false),
    yaw(-90.0f),
    pitch(0.0f)
{

}

QMatrix4x4 CameraSystem::getProjection()
{
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45.0f,(float)width / (float)height, 0.1f, 100.0f);
    return projectionMatrix;
}

QMatrix4x4 CameraSystem::getView()
{
    viewMatrix.setToIdentity();
    viewMatrix.lookAt(position,position+direction,up);
    return viewMatrix;
}

void CameraSystem::setMovementSpeed(float speed)
{
    movementSpeed = speed;
}

void CameraSystem::moveLeft()
{
    position += movementSpeed*direction;
}

void CameraSystem::moveRight()
{
    position -= movementSpeed*direction;
}

void CameraSystem::moveForward()
{
    position -= QVector3D::crossProduct(direction,up).normalized() *movementSpeed;
}

void CameraSystem::moveBackward()
{
    position += QVector3D::crossProduct(direction,up).normalized() *movementSpeed;
}

void CameraSystem::setPosition(const QVector3D &pos)
{
	position = pos;
}

void CameraSystem::setDirection(const QVector3D &dir)
{
	direction = dir;
}

void CameraSystem::setProjectionSize(int w, int h)
{
	width = w;
	height = h;
}

QVector3D CameraSystem::getPosition() const
{
    return position;
}

QVector3D CameraSystem::getDirection() const
{
    return direction;
}

void CameraSystem::handleMouseMovement(const QVector2D& mousePos, float speed)
{

    if(!isSetMouse)
    {
        oldMousePosition = mousePos;
        isSetMouse = true;
    }

    float xoffset = mousePos.x() - oldMousePosition.x();
    float yoffset = oldMousePosition.y() - mousePos.y();
    oldMousePosition = mousePos;

    xoffset *= speed;
    yoffset *= speed;

    yaw   += xoffset;
    pitch += yoffset;

    if(pitch > 80.0f)
        pitch = 80.0f;
    if(pitch < -80.0f)
        pitch = -80.0f;

    QVector3D front;
    front.setX( cos(qDegreesToRadians(yaw)) * cos(qDegreesToRadians(pitch)) );
    front.setY( sin(qDegreesToRadians(pitch)) );
    front.setZ( sin(qDegreesToRadians(yaw)) * cos(qDegreesToRadians(pitch)) );
    direction = front.normalized();

}

void CameraSystem::resetMouse()
{
    isSetMouse = false;
}


