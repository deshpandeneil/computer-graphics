#include <math.h>
#include <GL/glut.h>

struct Point {
	int x;
	int y;
};

struct Color {
	float r;
	float g;
	float b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(int x, int y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(int x, int y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();

}

void BoundaryFill(int x, int y, Color fillColor, Color boundaryColor) {
	Color currentColor = getPixelColor(x, y);
	if(currentColor.r != boundaryColor.r && currentColor.g != boundaryColor.g && currentColor.b != boundaryColor.b) {
		setPixelColor(x, y, fillColor);
		BoundaryFill(x+1, y, fillColor, boundaryColor);
		BoundaryFill(x-1, y, fillColor, boundaryColor);
		BoundaryFill(x, y+1, fillColor, boundaryColor);
		BoundaryFill(x, y-1, fillColor, boundaryColor);
	}
}

void onMouseClick(int button, int state, int x, int y)
{
	Color fillColor = {0.0f, 1.0f, 0.0f};		// red color will be filled
	Color boundaryColor = {0.0f, 0.0f, 0.0f}; // black- boundary

	Point p = {101, 199}; // a point inside the square

	BoundaryFill(p.x, p.y, fillColor, boundaryColor);
}

void draw_dda(Point p1, Point p2) {
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;

	float x1 = p1.x;
	float y1 = p1.y;

	float step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	float xInc = dx/step;
	float yInc = dy/step;

	for(float i = 1; i <= step; i++) {
		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}
}

void display(void) {
	Point p1 = {100, 100}, // bottom-right
		p2 = {200, 100}, // bottom-left
		p3 = {200, 200}, // top-right
		p4 = {100, 200}; // top-left
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		draw_dda(p1, p2);
		draw_dda(p2, p3);
		draw_dda(p3, p4);
		draw_dda(p4, p1);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Boundary Fill");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}
