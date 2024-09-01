#include "Camera.h"

Camera::Camera()
{
}

void Camera::SetPosition(float posX, float posY, float posZ, float viewX, float viewY, float ViewZ, float upX, float upY, float upZ)
{
   Position.x = posX; Position.y = posY; Position.z = posZ;
   View.x = viewX; View.y = viewY; View.z = ViewZ;
   UpVector.x = upX; UpVector.y = upY; UpVector.z = upZ;
   Coords3D Vector = View - Position;
   firstAngel = acosf(Vector.z / sqrt(Vector.z * Vector.z + Vector.x * Vector.x)) * 180 / M_PI;
   if(Vector.x < 0)
      firstAngel *=-1;
}

void Camera::MoveCamera(float speed)
{
   Coords3D DirectionView = View - Position;
   
   Position.x += DirectionView.x * speed;
   Position.y += DirectionView.y * speed;
   Position.z += DirectionView.z * speed;

   View.x += DirectionView.x * speed ;
   View.z += DirectionView.z * speed;
   View.y += DirectionView.y * speed ;
}


void Camera::RotateAroundOY(Coords3D center, float angel, float x, float y, float z)
{

   Coords3D vPos = View - Position;

   firstAngel += angel * 180/M_PI ;
  
   float cosA = (float)cos(firstAngel * M_PI / 180);
   float sinA = (float)sin(firstAngel * M_PI / 180);

   View.x = sinA * Norm(vPos) + Position.x;
   View.z = cosA * Norm(vPos) + Position.z;
}

void Camera::cameraMoveLeft(float speed)
{
   float c = cos(firstAngel * M_PI/180 + M_PI/2);
   float s = sin(firstAngel * M_PI/180 + M_PI/2);
   Position.x += s * speed;
   Position.z += c * speed;
   
   View.x +=  s * speed;
   View.z +=  c * speed;
}
