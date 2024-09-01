
#include<cmath>
#include "math.h"
#include<fstream>
#include<vector>
#include "glut.h"
#include "Camera.h"
#include "Coords3D.h"
#include <stdio.h>


#pragma once

using namespace std;

#define M_PI       3.14159265358979323846   // pi

float kspeed = 0.05f;
Camera camera;
GLint Width = 512, Height = 512;
bool perspective = true;
bool wireFrameMode = false;
bool smothNormals = false;
bool textureMod=false;
bool drawNormalesMode = false;
bool TurningLight = false;
bool disablePrevLight = true;

float angel = 60.0f;
float mas = 10.0f;
float SMatrix[4][4];
unsigned char lightSelection = 1;

struct triangel
{
   Coords3D firstPoint;
   Coords3D secondPoint;
   Coords3D thirdPoint;
   bool changeDirection = false;
};
vector<Coords3D> smoothNormals;
vector<Coords3D> scales;
vector<Coords3D> path;
vector<triangel> figure;
vector<Coords3D> normals;
triangel tmp;
void ReadFiles()
{
   ifstream file("coords2d.txt");
   file >> tmp.firstPoint.x >> tmp.firstPoint.y;
   file >> tmp.secondPoint.x >> tmp.secondPoint.y;
   file >> tmp.thirdPoint.x >> tmp.thirdPoint.y;
   
   file.close();
   file.open("traj.txt");
   while(!file.eof())
   {
      Coords3D traj;
      file >> traj.x >> traj.y >> traj.z;
      path.push_back(traj);
   }
   file.close();
   file.open("coef.txt");
   while(!file.eof())
   { 
      Coords3D scale;
      file >> scale.x >> scale.y >> scale.z;
      scales.push_back(scale);
   }
}
Coords3D multCoords(float matrix[4][4], Coords3D vec)
{
   float vect[4] = {vec.x, vec.y, vec.z, 1.0f};
   float resVec[4];
   for (int i = 0; i < 4; i++)
   {
      double s = 0;
      for(int j = 0; j < 4; j++)
         s+= matrix[i][j] * vect[j];
      resVec[i] = s;
   }
   return Coords3D(resVec[0],resVec[1],resVec[2]);
}


void makeScaleMatrix(float sx, float sy, float sz)
{
   SMatrix[0][0] = sx; SMatrix[0][1] = 0;
   SMatrix[0][2] = 0; SMatrix[0][3] = 0;
   SMatrix[1][0] = 0; SMatrix[1][1] = sy;
   SMatrix[1][2] = 0; SMatrix[1][3] = 0;
   SMatrix[2][0] = 0; SMatrix[2][1] = 0;
   SMatrix[2][2] = sz; SMatrix[2][3] = 0;
   SMatrix[3][0] = 0; SMatrix[3][1] = 0;
   SMatrix[3][2] = 0; SMatrix[3][3] = 1;
}


