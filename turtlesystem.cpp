#define _USE_MATH_DEFINES
#include "turtlesystem.h"
#include <QMatrix4x4>
#include <QDebug>
#include <QVector4D>
#include <QQuaternion>
#include <algorithm>
#include <regex>
#include <QElapsedTimer>
#include <sstream>
#include <cmath>
#include "interpolation.h"

TurtleSystem::TurtleSystem(const std::string& ls,float angle, float length, float thick, float decfac, float leafscalex, float leafscaley, float decfacLeaf, unsigned int hsteps, float tangent1, float tangent2, float dist) :
    lsystem(ls),
    delta(angle),
    d(length),
	nodePosition(0.0f,0.0f,0.0f),
    lastHeading(0.0f,1.0f,0.0f),
    thickness(thick),
    decfactor(decfac),
	leafScaleX(leafscalex),
	leafScaleY(leafscaley),
	decfactorLeaf(decfacLeaf),
    hermitesteps(hsteps)
{
	leafs.clear();
	branches.clear();

	minAngle = dist;
    lastNodePosition = nodePosition;
    orientation.setToIdentity();
	orientation.rotate(-90, 0.0, 0.0, 1.0);
	tangentLength = tangent1;
	tangentLength2 = tangent2;
	lastThickness = thickness;
	lastOrientation = orientation;


	S_BRANCH branch;
	branch.position = nodePosition;
	branch.binormal = getLeftAxis();
	branch.normal = getUpAxis();
	branch.thickness = thickness;
	branch.v = 0;
	branches.push_back(branch);
	uv = 0;
	
}

