#include <stdio.h>
#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;


void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(1.0f,0.0f);
        glVertex2f(-1.0f,0.0f);
        glVertex2f(0.0f,1.0f);
        glVertex2f(0.0f,-1.0f);
    glEnd();

    float x,y,r = 70;

    for(x= 0 ;x <= r; x++){
        y = sqrt(pow(r,2) - pow(x,2));
        glBegin(GL_POINTS);
        glColor3f(1.0f,1.0f,1.0f);
            glVertex2f(x/100,y/100);
            glVertex2f(x/100,-y/100);
            glVertex2f(-x/100,y/100);
            glVertex2f(-x/100,-y/100);
        glEnd();

    }
    glFlush();
}

int main(int argc,char** argv){

    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(80,50);
    glutCreateWindow("Direct Line");
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
