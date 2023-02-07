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

    float x = 0, y = 70 , r = 70;
    float P = 10 - r;

    for( x = 0; x<y ; x++){
        if(P < 0){
            P = P + (2 * x) + 3;
            glPointSize(3.0f);
                glBegin(GL_POINTS);
                    glColor3f(0.5f,0.5f,1.0f);
                    glVertex2f(x/100,y/100);
                    glVertex2f(y/100,x/100);
                    glVertex2f(-x/100,y/100);
                    glVertex2f(y/100,-x/100);
                    glVertex2f(x/100,-y/100);
                    glVertex2f(-y/100,x/100);
                    glVertex2f(-x/100,-y/100);
                    glVertex2f(-y/100,-x/100);
                glEnd();
        }
        else if(P >= 0){
            P = P + (2 * x) - (2 * y) + 3;
            glPointSize(3.0f);
                glBegin(GL_POINTS);
                    glColor3f(0.5f,0.5f,1.0f);
                    glVertex2f(x/100,y/100);
                    glVertex2f(y/100,x/100);
                    glVertex2f(-x/100,y/100);
                    glVertex2f(y/100,-x/100);
                    glVertex2f(x/100,-y/100);
                    glVertex2f(-y/100,x/100);
                    glVertex2f(-x/100,-y/100);
                    glVertex2f(-y/100,-x/100);
                glEnd();
            y = y - 1;
        }
    }
    glFlush();
}

int main(int argc,char** argv){

    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(80,50);
    glutCreateWindow("Mid Point Circle Drawing");
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
