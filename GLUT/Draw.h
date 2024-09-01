#include "Header.h"
#pragma once
void DrawWithoutTexAndSmoothNormales()
{
	auto &nN = normals.begin(); 
	auto n = *nN;
	auto &begin = figure.begin();
	auto tmp = *begin;
	glBegin(GL_TRIANGLES);
	glNormal3f(n.x, n.y, n.z); nN++;
	glColor3ub(255, 0, 160);
	glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glEnd();

	for (auto &i = figure.begin(); i != figure.end() - 1; i++)
	{
		n = *nN;
		auto tmp1 = *i; 
		auto tmp2 = *(i+1); 
		glBegin(GL_POLYGON);
		glNormal3f(n.x, n.y, n.z); nN++;
		n = *nN;
		glColor3ub(0, 255, 160);
		glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(n.x, n.y, n.z); nN++;
		n = *nN;
		glColor3ub(0, 170, 160);
		glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(n.x, n.y, n.z); nN++;
		n = *nN;
		glColor3ub(255, 255, 0);
		glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glEnd();
	}

	auto &j = figure.end() - 1;
	tmp = *j;
	glBegin(GL_TRIANGLES);
	glNormal3f(n.x, n.y, n.z);

	glColor3ub(0, 0, 255);
	glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glEnd();
}
void DrawWireFrameMode()
{
	glBegin(GL_LINE_STRIP);
	glColor3ub(255, 0, 0);
	for (auto &i = figure.begin(); i != figure.end(); i++)
	{
		auto tmp = *i;
		glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3ub(255, 0, 0);
	for (auto &i = figure.begin(); i != figure.end(); i++)
	{
		auto tmp = *i;
		glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3ub(255, 0, 0);
	for (auto &i = figure.begin(); i != figure.end(); i++)
	{
		auto tmp = *i;
		glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	}
	glEnd();

	for (auto &i = figure.begin(); i != figure.end(); i++)
	{
		auto tmp = *i;
		glBegin(GL_LINE_LOOP);
		glColor3ub(255, 0, 0);
		glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
		glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
		glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
		glEnd();
	}

}
void DrawWithoutTex()
{
	auto& nN = smoothNormals.begin();
	auto n = *nN;
	auto& begin = figure.begin();
	auto tmp = *begin;
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 0, 160);

	glNormal3f(n.x, n.y, n.z);
	glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z); nN++;
	n = *nN;
	glNormal3f(n.x, n.y, n.z); nN++;
	glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	n=*nN;
	glNormal3f(n.x, n.y, n.z);
	glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glEnd();

	nN = smoothNormals.begin();
	for (auto &i = figure.begin(); i != figure.end() - 1; i++)
	{
		auto tmp1 = *i;
		auto tmp2 = *(i + 1);
		glBegin(GL_POLYGON);
		glColor3ub(0, 255, 160);

		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z); ;
		n = *(nN + 3);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		n = *(nN + 4);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		n =*(nN + 1);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glEnd();

		glBegin(GL_POLYGON);

		glColor3ub(0, 170, 160);
		n = *(nN + 2);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		n = *(nN + 5);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		n = *(nN + 3);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		n = *nN;
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3ub(255, 255, 0);
		n=*(nN + 1);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		n = *(nN + 4);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		n = *(nN + 5);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		n = *(nN + 2);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glEnd();

		nN += 3;
	}

	auto &j = figure.end()-1;
	tmp = *j;
	glBegin(GL_TRIANGLES);
	glColor3ub(0, 0, 255);
	glNormal3f(n.x, n.y, n.z);
	glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	n = *(nN + 1);
	glNormal3f(n.x, n.y, n.z);
	glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	n = *(nN + 2);
	glNormal3f(n.x, n.y, n.z);
	glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glEnd();
}


