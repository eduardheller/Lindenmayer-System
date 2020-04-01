#define _USE_MATH_DEFINES
#include "primitives.h"
#include <QVector>
#include <QMatrix4x4>
#include <QVector2D>
#include <QDebug>
#include <cmath>
#include "Logger.h"
Primitives::Primitives() 
{

}

QVector<QVector3D> Primitives::createDisc(QVector3D p1, QVector3D B, QVector3D N, float r1, int m, float v)
{
    QVector3D n;
    QVector3D p;
    QVector<QVector3D> disc;

    for (int i=0;i<=m;i++) {
        float u = i /(float)m;
        float theta1 = u * 2*M_PI;

		n = cos(theta1) * B + sin(theta1) * N;
        n.normalize();
		p = p1 + r1 * n;

		disc.push_back(p);
		disc.push_back(n);
		disc.push_back(QVector3D(u, v,0));
    }


    return disc;
}

QVector<int> Primitives::createBranchIndices(int disc1, int disc2, int aprox)
{
	QVector<int> indices;

	for (int j = 0; j < aprox; j++) {
		indices.push_back(disc2*aprox + disc2 + j);
		indices.push_back(disc1*aprox + disc1 + j);
		indices.push_back(disc1*aprox + disc1 + j + 1);

		indices.push_back(disc2*aprox + disc2 + j);
		indices.push_back(disc1*aprox + disc1 + j + 1);
		indices.push_back(disc2*aprox + disc2 + j + 1);
	}
	
	return indices;
}

QVector<QVector3D> Primitives::createPlane(int dim, float cellsize,float y)
{
    QVector<QVector3D> data;
    float center = dim/2.0f;
    for(int i = 0; i<dim; i++){
        for(int j = 0; j<dim; j++){
            data.push_back(QVector3D(-4.5f+i*cellsize-center,y, -4.5f+j*cellsize-center));
            float u,v;

            if(i%2==0) u=0;
            else u=1;

            if(j%2==0) v = 1;
            else v = 0;

            data.push_back(QVector3D(0,1.0f,0));
            data.push_back(QVector3D(u,v,0.0f));
        }
    }
    return data;
}

QVector<int> Primitives::createPlaneIndices(int dim)
{
    QVector<int> indices;
    int curr = 0;
    for(int i = 0; i<dim-1; i++){
        for(int j = 0; j<dim-1; j++){
            indices.push_back(dim*i+j);
            indices.push_back(dim*i+j+dim);
            indices.push_back(dim*i+j+dim+1);

            indices.push_back(dim*i+j);
            indices.push_back(dim*i+j+dim+1);
            indices.push_back(dim*i+j+1);
        }
    }
    return indices;
}

QVector<QVector3D> Primitives::createLeafPlanar(QVector3D pos, QMatrix4x4 dir, float sizex, float sizey, float bending)
{

	QVector<QVector3D> data;
	QVector3D heading = dir.row(0).toVector3D();
	QVector3D left = dir.row(1).toVector3D();
	QVector3D up = -dir.row(2).toVector3D();

	QVector3D vertex1 = pos - sizex*left + sizex*bending*up;
	data.push_back(vertex1);
	data.push_back(up);
	data.push_back(QVector3D(0.0f, 0.0f, 0.0f));

	QVector3D vertex2 = pos;
	data.push_back(vertex2);
	data.push_back(up);
	data.push_back(QVector3D(0.5f, 0.0f, 0.0f));

	QVector3D vertex3 = pos + sizey*heading;
	data.push_back(vertex3);
	data.push_back(up);
	data.push_back(QVector3D(0.5, 1.0f, 0.0f));

	QVector3D vertex4 = vertex1 + sizey*heading + sizex*bending*up;
	data.push_back(vertex4);
	data.push_back(up);
	data.push_back(QVector3D(0.0f, 1.0f, 0.0f));

	QVector3D vertex5 = pos + sizex*left  + sizex*bending*up;
	data.push_back(vertex5);
	data.push_back(up);
	data.push_back(QVector3D(1.0f, 0.0f, 0.0f));

	QVector3D vertex6 = vertex5 + sizey*heading + sizex*bending*up;
	data.push_back(vertex6);
	data.push_back(up);
	data.push_back(QVector3D(1.0f, 1.0f, 0.0f));

	return data;
}

QVector<int> Primitives::createLeafIndices(int dim)
{
	QVector<int> indices;
	int index = 0;
	for (int i = 0; i < dim; i++) {
		indices.push_back(index); // 0
		index++; 
		indices.push_back(index); // 1
		index++; // 2
		indices.push_back(index); // 2

		int first = index - 2;
		indices.push_back(first); // 0 
		indices.push_back(index); // 2
		index++;
		indices.push_back(index); // 3

		first++;
		indices.push_back(first); // 1
		index++;
		indices.push_back(index); // 4
		index++;
		indices.push_back(index); // 5

		indices.push_back(first); // 1
		indices.push_back(index); // 5
		first++;
		indices.push_back(first); // 2
		index++;
	}
	return indices;

}
