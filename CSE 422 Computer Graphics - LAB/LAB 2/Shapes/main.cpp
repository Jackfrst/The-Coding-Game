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


        glColor3f(1.0f,0.0f,0.0f); //Reqtangle
        glVertex2f(-0.3f,0.3f);
        glVertex2f(-0.7f,0.3f);
        glVertex2f(-0.3f,0.6f);
        glVertex2f(-0.7f,0.6f);
        glVertex2f(-0.3f,0.3f);
        glVertex2f(-0.3f,0.6f);
        glVertex2f(-0.7f,0.3f);
        glVertex2f(-0.7f,0.6f);


        glColor3f(0.0f,1.0f,0.0f); //Triangle
        glVertex2f(0.3f,0.3f);
        glVertex2f(0.7f,0.3f);
        glVertex2f(0.3f,0.3f);
        glVertex2f(0.5f,0.6f);
        glVertex2f(0.5f,0.6f);
        glVertex2f(0.7f,0.3f);


        glColor3f(0.0f,0.0f,1.0f); //Lines
        glVertex2f(-0.3f,-0.3f);
        glVertex2f(-0.7f,-0.3f);
        glVertex2f(-0.3f,-0.5f);
        glVertex2f(-0.7f,-0.5f);
        glVertex2f(-0.3f,-0.7f);
        glVertex2f(-0.7f,-0.7f);


    glEnd();

    glPointSize(3.0f);
    glBegin(GL_POINTS);
        glColor3f(0.5f,0.5f,1.0f);

        float x_vs = 0.3; //Horizontal
        float y_vs = -0.8;
        float x_ve = 0.3;
        float y_ve = -0.3;
        for(float i = y_vs ; i <= y_ve ; i+= 0.00001 ){
            glVertex2f(x_vs,i);
        }

        float x_hs = 0.3; //Vertical
        float y_hs = -0.8;
        float x_he = 0.8;
        float y_he = -0.8;
        for(float i = x_hs ; i <= x_he ; i+= 0.00001 ){
            glVertex2f(i,y_hs);
        }

        float x_d1s = 0.3; //diagonal m = 1
        float y_d1s = -0.8;
        float x_d1e = 0.8;
        float y_d1e = -0.3;
        for(float i = x_d1s ; i <= x_d1e ; i+= 0.00001 ){
            y_hs += 0.00001;
            glVertex2f(i,y_hs);
        }

        float x_d2s = 0.3; //diagonal m = 1
        float y_d2s = -0.3;
        float x_d2e = 0.8;
        float y_d2e = -0.8;
        for(float i = x_d2s ; i <= x_d2e ; i+= 0.00001 ){
            y_hs -= 0.00001;
            glVertex2f(i,y_hs);
        }
    glEnd();

    glFlush();
}

int main(int argc,char** argv){

    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(80,50);
    glutCreateWindow("Lab 2");
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
