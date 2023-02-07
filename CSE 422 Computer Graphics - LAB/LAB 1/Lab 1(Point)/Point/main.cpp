#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
        glColor3f(1.0f,1.0f,1.0f);

        glVertex2f(1.0f,0.0f);
        glVertex2f(-1.0f,0.0f);

        glVertex2f(0.0f,1.0f);
        glVertex2f(0.0f,-1.0f);
    glEnd();

    glPointSize(20.0f);
    glBegin(GL_POINTS);

        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(-1.0f,-1.0f);

        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(1.0f,1.0f);

        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(1.0f,-1.0f);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-1.0f,1.0f);

        glColor3f(0.5f,0.5f,0.5f);
        glVertex2f(-0.7f,0.7f);

        glColor3f(0.2f,0.3f,0.4f);
        glVertex2f(-0.3f,-0.3f);

        glColor3f(0.1f,0.2f,0.3f);
        glVertex2f(0.3f,0.3f);

        glColor3f(0.5f,0.3f,0.7f);
        glVertex2f(-0.7f,0.5f);

        glColor3f(0.8f,0.8f,0.8f);
        glVertex2f(-0.5f,0.5f);

        glColor3f(0.9f,1.0f,0.5f);
        glVertex2f(-0.1f,0.9f);

        glColor3f(0.2f,0.5f,0.7f);
        glVertex2f(0.6f,-0.6f);

        glColor3f(0.7f,0.5f,0.7f);
        glVertex2f(0.6f,-0.5f);

        glColor3f(0.2f,0.7f,0.7f);
        glVertex2f(0.6f,-0.3f);

        glColor3f(0.5f,0.5f,0.7f);
        glVertex2f(-0.6f,-0.6f);

        glColor3f(0.7f,0.5f,0.5f);
        glVertex2f(-0.7f,-0.6f);

    glEnd();

    glFlush();
}

int main(int argc,char** argv){

    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(80,50);
    glutCreateWindow("Lab 1");
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
