#ifndef TURTLESYSTEM_H
#define TURTLESYSTEM_H


#include <string>
#include <vector>
#include <QVector>
#include <QStack>
#include <QVector3D>
#include <QMatrix4x4>
#include <tuple>


struct S_LEAF {
	// Position des Blattes
	QVector3D position;
	// Orientation des Blattes
	QMatrix4x4 orientation;
	// Größe des Blatts
	float sizex;
	float sizey;
};

struct S_BRANCH {
	// Position des Blattes
	QVector3D position;
	// Binormalvektor
	QVector3D binormal;
	// Hauptnormalenvektor
	QVector3D normal;
	// Radius
	float thickness;
	// V Koordinate 
	float v;
};

struct S_DRAW_ELEMENTS{
	// Vektor der Äste
	QVector<S_BRANCH> branches;
	// Indizes der Knotenpunkte
    QVector<unsigned int> indices;
	// Vektor der Blätter
	QVector<S_LEAF> leafs;
};

class TurtleSystem
{
public:
	TurtleSystem(const std::string& lsystem, float delta, float length, float thickness, float decfac, float leafScaleX, float leafScaleY, float decfacLeaf, unsigned int hermitesteps = 0, float tangentlength = 1.0f, float tangentLength2 = 1.0f, float dist = 0.001f);
	~TurtleSystem();
	S_DRAW_ELEMENTS getDrawData();

private:

	unsigned int hermitesteps;
	QVector3D getLeftAxis();
	QVector3D getHeadingAxis();
	QVector3D getUpAxis();
	bool differenceTooHigh(const QVector3D& t1, const QVector3D& t2);
	bool areInSameLine(const QVector3D& t1, const QVector3D& t2);

    struct S_STACK{
        QVector3D nodePosition;
        QMatrix4x4 orientation;
		QMatrix4x4 lastOrientation;
        QVector3D lastNodePosition;
        QVector3D lastHeading;
        float thickness;
		float lastThickness;
		float leafSizeX;
		float leafSizeY;
        int index;
		float uv;
    };

    QStack<S_STACK> stack;
    std::string lsystem;

    // Turtle tuple (x,y,z,alpha)
    QVector3D nodePosition;
	QVector3D lastNodePosition;
	QVector3D lastHeading;
    QMatrix4x4 orientation;
	QMatrix4x4 lastOrientation;
    

	QVector<S_BRANCH> branches;
    QVector<unsigned int> indices;
	QVector<S_LEAF> leafs;

    // Give parameters
    float d;
    float delta;
    float thickness;
	float decfactorLeaf;
    float decfactor;
	float tangentLength;
	float tangentLength2;
	float minAngle;
	float lastThickness;
	float leafScaleX;
	float leafScaleY;
	float uv;

};

#endif // TURTLESYSTEM_H