void DrawWithoutSMoothNormales()
{
	auto &nN = normals.begin();
	auto n = *nN;
	auto& begin = figure.begin();
	auto tmp = *begin;
	glEnable(GL_TEXTURE_2D);	//разрешить текстурирование
	glBindTexture(GL_TEXTURE_2D, texture);	//выбрать текстуру
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);	//умножение

	//устанавливается нормаль для каждой плоскости
	//и тестурные координаты
	glBegin(GL_TRIANGLES);
	glNormal3f(n.x, n.y, n.z); nN++;
	n = *nN;
	glTexCoord2f(0.0f, 0.0f); glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	glTexCoord2f(0.5f, 1.0f); glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glEnd();

	for (auto &i = figure.begin(); i != figure.end() - 1; i++)
	{
		auto tmp1 = *i;
		auto tmp2 = *(i + 1);
		glBegin(GL_POLYGON);
		glNormal3f(n.x, n.y, n.z); nN++;
		n = *nN;

		glTexCoord2f(0, 1); glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glTexCoord2f(1, 1); glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		glTexCoord2f(1, 0); glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		glTexCoord2f(0, 0); glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(n.x, n.y, n.z); nN++;
		n = *nN;

		glTexCoord2f(0, 1); glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glTexCoord2f(1, 1); glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		glTexCoord2f(1, 0); glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		glTexCoord2f(0, 0); glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glEnd();

		glBegin(GL_POLYGON);
		glNormal3f(n.x, n.y, n.z); nN++;
		n = *nN;
		
		glTexCoord2f(0, 1); glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glTexCoord2f(1, 1); glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		glTexCoord2f(1, 0); glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		glTexCoord2f(0, 0); glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glEnd();
	}

	auto& j = figure.end() - 1;
	tmp = *j;
	glBegin(GL_TRIANGLES);
	glNormal3f(n.x, n.y, n.z); 


	glTexCoord2f(0.0f, 0.0f); glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	glTexCoord2f(0.5, 1); glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	glTexCoord2f(1, 0); glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glEnd();

	//отключить текстурирование
	glDisable(GL_TEXTURE_2D);
}


