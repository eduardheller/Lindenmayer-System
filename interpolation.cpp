#include "interpolation.h"

QVector3D Interpolation::getHermiteInterpPosition(float t, const QVector3D& p1, const QVector3D& p2, const QVector3D& m1, const QVector3D& m2)
{
	float h1 = 2*t*t*t - 3*t*t + 1;
	float h2 = -2*t*t*t + 3*t*t;
	float h3 = t*t*t - 2*t*t + t;
	float h4 = t*t*t - t*t;

	return (h1*p1 + h2*p2 + h3*m1 +h4*m2);
}

QVector3D Interpolation::getHermiteInterpTangent(float t, const QVector3D& p1, const QVector3D& p2, const QVector3D& m1, const QVector3D& m2)
{
	float h1 = 6*t*t - 6*t;
	float h2 = -6*t*t + 6*t;
	float h3 = 3*t*t - 4*t + 1;
	float h4 = 3*t*t - 2*t;

	return (h1*p1 + h2*p2 + h3*m1 + h4*m2).normalized();
}

float Interpolation::getLinearInterpolateScalar(float t, float start, float end)
{
	return  start - (t * (start - end));
}
