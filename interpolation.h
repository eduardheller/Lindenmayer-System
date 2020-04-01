#pragma once

#include <QVector3D>

class Interpolation {

public:
	static QVector3D getHermiteInterpPosition(float t, const QVector3D& p1, const QVector3D& p2, const QVector3D& m1, const QVector3D& m2);
	static QVector3D getHermiteInterpTangent(float t, const QVector3D& p1, const QVector3D& p2, const QVector3D& m1, const QVector3D& m2);
	static float getLinearInterpolateScalar(float t, float start, float end);

};