#define _MATH_DEFINES_DEFINED
#include<math.h>
#include "math.h"

#pragma once
class Coords3D
{
public:
   float x, y, z;
   Coords3D()
   {
      x = 0; y = 0; z = 0;
   }
   Coords3D(float x, float y, float z);
   Coords3D operator+(const Coords3D &AddValue);
   Coords3D operator-(const Coords3D &SubValue);
   Coords3D operator*(const float &value);
   Coords3D operator/(const float &value);
   void operator+=(const Coords3D AddValue);
   void operator*=(const float&value);
};
float Norm(const Coords3D &vec);

Coords3D Cross(const Coords3D &vec1, const Coords3D &vec2);

Coords3D Normalize(Coords3D vec);

float Scalar(const Coords3D &vec1, const Coords3D &vec2);

Coords3D Normal(Coords3D &vec1, Coords3D &vec2, Coords3D &vec3);

Coords3D Vector(const Coords3D &vec1, const Coords3D &vec2);

Coords3D ChangeNormal(const Coords3D& vec1, const Coords3D& vec2, const Coords3D& vec3);