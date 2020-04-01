#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <QVector3D>
#include <QVector>
#include <QMatrix4x4>
class Primitives
{
public:
    Primitives();

    QVector<QVector3D> createDisc(QVector3D p1, QVector3D B, QVector3D N, float r1, int m, float tscale);
	QVector<int> createBranchIndices(int disc1, int disc2, int aprox);
    QVector<QVector3D> createPlane(int dim, float cellsize, float y);
    QVector<int> createPlaneIndices(int dim);
	QVector<QVector3D> createLeafPlanar(QVector3D pos, QMatrix4x4 dir, float sizex, float sizey, float bending);
	QVector<int> createLeafIndices(int dim);
};

#endif // PRIMITIVES_H
