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

        float m = (y_e - y_s) / (x_e - x_s); //m

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

        if(m < 1){
            for(float i = x_s ; i <= x_e ; i++){
                glVertex2f((i/1000),(round(y)/1000));
                y = y + m;
            }
        }

        else if(m > 1){
            for(float i = y_s ; i <= y_e ; i++){
                glVertex2f(round(x)/1000,(i/1000));
                float m1 =  1/m;
                x = x + m1;
            }
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
    glutCreateWindow("Simple Digital Differential Analyzer");
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


