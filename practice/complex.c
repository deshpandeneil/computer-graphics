#include <GL/freeglut.h>
#include <GL/gl.h>
void line(float x1,float y1, float x2, float y2){
    glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);  
    glEnd();
}
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	//start of square of hut
    glBegin(GL_LINES);
        glVertex2f(0.3,-0.4); 
        glVertex2f(0.3,0.0); 
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.3,0.0); 
        glVertex2f(0.8,0.0); 
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.8,0.0); 
        glVertex2f(0.8,-0.4); 
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.8,-0.4); 
        glVertex2f(0.3,-0.4); 
    glEnd();
  //start of top of hut
    glBegin(GL_LINES);
        glVertex2f(0.3,0.0); 
        glVertex2f(0.55,0.3);  
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.55,0.3); 
        glVertex2f(0.8,0.0); 
    glEnd();
    //start of door of hut
    glBegin(GL_LINES);
        glVertex2f(0.45,-0.4); 
        glVertex2f(0.45,-0.2); 
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.45,-0.2); 
        glVertex2f(0.65,-0.2);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.65,-0.2); 
        glVertex2f(0.65,-0.4); 
    glEnd();
    //start of mountains
    glBegin(GL_LINES);
        glVertex2f(-0.5,0.25); 
        glVertex2f(-0.1,0.6); 
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(-0.1,0.6);
        glVertex2f(0.15,0.2); 
         
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.15,0.2); 
        glVertex2f(0.6,0.6);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.6,0.6);
        glVertex2f(0.9,0.15);
    glEnd();
    //start of car
    glBegin(GL_LINES);
        glVertex2f(-0.5,0);
        glVertex2f(-0.2,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(-0.2,0);
        glVertex2f(-0.2,-0.15);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(-0.2,-0.15);
        glVertex2f(-0.5,-0.15);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(-0.5,-0.15);
        glVertex2f(-0.5,0);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Scenery");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}

