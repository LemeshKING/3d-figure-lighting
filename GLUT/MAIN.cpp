/*
Отключено консольное (главное) окно:
	Linker ->  Advanced -> Entery Point := "mainCRTStartup"
	Linker ->  System -> SubSystem := "Windows (/SUBSYSTEM:WINDOWS)"
*/

#include"Header.h"
#include"Draw.h" 

using namespace std;

void Draw3DSGrid()
{
	glColor3ub(255, 255, 255);
	for (float i = -250; i <= 250; i += 1)
	{
		glBegin(GL_LINES);
		// Ось Х
		glVertex3f(-250, 0, i);
		glVertex3f(250, 0, i);

		// Ось Z
		glVertex3f(i, 0, -250);
		glVertex3f(i, 0, 250);
		glEnd();
	}
}
void Shine_a_Light()
{
	if (disablePrevLight)
	{
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
	}
	GLfloat ambience[4] = { 0.1f, 0.1f, 0.1f, 1.0 };	//Цвет мирового света
	GLfloat material_diffuse[] = { 1.0, 1.0, 1.0, 1 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_diffuse);
	glEnable(GL_COLOR_MATERIAL);
	
	if (lightSelection == 1)
	{
		//направленный источник света
	//находится в бесконечности и свет от него распространяется в заданном направлении
		
		GLfloat light0_diffuse[] = { 0.4, 0.7, 0.2 };
		GLfloat light0_direction[] = { 0.0, 0.0, 1.0, 1.0 };
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
		glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
	}
	if (lightSelection == 2)
	{
		//точечный источник света
		//убывание интенсивности с расстоянием
		//отключено (по умолчанию)
		GLfloat light1_diffuse[] = { 0.4f, 0.7f, 0.2f };
		GLfloat light1_position[] = { 0.0, 0.0, 1.0, 1.0 };
		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1, GL_AMBIENT, ambience);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	}
	if (lightSelection == 3)
	{
		//точечный источник света
		//убывание интенсивности с расстоянием
		GLfloat light2_diffuse[] = { 0.4, 0.7, 0.2 };
		GLfloat light2_position[] = { -5.0, 8.0, -4.0, 1.0 };
		glEnable(GL_LIGHT2);
		glLightfv(GL_LIGHT2, GL_AMBIENT, ambience);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
		glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.04);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.04);
	}
	if (lightSelection == 4)
	{
		//прожектор
		//убывание интенсивности с расстоянием
		//отключено (по умолчанию)
		GLfloat light3_diffuse[] = { 0.4, 0.7, 0.2 };
		GLfloat light3_position[] = { -5.0, 8.0, 3.0, 1.0 };
		GLfloat light3_spot_direction[] = { 1.0, -1.0, 1.0 };
		glEnable(GL_LIGHT3);
		glLightfv(GL_LIGHT3, GL_AMBIENT, ambience);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, light3_diffuse);
		glLightfv(GL_LIGHT3, GL_POSITION, light3_position);
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 50);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light3_spot_direction);
	}
	if (lightSelection == 5)
	{
		//прожектор
		//включен рассчет убывания интенсивности для прожектора
		GLfloat light4_diffuse[] = { 0.4, 0.7, 0.2 };
		GLfloat light4_position[] = { -5.0, 8.0, -3.0, 1.0 };
		GLfloat light4_spot_direction[] = { 1.0, -1.0, -1.0 };
		glEnable(GL_LIGHT4);
		glLightfv(GL_LIGHT4, GL_AMBIENT, ambience);
		glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse);
		glLightfv(GL_LIGHT4, GL_POSITION, light4_position);
		glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 51);
		glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4_spot_direction);
		glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 15.0);
	}
}
void DrawFigure()
{
	if(!wireFrameMode)
		if(!smothNormals)
			if(!textureMod)
				DrawWithoutTexAndSmoothNormales();
			else 
				DrawWithoutSMoothNormales();
		else if(!textureMod)
			DrawWithoutTex();
		else
			DrawAll();
	else 
		DrawWireFrameMode();
	
	if(drawNormalesMode && smothNormals)
		DrawSmoothNormales();
	else if (drawNormalesMode)
		DrawNormales();
}