void DrawNormales()
{
	auto &nN = normals.begin();
	auto n = *nN;
	auto &begin = figure.begin();
	auto tmp = *begin;
	glLineWidth(5.0f);
	glBegin(GL_LINE_STRIP);
	glColor3ub(52,62,64);
	glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	glVertex3f(tmp.firstPoint.x + n.x, tmp.firstPoint.y + n.y, tmp.firstPoint.z + n.z);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3ub(52,62,64);
	glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	glVertex3f(tmp.secondPoint.x + n.x, tmp.secondPoint.y + n.y, tmp.secondPoint.z + n.z);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3ub(52,62,64);
	glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glVertex3f(tmp.thirdPoint.x + n.x, tmp.thirdPoint.y + n.y, tmp.thirdPoint.z + n.z);
	glEnd();

	nN++;
	n = *nN;
	for (auto &i = figure.begin(); i != figure.end() - 1; i++)
	{
		auto tmp1 = *i;
		auto tmp2 =*(i+1);
		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glVertex3f(tmp1.firstPoint.x + n.x, tmp1.firstPoint.y + n.y, tmp1.firstPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		glVertex3f(tmp2.firstPoint.x + n.x, tmp2.firstPoint.y + n.y, tmp2.firstPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		glVertex3f(tmp2.secondPoint.x + n.x, tmp2.secondPoint.y + n.y, tmp2.secondPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glVertex3f(tmp1.secondPoint.x + n.x, tmp1.secondPoint.y + n.y, tmp1.secondPoint.z + n.z);
		glEnd();

		nN++;
		n = *nN;
		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glVertex3f(tmp1.thirdPoint.x + n.x, tmp1.thirdPoint.y + n.y, tmp1.thirdPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		glVertex3f(tmp2.thirdPoint.x + n.x, tmp2.thirdPoint.y + n.y, tmp2.thirdPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		glVertex3f(tmp2.firstPoint.x + n.x, tmp2.firstPoint.y + n.y, tmp2.firstPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glVertex3f(tmp1.firstPoint.x + n.x, tmp1.firstPoint.y + n.y, tmp1.firstPoint.z + n.z);
		glEnd();

		nN++;
		n = *nN;
		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glVertex3f(tmp1.secondPoint.x + n.x, tmp1.secondPoint.y + n.y, tmp1.secondPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		glVertex3f(tmp2.secondPoint.x + n.x, tmp2.secondPoint.y + n.y, tmp2.secondPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		glVertex3f(tmp2.thirdPoint.x + n.x, tmp2.thirdPoint.y + n.y, tmp2.thirdPoint.z + n.z);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glVertex3f(tmp1.thirdPoint.x + n.x, tmp1.thirdPoint.y + n.y, tmp1.thirdPoint.z + n.z);
		glEnd();

		nN++;
		n = *nN;
	}

	auto &j = figure.end() - 1;
	tmp = *j;
	glBegin(GL_LINE_STRIP);
	glColor3ub(52,62,64);
	glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	glVertex3f(tmp.firstPoint.x + n.x, tmp.firstPoint.y + n.y, tmp.firstPoint.z + n.z);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3ub(52,62,64);
	glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	glVertex3f(tmp.secondPoint.x + n.x, tmp.secondPoint.y + n.y, tmp.secondPoint.z + n.z);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3ub(52,62,64);
	glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glVertex3f(tmp.thirdPoint.x + n.x, tmp.thirdPoint.y + n.y, tmp.thirdPoint.z + n.z);
	glEnd();
	glLineWidth(1.0f);

}
void DrawSmoothNormales()
{	
	glLineWidth(5.0f);
	auto &nN = smoothNormals.begin();
	
	for (auto& i = figure.begin(); i != figure.end(); i++)
	{	
		auto n = *nN;
		auto tmp1 = *i;
		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glVertex3f(tmp1.firstPoint.x + n.x, tmp1.firstPoint.y + n.y, tmp1.firstPoint.z + n.z);
		glEnd();
		n = *(nN + 1);
		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glVertex3f(tmp1.secondPoint.x + n.x, tmp1.secondPoint.y + n.y, tmp1.secondPoint.z + n.z);
		glEnd();
		n = *(nN + 2);
		glBegin(GL_LINE_STRIP);
		glColor3ub(52,62,64);
		glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glVertex3f(tmp1.thirdPoint.x + n.x, tmp1.thirdPoint.y + n.y, tmp1.thirdPoint.z + n.z);
		glEnd();
		nN += 3;
		
	}
	glLineWidth(1.0f);
}
void DrawAll()
{
	auto &nN=smoothNormals.begin();
	auto n = *nN;
	auto tmp = *figure.begin();
	glEnable(GL_TEXTURE_2D);	//разрешить текстурирование
	glBindTexture(GL_TEXTURE_2D, texture);	//выбрать текстуру
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);	//умножение

	//устанавливается нормаль для каждой вершины
	//и текстурные коорднаты
	glBegin(GL_TRIANGLES);


	glNormal3f(n.x, n.y, n.z);
	glTexCoord2f(0, 0); glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	n = *(nN + 1);
	glNormal3f(n.x, n.y, n.z);
	glTexCoord2f(0.5, 1); glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	n = *(nN + 2);
	glNormal3f(n.x, n.y, n.z);
	glTexCoord2f(1, 0); glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glEnd();

	for (auto &i = figure.begin(); i != figure.end() - 1; i++)
	{
		n = *nN;
		auto tmp1 = *i;
		auto tmp2 = *(i+1);
		glBegin(GL_POLYGON);


		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(0, 1); glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		n = *(nN + 3);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(1, 1); glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		n = *(nN + 4);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(1, 0); glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		n =*(nN + 1);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(0, 0); glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		glEnd();

		glBegin(GL_POLYGON);

		n = *(nN + 2);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(0, 1); glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		n = *(nN + 5);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(1, 1); glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		n = *(nN + 3);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(1, 0); glVertex3f(tmp2.firstPoint.x, tmp2.firstPoint.y, tmp2.firstPoint.z);
		n = *nN;
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(0, 0); glVertex3f(tmp1.firstPoint.x, tmp1.firstPoint.y, tmp1.firstPoint.z);
		glEnd();

		glBegin(GL_POLYGON);

		n = *(nN + 1);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(0, 1); glVertex3f(tmp1.secondPoint.x, tmp1.secondPoint.y, tmp1.secondPoint.z);
		n = *(nN + 4);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(1, 1); glVertex3f(tmp2.secondPoint.x, tmp2.secondPoint.y, tmp2.secondPoint.z);
		n = *(nN + 5);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(1, 0); glVertex3f(tmp2.thirdPoint.x, tmp2.thirdPoint.y, tmp2.thirdPoint.z);
		n = *(nN + 2);
		glNormal3f(n.x, n.y, n.z);
		glTexCoord2f(0, 0); glVertex3f(tmp1.thirdPoint.x, tmp1.thirdPoint.y, tmp1.thirdPoint.z);
		glEnd();
		nN += 3;
	}

	tmp  = *(figure.end() - 1);
	glBegin(GL_TRIANGLES);


	glNormal3f(n.x, n.y, n.z);
	glTexCoord2f(0, 0); glVertex3f(tmp.firstPoint.x, tmp.firstPoint.y, tmp.firstPoint.z);
	n = *(nN + 1);
	glNormal3f(n.x, n.y, n.z);
	glTexCoord2f(0.5, 1); glVertex3f(tmp.secondPoint.x, tmp.secondPoint.y, tmp.secondPoint.z);
	n = *(nN + 2);
	glNormal3f(n.x, n.y, n.z);
	glTexCoord2f(1, 0); glVertex3f(tmp.thirdPoint.x, tmp.thirdPoint.y, tmp.thirdPoint.z);
	glEnd();

	//отключить текстурирование
	glDisable(GL_TEXTURE_2D);
}