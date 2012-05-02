// fenxing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "glut.h"
#include "math.h"
#include <iostream>

using namespace std;

#pragma comment(lib,"glut32.lib")

 
#define MAX 700
#define M 1024 * 1024 * 1024
#define N 255

int red[MAX][MAX];
int green[MAX][MAX];
int blue[MAX][MAX];
int r[MAX][MAX];
int g[MAX][MAX];
int b[MAX][MAX];
 
void display(void);
void compute(void);
void julia(int , int);
void mouse(int, int, int, int);
void set(int, int, int);
 
/****************************************
*                                      *
*  计数单位:                           *
*           i from 0 to MAX            *
*           j from 0 to MAX            *
*                                      *
*  画布坐标:                           *
*           x = -1 + i / (MAX / 2)     *
*           y = 1 - j / (MAX / 2)      *
*                                      *
*  复平面坐标:                         *
*           a = -2.25 + i / (MAX / 3)  *
*           b = 1.5 - j / (MAX / 3)    *
*                                      *
****************************************/



int _tmain(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(MAX, MAX);
	glutCreateWindow("OpenGL");
	compute();
	glutDisplayFunc(&display);
	glutMouseFunc(&mouse);
	glutMainLoop();

	return 0;
}



/* display:  显示 */
void display(void)
{
	int i, j;
	double x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	for (i = 0; i < MAX; ++i)
	
	for (j = 0; j < MAX; ++j) 
	{
		x = -1 + (double)i / (MAX / 2);
		y = 1 - (double)j / (MAX / 2);
		glBegin(GL_POINTS);
		glColor3us(red[i][j], green[i][j], blue[i][j]);
		cout<<"x:"<<x<<"y:"<<y<<endl;
		glVertex2d(x, y);
		glEnd();
	}

	glFlush();
}
 
/* compute:  计算逃逸次数k ,并将其传递给set函数写入颜色索引 */
void compute(void)
{
	int i, j, k;
	double a, b, real, imag, real2, imag2;
 
	for (i = 0; i <MAX; ++i)
	for (j = 0; j < MAX; ++j) 
	{
		/* 一个 c 对应一个屏幕上一个点; step = 3 / (MAX - 1) */
		a = -2.25 + (double)i / ((MAX - 1) / 3);
		b = 1.5 - (double)j / ((MAX - 1) / 3);
		real = 0;
		imag = 0;
		for (k = 0; k <N; ++k)
		{ 
			real2 = real * real - imag * imag + a; 
			imag2 = 2 * real * imag + b;
			real = real2;
			imag = imag2;
			if (real * real + imag * imag > M)//fix later 
			{
				set(i, j, k);
				break;
			}
		}
	}
}
 
/* set:  set color at red[] green[] blue[] */
void set(int i, int j, int k)
{
	red[i][j] =(int) exp((float)k);
	blue[i][j] = 0;
	green[i][j] = k * k * k + k * k + k;

}
 
/* mouse:  display the 坐标 you clicked */
void mouse(int button, int state, int x, int y)
{
	printf("x:%d  y:%d  button:%d  state:%d\n", x, y, button, state);
	julia(x, y);

}
 
/* julia: compute the julia set based on the point you have clicked */
void julia(int a, int b)
{
	int i, j, k;
	double p, q, d, x, y, x2, y2, xy2;
	p = -2.25 + (double)a / (MAX / 3);
	q = 1.5 - (double)b / (MAX / 3);
	for (i = 0; i <MAX; ++i)
		for (j = 0; j <MAX; ++j) 
		{
			red[i][j] = 0;
			green[i][j] = 0;
			blue[i][j] = 0;
		}
 
	for (i = 0; i <MAX; ++i)
		for (j = 0; j < MAX; ++j) 
		{
/* 一个初始值对应屏幕上一个点; step = d */
			d = 3.0 / (MAX - 1);
			x = -1.5 + (double)i * d;
			y = -1.5 + (double)j * d;
			for (k = 0; k < N; ++k) 
			{
				x2 = x * x;   
				y2 = y * y; 
				xy2 = x * y * 2;
				x = x2 - y2 + p;
				y = xy2 + q;  
				
				if (x2 + y2> M) 
				{
					set(i, j, k);
					break;
				}
			}
	}
display();
return;
}

