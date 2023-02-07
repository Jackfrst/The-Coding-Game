#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

float x_s ; //points
float y_s ;
float x_e ;
float y_e ;

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
        glColor3f(1.0f,1.0f,1.0f);

        glVertex2f(1.0f,0.0f);
        glVertex2f(-1.0f,0.0f);

        glVertex2f(0.0f,1.0f);
        glVertex2f(0.0f,-1.0f);

    glEnd();

    glPointSize(3.0f);
    glBegin(GL_POINTS);
        glColor3f(0.5f,0.5f,1.0f);

        if(x_s > x_e || y_s > y_e){   //swaping
            float temp = x_s;
            float temp1 = y_s;
            x_s =  x_e;
            y_s =  y_e;
            x_e = temp;
            y_e =  temp1;
        }

        float x = x_s;
        float y = y_s;
        float m = (y_e - y_s) / (x_e - x_s);
        float b =  y_s - (m * x_s);

        for(float i = x; i <= x_e ; i++){
                glVertex2f((i/1000),(y/1000));
                y = m*x + b;
        }

    glEnd();

    glFlush();
}

int main(int argc,char** argv){
    cout<<"Give a point (x_s,y_s): ";
    cin>>x_s>>y_s;
    cout<<"Give another point (x_e,y_e): ";
    cin>>x_e>>y_e;

    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(80,50);
    glutCreateWindow("Direct Line Drawing :");
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

/*#include<windows.h>
#include <GL/glut.h>
#include<math.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    float xs=10 ,ys=30, xe=50 , ye=90;
    float m = (ye-ys)/(xe-xs);
    float b = ys-m*xs;

    for(float i=xs; i<=xe; i+=0.001){
        float x = x + 1;
        float y = m*x + b;
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_POINTS);
            glVertex2f(x/1000,round(y)/1000);
        glEnd();

    }
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(360,360);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("Lab 3");
    glutDisplayFunc(display);
    glutMainLoop();
}*/



