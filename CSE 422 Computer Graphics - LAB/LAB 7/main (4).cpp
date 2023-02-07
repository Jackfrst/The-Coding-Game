#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float angle = 0;
float t,s=0.5,m=0;

void myinit(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

void keyboard(unsigned char key, int x, int y){
        if(key==8)
        {
            exit(0);

        }else if(key == 82 || key == 114){
            angle-=0.1;

            glRotatef(angle,0,0,1);
            glutPostRedisplay();

        }else if(key == 84 || key == 116 )
        {
             t+=0.02;
             glTranslatef(t,0,0);
             glutPostRedisplay();
        }else if(key == 43){
                 s+=0.03;
                 glScalef(s,s,0);
                 glutPostRedisplay();
        }
        (void)(x);
        (void)(y);
    }

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);  ///red color

    glBegin(GL_TRIANGLES);
       glVertex3f(0.2,0.2,0.0);
       glVertex3f(0.5,0.2,0.0);
       glVertex3f(0.25,0.5,0.0);
    glEnd();
    glFlush();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Polygon");
    glutDisplayFunc(display);
    myinit();
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
