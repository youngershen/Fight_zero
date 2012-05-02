// Blade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "glut.h"

#include <iostream>

#pragma comment(lib,"glut32.lib")

using namespace std;
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 

void init_window(int argc,char ** argv,char * title,int width,int height, int px,int py);
void display_func(void);
void mouse_func(int button,int state,int x ,int y);
void motion_func(int x, int y);

int mouse_x;
int mouse_y;

int _tmain(int argc,char ** argv)
{
	init_window(argc,argv,"test",640,400,0,0);

	glutDisplayFunc(&display_func);
	glutMouseFunc(&mouse_func);
	glTranslatef(-1.0f,1.0f,0.0f);
	//glutMotionFunc(&motion_func);
	glutPassiveMotionFunc(&motion_func);
	glutMainLoop();
	
	return 0;
}

void init_window(int argc,char ** argv ,char * title,int width,int height,int px,int py)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(px,py);
	int flag  = glutCreateWindow(title);
	cout<<"create window flag is ::"<<flag<<endl;
}

void display_func(void)
{
	/*
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
	glVertex2d(100, 100);
	glEnd();
	glFlush();
	*/
	//glTranslatef(3.0,0.0,0.0); // 右移3单位
	// glClear(GL_COLOR_BUFFER_BIT);
	// glColor3f(1.0,0.0,0.0); // 一次性将当前色设置为蓝色
	// glBegin(GL_POINTS);      // 绘制正方形（逆时针画出来的正方形才是正面朝着我们的）
	// glVertex2d(100, 100);
	// glVertex3f(-1.0,-1.0, 0.0); // 左下
    //glVertex3f( 1.0,-1.0, 0.0); // 右下
    //glVertex3f( 1.0, 1.0, 0.0); // 右上
    //glVertex3f(-1.0, 1.0, 0.0); // 左上
	
	glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(6.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
    glFlush();
	
}

void mouse_func(int button,int state,int x ,int y)
{

	cout<<"mouse x position ::"<<x<<endl;
	cout<<"mouse y position ::"<<y<<endl;
	cout<<"mouse button ::"<<button<<endl;
	cout<<"mouse state ::"<<state<<endl;
	mouse_x = x;
	mouse_y = y;
	display_func();
}
void motion_func(int x,int y)
{
	//cout<<"motion x ::"<<x<<endl;
	//cout<<"motion y ::"<<y<<endl;
	


}