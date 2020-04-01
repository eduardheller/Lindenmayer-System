#ifndef CAMERASYSTEM_H
#define CAMERASYSTEM_H

#include <QMatrix4x4>
#include <QVector3D>
#include <QVector2D>

/**
*  Camera Class
*/
class CameraSystem
{
public:

    CameraSystem(const QVector3D& position, const QVector3D& direction, int width, int height);


    QMatrix4x4 getView();
    QMatrix4x4 getProjection();

    void setMovementSpeed(float speed);
    void moveLeft();
    void moveRight();
    void moveForward();
    void moveBackward();
	void setPosition(const QVector3D&);
	void setDirection(const QVector3D&);

	void setProjectionSize(int x, int y);

    QVector3D getPosition() const;
    QVector3D getDirection() const;

    void handleMouseMovement(const QVector2D& mousePos, float speed);
    void resetMouse();

private:
	int width;
	int height;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 projectionMatrix;
    QVector3D position;
    QVector3D direction;
    QVector3D up;
    QVector2D oldMousePosition;
    float movementSpeed;
    bool isSetMouse;
    float yaw;
    float pitch;
};

#endif // CAMERASYSTEM_H
