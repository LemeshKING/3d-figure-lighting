#include "Coords3D.h"


Coords3D::Coords3D(float x, float y, float z)
{
   this->x = x;
   this->y = y;
   this->z = z;
}

Coords3D Coords3D::operator+(const Coords3D &AddValue)
{
   return Coords3D(x + AddValue.x, y + AddValue.y, z + AddValue.z);
}

Coords3D Coords3D::operator-(const Coords3D &SubValue)
{
   return Coords3D(x - SubValue.x, y - SubValue.y, z - SubValue.z);
}

Coords3D Coords3D::operator*(const float &value)
{
   return Coords3D(x * value, y * value, z * value);
}

Coords3D Coords3D::operator/(const float &value)
{
   return Coords3D(x / value, y / value, z / value);
}

void Coords3D::operator+=(const Coords3D AddValue)
{
   this->x += AddValue.x;
   this->y += AddValue.y;
   this->z += AddValue.z;
}

void Coords3D::operator*=(const float& value)
{
   this->x *= value;
   this->y *= value;
   this->z *= value;
}

float Norm(const Coords3D &vec)
{
   return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

Coords3D Cross(const Coords3D &vec1, const Coords3D &vec2)
{
   Coords3D Normal;
   Normal.x = vec1.y * vec2.z - vec1.z * vec2.y;
   Normal.y = vec1.z * vec2.x - vec1.x * vec2.z;
   Normal.z = vec1.x * vec2.y - vec1.y * vec2.x;
   return Normal;
}

Coords3D Normalize(Coords3D vec)
{
   float norm = Norm(vec);
   vec = vec / norm;
   return vec;
}

float Scalar(const Coords3D &vec1, const Coords3D &vec2)
{
   return vec1.x*vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

Coords3D Normal(Coords3D &vec1, Coords3D &vec2, Coords3D &vec3)
{
   
   Coords3D first = vec3 - vec1;
   Coords3D second = vec2 - vec1;
   Coords3D Normal = Cross(first,second);
   Normal = Normalize(Normal);
   //if(Normal.y < 0);
   //   Normal.y *= -1;
// 
// 
// 
// 
   //if (Normal.x < 0);
   //   Normal.x *= -1;
   return Normal;
}

Coords3D Vector(const Coords3D& vec1, const Coords3D &vec2)
{
   Coords3D tmp;
   tmp.x = vec1.x - vec2.x;
   tmp.y = vec1.y - vec2.y;
   tmp.z = vec1.z - vec2.z;
   return tmp;
}

Coords3D ChangeNormal(const Coords3D& vec1, const Coords3D& vec2, const Coords3D& vec3)
{
   Coords3D first = Vector(vec3, vec2);
   Coords3D second = Vector(vec2, vec1);
   Coords3D Normal = Cross(first, second);
   Normal = Normalize(Normal);
   return Normal;
}