void BuildFigure()
{  
   
   figure.push_back(tmp);
   for (int i = 0; i < path.size(); i++)
   {
      triangel tmp2 = figure[i];
      tmp2.firstPoint += path[i];
      tmp2.secondPoint += path[i];
      tmp2.thirdPoint += path[i];
      figure.push_back(tmp2);
   }
   for(int i = 1; i < path.size(); i++)
      if(path[i].z * path[i-1].z < 0)
         figure[i+1].changeDirection = true;
   for (int i = 0; i < figure.size(); i++)
   {
      makeScaleMatrix(scales[i].x, scales[i].y, scales[i].z);
      figure[i].firstPoint = multCoords(SMatrix,figure[i].firstPoint);
      figure[i].secondPoint = multCoords(SMatrix, figure[i].secondPoint);
      figure[i].thirdPoint = multCoords(SMatrix, figure[i].thirdPoint);
   }

}
void calcNormals()
{
   Coords3D normal;
   //отдельно вычисл€ютс€ нормали к первому треугольнику
   normal = Normal(figure[0].firstPoint, figure[0].secondPoint, figure[0].thirdPoint);
   normals.push_back(normal);

   for (int i = 0; i < figure.size() - 1; i++)
   {
      if(!figure[i].changeDirection)
      {  
         normal = Normal(figure[i].firstPoint, figure[i].secondPoint, figure[i + 1].firstPoint);
         normals.push_back(normal);

         normal = Normal(figure[i].firstPoint, figure[i].thirdPoint, figure[i + 1].thirdPoint);
         normals.push_back(normal);

         normal = Normal(figure[i].secondPoint, figure[i].thirdPoint, figure[i + 1].secondPoint);
         normals.push_back(normal);
      }
      else 
      {  
         normal = ChangeNormal(figure[i].secondPoint, figure[i].firstPoint, figure[i + 1].firstPoint);
         normals.push_back(normal);

         normal = ChangeNormal(figure[i].firstPoint, figure[i].thirdPoint, figure[i + 1].thirdPoint);
         normals.push_back(normal);

         normal = ChangeNormal(figure[i].thirdPoint, figure[i].secondPoint, figure[i + 1].secondPoint);
         normals.push_back(normal);
         if(!figure[i+1].changeDirection)
            figure[i + 1].changeDirection = !figure[i + 1].changeDirection;
      }
   }

   
   int j = figure.size() - 1;
   if(!figure[j].changeDirection)
      normal = Normal(figure[j].firstPoint, figure[j].thirdPoint, figure[j].secondPoint);
   else
      normal = ChangeNormal(figure[j].firstPoint, figure[j].thirdPoint, figure[j].secondPoint);
   normals.push_back(normal);
   
}
void calcSmoothNormals()
{
   Coords3D smoothNormal;

   smoothNormal = (normals[0] + normals[1] + normals[2]) / 3.0;
   smoothNormals.push_back(smoothNormal);

   smoothNormal = (normals[0] + normals[1] + normals[3]) / 3.0;
   smoothNormals.push_back(smoothNormal);

   smoothNormal = (normals[0] + normals[2] + normals[3]) / 3.0;
   smoothNormals.push_back(smoothNormal);

   int nN = 1;
   for (int i = 1; i < figure.size() - 1; i++)
   {
      smoothNormal = (normals[nN] + normals[nN + 1] + normals[nN + 3] + normals[nN + 4]) / 4.0;
      smoothNormals.push_back(smoothNormal);

      smoothNormal = (normals[nN] + normals[nN + 2] + normals[nN + 3] + normals[nN + 5]) / 4.0;
      smoothNormals.push_back(smoothNormal);

      smoothNormal = (normals[nN + 1] + normals[nN + 2] + normals[nN + 4] + normals[nN + 5]) / 4.0;
      smoothNormals.push_back(smoothNormal);
      nN += 3;
   }
   int j = normals.size() - 1;
   smoothNormal = (normals[j] + normals[j - 2] + normals[j - 3]) / 3.0;
   smoothNormals.push_back(smoothNormal);

   smoothNormal = (normals[j] + normals[j - 1] + normals[j - 3]) / 3.0;
   smoothNormals.push_back(smoothNormal);

   smoothNormal = (normals[j] + normals[j - 1] + normals[j - 2]) / 3.0;
   smoothNormals.push_back(smoothNormal);
}

GLuint texture;


void LoadTex()
{
   int width = 2, height = 2;
   struct 
   {
      unsigned char r = 0, g = 0, b = 0, a = 1;
   } data[2][2];

   memset(data, 0, sizeof(data));
   data[0][0].r = 255;
   data[1][0].g = 255;
   data[1][1].b = 255;
   data[0][1].r = 255;
   data[0][1].g = 255;
  
   glGenTextures(1,&texture);
   glBindTexture(GL_TEXTURE_2D, texture);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
   glBindTexture(GL_TEXTURE_2D,0);
   
}