void Display(void)
{
	glClearColor(0.5, 0.5, 0.5, 1); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	if(TurningLight)
		glEnable(GL_LIGHTING);
	else
		glDisable(GL_LIGHTING);
	glLoadIdentity();
	gluLookAt(camera.Position.x, camera.Position.y, camera.Position.z,
		camera.View.x, camera.View.y, camera.View.z,
		camera.UpVector.x, camera.UpVector.y, camera.UpVector.z);
	Shine_a_Light();
	GLfloat light0_position[] = { 0.0f, 3.0f, 0.0f, 0.0f };
	GLfloat light1_position[] = { 0.0f, 100.0f, 0.0f, 1.0f };
	GLfloat light2_position[] = { 0.0f, 100.0f, 0.0f, 1.0f };
	GLfloat light3_position[] = { 0.0f, 15.0f, 0.0f, 1.0f };
	GLfloat light3_spot_direction[] = { 0.0f, -1.0f, 0.0f, 1.0f };
	GLfloat light4_position[] = { 0.0f, 15.0f, 0.0f, 1.0f };
	GLfloat light4_spot_direction[] = { 0.0f, -1.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	glLightfv(GL_LIGHT3, GL_POSITION, light3_position);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light3_spot_direction);
	glLightfv(GL_LIGHT4, GL_POSITION, light4_position);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4_spot_direction);
	Draw3DSGrid();
	DrawFigure();
	glTranslatef(camera.View.x, 0, camera.View.z);
	glFinish();
	glutSwapBuffers();
}

/* Функция изменения размеров окна */
void Reshape(GLint w, GLint h)
{
	Width = w;    Height = h;
	glViewport(0, 0, w, h);
	if(Height == 0) Height = 1;
	float ratio = 1.0 * Width/Height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(perspective)
		gluPerspective(angel,ratio, 0.1f, 100.0f);
	else if(Width >= Height)
		glOrtho(-mas * ratio, mas * ratio, -mas, mas, -10.0f, 10.f);
	else
		glOrtho(-mas, mas, -mas/ratio, mas/ratio, -10.0f, 10.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/* Функция обработки сообщений от клавиатуры */
void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'w')
		camera.MoveCamera(kspeed);
	if (key == 's')
		camera.MoveCamera(-kspeed);
	if (key == 'a')
	{
		camera.cameraMoveLeft(kspeed * 5);
	}
	if (key == 'd')
	{
		camera.cameraMoveLeft(-kspeed * 5);
	}
	if (key == 'q')
		camera.RotateAroundOY(camera.View, 5* M_PI / 180 , 0.0f, 1.0f, 0.0f);
	if (key == 'e')
		camera.RotateAroundOY(camera.View,  -M_PI/180 * 5  , 0.0f, 1.0f, 0.0f);
	if (key == ' ')
	{ 
		camera.Position.y += kspeed * 2;
		camera.View.y += kspeed * 2;
	}
	if(key =='p')
		{
			perspective = !perspective;
			Reshape(Width, Height);
		}
	if(key =='k')
		wireFrameMode = !wireFrameMode;
	if(key == 'b')
		drawNormalesMode = !drawNormalesMode;
	if(key =='v')
		smothNormals = !smothNormals;
	if(key == 'l')
		TurningLight = !TurningLight;
	if(key == '1')
		lightSelection = 1;
	if(key == '2')
		lightSelection = 2;
	if(key =='3')
		lightSelection = 3;
	if(key == '4')
		lightSelection = 4;
	if(key == '5')
		lightSelection = 5;
	if(key == 't')
		disablePrevLight =!disablePrevLight;
	if(key =='y')
		textureMod = !textureMod;
	if(key == '+' && !perspective)
	{
		mas -=0.05;
		Reshape(Width, Height);
	}
	if (key == '-' && !perspective)
	{
		mas += 0.05;
		Reshape(Width, Height);
	}

	glutPostRedisplay();
}
void SpecialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN)
	{
		camera.Position.y -= kspeed * 2;
		camera.View.y -= kspeed * 2;
	}
	glutPostRedisplay();
}

/* Функция обработки сообщения от мыши */
void Mouse(int button, int state, int x, int y)
{

}

void Menu(int pos)
{
	
}

void Init()
{
	camera.SetPosition(-1.0f, 3.0f, 0.0f, 4, 3.0f, 0, 0.0f, 1.0f, 0.0f);
	ReadFiles();
	BuildFigure();
	calcNormals();
	calcSmoothNormals();
	LoadTex();
	
}

/* Головная программа */
void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE |GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("");
	Init();
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeyboard);
	glutMouseFunc(Mouse);
	glEnable(GL_NORMALIZE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutMainLoop();

}
