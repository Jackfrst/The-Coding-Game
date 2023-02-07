#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    /*glBegin(GL_LINES);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-1.0,0.0f);
        glVertex2f(1.0f,0.0f);
        glVertex2f(0.0f,-1.0f);
        glVertex2f(0.0f,1.0f);
    glEnd();*/

    glBegin(GL_LINES);
        glColor3f(1.0f,0.0f,0.0f);

        glVertex2f(0.0,0.3f);   // Left ear
        glVertex2f(0.5f,0.3f);
        glVertex2f(0.5f,0.3f);
        glVertex2f(0.6f,0.7f);
        glVertex2f(0.0f,0.3f);
        glVertex2f(0.6f,0.7f);

        glVertex2f(0.0,0.3f);      // Right ear
        glVertex2f(-0.5f,0.3f);
        glVertex2f(-0.5f,0.3f);
        glVertex2f(-0.6f,0.7f);
        glVertex2f(0.0f,0.3f);
        glVertex2f(-0.6f,0.7f);

        glVertex2f(0.5f,0.3f);    //Head
        glVertex2f(0.35f,-0.4f);
        glVertex2f(-0.5f,0.3f);
        glVertex2f(-0.35f,-0.4f);
        glVertex2f(0.35f,-0.4f);
        glVertex2f(-0.35f,-0.4f);

        glVertex2f(0.0f,-0.25f); //Mouth
        glVertex2f(-0.1f,-0.3f);
        glVertex2f(-0.1f,-0.3f);
        glVertex2f(-0.2f,-0.25f);
        glVertex2f(0.0f,-0.25f);
        glVertex2f(0.1f,-0.3f);
        glVertex2f(0.1f,-0.3f);
        glVertex2f(0.2f,-0.25f);

        glVertex2f(0.1f,0.05f);
        glVertex2f(0.3f,0.1f);
        glVertex2f(0.3f,0.1f);
        glVertex2f(0.25f,0.025f);
        glVertex2f(0.25f,0.025f);
        glVertex2f(0.1f,0.05f);

        glVertex2f(-0.1f,0.05f);
        glVertex2f(-0.3f,0.1f);
        glVertex2f(-0.3f,0.1f);
        glVertex2f(-0.25f,0.025f);
        glVertex2f(-0.25f,0.025f);
        glVertex2f(-0.1f,0.05f);

    glEnd();

    /*glPointSize(20.0f);
        glBegin(GL_POINTS);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(0.7f,0.7f);
    glEnd();*/

    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc,argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(80,60);
    glutCreateWindow("LAB 1");
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