S_DRAW_ELEMENTS TurtleSystem::getDrawData()
{
    int index = 0;
	int pairIndex = 1;

    for(unsigned int i = 0; i<lsystem.length(); i++){

        char current = lsystem[i];
		char next;
		bool hasParam = false;
		float param;
		if (i < lsystem.length() - 1) {
			next = lsystem[i + 1];
			if (next == '(') {
				hasParam = true;
				std::string number;
				int j = i + 1;
				while (lsystem[++j] != ')' && j < lsystem.length()) {
					number.append((char*)&lsystem[j], sizeof(lsystem[j]));
				}
				std::istringstream paramString(number);
				paramString >> param;
				i = j;
			}
		}

        if(current == 'F'){

			QVector3D heading = getHeadingAxis();
            //QVector3D heading = getHeadingAxis();
			float step;
			if (hasParam) step = param;
			else step = d;
			nodePosition += heading*step;

			QVector3D B = lastOrientation.row(2).toVector3D(); // UpVector from old orientation
			QVector3D lastTangent;

            for(float t = 0; t<=hermitesteps; t++ ){

                float s = (float)t / (float)hermitesteps;    

				QVector3D p = Interpolation::getHermiteInterpPosition(s, lastNodePosition, nodePosition, lastHeading*tangentLength, heading*tangentLength2);
				QVector3D tangent = Interpolation::getHermiteInterpTangent(s, lastNodePosition, nodePosition, lastHeading*tangentLength, heading*tangentLength2);

				// Lineare annährung
				float newThickness = thickness;
				if (thickness < lastThickness) newThickness = Interpolation::getLinearInterpolateScalar(s,lastThickness, thickness);
				
				if (areInSameLine(heading,lastHeading) && t<hermitesteps - 1) {
					t = hermitesteps-1;
					uv += step/newThickness*0.1f;
					continue;
				}
				else {
					float stepsize = 1.0 / (float)hermitesteps;
					uv += stepsize/newThickness*0.1f;
				}


				if(differenceTooHigh(tangent,lastTangent) && t<hermitesteps) {
					continue;
				}
			


				if (t > 0) {
					// Ken Sloan Method
					QVector3D N = QVector3D::crossProduct(B, tangent).normalized();
					B = QVector3D::crossProduct(tangent, N).normalized();

					S_BRANCH branch;
					branch.position = p;
					branch.binormal = N;
					branch.normal = B;
					branch.thickness = newThickness;
					branch.v = uv;
					branches.push_back(branch);

					indices.push_back(index);
					index = pairIndex;
					indices.push_back(pairIndex++);

					if (t == hermitesteps) {
						lastOrientation.setRow(0, QVector4D(tangent));
						lastOrientation.setRow(1, QVector4D(N));
						lastOrientation.setRow(2, QVector4D(B));
					}
				}
				lastTangent = tangent;
					


            }
			
            lastNodePosition = nodePosition;
            lastHeading = heading;
			lastThickness = thickness;
            continue;


        }else if(current == 'f'){
			float step;
			if (hasParam) step = param;
			else step = d;
            QVector4D vec = getHeadingAxis();
			nodePosition.setX(nodePosition.x()+vec.x()*step);
			nodePosition.setY(nodePosition.y()+vec.y()*step);
			nodePosition.setZ(nodePosition.z()+vec.z()*step);
            continue;

        }else if(current == '+'){
			if (hasParam) orientation.rotate(param, getUpAxis());
			else orientation.rotate(delta, getUpAxis());
            continue;

        }else if(current == '-'){
			if (hasParam) orientation.rotate(-param, getUpAxis());
			else orientation.rotate(-delta, getUpAxis());
            continue;

        }else if(current == '&'){
			if (hasParam) orientation.rotate(param, getLeftAxis());
			else orientation.rotate(delta, getLeftAxis());
            continue;

        }else if(current == '^'){
			if (hasParam) orientation.rotate(-param, getLeftAxis());
			else orientation.rotate(-delta, getLeftAxis());
            continue;

        }else if(current == '\\'){
            
			if (hasParam) orientation.rotate(param, getHeadingAxis());
			else orientation.rotate(delta, getHeadingAxis());
            continue;

        }else if(current == '/'){
			if (hasParam) orientation.rotate(-param, getHeadingAxis());
			else orientation.rotate(-delta, getHeadingAxis());
            continue;

        }else if(current == '|'){
            orientation.rotate(180,getUpAxis());
            continue;

        }else if(current == '['){
            S_STACK currState;
            currState.orientation = orientation;
            currState.nodePosition = nodePosition;
            currState.index = index;
            currState.lastHeading = lastHeading;
            currState.lastNodePosition = lastNodePosition;
            currState.thickness = thickness;
			currState.leafSizeX = leafScaleX;
			currState.leafSizeY = leafScaleY;
			currState.lastOrientation = lastOrientation;
			currState.lastThickness = lastThickness;
			currState.uv = uv;
            stack.push(currState);
            continue;

        }else if(current == ']'){
            S_STACK newState = stack.pop();
            orientation = newState.orientation;
			nodePosition = newState.nodePosition;
            index = newState.index;
			lastHeading = newState.lastHeading;
			lastOrientation = newState.lastOrientation;
			lastThickness = newState.lastThickness;
			lastNodePosition = newState.lastNodePosition;
            thickness = newState.thickness;
			leafScaleX = newState.leafSizeX;
			leafScaleY = newState.leafSizeY;
			uv = newState.uv;
            continue;

        }else if(current == '!'){
			if (hasParam)  thickness *= param;
			else thickness *= decfactor;
			leafScaleX *= decfactorLeaf;
			leafScaleY *= decfactorLeaf;
            continue;
		}
		else if (current == 'L') {
			S_LEAF leaf;
			leaf.orientation = orientation;
			leaf.position = nodePosition;
			leaf.sizex = leafScaleX;
			leaf.sizey = leafScaleY;
			leafs.push_back(leaf);
			continue;
		}

    }

    S_DRAW_ELEMENTS returnStruct;
	returnStruct.branches = branches;
    returnStruct.indices = indices;
	returnStruct.leafs = leafs;

    return returnStruct;
}

QVector3D TurtleSystem::getHeadingAxis()
{
    return orientation.row(0).toVector3D();
}

QVector3D TurtleSystem::getLeftAxis()
{
    return orientation.row(1).toVector3D();
}

QVector3D TurtleSystem::getUpAxis()
{
    return orientation.row(2).toVector3D();
}

bool TurtleSystem::differenceTooHigh(const QVector3D & t1, const QVector3D & t2)
{
	float dot = QVector3D::dotProduct(t1, t2);
	float angle = acos(dot);
	angle *= 180.0 / M_PI;
	return angle < minAngle;
}

bool TurtleSystem::areInSameLine(const QVector3D & t1, const QVector3D & t2)
{
	return t1==t2;
}


