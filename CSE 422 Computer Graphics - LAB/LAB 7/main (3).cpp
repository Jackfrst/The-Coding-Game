#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int px = 10,py = 10, theta = 10;
int x, y ,xe, ye;

void delay(float secs)
{
	float end = clock() / CLOCKS_PER_SEC + secs;
	while ((clock() / CLOCKS_PER_SEC) < end);
}

void translate(){

        int x=100, y=300 ,xe = 300, ye = 300;

        glBegin(GL_LINES);
            glColor3f(1.0f,0.0f,0.0f);
            glVertex2i(x,y);
            glVertex2i(xe,ye);
        glEnd();

        for(int i = 1 ; ; i++){
            glBegin(GL_LINES);
                x += px;
                xe+= px;
                y += py;
                ye+= py;
                if(xe > 600 || ye > 800)
                break;
                glColor3f(0.0f,1.0f,0.0f);
                glVertex2i(x,y);
                glVertex2i(xe,ye);
            glEnd();
            glFlush();
            usleep(500000);
            //delay(1);
        }
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,600,0,800);

    translate();
}

int main(int argc,char** argv){

    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(80,50);
    glutCreateWindow("Translate");
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
