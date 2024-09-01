#pragma once
#include "Coords3D.h"
#include "Coords2D.h"
#include "glut.h"

#define M_PI       3.14159265358979323846   // pi





class Camera
{
public:
   Coords3D Position; 
   Coords3D View;
   Coords3D UpVector;
   Camera();
   void SetPosition(float posX, float posY,float posZ,
                    float viewX, float viewY, float ViewZ,
                    float upX, float upY, float upZ);
   void MoveCamera(float speed);
   void RotateAroundOY(Coords3D center, float angel, float x, float y, float z);
   void cameraMoveLeft(float speed);
private:
   float firstAngel;
};

