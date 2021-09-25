#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

int r, xc, yc, x, y;
float p;

void putPixel(int x, int y){
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}

void plotPoints(int x, int y){
	putPixel(xc + x, yc + y);
	putPixel(xc + y, yc + x);
	putPixel(xc + y, yc - x);
	putPixel(xc + x, yc - y);
	putPixel(xc - x, yc - y);
	putPixel(xc - y, yc - x);
	putPixel(xc - x, yc + y);
	putPixel(xc + y, yc - x);
	putPixel(xc - y, yc + x);
}

void drawCircle(){
	glBegin(GL_LINES);
		glVertex2f(-1000, 0);
		glVertex2f(1000, 0);
		glVertex2f(0, 1000);
		glVertex2f(0, -1000);
	glEnd();
	p = 1.25 - r;
	x = 0, y = r;
	while(x < y){
		plotPoints(x, y);
		if(p < 0){
			p += 2 * x + 1;
		}
		else if(p >= 0){
			y--;
			p += 2 * (x - y) + 1;
		}
		x++;
	}
	glFlush();
}

void init(){
	glOrtho(-1000, 1000, -1000, 1000, -1000, 1000);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
}

int main(int argc, char** argv){
	cout << "\n\nEnter the radius: ";
	cin >> r;
	cout << "\n\nEnter the x coordinate of center: ";
	cin >> xc;
	cout << "\n\nEnter the y coordinate of center: ";
	cin >> yc;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(500,500);
	glutCreateWindow("Midpoint Circle Drawing Algorithm");
	init();
	glutDisplayFunc(drawCircle);
	glutMainLoop();
	return 0;
}
