#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<MMSystem.h>


using namespace std;


float _run = 0.0;
float _run1 = 0.0;
float _run2 = 0.0;
float _run3 = 0.0;
float _rain = 0.0;
float _nt = 0.0;
float _ang_tri = 0.0;
float sun_move = 0.0f;
float car1_speed = 0.0f;
float car2_speed = 0.0f;
float _angle = 30;
float _cameraAngle = 0;


bool onOff;

bool frd = false;
bool bck = false;
bool rainday = false;
bool rainynight = false;
bool night = false;



void init()
{
    glClearColor(0.0,0.5,0.8,1.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}
void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(30,144,255);
	glVertex2i(0,550);
    glVertex2i(1000,550);
    glVertex2i(1000,1000);
    glVertex2i(0,1000);
    glEnd();

}
void railtree()
{
     glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(80,120);
	glVertex2i(83,120);
	glVertex2i(83,160);
	glVertex2i(80,160);
	glEnd();

	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(80-9, 160);
    glVertex2i(83+9, 160);
    glVertex2i(82, 180);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(160,120);
	glVertex2i(163,120);
	glVertex2i(163,160);
	glVertex2i(160,160);
	glEnd();

	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(160-9, 160);
    glVertex2i(163+9, 160);
    glVertex2i(162, 180);
	glEnd();

glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(480,120);
	glVertex2i(483,120);
	glVertex2i(483,160);
	glVertex2i(480,160);
	glEnd();

	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(480-9, 160);
    glVertex2i(483+9, 160);
    glVertex2i(482, 180);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(580,120);
	glVertex2i(583,120);
	glVertex2i(583,160);
	glVertex2i(580,160);
	glEnd();

	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(580-9, 160);
    glVertex2i(583+9, 160);
    glVertex2i(582, 180);
	glEnd();

glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(880,120);
	glVertex2i(883,120);
	glVertex2i(883,160);
	glVertex2i(880,160);
	glEnd();

	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(880-9, 160);
    glVertex2i(883+9, 160);
    glVertex2i(882, 180);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(980,120);
	glVertex2i(983,120);
	glVertex2i(983,160);
	glVertex2i(980,160);
	glEnd();

	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(980-9, 160);
    glVertex2i(983+9, 160);
    glVertex2i(982, 180);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(380,120);
	glVertex2i(383,120);
	glVertex2i(383,160);
	glVertex2i(380,160);
	glEnd();

	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(380-9, 160);
    glVertex2i(383+9, 160);
    glVertex2i(382, 180);
	glEnd();

}

void Hill()
{
    glColor3f(.627,.322,.176);
  //glColor3ub(34, 177, 76);
    glBegin(GL_QUADS);
    glVertex2i(0,550);
    glVertex2i(0,560);
    glVertex2i(100,650);
    glVertex2i(200,550);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2i(400,550);
    glVertex2i(500,650);
    glVertex2i(600,550);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(100,550);
    glVertex2i(300,650);
    glVertex2i(500,550);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2i(600,550);
    glVertex2i(700,650);
    glVertex2i(800,550);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2i(800,550);
    glVertex2i(1000,650);
    glVertex2i(1000,550);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(700,550);
    glVertex2i(900,650);
    glVertex2i(1000,550);
    glEnd();

}


void Cloud1()
{
       glPushMatrix();
    glTranslatef(_run1, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


}
void Cloud2()
{
    //cloud 2
    glPushMatrix();
    glTranslatef(350, 100, 0);
    glPushMatrix();
    glTranslatef(200, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(180, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(250, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(230, 750, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(290, 760, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=40;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void Cloud3()
{
    //cloud 2
    glPushMatrix();
    glTranslatef(_run2, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(500, 700, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();///


    glPushMatrix();
    glTranslatef(530, 700, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
                                 ///

    glPushMatrix();
    glTranslatef(560, 700, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();///




    glPopMatrix();
}

void Cloud4()
{
     glPushMatrix();
    glTranslatef(_run2, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(300, 900, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();///


    glPushMatrix();
    glTranslatef(330, 900, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
                                 ///

    glPushMatrix();
    glTranslatef(360, 900, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();///




    glPopMatrix();
}

void Cloud5()
{
     glPushMatrix();
    glTranslatef(_run2, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(130, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();///


    glPushMatrix();
    glTranslatef(160, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=35;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
                                 ///

    glPushMatrix();
    glTranslatef(190, 800, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=25;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();///




    glPopMatrix();

}



void sun()
{
    glPushMatrix();
    glTranslatef(800,850, 0);


    //glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(249,215,28);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
   //glPopMatrix();

   //glPopMatrix();
}

void moon()
{
    glPushMatrix();
    glTranslatef(500,850, 0);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
   glEnd();
   glPopMatrix();
   glPopMatrix();


}

void star1()
{
    glColor3f(1.0f,1.0f,1.0f) ;
glBegin(GL_POLYGON);

glVertex2i (70,880);
glVertex2i (70,885);

glVertex2i(70,885);
glVertex2i(75,885);

glVertex2i(75,885);
glVertex2i(75,880);

glVertex2i(75,880);
glVertex2i(70,880);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(70,880);
glVertex2i(72,875);

glVertex2i(75,880);
glVertex2i(72,875);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(75,880);
glVertex2i(80,883);

glVertex2i(75,885);
glVertex2i(80,883);
glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(75,885);
glVertex2i(72,890);

glVertex2i(70,885);
glVertex2i(72,890);
glEnd();


glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(70,885);
glVertex2i(65,883);


glVertex2i(70,880);
glVertex2i(65,883);
glEnd();
}

void star2()
{
    glColor3f(1.0f,1.0f,1.0f) ;
glBegin(GL_POLYGON);

glVertex2i (170,880);
glVertex2i (170,885);

glVertex2i(170,885);
glVertex2i(175,885);

glVertex2i(175,885);
glVertex2i(175,880);

glVertex2i(175,880);
glVertex2i(170,880);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(170,880);
glVertex2i(172,875);

glVertex2i(175,880);
glVertex2i(172,875);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(175,880);
glVertex2i(180,883);

glVertex2i(175,885);
glVertex2i(180,883);
glEnd();

glColor3f(11.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(175,885);
glVertex2i(172,890);

glVertex2i(170,885);
glVertex2i(172,890);
glEnd();


glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(170,885);
glVertex2i(165,883);


glVertex2i(170,880);
glVertex2i(165,883);
glEnd();
}

void star3()
{
    glColor3f(1.0f,1.0f,1.0f) ;
glBegin(GL_POLYGON);

glVertex2i (70,980);
glVertex2i (70,985);

glVertex2i(70,985);
glVertex2i(75,985);

glVertex2i(75,985);
glVertex2i(75,980);

glVertex2i(75,980);
glVertex2i(70,980);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(70,980);
glVertex2i(72,975);

glVertex2i(75,980);
glVertex2i(72,975);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(75,980);
glVertex2i(80,983);

glVertex2i(75,985);
glVertex2i(80,983);
glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(75,985);
glVertex2i(72,990);

glVertex2i(70,985);
glVertex2i(72,990);
glEnd();


glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(70,985);
glVertex2i(65,983);


glVertex2i(70,980);
glVertex2i(65,983);
glEnd();
}

void star4()
{
    glColor3f(1.0f,1.0f,1.0f) ;
glBegin(GL_POLYGON);

glVertex2i (570,880);
glVertex2i (570,885);

glVertex2i(570,885);
glVertex2i(575,885);

glVertex2i(575,885);
glVertex2i(575,880);

glVertex2i(575,880);
glVertex2i(570,880);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(570,880);
glVertex2i(572,875);

glVertex2i(575,880);
glVertex2i(572,875);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(575,880);
glVertex2i(580,883);

glVertex2i(575,885);
glVertex2i(580,883);
glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(575,885);
glVertex2i(572,890);

glVertex2i(570,885);
glVertex2i(572,890);
glEnd();


glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(570,885);
glVertex2i(565,883);


glVertex2i(570,880);
glVertex2i(565,883);
glEnd();
}

void star5()
{
    glColor3f(1.0f,1.0f,1.0f) ;
glBegin(GL_POLYGON);

glVertex2i (970,880);
glVertex2i (970,885);

glVertex2i(970,885);
glVertex2i(975,885);

glVertex2i(975,885);
glVertex2i(975,880);

glVertex2i(975,880);
glVertex2i(970,880);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(970,880);
glVertex2i(972,875);

glVertex2i(975,880);
glVertex2i(972,875);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(975,880);
glVertex2i(980,883);

glVertex2i(975,885);
glVertex2i(980,883);
glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(975,885);
glVertex2i(972,890);

glVertex2i(970,885);
glVertex2i(972,890);
glEnd();


glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(970,885);
glVertex2i(965,883);


glVertex2i(970,880);
glVertex2i(965,883);
glEnd();
}
void star6()
{
    glColor3f(1.0f,1.0f,1.0f) ;
glBegin(GL_POLYGON);

glVertex2i (470,680);
glVertex2i (470,685);

glVertex2i(470,685);
glVertex2i(475,685);

glVertex2i(475,685);
glVertex2i(475,680);

glVertex2i(475,680);
glVertex2i(470,680);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(470,680);
glVertex2i(472,675);

glVertex2i(475,680);
glVertex2i(472,675);

glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(475,680);
glVertex2i(480,683);

glVertex2i(475,685);
glVertex2i(480,683);
glEnd();

glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);

glVertex2i(475,685);
glVertex2i(472,690);

glVertex2i(470,685);
glVertex2i(472,690);
glEnd();


glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2i(470,685);
glVertex2i(465,683);


glVertex2i(470,680);
glVertex2i(465,683);
glEnd();
}

void road()
{
    glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(0,330);
	glVertex2i(1000,330);
	glVertex2i(1000,280);
	glVertex2i(0,280);
	glEnd();
	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(840,390);
	glVertex2i(860,390);
	glVertex2i(860,320);
	glVertex2i(840,320);
	glEnd();
	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(300,330);
	glVertex2i(330-10,330);
	glVertex2i(300-10,550);
	glVertex2i(270,550);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
	glVertex2i(0,304);
	glVertex2i(1000,304);
	glVertex2i(0,307);
	glVertex2i(1000,307);
	glEnd();
}
void RoadLeftLamp()
{


	float a;
	for(a=0; a<=1000; a+=70)
    {
        float b=a+3;
        glColor3ub(66, 66, 49);
        glBegin(GL_QUADS);
        glVertex2i(a,332);
        glVertex2i(b,332);
        glVertex2i(b,350);
        glVertex2i(a,350);
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glVertex2i(a,350);
        glVertex2i(b,350);
        glVertex2i(b,355);
        glVertex2i(a,355);
        glEnd();
    }
}
void RoadRightLamp()
{
    float a;
	for(a=0; a<=1000; a+=70)
    {
        float b=a+3;
        glColor3ub(66, 66, 49);
        glBegin(GL_QUADS);
        glVertex2i(a,278);
        glVertex2i(b,278);
        glVertex2i(b,296);
        glVertex2i(a,296);
        glEnd();
        glColor3ub(255, 255, 255);
        glBegin(GL_QUADS);
        glVertex2i(a,296);
        glVertex2i(b,296);
        glVertex2i(b,301);
        glVertex2i(a,301);
        glEnd();
    }
}

void car1()
{
    glPushMatrix();
    glTranslatef(car1_speed, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(88,320, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(70,320, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();

    glColor3f(255,0,255);
    glBegin(GL_QUADS);
    glVertex2i(30-20+50, 317);
    glVertex2i(30+40-20+50, 317);
    glVertex2i(30+40-20+50, 325);
    glVertex2i(30-20+50, 325);
    glVertex2i(30+5-20+50, 325);
    glVertex2i(30+35-5-20+50, 325);
    glVertex2i(30+35-10-20+50, 317+20);
    glVertex2i(30+5+3-20+50, 317+20);
    glEnd();
    glColor3f(0,255,0);
    glBegin(GL_LINES);
    glVertex2i(30-20+50, 317+4);
    glVertex2i(30+40-20+50, 317+4);
    glEnd();
    glColor3f(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(30+5-20+3+50, 325);
    glVertex2i(30+35-5-20-14+50, 325);
    glVertex2i(30+35-5-20-14+50, 317+20-4);
    glVertex2i(30+5+3-20+2+50, 317+20-4);
    glVertex2i(30+35-5-20-14+2+50, 325);
    glVertex2i(30+35-5-20-14+11+50, 325);
    glVertex2i(30+35-5-20-14+10-2+50, 317+20-4);
    glVertex2i(30+35-5-20-14+2+50, 317+20-4);
    glEnd();
    glPopMatrix();
///
    glPushMatrix();
    glTranslatef(car2_speed, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(20,320, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(38,320, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();

    glColor3f(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(30-20, 317);
    glVertex2i(30+40-20, 317);
    glVertex2i(30+40-20, 325);
    glVertex2i(30-20, 325);
    glVertex2i(30+5-20, 325);
    glVertex2i(30+35-5-20, 325);
    glVertex2i(30+35-10-20, 317+20);
    glVertex2i(30+5+3-20, 317+20);
    glEnd();
    glColor3f(0,255,0);
    glBegin(GL_LINES);
    glVertex2i(30-20, 317+4);
    glVertex2i(30+40-20, 317+4);
    glEnd();
    glColor3f(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(30+5-20+3, 325);
    glVertex2i(30+35-5-20-14, 325);
    glVertex2i(30+35-5-20-14, 317+20-4);
    glVertex2i(30+5+3-20+2, 317+20-4);
    glVertex2i(30+35-5-20-14+2, 325);
    glVertex2i(30+35-5-20-14+11, 325);
    glVertex2i(30+35-5-20-14+10-2, 317+20-4);
    glVertex2i(30+35-5-20-14+2, 317+20-4);
    glEnd();
    glPopMatrix();
}
void car2()
{
    glPushMatrix();
    glTranslatef(-car1_speed, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(923,295, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(941,295, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();

    glColor3f(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(10+900, 317-25);
    glVertex2i(10+40+900, 317-25);
    glVertex2i(10+40+900, 325-25);
    glVertex2i(10+900, 325-25);
    glVertex2i(10+10+900, 325-25);
    glVertex2i(10+40-5+900, 325-25);
    glVertex2i(10+40-8+900, 317+20-25);
    glVertex2i(10+15+900, 317+20-25);
    glEnd();
    glColor3f(0,255,0);
    glBegin(GL_LINES);
    glVertex2i(30-20+50-50+900, 317+4-25);
    glVertex2i(30+40-20+50-50+900, 317+4-25);
    glEnd();
    glColor3f(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(10+10+3+900, 325-25);
    glVertex2i(10+40-5-12+900, 325-25);
    glVertex2i(10+40-5-12+900, 317+20-25-4);
    glVertex2i(10+15+1+900, 317+20-25-4);
    glVertex2i(10+40-5-12+2+900, 325-25);
    glVertex2i(10+40-5-12+10+900, 325-25);
    glVertex2i(10+40-5-12+10-2+900, 317+20-25-4);
    glVertex2i(10+40-5-12+2+900, 317+20-25-4);
    glEnd();
    glPopMatrix();
///
    glPushMatrix();
    glTranslatef(-car2_speed, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(1003,295, 0);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
   glEnd();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(1003+18,295, 0);
    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
   glEnd();
   glPopMatrix();

    glColor3f(0,0,255);
    glBegin(GL_QUADS);
    glVertex2i(10+900+80, 317-25);
    glVertex2i(10+40+900+80, 317-25);
    glVertex2i(10+40+900+80, 325-25);
    glVertex2i(10+900+80, 325-25);
    glVertex2i(10+10+900+80, 325-25);
    glVertex2i(10+40-5+900+80, 325-25);
    glVertex2i(10+40-8+900+80, 317+20-25);
    glVertex2i(10+15+900+80, 317+20-25);
    glEnd();
    glColor3f(0,255,0);
    glBegin(GL_LINES);
    glVertex2i(30-20+50-50+900+80, 317+4-25);
    glVertex2i(30+40-20+50-50+900+80, 317+4-25);
    glEnd();
    glColor3f(0,255,0);
    glBegin(GL_QUADS);
    glVertex2i(10+10+3+900+80, 325-25);
    glVertex2i(10+40-5-12+900+80, 325-25);
    glVertex2i(10+40-5-12+900+80, 317+20-25-4);
    glVertex2i(10+15+1+900+80, 317+20-25-4);
    glVertex2i(10+40-5-12+2+900+80, 325-25);
    glVertex2i(10+40-5-12+10+900+80, 325-25);
    glVertex2i(10+40-5-12+10-2+900+80, 317+20-25-4);
    glVertex2i(10+40-5-12+2+900+80, 317+20-25-4);
    glEnd();
    glPopMatrix();
}
void school()
{
    glColor3f(0.325, 0.101, 0.619);
	glBegin(GL_QUADS);
	glVertex2i(750, 530);
	glVertex2i(950, 530);
	glVertex2i(1000, 500);
	glVertex2i(700, 500);
	glEnd();
	glColor3ub(182, 163, 240);
	glBegin(GL_QUADS);
    glVertex2i(730, 500);
    glVertex2i(970, 500);
	glVertex2i(970, 400);
	glVertex2i(730, 400);
	glEnd();
	glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(730+100, 500);
    glVertex2i(970-100, 500);
	glVertex2i(970-100, 400);
	glVertex2i(730+100, 400);
	glEnd();
	///********************************
    /// second floor
	glColor3f(0.325, 0.101, 0.619);
	glBegin(GL_QUADS);
    glVertex2i(719, 450);
    glVertex2i(981, 450);
	glVertex2i(981, 440);
	glVertex2i(719, 440);
	glEnd();
///windrow
    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740, 480);
    glVertex2i(755, 480);
	glVertex2i(755, 460);
	glVertex2i(740, 460);
	glEnd();

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+30, 480);
    glVertex2i(755+30, 480);
	glVertex2i(755+30, 460);
	glVertex2i(740+30, 460);
	glEnd();

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+30+30, 495);
    glVertex2i(760+30+30, 495);
	glVertex2i(760+30+30, 450);
	glVertex2i(740+30+30, 450);
	glEnd();


///******************************
    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+30+30+80, 495);
    glVertex2i(760+30+30+80, 495);
	glVertex2i(760+30+30+80, 450);
	glVertex2i(740+30+30+80, 450);
	glEnd();

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+175, 480);
    glVertex2i(755+175, 480);
	glVertex2i(755+175, 460);
	glVertex2i(740+175, 460);
	glEnd();

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+175+30, 480);
    glVertex2i(755+175+30, 480);
	glVertex2i(755+175+30, 460);
	glVertex2i(740+175+30, 460);
	glEnd();


    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    float j;
    for(j=710;j<=970;j+=10)
   {
        glVertex2i(10+j,450);
        glVertex2i(10+j,470);

    }
    glEnd();

    glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(720, 468);
    glVertex2i(980, 468);
	glVertex2i(980, 470);
	glVertex2i(720, 470);
	glEnd();

///********************************
/// ground floor
    glColor3f(0.325, 0.101, 0.619);
	glBegin(GL_QUADS);
    glVertex2i(710, 400);
    glVertex2i(990, 400);
	glVertex2i(990, 390);
	glVertex2i(710, 390);
	glEnd();

///windrow

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740, 430);
    glVertex2i(755, 430);
	glVertex2i(755, 410);
	glVertex2i(740, 410);
	glEnd();

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+30, 430);
    glVertex2i(755+30, 430);
	glVertex2i(755+30, 410);
	glVertex2i(740+30, 410);
	glEnd();

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+30+30, 435);
    glVertex2i(760+30+30, 435);
	glVertex2i(760+30+30, 400);
	glVertex2i(740+30+30, 400);
	glEnd();
///******************************
    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+30+30+80, 435);
    glVertex2i(760+30+30+80, 435);
	glVertex2i(760+30+30+80, 400);
	glVertex2i(740+30+30+80, 400);
	glEnd();

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+175, 430);
    glVertex2i(755+175, 430);
	glVertex2i(755+175, 410);
	glVertex2i(740+175, 410);
	glEnd();

    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(740+175+30, 430);
    glVertex2i(755+175+30, 430);
	glVertex2i(755+175+30, 410);
	glVertex2i(740+175+30, 410);
	glEnd();


    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    //float j;
    for(j=710;j<=970;j+=10)
   {
        glVertex2i(10+j,400);
        glVertex2i(10+j,420);
    }
    glEnd();

    glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(720, 418);
    glVertex2i(980, 418);
	glVertex2i(980, 420);
	glVertex2i(720, 420);
	glEnd();



    glColor3f(197, 197, 197);
	glBegin(GL_QUADS);
    glVertex2i(730+100, 440);
    glVertex2i(970-100, 440);
	glVertex2i(970-101, 400);
	glVertex2i(730+100, 400);
	glEnd();
///Road Left style
	glColor3ub(204, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(833,370);
    glVertex2i(838,370);
    glVertex2i(835,370);
    glVertex2i(836,385);
    glColor3ub(224, 224, 224);
    glVertex2i(833+3,385);
    glVertex2i(833+3,385+5);
    glVertex2i(833-4+3,385-7+5);
    glVertex2i(833+4+3,385-7+5);
    glVertex2i(833+3,385-7+5);
    glVertex2i(833+4+3,385+5);
    glVertex2i(833+3,385-7+5);
    glVertex2i(833-4+3,385+5);
    glEnd();

    glColor3ub(204, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(833,370-20);
    glVertex2i(838,370-20);
    glVertex2i(835,370-20);
    glVertex2i(836,385-20);
    glColor3ub(224, 224, 224);
    glVertex2i(833+3,385-20);
    glVertex2i(833+3,385+5-20);
    glVertex2i(833-4+3,385-7+5-20);
    glVertex2i(833+4+3,385-7+5-20);
    glVertex2i(833+3,385-7+5-20);
    glVertex2i(833+4+3,385+5-20);
    glVertex2i(833+3,385-7+5-20);
    glVertex2i(833-4+3,385+5-20);
    glEnd();

    glColor3ub(204, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(833,370-20-20);
    glVertex2i(838,370-20-20);
    glVertex2i(835,370-20-20);
    glVertex2i(836,385-20-20);
    glColor3ub(224, 224, 224);
    glVertex2i(833+3,385-20-20);
    glVertex2i(833+3,385+5-20-20);
    glVertex2i(833-4+3,385-7+5-20-20);
    glVertex2i(833+4+3,385-7+5-20-20);
    glVertex2i(833+3,385-7+5-20-20);
    glVertex2i(833+4+3,385+5-20-20);
    glVertex2i(833+3,385-7+5-20-20);
    glVertex2i(833-4+3,385+5-20-20);
    glEnd();
///Road Right style
    glColor3ub(204, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(833+29,370);
    glVertex2i(838+29,370);
    glVertex2i(835+29,370);
    glVertex2i(836+29,385);
    glColor3ub(224+29, 224, 224);
    glVertex2i(833+3+29,385);
    glVertex2i(833+3+29,385+5);
    glVertex2i(833-4+3+29,385-7+5);
    glVertex2i(833+4+3+29,385-7+5);
    glVertex2i(833+3+29,385-7+5);
    glVertex2i(833+4+3+29,385+5);
    glVertex2i(833+3+29,385-7+5);
    glVertex2i(833-4+3+29,385+5);
    glEnd();

    glColor3ub(204, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(833+29,370-20);
    glVertex2i(838+29,370-20);
    glVertex2i(835+29,370-20);
    glVertex2i(836+29,385-20);
    glColor3ub(224+29, 224, 224);
    glVertex2i(833+3+29,385-20);
    glVertex2i(833+3+29,385+5-20);
    glVertex2i(833-4+3+29,385-7+5-20);
    glVertex2i(833+4+3+29,385-7+5-20);
    glVertex2i(833+3+29,385-7+5-20);
    glVertex2i(833+4+3+29,385+5-20);
    glVertex2i(833+3+29,385-7+5-20);
    glVertex2i(833-4+3+29,385+5-20);
    glEnd();

    glColor3ub(204, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(833+29,370-20-20);
    glVertex2i(838+29,370-20-20);
    glVertex2i(835+29,370-20-20);
    glVertex2i(836+29,385-20-20);
    glColor3ub(224+29, 224, 224);
    glVertex2i(833+3+29,385-20-20);
    glVertex2i(833+3+29,385+5-20-20);
    glVertex2i(833-4+3+29,385-7+5-20-20);
    glVertex2i(833+4+3+29,385-7+5-20-20);
    glVertex2i(833+3+29,385-7+5-20-20);
    glVertex2i(833+4+3+29,385+5-20-20);
    glVertex2i(833+3+29,385-7+5-20-20);
    glVertex2i(833-4+3+29,385+5-20-20);
    glEnd();
}
void flag()
{
    glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(800-10,360);
	glVertex2i(820-10,360);
	glVertex2i(820-10,380);
	glVertex2i(800-10,380);
	glEnd();

	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
	glVertex2i(799,370);
	glVertex2i(801,370);
	glVertex2i(801,510);
	glVertex2i(799,510);
	glEnd();

    glColor3ub(0, 204, 0);
	glBegin(GL_QUADS);
	glVertex2i(801,485);
	glVertex2i(825,485);
	glVertex2i(825,510);
	glVertex2i(801,510);
	glEnd();

    glPushMatrix();
    glTranslatef(812,499, 0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=6;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
}


void land()
{
	glColor3ub(0, 153, 0);
	glBegin(GL_QUADS);
    glVertex2i(0, 120);
    glVertex2i(1000, 120);
	glVertex2i(1000, 550);
	glVertex2i(0, 550);
	glEnd();
}
void house1()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(100, 520);
    glVertex2i(180, 520);
	glVertex2i(170, 530);
	glVertex2i(110, 530);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
    glVertex2i(115, 520);
    glVertex2i(165, 520);
	glVertex2i(165, 480);
	glVertex2i(115, 480);
	glEnd();
	glColor3ub(66, 66, 49);
	glBegin(GL_QUADS);
    glVertex2i(105, 480);
    glVertex2i(175, 480);
	glVertex2i(175, 475);
	glVertex2i(105, 475);
	glEnd();
///Door
	glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(115+20, 480);
    glVertex2i(165-20, 480);
	glVertex2i(165-20, 510);
	glVertex2i(115+20, 510);
	glEnd();
///window
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(115+5, 495);
    glVertex2i(115+5+8, 495);
	glVertex2i(115+5+8, 513);
	glVertex2i(115+5, 513);
	glEnd();
	glBegin(GL_QUADS);
    glVertex2i(120, 495);
    glVertex2i(128, 495);
	glVertex2i(128, 513);
	glVertex2i(120, 513);
	glEnd();
	glBegin(GL_QUADS);
    glVertex2i(120+30, 495);
    glVertex2i(128+30, 495);
	glVertex2i(128+30, 513);
	glVertex2i(120+30, 513);
	glEnd();
///HomeSiteTree
    glColor3ub(204, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(107, 470);
	glVertex2i(112, 470);
	glVertex2i(109, 470);
	glVertex2i(109, 495);
	glVertex2i(105, 485);
	glVertex2i(114, 485);
	glVertex2i(109, 485);
	glVertex2i(113, 495);
	glVertex2i(109, 485);
	glVertex2i(105, 495);

	glVertex2i(107+61, 470);
	glVertex2i(112+61, 470);
	glVertex2i(109+61, 470);
	glVertex2i(109+61, 495);
	glVertex2i(105+61, 485);
	glVertex2i(114+61, 485);
	glVertex2i(109+61, 485);
	glVertex2i(113+61, 495);
	glVertex2i(109+61, 485);
	glVertex2i(105+61, 495);
	glEnd();
}
void house4()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(220, 470);
    glVertex2i(260, 470);
	glVertex2i(240, 490);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i(220+8, 470);
	glVertex2i(260-8, 470);
	glVertex2i(260-8, 440);
    glVertex2i(220+8, 440);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(220+4, 440);
    glVertex2i(260-4, 440);
    glVertex2i(260-4, 435);
    glVertex2i(220+4, 435);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(220+8+8, 460);
	glVertex2i(260-8-8, 460);
	glVertex2i(260-8-8, 440);
    glVertex2i(220+8+8, 440);
	glEnd();
}
void house10()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(220, 470-70);
    glVertex2i(260, 470-70);
	glVertex2i(240, 490-70);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i(220+8, 470-70);
	glVertex2i(260-8, 470-70);
	glVertex2i(260-8, 440-70);
    glVertex2i(220+8, 440-70);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(220+4, 440-70);
    glVertex2i(260-4, 440-70);
    glVertex2i(260-4, 435-70);
    glVertex2i(220+4, 435-70);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(220+8+8, 460-70);
	glVertex2i(260-8-8, 460-70);
	glVertex2i(260-8-8, 440-70);
    glVertex2i(220+8+8, 440-70);
	glEnd();
}
void house9()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(220-40, 470-20);
    glVertex2i(260-40, 470-20);
	glVertex2i(240-40, 490-20);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i(220+8-40, 470-20);
	glVertex2i(260-8-40, 470-20);
	glVertex2i(260-8-40, 440-20);
    glVertex2i(220+8-40, 440-20);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(220+4-40, 440-20);
    glVertex2i(260-4-40, 440-20);
    glVertex2i(260-4-40, 435-20);
    glVertex2i(220+4-40, 435-20);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(220+8+8-40, 460-20);
	glVertex2i(260-8-8-40, 460-20);
	glVertex2i(260-8-8-40, 440-20);
    glVertex2i(220+8+8-40, 440-20);
	glEnd();
}
void house3()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(190, 520);
    glVertex2i(230, 520);
	glVertex2i(210, 540);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i(198, 520);
	glVertex2i(222, 520);
	glVertex2i(222, 490);
    glVertex2i(198, 490);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(194, 520-30);
    glVertex2i(230-4, 520-30);
	glVertex2i(230-4, 520-30-5);
	glVertex2i(194, 520-30-5);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(198+8, 490);
    glVertex2i(222-8, 490);
	glVertex2i(222-8, 510);
	glVertex2i(198+8, 510);
	glEnd();
}
void house5()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(20, 545);
    glVertex2i(40, 545);
	glVertex2i(30, 560);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i(25, 545);
	glVertex2i(35, 545);
	glVertex2i(35, 530);
    glVertex2i(25, 530);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(22, 530);
	glVertex2i(40-2, 530);
	glVertex2i(40-2, 525);
    glVertex2i(22, 525);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(25+3, 540);
	glVertex2i(35-3, 540);
	glVertex2i(35-3, 530);
    glVertex2i(25+3, 530);
	glEnd();
}
void house6()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(20+25, 545);
    glVertex2i(40+25, 545);
	glVertex2i(30+25, 560);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i(25+25, 545);
	glVertex2i(35+25, 545);
	glVertex2i(35+25, 530);
    glVertex2i(25+25, 530);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(22+25, 530);
	glVertex2i(40-2+25, 530);
	glVertex2i(40-2+25, 525);
    glVertex2i(22+25, 525);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(25+3+25, 540);
	glVertex2i(35-3+25, 540);
	glVertex2i(35-3+25, 530);
    glVertex2i(25+3+25, 530);
	glEnd();
}
void house7()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(20-20, 545-40);
    glVertex2i(40-20, 545-40);
	glVertex2i(30-20, 560-40);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i(25-20, 545-40);
	glVertex2i(35-20, 545-40);
	glVertex2i(35-20, 530-40);
    glVertex2i(25-20, 530-40);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(22-20, 530-40);
	glVertex2i(40-2-20, 530-40);
	glVertex2i(40-2-20, 525-40);
    glVertex2i(22-20, 525-40);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(25+3-20, 540-40);
	glVertex2i(35-3-20, 540-40);
	glVertex2i(35-3-20, 530-40);
    glVertex2i(25+3-20, 530-40);
	glEnd();
}
void house8()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i((20-20)*2+60, (545-40)+10);
    glVertex2i((40-20)*2+60, (545-40)+10);
	glVertex2i((30-20)*2+60, (560-40)+10);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i((25-20)*2+60, (545-40)+10);
	glVertex2i((35-20)*2+60, (545-40)+10);
	glVertex2i((35-20)*2+60, (530-40)+10);
    glVertex2i((25-20)*2+60, (530-40)+10);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i((22-20)*2+60, (530-40)+10);
	glVertex2i((40-2-20)*2+60, (530-40)+10);
	glVertex2i((40-2-20)*2+60, (525-40)+10);
    glVertex2i((22-20)*2+60, (525-40)+10);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i((25+3-20)*2+60, (540-40)+10);
	glVertex2i((35-3-20)*2+60, (540-40)+10);
	glVertex2i((35-3-20)*2+60, (530-40)+10);
    glVertex2i((25+3-20)*2+60, (530-40)+10);
	glEnd();
}
void house2()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(50, 450);
    glVertex2i(80, 445);
	glVertex2i(65, 470);
	glEnd();
	glColor3ub(255, 255, 255);
	glBegin(GL_LINES);
    glVertex2i(80, 445);
	glVertex2i(65, 470);
	glVertex2i(80, 446);
	glVertex2i(65, 471);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(80, 445);
	glVertex2i(100, 470-10);
	glVertex2i(90, 480);
    glVertex2i(65, 470);
	glEnd();


	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
    glVertex2i(50, 450);
    glVertex2i(80, 445);
	glVertex2i(80, 420);
	glVertex2i(50, 430);
	glEnd();
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(48, 430);
    glVertex2i(80, 420);
	glVertex2i(80, 420-5);
	glVertex2i(48, 430-5);
	glEnd();


	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
    glVertex2i(80, 445);
    glVertex2i(100, 460);
	glVertex2i(100, 435);
	glVertex2i(80, 420);
	glEnd();
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(80, 420);
    glVertex2i(100+2, 435+2);
	glVertex2i(100+2, 430+2);
	glVertex2i(80, 415);
	glEnd();


	glColor3ub(102, 0, 0);
	glBegin(GL_LINES);
    glVertex2i(80, 445);
    glVertex2i(80, 420);
    glVertex2i(81, 420);
    glVertex2i(81, 420);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(50+10, 425);
    glVertex2i(80-10, 420);
	glVertex2i(80-10, 437);
	glVertex2i(50+10, 440);
	glEnd();

	glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(80+7, 445-4);
    glVertex2i(100-7, 460-13);
	glVertex2i(100-7, 435-5);
	glVertex2i(80+7, 420+5);
	glEnd();
}
void LeftRoadTree()
{
    glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(282, 345);
    glVertex2i(285, 345);
    glVertex2i(285, 370);
	glVertex2i(282, 370);
	glEnd();
	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(282-9, 370);
    glVertex2i(285+9, 370);
    glVertex2i(284, 390);
	glEnd();
	glColor3ub(0, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(282-9, 370+6);
    glVertex2i(285+9, 370+6);
    glVertex2i(284, 390+6);
	glEnd();
///
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(275, 345+50);
    glVertex2i(278, 345+50);
    glVertex2i(278, 370+50);
	glVertex2i(275, 370+50);
	glEnd();
    glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(282-9-7, 370+50);
    glVertex2i(285+9-7, 370+50);
    glVertex2i(284-7, 390+50);
	glEnd();
    glColor3ub(0, 204, 0);
    glBegin(GL_POLYGON);
	glVertex2i(282-9-7, 370+50+6);
    glVertex2i(285+9-7, 370+50+6);
    glVertex2i(284-7, 390+50+6);
	glEnd();
///
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(275-7, 345+50+50);
    glVertex2i(278-7, 345+50+50);
    glVertex2i(278-7, 370+50+50);
	glVertex2i(275-7, 370+50+50);
	glEnd();
    glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(282-9-7-7, 370+50+50);
    glVertex2i(285+9-7-7, 370+50+50);
    glVertex2i(284-7-7, 390+50+50);
	glEnd();
    glColor3ub(0, 204, 0);
    glBegin(GL_POLYGON);
	glVertex2i(282-9-7-7, 370+50+50+6);
    glVertex2i(285+9-7-7, 370+50+50+6);
    glVertex2i(284-7-7, 390+50+50+6);
	glEnd();
///
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(275-7-7, 345+50+50+50);
    glVertex2i(278-7-7, 345+50+50+50);
    glVertex2i(278-7-7, 370+50+50+50);
	glVertex2i(275-7-7, 370+50+50+50);
	glEnd();
	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(282-9-7-7-7, 370+50+50+50);
    glVertex2i(285+9-7-7-7, 370+50+50+50);
    glVertex2i(284-7-7-7, 390+50+50+50);
	glEnd();
    glColor3ub(0, 204, 0);
    glBegin(GL_POLYGON);
	glVertex2i(282-9-7-7-7, 370+50+50+50+6);
    glVertex2i(285+9-7-7-7, 370+50+50+50+6);
    glVertex2i(284-7-7-7, 390+50+50+50+6);
	glEnd();
}
void HillTree()
{
    float a;
    for(a=0;a<1000;a+=100)
    {
        float b=a+2;
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(a, 545);
        glVertex2i(b, 545);
        glVertex2i(b, 560);
        glVertex2i(a, 560);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, 560);
        glVertex2i(b+5, 560);
        glVertex2i(a+1,570);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-5, 560+4);
        glVertex2i(b+5, 560+4);
        glVertex2i(a+1,570+4);
        glEnd();
    }
}
void HillTree2()
{
    float a;
    for(a=10;a<1000;a+=120)
    {
        float b=a+2;
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(a, 545);
        glVertex2i(b, 545);
        glVertex2i(b, 580);
        glVertex2i(a, 580);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-8, 580);
        glVertex2i(b+8, 580);
        glVertex2i(a+1,590);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-8, 580+5);
        glVertex2i(b+8, 580+5);
        glVertex2i(a+1,590+10);
        glEnd();

    }
}
void HillTree3()
{
    float a;
    for(a=10;a<1000;a+=160)
    {
        float b=a+2;
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(a, 545);
        glVertex2i(b, 545);
        glVertex2i(b, 580);
        glVertex2i(a, 580);
        glEnd();
        glColor3ub(102, 204, 0);
        glBegin(GL_POLYGON);
        glVertex2i(a-4, 560-2);
        glVertex2i(b+4, 560-2);
        glVertex2i(a+1,590+4);
        glEnd();
    }
}
void tree1()
{
    glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(20, 380);
    glVertex2i(25, 380);
    glVertex2i(25, 420);
	glVertex2i(20, 420);
	glEnd();
	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(20, 420);
    glVertex2i(20-15, 410);
    glVertex2i(20, 450);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2i(20, 420);
    glVertex2i(25, 420);
    glVertex2i(25, 450);
	glVertex2i(20, 450);
	glEnd();

	glColor3ub(102, 204, 0);
	glBegin(GL_POLYGON);
	glVertex2i(25, 420);
    glVertex2i(20+15+5, 410);
    glVertex2i(25, 450);
	glEnd();
}



/*void HillTree4()
{
    float a;
    for(a=10;a<1000;a+=100)
    {
        float b=a+2;
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2i(a, 545);
        glVertex2i(b, 545);
        glVertex2i(b, 580);
        glVertex2i(a, 580);
        glEnd();
    }
}*/
void building2()
{
    glColor3ub(102, 0, 204);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 360+20);
    glVertex2i(700-30, 360+20);
    glVertex2i(700-30, 370+20);
    glVertex2i(620-30, 370+20);
    glEnd();

    glColor3ub(0, 204, 204);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 370+20);
    glVertex2i(700-30, 370+20);
    glVertex2i(700-30, 520+20);
    glVertex2i(620-30, 520+20);
    glEnd();

    glColor3ub(102, 0, 51);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 520+20);
    glVertex2i(700-30, 520+20);
    glVertex2i(700-30, 525+20);
    glVertex2i(620-30, 525+20);
    glEnd();

    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(620-30, 370+50+20);
    glVertex2i(700-30, 370+50+20);
    glVertex2i(620-30, 370+50+50+20);
    glVertex2i(700-30, 370+50+50+20);
    glVertex2i(620+40-30, 370+20);
    glVertex2i(620+40-30, 520+20);
    glEnd();
///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 370+20+35);
    glVertex2i(620-30+10, 370+20+35);
    glVertex2i(620-30+10, 370+20+50);
    glVertex2i(620-30, 370+20+50);
    glEnd();
    glColor3ub(200, 130, 40);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 370+20+35+1);
    glVertex2i(620-30+10-1, 370+20+35+1);
    glVertex2i(620-30+10-1, 370+20+50);
    glVertex2i(620-30, 370+20+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620-30+13, 370+20+8);
    glVertex2i(620-30+34, 370+20+8);
    glVertex2i(620-30+34, 370+20+36);
    glVertex2i(620-30+13, 370+20+36);
    glEnd();
    glColor3ub(155, 112, 60);
    glBegin(GL_QUADS);
    glVertex2i(620-30+13+1, 370+20+8+4);
    glVertex2i(620-30+34-2, 370+20+8+4);
    glVertex2i(620-30+34-2, 370+20+36-1);
    glVertex2i(620-30+13+1, 370+20+36-1);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 370+20+35+50);
    glVertex2i(620-30+10, 370+20+35+50);
    glVertex2i(620-30+10, 370+20+50+50);
    glVertex2i(620-30, 370+20+50+50);
    glEnd();
    glColor3ub(200, 130, 40);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 370+20+35+1+50);
    glVertex2i(620-30+10-1, 370+20+35+1+50);
    glVertex2i(620-30+10-1, 370+20+50+50);
    glVertex2i(620-30, 370+20+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620-30+13, 370+20+8+50);
    glVertex2i(620-30+34, 370+20+8+50);
    glVertex2i(620-30+34, 370+20+36+50);
    glVertex2i(620-30+13, 370+20+36+50);
    glEnd();
    glColor3ub(155, 112, 60);
    glBegin(GL_QUADS);
    glVertex2i(620-30+13+1, 370+20+8+4+50);
    glVertex2i(620-30+34-2, 370+20+8+4+50);
    glVertex2i(620-30+34-2, 370+20+36-1+50);
    glVertex2i(620-30+13+1, 370+20+36-1+50);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 370+20+35+50+50);
    glVertex2i(620-30+10, 370+20+35+50+50);
    glVertex2i(620-30+10, 370+20+50+50+50);
    glVertex2i(620-30, 370+20+50+50+50);
    glEnd();
    glColor3ub(200, 130, 40);
    glBegin(GL_QUADS);
    glVertex2i(620-30, 370+20+35+1+50+50);
    glVertex2i(620-30+10-1, 370+20+35+1+50+50);
    glVertex2i(620-30+10-1, 370+20+50+50+50);
    glVertex2i(620-30, 370+20+50+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620-30+13, 370+20+8+50+50);
    glVertex2i(620-30+34, 370+20+8+50+50);
    glVertex2i(620-30+34, 370+20+36+50+50);
    glVertex2i(620-30+13, 370+20+36+50+50);
    glEnd();
    glColor3ub(155, 112, 60);
    glBegin(GL_QUADS);
    glVertex2i(620-30+13+1, 370+20+8+4+50+50);
    glVertex2i(620-30+34-2, 370+20+8+4+50+50);
    glVertex2i(620-30+34-2, 370+20+36-1+50+50);
    glVertex2i(620-30+13+1, 370+20+36-1+50+50);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620-30+40, 370+20+35+50+50);
    glVertex2i(620-30+10+40, 370+20+35+50+50);
    glVertex2i(620-30+10+40, 370+20+50+50+50);
    glVertex2i(620-30+40, 370+20+50+50+50);
    glEnd();
    glColor3ub(200, 130, 40);
    glBegin(GL_QUADS);
    glVertex2i(620-30+40, 370+20+35+1+50+50);
    glVertex2i(620-30+10-1+40, 370+20+35+1+50+50);
    glVertex2i(620-30+10-1+40, 370+20+50+50+50);
    glVertex2i(620-30+40, 370+20+50+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620-30+13+40, 370+20+8+50+50);
    glVertex2i(620-30+34+40, 370+20+8+50+50);
    glVertex2i(620-30+34+40, 370+20+36+50+50);
    glVertex2i(620-30+13+40, 370+20+36+50+50);
    glEnd();
    glColor3ub(155, 112, 60);
    glBegin(GL_QUADS);
    glVertex2i(620-30+13+1+40, 370+20+8+4+50+50);
    glVertex2i(620-30+34-2+40, 370+20+8+4+50+50);
    glVertex2i(620-30+34-2+40, 370+20+36-1+50+50);
    glVertex2i(620-30+13+1+40, 370+20+36-1+50+50);
    glEnd();
}
void building1()
{
    glColor3ub(0, 204, 204);
    glBegin(GL_QUADS);
    glVertex2i(620, 360);
    glVertex2i(700, 360);
    glVertex2i(700, 370);
    glVertex2i(620, 370);
    glEnd();

    glColor3ub(209, 203, 123);
    glBegin(GL_QUADS);
    glVertex2i(620, 370);
    glVertex2i(700, 370);
    glVertex2i(700, 520);
    glVertex2i(620, 520);
    glEnd();

    glColor3ub(102, 0, 51);
    glBegin(GL_QUADS);
    glVertex2i(620, 520);
    glVertex2i(700, 520);
    glVertex2i(700, 525);
    glVertex2i(620, 525);
    glEnd();

    glColor3ub(0, 204, 204);
    glBegin(GL_LINES);
    glVertex2i(620, 370+50);
    glVertex2i(700, 370+50);
    glVertex2i(620, 370+50+50);
    glVertex2i(700, 370+50+50);
    glVertex2i(620+40, 370);
    glVertex2i(620+40, 520);
    glEnd();
///Door
    glColor3ub(102, 0, 51);
    glBegin(GL_QUADS);
    glVertex2i(620+16, 370+7);
    glVertex2i(620+40-16, 370+7);
    glVertex2i(620+40-16, 370+50-8);
    glVertex2i(620+16, 370+50-8);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+16, 370+7);
    glVertex2i(620+40-16, 370+7);
    glVertex2i(620+40-16, 370+7+2);
    glVertex2i(620+16, 370+7+2);
    glVertex2i(620+40-16-2, 370+7);
    glVertex2i(620+40-16, 370+7);
    glVertex2i(620+40-16, 370+50-8);
    glVertex2i(620+40-16-2, 370+50-8);
    glVertex2i(620+16, 370+50-8-1);
    glVertex2i(620+40-16, 370+50-8-1);
    glVertex2i(620+40-16, 370+50-8);
    glVertex2i(620+16, 370+50-8);
    glVertex2i(620+16, 370+7);
    glVertex2i(620+16+1, 370+7);
    glVertex2i(620+16+1, 370+50-8);
    glVertex2i(620+16, 370+50-8);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3, 370+15);
    glVertex2i(620+3+10, 370+15);
    glVertex2i(620+3+10, 370+50-10);
    glVertex2i(620+3, 370+50-10);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3, 370+15);
    glVertex2i(620+2+10+1, 370+15);
    glVertex2i(620+2+10+1, 370+15+3);
    glVertex2i(620+3, 370+15+3);
    glVertex2i(620+2+10+1-2, 370+15);
    glVertex2i(620+2+10+1, 370+15);
    glVertex2i(620+2+10+1, 370+50-10);
    glVertex2i(620+2+10+1-2, 370+50-10);
    glVertex2i(620+2+1, 370+50-10-2);
    glVertex2i(620+2+10+1, 370+50-10-2);
    glVertex2i(620+2+10+1, 370+50-10);
    glVertex2i(620+2+1, 370+50-10);
    glVertex2i(620+2+1, 370+15);
    glVertex2i(620+2+1+1, 370+15);
    glVertex2i(620+2+1+1, 370+50-10);
    glVertex2i(620+2+1, 370+50-10);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24, 370+15);
    glVertex2i(620+3+10+24, 370+15);
    glVertex2i(620+3+10+24, 370+50-10);
    glVertex2i(620+3+24, 370+50-10);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24, 370+15);
    glVertex2i(620+2+10+1+24, 370+15);
    glVertex2i(620+2+10+1+24, 370+15+3);
    glVertex2i(620+3+24, 370+15+3);
    glVertex2i(620+2+10+1-2+24, 370+15);
    glVertex2i(620+2+10+1+24, 370+15);
    glVertex2i(620+2+10+1+24, 370+50-10);
    glVertex2i(620+2+10+1-2+24, 370+50-10);
    glVertex2i(620+2+1+24, 370+50-10-2);
    glVertex2i(620+2+10+1+24, 370+50-10-2);
    glVertex2i(620+2+10+1+24, 370+50-10);
    glVertex2i(620+2+1+24, 370+50-10);
    glVertex2i(620+2+1+24, 370+15);
    glVertex2i(620+2+1+1+24, 370+15);
    glVertex2i(620+2+1+1+24, 370+50-10);
    glVertex2i(620+2+1+24, 370+50-10);
    glEnd();
///***
    glColor3ub(102, 0, 51);
    glBegin(GL_QUADS);
    glVertex2i(620+16, 370+7+50);
    glVertex2i(620+40-16, 370+7+50);
    glVertex2i(620+40-16, 370+50-8+50);
    glVertex2i(620+16, 370+50-8+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+16, 370+7+50);
    glVertex2i(620+40-16, 370+7+50);
    glVertex2i(620+40-16, 370+7+2+50);
    glVertex2i(620+16, 370+7+2+50);
    glVertex2i(620+40-16-2, 370+7+50);
    glVertex2i(620+40-16, 370+7+50);
    glVertex2i(620+40-16, 370+50-8+50);
    glVertex2i(620+40-16-2, 370+50-8+50);
    glVertex2i(620+16, 370+50-8-1+50);
    glVertex2i(620+40-16, 370+50-8-1+50);
    glVertex2i(620+40-16, 370+50-8+50);
    glVertex2i(620+16, 370+50-8+50);
    glVertex2i(620+16, 370+7+50);
    glVertex2i(620+16+1, 370+7+50);
    glVertex2i(620+16+1, 370+50-8+50);
    glVertex2i(620+16, 370+50-8+50);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3, 370+15+50);
    glVertex2i(620+3+10, 370+15+50);
    glVertex2i(620+3+10, 370+50-10+50);
    glVertex2i(620+3, 370+50-10+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3, 370+15+50);
    glVertex2i(620+2+10+1, 370+15+50);
    glVertex2i(620+2+10+1, 370+15+3+50);
    glVertex2i(620+3, 370+15+3+50);
    glVertex2i(620+2+10+1-2, 370+15+50);
    glVertex2i(620+2+10+1, 370+15+50);
    glVertex2i(620+2+10+1, 370+50-10+50);
    glVertex2i(620+2+10+1-2, 370+50-10+50);
    glVertex2i(620+2+1, 370+50-10-2+50);
    glVertex2i(620+2+10+1, 370+50-10-2+50);
    glVertex2i(620+2+10+1, 370+50-10+50);
    glVertex2i(620+2+1, 370+50-10+50);
    glVertex2i(620+2+1, 370+15+50);
    glVertex2i(620+2+1+1, 370+15+50);
    glVertex2i(620+2+1+1, 370+50-10+50);
    glVertex2i(620+2+1, 370+50-10+50);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24, 370+15+50);
    glVertex2i(620+3+10+24, 370+15+50);
    glVertex2i(620+3+10+24, 370+50-10+50);
    glVertex2i(620+3+24, 370+50-10+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24, 370+15+50);
    glVertex2i(620+2+10+1+24, 370+15+50);
    glVertex2i(620+2+10+1+24, 370+15+3+50);
    glVertex2i(620+3+24, 370+15+3+50);
    glVertex2i(620+2+10+1-2+24, 370+15+50);
    glVertex2i(620+2+10+1+24, 370+15+50);
    glVertex2i(620+2+10+1+24, 370+50-10+50);
    glVertex2i(620+2+10+1-2+24, 370+50-10+50);
    glVertex2i(620+2+1+24, 370+50-10-2+50);
    glVertex2i(620+2+10+1+24, 370+50-10-2+50);
    glVertex2i(620+2+10+1+24, 370+50-10+50);
    glVertex2i(620+2+1+24, 370+50-10+50);
    glVertex2i(620+2+1+24, 370+15+50);
    glVertex2i(620+2+1+1+24, 370+15+50);
    glVertex2i(620+2+1+1+24, 370+50-10+50);
    glVertex2i(620+2+1+24, 370+50-10+50);
    glEnd();
///***
    glColor3ub(102, 0, 51);
    glBegin(GL_QUADS);
    glVertex2i(620+16, 370+7+50+50);
    glVertex2i(620+40-16, 370+7+50+50);
    glVertex2i(620+40-16, 370+50-8+50+50);
    glVertex2i(620+16, 370+50-8+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+16, 370+7+50+50);
    glVertex2i(620+40-16, 370+7+50+50);
    glVertex2i(620+40-16, 370+7+2+50+50);
    glVertex2i(620+16, 370+7+2+50+50);
    glVertex2i(620+40-16-2, 370+7+50+50);
    glVertex2i(620+40-16, 370+7+50+50);
    glVertex2i(620+40-16, 370+50-8+50+50);
    glVertex2i(620+40-16-2, 370+50-8+50+50);
    glVertex2i(620+16, 370+50-8-1+50+50);
    glVertex2i(620+40-16, 370+50-8-1+50+50);
    glVertex2i(620+40-16, 370+50-8+50+50);
    glVertex2i(620+16, 370+50-8+50+50);
    glVertex2i(620+16, 370+7+50+50);
    glVertex2i(620+16+1, 370+7+50+50);
    glVertex2i(620+16+1, 370+50-8+50+50);
    glVertex2i(620+16, 370+50-8+50+50);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3, 370+15+50+50);
    glVertex2i(620+3+10, 370+15+50+50);
    glVertex2i(620+3+10, 370+50-10+50+50);
    glVertex2i(620+3, 370+50-10+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3, 370+15+50+50);
    glVertex2i(620+2+10+1, 370+15+50+50);
    glVertex2i(620+2+10+1, 370+15+3+50+50);
    glVertex2i(620+3, 370+15+3+50+50);
    glVertex2i(620+2+10+1-2, 370+15+50+50);
    glVertex2i(620+2+10+1, 370+15+50+50);
    glVertex2i(620+2+10+1, 370+50-10+50+50);
    glVertex2i(620+2+10+1-2, 370+50-10+50+50);
    glVertex2i(620+2+1, 370+50-10-2+50+50);
    glVertex2i(620+2+10+1, 370+50-10-2+50+50);
    glVertex2i(620+2+10+1, 370+50-10+50+50);
    glVertex2i(620+2+1, 370+50-10+50+50);
    glVertex2i(620+2+1, 370+15+50+50);
    glVertex2i(620+2+1+1, 370+15+50+50);
    glVertex2i(620+2+1+1, 370+50-10+50+50);
    glVertex2i(620+2+1, 370+50-10+50+50);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24, 370+15+50+50);
    glVertex2i(620+3+10+24, 370+15+50+50);
    glVertex2i(620+3+10+24, 370+50-10+50+50);
    glVertex2i(620+3+24, 370+50-10+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24, 370+15+50+50);
    glVertex2i(620+2+10+1+24, 370+15+50+50);
    glVertex2i(620+2+10+1+24, 370+15+3+50+50);
    glVertex2i(620+3+24, 370+15+3+50+50);
    glVertex2i(620+2+10+1-2+24, 370+15+50+50);
    glVertex2i(620+2+10+1+24, 370+15+50+50);
    glVertex2i(620+2+10+1+24, 370+50-10+50+50);
    glVertex2i(620+2+10+1-2+24, 370+50-10+50+50);
    glVertex2i(620+2+1+24, 370+50-10-2+50+50);
    glVertex2i(620+2+10+1+24, 370+50-10-2+50+50);
    glVertex2i(620+2+10+1+24, 370+50-10+50+50);
    glVertex2i(620+2+1+24, 370+50-10+50+50);
    glVertex2i(620+2+1+24, 370+15+50+50);
    glVertex2i(620+2+1+1+24, 370+15+50+50);
    glVertex2i(620+2+1+1+24, 370+50-10+50+50);
    glVertex2i(620+2+1+24, 370+50-10+50+50);
    glEnd();
///**************************
    glColor3ub(102, 0, 51);
    glBegin(GL_QUADS);
    glVertex2i(620+16+40, 370+7);
    glVertex2i(620+40-16+40, 370+7);
    glVertex2i(620+40-16+40, 370+50-8);
    glVertex2i(620+16+40, 370+50-8);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+16+40, 370+7);
    glVertex2i(620+40-16+40, 370+7);
    glVertex2i(620+40-16+40, 370+7+2);
    glVertex2i(620+16+40, 370+7+2);
    glVertex2i(620+40-16-2+40, 370+7);
    glVertex2i(620+40-16+40, 370+7);
    glVertex2i(620+40-16+40, 370+50-8);
    glVertex2i(620+40-16-2+40, 370+50-8);
    glVertex2i(620+16+40, 370+50-8-1);
    glVertex2i(620+40-16+40, 370+50-8-1);
    glVertex2i(620+40-16+40, 370+50-8);
    glVertex2i(620+16+40, 370+50-8);
    glVertex2i(620+16+40, 370+7);
    glVertex2i(620+16+1+40, 370+7);
    glVertex2i(620+16+1+40, 370+50-8);
    glVertex2i(620+16+40, 370+50-8);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+40, 370+15);
    glVertex2i(620+3+10+40, 370+15);
    glVertex2i(620+3+10+40, 370+50-10);
    glVertex2i(620+3+40, 370+50-10);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+40, 370+15);
    glVertex2i(620+2+10+1+40, 370+15);
    glVertex2i(620+2+10+1+40, 370+15+3);
    glVertex2i(620+3+40, 370+15+3);
    glVertex2i(620+2+10+1-2+40, 370+15);
    glVertex2i(620+2+10+1+40, 370+15);
    glVertex2i(620+2+10+1+40, 370+50-10);
    glVertex2i(620+2+10+1-2+40, 370+50-10);
    glVertex2i(620+2+1+40, 370+50-10-2);
    glVertex2i(620+2+10+1+40, 370+50-10-2);
    glVertex2i(620+2+10+1+40, 370+50-10);
    glVertex2i(620+2+1+40, 370+50-10);
    glVertex2i(620+2+1+40, 370+15);
    glVertex2i(620+2+1+1+40, 370+15);
    glVertex2i(620+2+1+1+40, 370+50-10);
    glVertex2i(620+2+1+40, 370+50-10);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24+40, 370+15);
    glVertex2i(620+3+10+24+40, 370+15);
    glVertex2i(620+3+10+24+40, 370+50-10);
    glVertex2i(620+3+24+40, 370+50-10);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24+40, 370+15);
    glVertex2i(620+2+10+1+24+40, 370+15);
    glVertex2i(620+2+10+1+24+40, 370+15+3);
    glVertex2i(620+3+24+40, 370+15+3);
    glVertex2i(620+2+10+1-2+24+40, 370+15);
    glVertex2i(620+2+10+1+24+40, 370+15);
    glVertex2i(620+2+10+1+24+40, 370+50-10);
    glVertex2i(620+2+10+1-2+24+40, 370+50-10);
    glVertex2i(620+2+1+24+40, 370+50-10-2);
    glVertex2i(620+2+10+1+24+40, 370+50-10-2);
    glVertex2i(620+2+10+1+24+40, 370+50-10);
    glVertex2i(620+2+1+24+40, 370+50-10);
    glVertex2i(620+2+1+24+40, 370+15);
    glVertex2i(620+2+1+1+24+40, 370+15);
    glVertex2i(620+2+1+1+24+40, 370+50-10);
    glVertex2i(620+2+1+24+40, 370+50-10);
    glEnd();
///***
    glColor3ub(102, 0, 51);
    glBegin(GL_QUADS);
    glVertex2i(620+16+40, 370+7+50);
    glVertex2i(620+40-16+40, 370+7+50);
    glVertex2i(620+40-16+40, 370+50-8+50);
    glVertex2i(620+16+40, 370+50-8+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+16+40, 370+7+50);
    glVertex2i(620+40-16+40, 370+7+50);
    glVertex2i(620+40-16+40, 370+7+2+50);
    glVertex2i(620+16+40, 370+7+2+50);
    glVertex2i(620+40-16-2+40, 370+7+50);
    glVertex2i(620+40-16+40, 370+7+50);
    glVertex2i(620+40-16+40, 370+50-8+50);
    glVertex2i(620+40-16-2+40, 370+50-8+50);
    glVertex2i(620+16+40, 370+50-8-1+50);
    glVertex2i(620+40-16+40, 370+50-8-1+50);
    glVertex2i(620+40-16+40, 370+50-8+50);
    glVertex2i(620+16+40, 370+50-8+50);
    glVertex2i(620+16+40, 370+7+50);
    glVertex2i(620+16+1+40, 370+7+50);
    glVertex2i(620+16+1+40, 370+50-8+50);
    glVertex2i(620+16+40, 370+50-8+50);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+40, 370+15+50);
    glVertex2i(620+3+10+40, 370+15+50);
    glVertex2i(620+3+10+40, 370+50-10+50);
    glVertex2i(620+3+40, 370+50-10+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+40, 370+15+50);
    glVertex2i(620+2+10+1+40, 370+15+50);
    glVertex2i(620+2+10+1+40, 370+15+3+50);
    glVertex2i(620+3+40, 370+15+3+50);
    glVertex2i(620+2+10+1-2+40, 370+15+50);
    glVertex2i(620+2+10+1+40, 370+15+50);
    glVertex2i(620+2+10+1+40, 370+50-10+50);
    glVertex2i(620+2+10+1-2+40, 370+50-10+50);
    glVertex2i(620+2+1+40, 370+50-10-2+50);
    glVertex2i(620+2+10+1+40, 370+50-10-2+50);
    glVertex2i(620+2+10+1+40, 370+50-10+50);
    glVertex2i(620+2+1+40, 370+50-10+50);
    glVertex2i(620+2+1+40, 370+15+50);
    glVertex2i(620+2+1+1+40, 370+15+50);
    glVertex2i(620+2+1+1+40, 370+50-10+50);
    glVertex2i(620+2+1+40, 370+50-10+50);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24+40, 370+15+50);
    glVertex2i(620+3+10+24+40, 370+15+50);
    glVertex2i(620+3+10+24+40, 370+50-10+50);
    glVertex2i(620+3+24+40, 370+50-10+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24+40, 370+15+50);
    glVertex2i(620+2+10+1+24+40, 370+15+50);
    glVertex2i(620+2+10+1+24+40, 370+15+3+50);
    glVertex2i(620+3+24+40, 370+15+3+50);
    glVertex2i(620+2+10+1-2+24+40, 370+15+50);
    glVertex2i(620+2+10+1+24+40, 370+15+50);
    glVertex2i(620+2+10+1+24+40, 370+50-10+50);
    glVertex2i(620+2+10+1-2+24+40, 370+50-10+50);
    glVertex2i(620+2+1+24+40, 370+50-10-2+50);
    glVertex2i(620+2+10+1+24+40, 370+50-10-2+50);
    glVertex2i(620+2+10+1+24+40, 370+50-10+50);
    glVertex2i(620+2+1+24+40, 370+50-10+50);
    glVertex2i(620+2+1+24+40, 370+15+50);
    glVertex2i(620+2+1+1+24+40, 370+15+50);
    glVertex2i(620+2+1+1+24+40, 370+50-10+50);
    glVertex2i(620+2+1+24+40, 370+50-10+50);
    glEnd();
///***
    glColor3ub(102, 0, 51);
    glBegin(GL_QUADS);
    glVertex2i(620+16+40, 370+7+50+50);
    glVertex2i(620+40-16+40, 370+7+50+50);
    glVertex2i(620+40-16+40, 370+50-8+50+50);
    glVertex2i(620+16+40, 370+50-8+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+16+40, 370+7+50+50);
    glVertex2i(620+40-16+40, 370+7+50+50);
    glVertex2i(620+40-16+40, 370+7+2+50+50);
    glVertex2i(620+16+40, 370+7+2+50+50);
    glVertex2i(620+40-16-2+40, 370+7+50+50);
    glVertex2i(620+40-16+40, 370+7+50+50);
    glVertex2i(620+40-16+40, 370+50-8+50+50);
    glVertex2i(620+40-16-2+40, 370+50-8+50+50);
    glVertex2i(620+16+40, 370+50-8-1+50+50);
    glVertex2i(620+40-16+40, 370+50-8-1+50+50);
    glVertex2i(620+40-16+40, 370+50-8+50+50);
    glVertex2i(620+16+40, 370+50-8+50+50);
    glVertex2i(620+16+40, 370+7+50+50);
    glVertex2i(620+16+1+40, 370+7+50+50);
    glVertex2i(620+16+1+40, 370+50-8+50+50);
    glVertex2i(620+16+40, 370+50-8+50+50);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+40, 370+15+50+50);
    glVertex2i(620+3+10+40, 370+15+50+50);
    glVertex2i(620+3+10+40, 370+50-10+50+50);
    glVertex2i(620+3+40, 370+50-10+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+40, 370+15+50+50);
    glVertex2i(620+2+10+1+40, 370+15+50+50);
    glVertex2i(620+2+10+1+40, 370+15+3+50+50);
    glVertex2i(620+3+40, 370+15+3+50+50);
    glVertex2i(620+2+10+1-2+40, 370+15+50+50);
    glVertex2i(620+2+10+1+40, 370+15+50+50);
    glVertex2i(620+2+10+1+40, 370+50-10+50+50);
    glVertex2i(620+2+10+1-2+40, 370+50-10+50+50);
    glVertex2i(620+2+1+40, 370+50-10-2+50+50);
    glVertex2i(620+2+10+1+40, 370+50-10-2+50+50);
    glVertex2i(620+2+10+1+40, 370+50-10+50+50);
    glVertex2i(620+2+1+40, 370+50-10+50+50);
    glVertex2i(620+2+1+40, 370+15+50+50);
    glVertex2i(620+2+1+1+40, 370+15+50+50);
    glVertex2i(620+2+1+1+40, 370+50-10+50+50);
    glVertex2i(620+2+1+40, 370+50-10+50+50);
    glEnd();
///
    glColor3ub(153, 0, 76);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24+40, 370+15+50+50);
    glVertex2i(620+3+10+24+40, 370+15+50+50);
    glVertex2i(620+3+10+24+40, 370+50-10+50+50);
    glVertex2i(620+3+24+40, 370+50-10+50+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(620+3+24+40, 370+15+50+50);
    glVertex2i(620+2+10+1+24+40, 370+15+50+50);
    glVertex2i(620+2+10+1+24+40, 370+15+3+50+50);
    glVertex2i(620+3+24+40, 370+15+3+50+50);
    glVertex2i(620+2+10+1-2+24+40, 370+15+50+50);
    glVertex2i(620+2+10+1+24+40, 370+15+50+50);
    glVertex2i(620+2+10+1+24+40, 370+50-10+50+50);
    glVertex2i(620+2+10+1-2+24+40, 370+50-10+50+50);
    glVertex2i(620+2+1+24+40, 370+50-10-2+50+50);
    glVertex2i(620+2+10+1+24+40, 370+50-10-2+50+50);
    glVertex2i(620+2+10+1+24+40, 370+50-10+50+50);
    glVertex2i(620+2+1+24+40, 370+50-10+50+50);
    glVertex2i(620+2+1+24+40, 370+15+50+50);
    glVertex2i(620+2+1+1+24+40, 370+15+50+50);
    glVertex2i(620+2+1+1+24+40, 370+50-10+50+50);
    glVertex2i(620+2+1+24+40, 370+50-10+50+50);
    glEnd();
}
void hospital()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400+20+10+10+-1, 420);
    glVertex2i(510+60+20-10+10+1, 420);
    glVertex2i(510+60+20-10+10+1, 610+2);
    glVertex2i(400+20+10+10-1, 610+2);
    glEnd();
    glColor3ub(166, 230, 150);
    glBegin(GL_QUADS);
    glVertex2i(440, 420);
    glVertex2i(590, 420);
    glVertex2i(590, 610);
    glVertex2i(440, 610);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(460+20+10-1, 420);
    glVertex2i(510+20+10+1, 420);
    glVertex2i(510+20+10+1, 470+200+50+2);
    glVertex2i(460+20+10-1, 470+200+50+2);
    glEnd();
    glColor3ub(230, 230, 150);
    glBegin(GL_QUADS);
    glVertex2i(460+20+10, 420);
    glVertex2i(510+20+10, 420);
    glVertex2i(510+20+10, 470+200+50);
    glVertex2i(460+20+10, 470+200+50);
    glEnd();

    glColor3ub(200, 170, 170);
    glBegin(GL_QUADS);
    glVertex2i(400+20+5+10, 420-10);
    glVertex2i(570+20-5+10, 420-10);
    glVertex2i(570+20-5+10, 420);
    glVertex2i(400+20+5+10, 420);
    glEnd();
    glColor3ub(200, 170, 170);
    glBegin(GL_QUADS);
    glVertex2i(400+20+5+10+40+10, 420-10-30);
    glVertex2i(570+20-5+10-40-10, 420-10-30);
    glVertex2i(570+20-5+10-40, 420);
    glVertex2i(400+20+5+10+40, 420);
    glEnd();

    glColor3ub(152, 152, 152);
    glBegin(GL_LINES);
    glVertex2i(400+20+5+10, 420-10);
    glVertex2i(570+20-5+10, 420-10);
    glVertex2i(400+20+5+10, 420);
    glVertex2i(570+20-5+10, 420);
    glEnd();


///Line
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(440, 420+22);
    glVertex2i(590, 420+22);
    glVertex2i(440, 420+22+56);
    glVertex2i(590, 420+22+56);
    glVertex2i(440, 420+22+56+56);
    glVertex2i(590, 420+22+56+56);
    glVertex2i(440, 420+22+56+56+56);
    glVertex2i(590, 420+22+56+56+56);
    glEnd();
///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6, 420+8);
    glVertex2i(440+6+15, 420+8);
    glVertex2i(440+6+15, 420+18);
    glVertex2i(440+6, 420+18);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+2, 420+8+3);
    glVertex2i(440+6+15-2, 420+8+3);
    glVertex2i(440+6+15-2, 420+18-2);
    glVertex2i(440+6+2, 420+18-2);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6, 420+30);
    glVertex2i(440+6+15, 420+30);
    glVertex2i(440+6+15, 420+25+45);
    glVertex2i(440+6, 420+25+45);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1, 420+30+3);
    glVertex2i(440+6+8, 420+30+3);
    glVertex2i(440+6+8, 420+25+45-3);
    glVertex2i(440+6+1, 420+25+45-3);
    glVertex2i(440+6+10, 420+30+3);
    glVertex2i(440+6+15-2, 420+30+3);
    glVertex2i(440+6+15-2, 420+25+45-18);
    glVertex2i(440+6+10, 420+25+45-18);
    glVertex2i(440+6+10, 420+25+45-18+4);
    glVertex2i(440+6+15-2, 420+25+45-18+4);
    glVertex2i(440+6+15-2, 420+25+45-3);
    glVertex2i(440+6+10, 420+25+45-3);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6, 420+30+56);
    glVertex2i(440+6+15, 420+30+56);
    glVertex2i(440+6+15, 420+25+45+56);
    glVertex2i(440+6, 420+25+45+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1, 420+30+3+56);
    glVertex2i(440+6+8, 420+30+3+56);
    glVertex2i(440+6+8, 420+25+45-3+56);
    glVertex2i(440+6+1, 420+25+45-3+56);
    glVertex2i(440+6+10, 420+30+3+56);
    glVertex2i(440+6+15-2, 420+30+3+56);
    glVertex2i(440+6+15-2, 420+25+45-18+56);
    glVertex2i(440+6+10, 420+25+45-18+56);
    glVertex2i(440+6+10, 420+25+45-18+4+56);
    glVertex2i(440+6+15-2, 420+25+45-18+4+56);
    glVertex2i(440+6+15-2, 420+25+45-3+56);
    glVertex2i(440+6+10, 420+25+45-3+56);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6, 420+30+56+56);
    glVertex2i(440+6+15, 420+30+56+56);
    glVertex2i(440+6+15, 420+25+45+56+56);
    glVertex2i(440+6, 420+25+45+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1, 420+30+3+56+56);
    glVertex2i(440+6+8, 420+30+3+56+56);
    glVertex2i(440+6+8, 420+25+45-3+56+56);
    glVertex2i(440+6+1, 420+25+45-3+56+56);
    glVertex2i(440+6+10, 420+30+3+56+56);
    glVertex2i(440+6+15-2, 420+30+3+56+56);
    glVertex2i(440+6+15-2, 420+25+45-18+56+56);
    glVertex2i(440+6+10, 420+25+45-18+56+56);
    glVertex2i(440+6+10, 420+25+45-18+4+56+56);
    glVertex2i(440+6+15-2, 420+25+45-18+4+56+56);
    glVertex2i(440+6+15-2, 420+25+45-3+56+56);
    glVertex2i(440+6+10, 420+25+45-3+56+56);
    glEnd();
///***
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+23, 420+8);
    glVertex2i(440+6+15+23, 420+8);
    glVertex2i(440+6+15+23, 420+18);
    glVertex2i(440+6+23, 420+18);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+2+23, 420+8+3);
    glVertex2i(440+6+15-2+23, 420+8+3);
    glVertex2i(440+6+15-2+23, 420+18-2);
    glVertex2i(440+6+2+23, 420+18-2);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+23, 420+30);
    glVertex2i(440+6+15+23, 420+30);
    glVertex2i(440+6+15+23, 420+25+45);
    glVertex2i(440+6+23, 420+25+45);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+23, 420+30+3);
    glVertex2i(440+6+8+23, 420+30+3);
    glVertex2i(440+6+8+23, 420+25+45-3);
    glVertex2i(440+6+1+23, 420+25+45-3);
    glVertex2i(440+6+10+23, 420+30+3);
    glVertex2i(440+6+15-2+23, 420+30+3);
    glVertex2i(440+6+15-2+23, 420+25+45-18);
    glVertex2i(440+6+10+23, 420+25+45-18);
    glVertex2i(440+6+10+23, 420+25+45-18+4);
    glVertex2i(440+6+15-2+23, 420+25+45-18+4);
    glVertex2i(440+6+15-2+23, 420+25+45-3);
    glVertex2i(440+6+10+23, 420+25+45-3);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+23, 420+30+56);
    glVertex2i(440+6+15+23, 420+30+56);
    glVertex2i(440+6+15+23, 420+25+45+56);
    glVertex2i(440+6+23, 420+25+45+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+23, 420+30+3+56);
    glVertex2i(440+6+8+23, 420+30+3+56);
    glVertex2i(440+6+8+23, 420+25+45-3+56);
    glVertex2i(440+6+1+23, 420+25+45-3+56);
    glVertex2i(440+6+10+23, 420+30+3+56);
    glVertex2i(440+6+15-2+23, 420+30+3+56);
    glVertex2i(440+6+15-2+23, 420+25+45-18+56);
    glVertex2i(440+6+10+23, 420+25+45-18+56);
    glVertex2i(440+6+10+23, 420+25+45-18+4+56);
    glVertex2i(440+6+15-2+23, 420+25+45-18+4+56);
    glVertex2i(440+6+15-2+23, 420+25+45-3+56);
    glVertex2i(440+6+10+23, 420+25+45-3+56);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+23, 420+30+56+56);
    glVertex2i(440+6+15+23, 420+30+56+56);
    glVertex2i(440+6+15+23, 420+25+45+56+56);
    glVertex2i(440+6+23, 420+25+45+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+23, 420+30+3+56+56);
    glVertex2i(440+6+8+23, 420+30+3+56+56);
    glVertex2i(440+6+8+23, 420+25+45-3+56+56);
    glVertex2i(440+6+1+23, 420+25+45-3+56+56);
    glVertex2i(440+6+10+23, 420+30+3+56+56);
    glVertex2i(440+6+15-2+23, 420+30+3+56+56);
    glVertex2i(440+6+15-2+23, 420+25+45-18+56+56);
    glVertex2i(440+6+10+23, 420+25+45-18+56+56);
    glVertex2i(440+6+10+23, 420+25+45-18+4+56+56);
    glVertex2i(440+6+15-2+23, 420+25+45-18+4+56+56);
    glVertex2i(440+6+15-2+23, 420+25+45-3+56+56);
    glVertex2i(440+6+10+23, 420+25+45-3+56+56);
    glEnd();
///***3
///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+100, 420+8);
    glVertex2i(440+6+15+100, 420+8);
    glVertex2i(440+6+15+100, 420+18);
    glVertex2i(440+6+100, 420+18);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+2+100, 420+8+3);
    glVertex2i(440+6+15-2+100, 420+8+3);
    glVertex2i(440+6+15-2+100, 420+18-2);
    glVertex2i(440+6+2+100, 420+18-2);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+100, 420+30);
    glVertex2i(440+6+15+100, 420+30);
    glVertex2i(440+6+15+100, 420+25+45);
    glVertex2i(440+6+100, 420+25+45);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+100, 420+30+3);
    glVertex2i(440+6+8+100, 420+30+3);
    glVertex2i(440+6+8+100, 420+25+45-3);
    glVertex2i(440+6+1+100, 420+25+45-3);
    glVertex2i(440+6+10+100, 420+30+3);
    glVertex2i(440+6+15-2+100, 420+30+3);
    glVertex2i(440+6+15-2+100, 420+25+45-18);
    glVertex2i(440+6+10+100, 420+25+45-18);
    glVertex2i(440+6+10+100, 420+25+45-18+4);
    glVertex2i(440+6+15-2+100, 420+25+45-18+4);
    glVertex2i(440+6+15-2+100, 420+25+45-3);
    glVertex2i(440+6+10+100, 420+25+45-3);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+100, 420+30+56);
    glVertex2i(440+6+15+100, 420+30+56);
    glVertex2i(440+6+15+100, 420+25+45+56);
    glVertex2i(440+6+100, 420+25+45+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+100, 420+30+3+56);
    glVertex2i(440+6+8+100, 420+30+3+56);
    glVertex2i(440+6+8+100, 420+25+45-3+56);
    glVertex2i(440+6+1+100, 420+25+45-3+56);
    glVertex2i(440+6+10+100, 420+30+3+56);
    glVertex2i(440+6+15-2+100, 420+30+3+56);
    glVertex2i(440+6+15-2+100, 420+25+45-18+56);
    glVertex2i(440+6+10+100, 420+25+45-18+56);
    glVertex2i(440+6+10+100, 420+25+45-18+4+56);
    glVertex2i(440+6+15-2+100, 420+25+45-18+4+56);
    glVertex2i(440+6+15-2+100, 420+25+45-3+56);
    glVertex2i(440+6+10+100, 420+25+45-3+56);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+100, 420+30+56+56);
    glVertex2i(440+6+15+100, 420+30+56+56);
    glVertex2i(440+6+15+100, 420+25+45+56+56);
    glVertex2i(440+6+100, 420+25+45+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+100, 420+30+3+56+56);
    glVertex2i(440+6+8+100, 420+30+3+56+56);
    glVertex2i(440+6+8+100, 420+25+45-3+56+56);
    glVertex2i(440+6+1+100, 420+25+45-3+56+56);
    glVertex2i(440+6+10+100, 420+30+3+56+56);
    glVertex2i(440+6+15-2+100, 420+30+3+56+56);
    glVertex2i(440+6+15-2+100, 420+25+45-18+56+56);
    glVertex2i(440+6+10+100, 420+25+45-18+56+56);
    glVertex2i(440+6+10+100, 420+25+45-18+4+56+56);
    glVertex2i(440+6+15-2+100, 420+25+45-18+4+56+56);
    glVertex2i(440+6+15-2+100, 420+25+45-3+56+56);
    glVertex2i(440+6+10+100, 420+25+45-3+56+56);
    glEnd();
///***
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+23+100, 420+8);
    glVertex2i(440+6+15+23+100, 420+8);
    glVertex2i(440+6+15+23+100, 420+18);
    glVertex2i(440+6+23+100, 420+18);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+2+23+100, 420+8+3);
    glVertex2i(440+6+15-2+23+100, 420+8+3);
    glVertex2i(440+6+15-2+23+100, 420+18-2);
    glVertex2i(440+6+2+23+100, 420+18-2);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+23+100, 420+30);
    glVertex2i(440+6+15+23+100, 420+30);
    glVertex2i(440+6+15+23+100, 420+25+45);
    glVertex2i(440+6+23+100, 420+25+45);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+23+100, 420+30+3);
    glVertex2i(440+6+8+23+100, 420+30+3);
    glVertex2i(440+6+8+23+100, 420+25+45-3);
    glVertex2i(440+6+1+23+100, 420+25+45-3);
    glVertex2i(440+6+10+23+100, 420+30+3);
    glVertex2i(440+6+15-2+23+100, 420+30+3);
    glVertex2i(440+6+15-2+23+100, 420+25+45-18);
    glVertex2i(440+6+10+23+100, 420+25+45-18);
    glVertex2i(440+6+10+23+100, 420+25+45-18+4);
    glVertex2i(440+6+15-2+23+100, 420+25+45-18+4);
    glVertex2i(440+6+15-2+23+100, 420+25+45-3);
    glVertex2i(440+6+10+23+100, 420+25+45-3);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+23+100, 420+30+56);
    glVertex2i(440+6+15+23+100, 420+30+56);
    glVertex2i(440+6+15+23+100, 420+25+45+56);
    glVertex2i(440+6+23+100, 420+25+45+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+23+100, 420+30+3+56);
    glVertex2i(440+6+8+23+100, 420+30+3+56);
    glVertex2i(440+6+8+23+100, 420+25+45-3+56);
    glVertex2i(440+6+1+23+100, 420+25+45-3+56);
    glVertex2i(440+6+10+23+100, 420+30+3+56);
    glVertex2i(440+6+15-2+23+100, 420+30+3+56);
    glVertex2i(440+6+15-2+23+100, 420+25+45-18+56);
    glVertex2i(440+6+10+23+100, 420+25+45-18+56);
    glVertex2i(440+6+10+23+100, 420+25+45-18+4+56);
    glVertex2i(440+6+15-2+23+100, 420+25+45-18+4+56);
    glVertex2i(440+6+15-2+23+100, 420+25+45-3+56);
    glVertex2i(440+6+10+23+100, 420+25+45-3+56);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(440+6+23+100, 420+30+56+56);
    glVertex2i(440+6+15+23+100, 420+30+56+56);
    glVertex2i(440+6+15+23+100, 420+25+45+56+56);
    glVertex2i(440+6+23+100, 420+25+45+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(440+6+1+23+100, 420+30+3+56+56);
    glVertex2i(440+6+8+23+100, 420+30+3+56+56);
    glVertex2i(440+6+8+23+100, 420+25+45-3+56+56);
    glVertex2i(440+6+1+23+100, 420+25+45-3+56+56);
    glVertex2i(440+6+10+23+100, 420+30+3+56+56);
    glVertex2i(440+6+15-2+23+100, 420+30+3+56+56);
    glVertex2i(440+6+15-2+23+100, 420+25+45-18+56+56);
    glVertex2i(440+6+10+23+100, 420+25+45-18+56+56);
    glVertex2i(440+6+10+23+100, 420+25+45-18+4+56+56);
    glVertex2i(440+6+15-2+23+100, 420+25+45-18+4+56+56);
    glVertex2i(440+6+15-2+23+100, 420+25+45-3+56+56);
    glVertex2i(440+6+10+23+100, 420+25+45-3+56+56);
    glEnd();
///******
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5, 450+5);
    glVertex2i(490+4+7, 450+5);
    glVertex2i(490+4+7, 450+30+10);
    glVertex2i(490+5, 450+30+10);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1, 450+5+1);
    glVertex2i(490+5+7-2, 450+5+1);
    glVertex2i(490+5+7-2, 450+30+10-2);
    glVertex2i(490+5+1, 450+30+10-2);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11, 450+5);
    glVertex2i(490+4+7+11, 450+5);
    glVertex2i(490+4+7+11, 450+30+10);
    glVertex2i(490+5+11, 450+30+10);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11, 450+5+1);
    glVertex2i(490+5+7-2+11, 450+5+1);
    glVertex2i(490+5+7-2+11, 450+30+10-2);
    glVertex2i(490+5+1+11, 450+30+10-2);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11, 450+5);
    glVertex2i(490+4+7+11+11, 450+5);
    glVertex2i(490+4+7+11+11, 450+30+10);
    glVertex2i(490+5+11+11, 450+30+10);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11, 450+5+1);
    glVertex2i(490+5+7-2+11+11, 450+5+1);
    glVertex2i(490+5+7-2+11+11, 450+30+10-2);
    glVertex2i(490+5+1+11+11, 450+30+10-2);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11+11, 450+5);
    glVertex2i(490+4+7+11+11+11, 450+5);
    glVertex2i(490+4+7+11+11+11, 450+30+10);
    glVertex2i(490+5+11+11+11, 450+30+10);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11+11, 450+5+1);
    glVertex2i(490+5+7-2+11+11+11, 450+5+1);
    glVertex2i(490+5+7-2+11+11+11, 450+30+10-2);
    glVertex2i(490+5+1+11+11+11, 450+30+10-2);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5, 450+5+56);
    glVertex2i(490+4+7, 450+5+56);
    glVertex2i(490+4+7, 450+30+10+56);
    glVertex2i(490+5, 450+30+10+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1, 450+5+1+56);
    glVertex2i(490+5+7-2, 450+5+1+56);
    glVertex2i(490+5+7-2, 450+30+10-2+56);
    glVertex2i(490+5+1, 450+30+10-2+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11, 450+5+56);
    glVertex2i(490+4+7+11, 450+5+56);
    glVertex2i(490+4+7+11, 450+30+10+56);
    glVertex2i(490+5+11, 450+30+10+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11, 450+5+1+56);
    glVertex2i(490+5+7-2+11, 450+5+1+56);
    glVertex2i(490+5+7-2+11, 450+30+10-2+56);
    glVertex2i(490+5+1+11, 450+30+10-2+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11, 450+5+56);
    glVertex2i(490+4+7+11+11, 450+5+56);
    glVertex2i(490+4+7+11+11, 450+30+10+56);
    glVertex2i(490+5+11+11, 450+30+10+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11, 450+5+1+56);
    glVertex2i(490+5+7-2+11+11, 450+5+1+56);
    glVertex2i(490+5+7-2+11+11, 450+30+10-2+56);
    glVertex2i(490+5+1+11+11, 450+30+10-2+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11+11, 450+5+56);
    glVertex2i(490+4+7+11+11+11, 450+5+56);
    glVertex2i(490+4+7+11+11+11, 450+30+10+56);
    glVertex2i(490+5+11+11+11, 450+30+10+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11+11, 450+5+1+56);
    glVertex2i(490+5+7-2+11+11+11, 450+5+1+56);
    glVertex2i(490+5+7-2+11+11+11, 450+30+10-2+56);
    glVertex2i(490+5+1+11+11+11, 450+30+10-2+56);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5, 450+5+56+56);
    glVertex2i(490+4+7, 450+5+56+56);
    glVertex2i(490+4+7, 450+30+10+56+56);
    glVertex2i(490+5, 450+30+10+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1, 450+5+1+56+56);
    glVertex2i(490+5+7-2, 450+5+1+56+56);
    glVertex2i(490+5+7-2, 450+30+10-2+56+56);
    glVertex2i(490+5+1, 450+30+10-2+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11, 450+5+56+56);
    glVertex2i(490+4+7+11, 450+5+56+56);
    glVertex2i(490+4+7+11, 450+30+10+56+56);
    glVertex2i(490+5+11, 450+30+10+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11, 450+5+1+56+56);
    glVertex2i(490+5+7-2+11, 450+5+1+56+56);
    glVertex2i(490+5+7-2+11, 450+30+10-2+56+56);
    glVertex2i(490+5+1+11, 450+30+10-2+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11, 450+5+56+56);
    glVertex2i(490+4+7+11+11, 450+5+56+56);
    glVertex2i(490+4+7+11+11, 450+30+10+56+56);
    glVertex2i(490+5+11+11, 450+30+10+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11, 450+5+1+56+56);
    glVertex2i(490+5+7-2+11+11, 450+5+1+56+56);
    glVertex2i(490+5+7-2+11+11, 450+30+10-2+56+56);
    glVertex2i(490+5+1+11+11, 450+30+10-2+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11+11, 450+5+56+56);
    glVertex2i(490+4+7+11+11+11, 450+5+56+56);
    glVertex2i(490+4+7+11+11+11, 450+30+10+56+56);
    glVertex2i(490+5+11+11+11, 450+30+10+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11+11, 450+5+1+56+56);
    glVertex2i(490+5+7-2+11+11+11, 450+5+1+56+56);
    glVertex2i(490+5+7-2+11+11+11, 450+30+10-2+56+56);
    glVertex2i(490+5+1+11+11+11, 450+30+10-2+56+56);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5, 450+5+56+56+56);
    glVertex2i(490+4+7, 450+5+56+56+56);
    glVertex2i(490+4+7, 450+30+10+56+56+56);
    glVertex2i(490+5, 450+30+10+56+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1, 450+5+1+56+56+56);
    glVertex2i(490+5+7-2, 450+5+1+56+56+56);
    glVertex2i(490+5+7-2, 450+30+10-2+56+56+56);
    glVertex2i(490+5+1, 450+30+10-2+56+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11, 450+5+56+56+56);
    glVertex2i(490+4+7+11, 450+5+56+56+56);
    glVertex2i(490+4+7+11, 450+30+10+56+56+56);
    glVertex2i(490+5+11, 450+30+10+56+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11, 450+5+1+56+56+56);
    glVertex2i(490+5+7-2+11, 450+5+1+56+56+56);
    glVertex2i(490+5+7-2+11, 450+30+10-2+56+56+56);
    glVertex2i(490+5+1+11, 450+30+10-2+56+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11, 450+5+56+56+56);
    glVertex2i(490+4+7+11+11, 450+5+56+56+56);
    glVertex2i(490+4+7+11+11, 450+30+10+56+56+56);
    glVertex2i(490+5+11+11, 450+30+10+56+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11, 450+5+1+56+56+56);
    glVertex2i(490+5+7-2+11+11, 450+5+1+56+56+56);
    glVertex2i(490+5+7-2+11+11, 450+30+10-2+56+56+56);
    glVertex2i(490+5+1+11+11, 450+30+10-2+56+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11+11, 450+5+56+56+56);
    glVertex2i(490+4+7+11+11+11, 450+5+56+56+56);
    glVertex2i(490+4+7+11+11+11, 450+30+10+56+56+56);
    glVertex2i(490+5+11+11+11, 450+30+10+56+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11+11, 450+5+1+56+56+56);
    glVertex2i(490+5+7-2+11+11+11, 450+5+1+56+56+56);
    glVertex2i(490+5+7-2+11+11+11, 450+30+10-2+56+56+56);
    glVertex2i(490+5+1+11+11+11, 450+30+10-2+56+56+56);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5, 450+5+56+56+56+56);
    glVertex2i(490+4+7, 450+5+56+56+56+56);
    glVertex2i(490+4+7, 450+30+10+56+56+56+56);
    glVertex2i(490+5, 450+30+10+56+56+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1, 450+5+1+56+56+56+56);
    glVertex2i(490+5+7-2, 450+5+1+56+56+56+56);
    glVertex2i(490+5+7-2, 450+30+10-2+56+56+56+56);
    glVertex2i(490+5+1, 450+30+10-2+56+56+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11, 450+5+56+56+56+56);
    glVertex2i(490+4+7+11, 450+5+56+56+56+56);
    glVertex2i(490+4+7+11, 450+30+10+56+56+56+56);
    glVertex2i(490+5+11, 450+30+10+56+56+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11, 450+5+1+56+56+56+56);
    glVertex2i(490+5+7-2+11, 450+5+1+56+56+56+56);
    glVertex2i(490+5+7-2+11, 450+30+10-2+56+56+56+56);
    glVertex2i(490+5+1+11, 450+30+10-2+56+56+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11, 450+5+56+56+56+56);
    glVertex2i(490+4+7+11+11, 450+5+56+56+56+56);
    glVertex2i(490+4+7+11+11, 450+30+10+56+56+56+56);
    glVertex2i(490+5+11+11, 450+30+10+56+56+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11, 450+5+1+56+56+56+56);
    glVertex2i(490+5+7-2+11+11, 450+5+1+56+56+56+56);
    glVertex2i(490+5+7-2+11+11, 450+30+10-2+56+56+56+56);
    glVertex2i(490+5+1+11+11, 450+30+10-2+56+56+56+56);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+5+11+11+11, 450+5+56+56+56+56);
    glVertex2i(490+4+7+11+11+11, 450+5+56+56+56+56);
    glVertex2i(490+4+7+11+11+11, 450+30+10+56+56+56+56);
    glVertex2i(490+5+11+11+11, 450+30+10+56+56+56+56);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+5+1+11+11+11, 450+5+1+56+56+56+56);
    glVertex2i(490+5+7-2+11+11+11, 450+5+1+56+56+56+56);
    glVertex2i(490+5+7-2+11+11+11, 450+30+10-2+56+56+56+56);
    glVertex2i(490+5+1+11+11+11, 450+30+10-2+56+56+56+56);
    glEnd();
///MainDoor
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(490+10, 410);
    glVertex2i(490+40, 410);
    glVertex2i(490+40, 440);
    glVertex2i(490+10, 440);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+10+14.5, 410+3);
    glVertex2i(490+10+15.5, 410+3);
    glVertex2i(490+10+15.5, 440-3);
    glVertex2i(490+10+14.5, 440-3);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(490+10+2, 410+3);
    glVertex2i(490+10+13, 410+3);
    glVertex2i(490+10+13, 440-3);
    glVertex2i(490+10+2, 440-3);
    glVertex2i(490+10+17, 410+3);
    glVertex2i(490+10+28, 410+3);
    glVertex2i(490+10+28, 440-3);
    glVertex2i(490+10+17, 440-3);
    glEnd();
}
void Net1()
{
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(70, 550);
    glVertex2i(73, 550);
    glVertex2i(73, 630);
    glVertex2i(70, 630);
    glVertex2i(70-2, 630);
    glVertex2i(73+2, 630);
    glVertex2i(73+2, 640);
    glVertex2i(70-2, 640);
    glEnd();
///Center()
    glTranslatef(73, 638, 0);
	glRotatef(_angle, 0, 0, 1);
    glBegin(GL_POLYGON);
    {
        glVertex2i(0, 0);
        glVertex2i(30, 15);
        glVertex2i(5, -2);
        glVertex2i(0, 0);
        glVertex2i(-25, 15);
        glVertex2i(5, -8);
        glVertex2i(0, 0);
        glVertex2i(10, -30);
        glVertex2i(5, 0);
    }
    glEnd();
    glPopMatrix();

///***
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(70+700, 550);
    glVertex2i(73+700, 550);
    glVertex2i(73+700, 630);
    glVertex2i(70+700, 630);
    glVertex2i(70-2+700, 630);
    glVertex2i(73+2+700, 630);
    glVertex2i(73+2+700, 640);
    glVertex2i(70-2+700, 640);
    glEnd();
///Center()
    glTranslatef(772, 638, 0);
	glRotatef(_angle, 0, 0, 1);
    glBegin(GL_POLYGON);
    {
        glVertex2i(0, 0);
        glVertex2i(30, 15);
        glVertex2i(5, -2);
        glVertex2i(0, 0);
        glVertex2i(-25, 15);
        glVertex2i(5, -8);
        glVertex2i(0, 0);
        glVertex2i(10, -30);
        glVertex2i(5, 0);
    }
    glEnd();
    glPopMatrix();
}
void building3()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(330, 350);
    glVertex2i(390, 350);
    glVertex2i(390, 360);
    glVertex2i(330, 360);
    glEnd();

    glColor3ub(164, 125, 125);
    glBegin(GL_QUADS);
    glVertex2i(330, 360);
    glVertex2i(390, 360);
    glVertex2i(390, 360+150);
    glVertex2i(330, 360+150);
    glEnd();
///Line
    glColor3ub(0, 255, 0);
    glBegin(GL_LINES);
    glVertex2i(330, 360+50);
    glVertex2i(390, 360+50);
    glVertex2i(390, 360+100);
    glVertex2i(330, 360+100);
    glVertex2i(390, 360+150);
    glVertex2i(330, 360+150);
    glEnd();
///MainDoor
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-7, 360);
    glVertex2i(360+7, 360);
    glVertex2i(360+7, 360+35);
    glVertex2i(360-7, 360+35);
    glEnd();
    glColor3ub(191, 191, 191);
    glBegin(GL_QUADS);
    glVertex2i(360-7+1, 360+3);
    glVertex2i(360+7-2, 360+3);
    glVertex2i(360+7-2, 360+35-2);
    glVertex2i(360-7+1, 360+35-2);
    glEnd();
    //glColor3ub(182, 163, 240);
	//glColor3ub(55, 161, 163);
	//glColor3f(0.850, 0.490, 0.756);
	//glColor3f(0.192, 0.576, 0.705);
	//glColor3ub(109, 109, 115);
    //glColor3ub(191, 191, 191);
///window
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5, 360+20);
    glVertex2i(330+20, 360+20);
    glVertex2i(330+20, 360+40);
    glVertex2i(330+5, 360+40);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1, 360+20+3);
    glVertex2i(330+20-2, 360+20+3);
    glVertex2i(330+20-2, 360+40-2);
    glVertex2i(330+5+1, 360+40-2);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5, 360+20+50);
    glVertex2i(330+20, 360+20+50);
    glVertex2i(330+20, 360+40+50);
    glVertex2i(330+5, 360+40+50);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1, 360+20+3+50);
    glVertex2i(330+20-2, 360+20+3+50);
    glVertex2i(330+20-2, 360+40-2+50);
    glVertex2i(330+5+1, 360+40-2+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5, 360+20+50+50);
    glVertex2i(330+20, 360+20+50+50);
    glVertex2i(330+20, 360+40+50+50);
    glVertex2i(330+5, 360+40+50+50);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1, 360+20+3+50+50);
    glVertex2i(330+20-2, 360+20+3+50+50);
    glVertex2i(330+20-2, 360+40-2+50+50);
    glVertex2i(330+5+1, 360+40-2+50+50);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20, 360+20);
    glVertex2i(390-5, 360+20);
    glVertex2i(390-5, 360+40);
    glVertex2i(390-20, 360+40);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1, 360+20+3);
    glVertex2i(390-5-2, 360+20+3);
    glVertex2i(390-5-2, 360+40-2);
    glVertex2i(390-20+1, 360+40-2);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20, 360+20+50);
    glVertex2i(390-5, 360+20+50);
    glVertex2i(390-5, 360+40+50);
    glVertex2i(390-20, 360+40+50);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1, 360+20+3+50);
    glVertex2i(390-5-2, 360+20+3+50);
    glVertex2i(390-5-2, 360+40-2+50);
    glVertex2i(390-20+1, 360+40-2+50);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20, 360+20+50+50);
    glVertex2i(390-5, 360+20+50+50);
    glVertex2i(390-5, 360+40+50+50);
    glVertex2i(390-20, 360+40+50+50);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1, 360+20+3+50+50);
    glVertex2i(390-5-2, 360+20+3+50+50);
    glVertex2i(390-5-2, 360+40-2+50+50);
    glVertex2i(390-20+1, 360+40-2+50+50);
    glEnd();
///**
    glColor3f(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-3, 360+20+3-15+50);
    glVertex2i(360+3, 360+20+3-15+50);
    glVertex2i(360+3, 360+40-2+5+50);
    glVertex2i(360-3, 360+40-2+5+50);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(360-3+1, 360+20+3-15+50+3);
    glVertex2i(360+3-1, 360+20+3-15+50+3);
    glVertex2i(360+3-1, 360+40-2+5+50-2);
    glVertex2i(360-3+1, 360+40-2+5+50-2);
    glEnd();

    glColor3f(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-3, 360+20+3-15+50+50);
    glVertex2i(360+3, 360+20+3-15+50+50);
    glVertex2i(360+3, 360+40-2+5+50+50);
    glVertex2i(360-3, 360+40-2+5+50+50);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(360-3+1, 360+20+3-15+50+50+3);
    glVertex2i(360+3-1, 360+20+3-15+50+50+3);
    glVertex2i(360+3-1, 360+40-2+5+50+50-2);
    glVertex2i(360-3+1, 360+40-2+5+50+50-2);
    glEnd();
}
void building4()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(330+330, 350+45);
    glVertex2i(390+330, 350+45);
    glVertex2i(390+330, 360+45);
    glVertex2i(330+330, 360+45);
    glEnd();

    glColor3ub(164, 125, 125);
    glBegin(GL_QUADS);
    glVertex2i(330+330, 360+45);
    glVertex2i(390+330, 360+45);
    glVertex2i(390+330, 360+150+45);
    glVertex2i(330+330, 360+150+45);
    glEnd();
///Line
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2i(330+330, 360+50+45);
    glVertex2i(390+330, 360+50+45);
    glVertex2i(390+330, 360+100+45);
    glVertex2i(330+330, 360+100+45);
    glVertex2i(390+330, 360+150+45);
    glVertex2i(330+330, 360+150+45);
    glEnd();
///MainDoor
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-7+330, 360+45);
    glVertex2i(360+7+330, 360+45);
    glVertex2i(360+7+330, 360+35+45);
    glVertex2i(360-7+330, 360+35+45);
    glEnd();
    glColor3ub(191, 191, 191);
    glBegin(GL_QUADS);
    glVertex2i(360-7+1+330, 360+3+45);
    glVertex2i(360+7-2+330, 360+3+45);
    glVertex2i(360+7-2+330, 360+35-2+45);
    glVertex2i(360-7+1+330, 360+35-2+45);
    glEnd();
///window
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5+330, 360+20+45);
    glVertex2i(330+20+330, 360+20+45);
    glVertex2i(330+20+330, 360+40+45);
    glVertex2i(330+5+330, 360+40+45);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1+330, 360+20+3+45);
    glVertex2i(330+20-2+330, 360+20+3+45);
    glVertex2i(330+20-2+330, 360+40-2+45);
    glVertex2i(330+5+1+330, 360+40-2+45);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5+330, 360+20+50+45);
    glVertex2i(330+20+330, 360+20+50+45);
    glVertex2i(330+20+330, 360+40+50+45);
    glVertex2i(330+5+330, 360+40+50+45);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1+330, 360+20+3+50+45);
    glVertex2i(330+20-2+330, 360+20+3+50+45);
    glVertex2i(330+20-2+330, 360+40-2+50+45);
    glVertex2i(330+5+1+330, 360+40-2+50+45);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5+330, 360+20+50+50+45);
    glVertex2i(330+20+330, 360+20+50+50+45);
    glVertex2i(330+20+330, 360+40+50+50+45);
    glVertex2i(330+5+330, 360+40+50+50+45);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1+330, 360+20+3+50+50+45);
    glVertex2i(330+20-2+330, 360+20+3+50+50+45);
    glVertex2i(330+20-2+330, 360+40-2+50+50+45);
    glVertex2i(330+5+1+330, 360+40-2+50+50+45);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20+330, 360+20+45);
    glVertex2i(390-5+330, 360+20+45);
    glVertex2i(390-5+330, 360+40+45);
    glVertex2i(390-20+330, 360+40+45);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1+330, 360+20+3+45);
    glVertex2i(390-5-2+330, 360+20+3+45);
    glVertex2i(390-5-2+330, 360+40-2+45);
    glVertex2i(390-20+1+330, 360+40-2+45);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20+330, 360+20+50+45);
    glVertex2i(390-5+330, 360+20+50+45);
    glVertex2i(390-5+330, 360+40+50+45);
    glVertex2i(390-20+330, 360+40+50+45);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1+330, 360+20+3+50+45);
    glVertex2i(390-5-2+330, 360+20+3+50+45);
    glVertex2i(390-5-2+330, 360+40-2+50+45);
    glVertex2i(390-20+1+330, 360+40-2+50+45);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20+330, 360+20+50+50+45);
    glVertex2i(390-5+330, 360+20+50+50+45);
    glVertex2i(390-5+330, 360+40+50+50+45);
    glVertex2i(390-20+330, 360+40+50+50+45);
    glEnd();
    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1+330, 360+20+3+50+50+45);
    glVertex2i(390-5-2+330, 360+20+3+50+50+45);
    glVertex2i(390-5-2+330, 360+40-2+50+50+45);
    glVertex2i(390-20+1+330, 360+40-2+50+50+45);
    glEnd();
///**
    glColor3f(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-3+330, 360+20+3-15+50+45);
    glVertex2i(360+3+330, 360+20+3-15+50+45);
    glVertex2i(360+3+330, 360+40-2+5+50+45);
    glVertex2i(360-3+330, 360+40-2+5+50+45);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(360-3+1+330, 360+20+3-15+50+3+45);
    glVertex2i(360+3-1+330, 360+20+3-15+50+3+45);
    glVertex2i(360+3-1+330, 360+40-2+5+50-2+45);
    glVertex2i(360-3+1+330, 360+40-2+5+50-2+45);
    glEnd();

    glColor3f(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-3+330, 360+20+3-15+50+50+45);
    glVertex2i(360+3+330, 360+20+3-15+50+50+45);
    glVertex2i(360+3+330, 360+40-2+5+50+50+45);
    glVertex2i(360-3+330, 360+40-2+5+50+50+45);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(360-3+1+330, 360+20+3-15+50+50+3+45);
    glVertex2i(360+3-1+330, 360+20+3-15+50+50+3+45);
    glVertex2i(360+3-1+330, 360+40-2+5+50+50-2+45);
    glVertex2i(360-3+1+330, 360+40-2+5+50+50-2+45);
    glEnd();
}
void building5()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400-5, 360);
    glVertex2i(460-5, 360);
    glVertex2i(460-5, 370);
    glVertex2i(400-5, 370);
    glEnd();

    glColor3ub(8, 218, 218);
    glBegin(GL_QUADS);
    glVertex2i(400-5, 370);
    glVertex2i(460-5, 370);
    glVertex2i(460-5, 370+100);
    glVertex2i(400-5, 370+100);
    glEnd();
///Line
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(400-5, 370+50);
    glVertex2i(460-5, 370+50);
    glVertex2i(460-5, 370+100);
    glVertex2i(400-5, 370+100);
    glVertex2i(400-5+30, 370+100);
    glVertex2i(400-5+30, 370);

    glEnd();
///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(400-5+5, 370+10);
    glVertex2i(400-5+25, 370+10);
    glVertex2i(400-5+25, 370+10+30);
    glVertex2i(400-5+5, 370+10+30);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400+2, 370+10+3);
    glVertex2i(400+9, 370+10+3);
    glVertex2i(400+9, 370+10+30-2);
    glVertex2i(400+2, 370+10+30-2);
    glVertex2i(400+2+9, 370+10+3);
    glVertex2i(400+9+9, 370+10+3);
    glVertex2i(400+9+9, 370+10+30-2);
    glVertex2i(400+2+9, 370+10+30-2);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(400-5+5, 370+10+50);
    glVertex2i(400-5+25, 370+10+50);
    glVertex2i(400-5+25, 370+10+30+50);
    glVertex2i(400-5+5, 370+10+30+50);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400+2, 370+10+3+50);
    glVertex2i(400+9, 370+10+3+50);
    glVertex2i(400+9, 370+10+30-2+50);
    glVertex2i(400+2, 370+10+30-2+50);
    glVertex2i(400+2+9, 370+10+3+50);
    glVertex2i(400+9+9, 370+10+3+50);
    glVertex2i(400+9+9, 370+10+30-2+50);
    glVertex2i(400+2+9, 370+10+30-2+50);
    glEnd();
///***
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(400-5+5+30, 370+10);
    glVertex2i(400-5+25+30, 370+10);
    glVertex2i(400-5+25+30, 370+10+30);
    glVertex2i(400-5+5+30, 370+10+30);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400+2+30, 370+10+3);
    glVertex2i(400+9+30, 370+10+3);
    glVertex2i(400+9+30, 370+10+30-2);
    glVertex2i(400+2+30, 370+10+30-2);
    glVertex2i(400+2+9+30, 370+10+3);
    glVertex2i(400+9+9+30, 370+10+3);
    glVertex2i(400+9+9+30, 370+10+30-2);
    glVertex2i(400+2+9+30, 370+10+30-2);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(400-5+5+30, 370+10+50);
    glVertex2i(400-5+25+30, 370+10+50);
    glVertex2i(400-5+25+30, 370+10+30+50);
    glVertex2i(400-5+5+30, 370+10+30+50);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400+2+30, 370+10+3+50);
    glVertex2i(400+9+30, 370+10+3+50);
    glVertex2i(400+9+30, 370+10+30-2+50);
    glVertex2i(400+2+30, 370+10+30-2+50);
    glVertex2i(400+2+9+30, 370+10+3+50);
    glVertex2i(400+9+9+30, 370+10+3+50);
    glVertex2i(400+9+9+30, 370+10+30-2+50);
    glVertex2i(400+2+9+30, 370+10+30-2+50);
    glEnd();
}
void building6()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400-5-75, 360+60);
    glVertex2i(460-5-75, 360+60);
    glVertex2i(460-5-75, 370+60);
    glVertex2i(400-5-75, 370+60);
    glEnd();

    glColor3ub(200, 100, 200);
    glBegin(GL_QUADS);
    glVertex2i(400-5-75, 370+60);
    glVertex2i(460-5-75, 370+60);
    glVertex2i(460-5-75, 370+100+60);
    glVertex2i(400-5-75, 370+100+60);
    glEnd();
///Line
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(400-5-75, 370+50+60);
    glVertex2i(460-5-75, 370+50+60);
    glVertex2i(460-5-75, 370+100+60);
    glVertex2i(400-5-75, 370+100+60);
    glVertex2i(400-5+30-75, 370+100+60);
    glVertex2i(400-5+30-75, 370+60);
    glEnd();
///Door
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(400-5+5-75, 370+10+60);
    glVertex2i(400-5+25-75, 370+10+60);
    glVertex2i(400-5+25-75, 370+10+30+60);
    glVertex2i(400-5+5-75, 370+10+30+60);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400+2-75, 370+10+3+60);
    glVertex2i(400+9-75, 370+10+3+60);
    glVertex2i(400+9-75, 370+10+30-2+60);
    glVertex2i(400+2-75, 370+10+30-2+60);
    glVertex2i(400+2+9-75, 370+10+3+60);
    glVertex2i(400+9+9-75, 370+10+3+60);
    glVertex2i(400+9+9-75, 370+10+30-2+60);
    glVertex2i(400+2+9-75, 370+10+30-2+60);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(400-5+5-75, 370+10+50+60);
    glVertex2i(400-5+25-75, 370+10+50+60);
    glVertex2i(400-5+25-75, 370+10+30+50+60);
    glVertex2i(400-5+5-75, 370+10+30+50+60);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400+2-75, 370+10+3+50+60);
    glVertex2i(400+9-75, 370+10+3+50+60);
    glVertex2i(400+9-75, 370+10+30-2+50+60);
    glVertex2i(400+2-75, 370+10+30-2+50+60);
    glVertex2i(400+2+9-75, 370+10+3+50+60);
    glVertex2i(400+9+9-75, 370+10+3+50+60);
    glVertex2i(400+9+9-75, 370+10+30-2+50+60);
    glVertex2i(400+2+9-75, 370+10+30-2+50+60);
    glEnd();
///***
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(400-5+5+30-75, 370+10+50+60);
    glVertex2i(400-5+25+30-75, 370+10+50+60);
    glVertex2i(400-5+25+30-75, 370+10+30+50+60);
    glVertex2i(400-5+5+30-75, 370+10+30+50+60);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(400+2+30-75, 370+10+3+50+60);
    glVertex2i(400+9+30-75, 370+10+3+50+60);
    glVertex2i(400+9+30-75, 370+10+30-2+50+60);
    glVertex2i(400+2+30-75, 370+10+30-2+50+60);
    glVertex2i(400+2+9+30-75, 370+10+3+50+60);
    glVertex2i(400+9+9+30-75, 370+10+3+50+60);
    glVertex2i(400+9+9+30-75, 370+10+30-2+50+60);
    glVertex2i(400+2+9+30-75, 370+10+30-2+50+60);
    glEnd();
}
void building7()
{
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(330+48, 350+35);
    glVertex2i(390+48, 350+35);
    glVertex2i(390+48, 360+35);
    glVertex2i(330+48, 360+35);
    glEnd();

    glColor3ub(230, 100, 70);
    glBegin(GL_QUADS);
    glVertex2i(330+48, 360+35);
    glVertex2i(390+48, 360+35);
    glVertex2i(390+48, 360+150+35);
    glVertex2i(330+48, 360+150+35);
    glEnd();
///Line
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2i(330+48, 360+50+35);
    glVertex2i(390+48, 360+50+35);
    glVertex2i(390+48, 360+100+35);
    glVertex2i(330+48, 360+100+35);
    glVertex2i(390+48, 360+150+35);
    glVertex2i(330+48, 360+150+35);
    glEnd();
///MainDoor
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-7+48, 360+35);
    glVertex2i(360+7+48, 360+35);
    glVertex2i(360+7+48, 360+35+35);
    glVertex2i(360-7+48, 360+35+35);
    glEnd();
    glColor3ub(191, 191, 191);
    glBegin(GL_QUADS);
    glVertex2i(360-7+1+48, 360+3+35);
    glVertex2i(360+7-2+48, 360+3+35);
    glVertex2i(360+7-2+48, 360+35-2+35);
    glVertex2i(360-7+1+48, 360+35-2+35);
    glEnd();
///window
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5+48, 360+20+35);
    glVertex2i(330+20+48, 360+20+35);
    glVertex2i(330+20+48, 360+40+35);
    glVertex2i(330+5+48, 360+40+35);
    glEnd();
    //glColor3ub(182, 163, 240);
	//glColor3ub(55, 161, 163);
	//glColor3f(0.850, 0.490, 0.756);
	//glColor3f(0.192, 0.576, 0.705);
	//glColor3ub(109, 109, 115);
    //glColor3ub(191, 191, 191);
    //glColor3f(0.192, 0.576, 0.705);
    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1+48, 360+20+3+35);
    glVertex2i(330+20-2+48, 360+20+3+35);
    glVertex2i(330+20-2+48, 360+40-2+35);
    glVertex2i(330+5+1+48, 360+40-2+35);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5+48, 360+20+50+35);
    glVertex2i(330+20+48, 360+20+50+35);
    glVertex2i(330+20+48, 360+40+50+35);
    glVertex2i(330+5+48, 360+40+50+35);
    glEnd();
    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1+48, 360+20+3+50+35);
    glVertex2i(330+20-2+48, 360+20+3+50+35);
    glVertex2i(330+20-2+48, 360+40-2+50+35);
    glVertex2i(330+5+1+48, 360+40-2+50+35);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(330+5+48, 360+20+50+50+35);
    glVertex2i(330+20+48, 360+20+50+50+35);
    glVertex2i(330+20+48, 360+40+50+50+35);
    glVertex2i(330+5+48, 360+40+50+50+35);
    glEnd();
    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(330+5+1+48, 360+20+3+50+50+35);
    glVertex2i(330+20-2+48, 360+20+3+50+50+35);
    glVertex2i(330+20-2+48, 360+40-2+50+50+35);
    glVertex2i(330+5+1+48, 360+40-2+50+50+35);
    glEnd();
///
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20+48, 360+20+35);
    glVertex2i(390-5+48, 360+20+35);
    glVertex2i(390-5+48, 360+40+35);
    glVertex2i(390-20+48, 360+40+35);
    glEnd();
    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1+48, 360+20+3+35);
    glVertex2i(390-5-2+48, 360+20+3+35);
    glVertex2i(390-5-2+48, 360+40-2+35);
    glVertex2i(390-20+1+48, 360+40-2+35);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20+48, 360+20+50+35);
    glVertex2i(390-5+48, 360+20+50+35);
    glVertex2i(390-5+48, 360+40+50+35);
    glVertex2i(390-20+48, 360+40+50+35);
    glEnd();
    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1+48, 360+20+3+50+35);
    glVertex2i(390-5-2+48, 360+20+3+50+35);
    glVertex2i(390-5-2+48, 360+40-2+50+35);
    glVertex2i(390-20+1+48, 360+40-2+50+35);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(390-20+48, 360+20+50+50+35);
    glVertex2i(390-5+48, 360+20+50+50+35);
    glVertex2i(390-5+48, 360+40+50+50+35);
    glVertex2i(390-20+48, 360+40+50+50+35);
    glEnd();
    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(390-20+1+48, 360+20+3+50+50+35);
    glVertex2i(390-5-2+48, 360+20+3+50+50+35);
    glVertex2i(390-5-2+48, 360+40-2+50+50+35);
    glVertex2i(390-20+1+48, 360+40-2+50+50+35);
    glEnd();
///**
    glColor3f(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-3+48, 360+20+3-15+50+35);
    glVertex2i(360+3+48, 360+20+3-15+50+35);
    glVertex2i(360+3+48, 360+40-2+5+50+35);
    glVertex2i(360-3+48, 360+40-2+5+50+35);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(360-3+1+48, 360+20+3-15+50+3+35);
    glVertex2i(360+3-1+48, 360+20+3-15+50+3+35);
    glVertex2i(360+3-1+48, 360+40-2+5+50-2+35);
    glVertex2i(360-3+1+48, 360+40-2+5+50-2+35);
    glEnd();

    glColor3f(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(360-3+48, 360+20+3-15+50+50+35);
    glVertex2i(360+3+48, 360+20+3-15+50+50+35);
    glVertex2i(360+3+48, 360+40-2+5+50+50+35);
    glVertex2i(360-3+48, 360+40-2+5+50+50+35);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(360-3+1+48, 360+20+3-15+50+50+3+35);
    glVertex2i(360+3-1+48, 360+20+3-15+50+50+3+35);
    glVertex2i(360+3-1+48, 360+40-2+5+50+50-2+35);
    glVertex2i(360-3+1+48, 360+40-2+5+50+50-2+35);
    glEnd();
}

void Bird()
{
    glPushMatrix();
    glTranslatef(_run1, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208);
    glVertex2f(10*4,80*4+500);
    glVertex2f(11*4,79*4+500);
    glVertex2f(12*4,78*4+500);
    glVertex2f(16*4,77*4+500);
    glVertex2f(19*4,79*4+500);
    glVertex2f(20.1*4,80*4+500);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 217);
    glVertex2f(17.5*4,80*4+500);
    glVertex2f(15*4,80*4+500);
    glVertex2f(14*4,84*4+500);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(242, 242, 242);
    glVertex2f(17.5*4,80*4+500);
    glVertex2f(14.4*4,80*4+500);
    glVertex2f(12*4,83*4+500);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(225, 225, 208);
    glVertex2f(70,820);
    glVertex2f(76,820);
    glVertex2f(75,825);
    glVertex2f(71,825);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208);
    glVertex2f(10*4+50,80*4+500);
    glVertex2f(11*4+50,79*4+500);
    glVertex2f(12*4+50,78*4+500);
    glVertex2f(16*4+50,77*4+500);
    glVertex2f(19*4+50,79*4+500);
    glVertex2f(20.1*4+50,80*4+500);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 217);
    glVertex2f(17.5*4+50,80*4+500);
    glVertex2f(15*4+50,80*4+500);
    glVertex2f(14*4+50,84*4+500);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(242, 242, 242);
    glVertex2f(17.5*4+50,80*4+500);
    glVertex2f(14.4*4+50,80*4+500);
    glVertex2f(12*4+50,83*4+500);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(225, 225, 208);
    glVertex2f(70+50,820);
    glVertex2f(76+50,820);
    glVertex2f(75+50,825);
    glVertex2f(71+50,825);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208);
    glVertex2f(10*4+50-30,80*4+500-30);
    glVertex2f(11*4+50-30,79*4+500-30);
    glVertex2f(12*4+50-30,78*4+500-30);
    glVertex2f(16*4+50-30,77*4+500-30);
    glVertex2f(19*4+50-30,79*4+500-30);
    glVertex2f(20.1*4+50-30,80*4+500-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 217);
    glVertex2f(17.5*4+50-30,80*4+500-30);
    glVertex2f(15*4+50-30,80*4+500-30);
    glVertex2f(14*4+50-30,84*4+500-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(242, 242, 242);
    glVertex2f(17.5*4+50-30,80*4+500-30);
    glVertex2f(14.4*4+50-30,80*4+500-30);
    glVertex2f(12*4+50-30,83*4+500-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(225, 225, 208);
    glVertex2f(70+50-30,820-30);
    glVertex2f(76+50-30,820-30);
    glVertex2f(75+50-30,825-30);
    glVertex2f(71+50-30,825-30);
    glEnd();
    glPopMatrix();
///
    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208);
    glVertex2f(10*4-40,80*4+500-20);
    glVertex2f(11*4-40,79*4+500-20);
    glVertex2f(12*4-40,78*4+500-20);
    glVertex2f(16*4-40,77*4+500-20);
    glVertex2f(19*4-40,79*4+500-20);
    glVertex2f(20.1*4-40,80*4+500-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 217);
    glVertex2f(17.5*4-40,80*4+500-20);
    glVertex2f(15*4-40,80*4+500-20);
    glVertex2f(14*4-40,84*4+500-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(242, 242, 242);
    glVertex2f(17.5*4-40,80*4+500-20);
    glVertex2f(14.4*4-40,80*4+500-20);
    glVertex2f(12*4-40,83*4+500-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(225, 225, 208);
    glVertex2f(70-40,820-20);
    glVertex2f(76-40,820-20);
    glVertex2f(75-40,825-20);
    glVertex2f(71-40,825-20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208);
    glVertex2f(10*4-40+60,80*4+500-20);
    glVertex2f(11*4-40+60,79*4+500-20);
    glVertex2f(12*4-40+60,78*4+500-20);
    glVertex2f(16*4-40+60,77*4+500-20);
    glVertex2f(19*4-40+60,79*4+500-20);
    glVertex2f(20.1*4-40+60,80*4+500-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 217);
    glVertex2f(17.5*4-40+60,80*4+500-20);
    glVertex2f(15*4-40+60,80*4+500-20);
    glVertex2f(14*4-40+60,84*4+500-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(242, 242, 242);
    glVertex2f(17.5*4-40+60,80*4+500-20);
    glVertex2f(14.4*4-40+60,80*4+500-20);
    glVertex2f(12*4-40+60,83*4+500-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(225, 225, 208);
    glVertex2f(70-40+60,820-20);
    glVertex2f(76-40+60,820-20);
    glVertex2f(75-40+60,825-20);
    glVertex2f(71-40+60,825-20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208);
    glVertex2f(10*4-100,80*4+500-20);
    glVertex2f(11*4-100,79*4+500-20);
    glVertex2f(12*4-100,78*4+500-20);
    glVertex2f(16*4-100,77*4+500-20);
    glVertex2f(19*4-100,79*4+500-20);
    glVertex2f(20.1*4-100,80*4+500-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 217);
    glVertex2f(17.5*4-100,80*4+500-20);
    glVertex2f(15*4-100,80*4+500-20);
    glVertex2f(14*4-100,84*4+500-20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(242, 242, 242);
    glVertex2f(17.5*4-100,80*4+500-20);
    glVertex2f(14.4*4-100,80*4+500-20);
    glVertex2f(12*4-100,83*4+500-20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(225, 225, 208);
    glVertex2f(70-100,820-20);
    glVertex2f(76-100,820-20);
    glVertex2f(75-100,825-20);
    glVertex2f(71-100,825-20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208);
    glVertex2f(10*4-100+30,80*4+500-20-30);
    glVertex2f(11*4-100+30,79*4+500-20-30);
    glVertex2f(12*4-100+30,78*4+500-20-30);
    glVertex2f(16*4-100+30,77*4+500-20-30);
    glVertex2f(19*4-100+30,79*4+500-20-30);
    glVertex2f(20.1*4-100+30,80*4+500-20-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(217, 217, 217);
    glVertex2f(17.5*4-100+30,80*4+500-20-30);
    glVertex2f(15*4-100+30,80*4+500-20-30);
    glVertex2f(14*4-100+30,84*4+500-20-30);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(242, 242, 242);
    glVertex2f(17.5*4-100+30,80*4+500-20-30);
    glVertex2f(14.4*4-100+30,80*4+500-20-30);
    glVertex2f(12*4-100+30,83*4+500-20-30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(225, 225, 208);
    glVertex2f(70-100+30,820-20-30);
    glVertex2f(76-100+30,820-20-30);
    glVertex2f(75-100+30,825-20-30);
    glVertex2f(71-100+30,825-20-30);
    glEnd();
    glPopMatrix();
}
void house11()
{
    glColor3ub(102, 0, 0);
	glBegin(GL_POLYGON);
    glVertex2i(20+210, 545-10);
    glVertex2i(40+210, 545-10);
	glVertex2i(30+210, 560-10);
	glEnd();
	glColor3ub(0, 204, 204);
	glBegin(GL_QUADS);
	glVertex2i(25+210, 545-10);
	glVertex2i(35+210, 545-10);
	glVertex2i(35+210, 530-10);
    glVertex2i(25+210, 530-10);
	glEnd();
	glColor3ub(102, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(22+210, 530-10);
	glVertex2i(40-2+210, 530-10);
	glVertex2i(40-2+210, 525-10);
    glVertex2i(22+210, 525-10);
	glEnd();
///Door
    glColor3ub(1, 51, 102);
	glBegin(GL_QUADS);
    glVertex2i(25+3+210, 540-10);
	glVertex2i(35-3+210, 540-10);
	glVertex2i(35-3+210, 530-10);
    glVertex2i(25+3+210, 530-10);
	glEnd();
}
void grass()
{
    glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
    glVertex2i(90, 370);
	glVertex2i(92, 370);
	glVertex2i(92-15, 380);
    glVertex2i(90-15, 380);
    glVertex2i(90, 370);
	glVertex2i(92, 370);
	glVertex2i(92-7, 385);
    glVertex2i(90-7, 385);
    glVertex2i(90, 370);
	glVertex2i(92, 370);
	glVertex2i(92, 385);
    glVertex2i(90, 385);
    glVertex2i(90, 370);
	glVertex2i(92, 370);
	glVertex2i(92+7, 385);
    glVertex2i(90+7, 385);
    glVertex2i(90, 370);
	glVertex2i(92, 370);
	glVertex2i(92+15, 380);
    glVertex2i(90+15, 380);
///
    glVertex2i(90-35, 370);
	glVertex2i(92-35, 370);
	glVertex2i(92-15-35, 380);
    glVertex2i(90-15-35, 380);
    glVertex2i(90-35, 370);
	glVertex2i(92-35, 370);
	glVertex2i(92-7-35, 385);
    glVertex2i(90-7-35, 385);
    glVertex2i(90-35, 370);
	glVertex2i(92-35, 370);
	glVertex2i(92-35, 385);
    glVertex2i(90-35, 385);
    glVertex2i(90-35, 370);
	glVertex2i(92-35, 370);
	glVertex2i(92+7-35, 385);
    glVertex2i(90+7-35, 385);
    glVertex2i(90-35, 370);
	glVertex2i(92-35, 370);
	glVertex2i(92+15-35, 380);
    glVertex2i(90+15-35, 380);
///
    glVertex2i(90+100, 370);
	glVertex2i(92+100, 370);
	glVertex2i(92-15+100, 380);
    glVertex2i(90-15+100, 380);
    glVertex2i(90+100, 370);
	glVertex2i(92+100, 370);
	glVertex2i(92-7+100, 385);
    glVertex2i(90-7+100, 385);
    glVertex2i(90+100, 370);
	glVertex2i(92+100, 370);
	glVertex2i(92+100, 385);
    glVertex2i(90+100, 385);
    glVertex2i(90+100, 370);
	glVertex2i(92+100, 370);
	glVertex2i(92+7+100, 385);
    glVertex2i(90+7+100, 385);
    glVertex2i(90+100, 370);
	glVertex2i(92+100, 370);
	glVertex2i(92+15+100, 380);
    glVertex2i(90+15+100, 380);
	glEnd();
}
void tree2()
{
   glPushMatrix();
   glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(169, 390);
    glVertex2i(171, 390);
    glVertex2i(171, 400+20);
    glVertex2i(169, 400+20);
   glEnd();
   glPopMatrix();

   glPushMatrix();
    glTranslatef(170,430, 0);
    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
   glEnd();
   glPopMatrix();

   glPushMatrix();
    glTranslatef(170,420, 0);
    glBegin(GL_POLYGON);
    glColor3ub(50,205,50);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y);
	}
   glEnd();
   glPopMatrix();
}
void Night_Boat()
{
    ///Left Stopping Boat
    glColor3f(0.423, 0.329, 0.588);
    glBegin(GL_QUADS);
    glVertex2i(70, 90);
    glVertex2i(50, 110);
	glVertex2i(130, 110);
	glVertex2i(110, 90);
	glEnd();

	glColor3f(0.329, 0.517, 0.588);
    glBegin(GL_QUADS);
    glVertex2i(90, 130);
    glVertex2i(110, 130);
	glVertex2i(110, 110);
	glVertex2i(90, 110);
	glEnd();

    glColor3ub (0,0,0);
    glPointSize(5);
    glBegin(GL_QUADS);
    glVertex2i(60, 140);
    glVertex2i(62, 140);
    glVertex2i(62, 80);
    glVertex2i(60, 80);
    glEnd();


	///Right Stopping Boat
	glColor3f(1, 0, 1);
    glBegin(GL_QUADS);
    glVertex2i(820, 90);
    glVertex2i(800, 110);
	glVertex2i(880, 110);
	glVertex2i(860, 90);
	glEnd();

	glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2i(820, 130);
    glVertex2i(840, 130);
	glVertex2i(840, 110);
	glVertex2i(820, 110);
	glEnd();

	glColor3ub (0,0,0);
    glPointSize(5);
    glBegin(GL_QUADS);
    glVertex2i(870, 140);
    glVertex2i(872, 140);
    glVertex2i(872, 80);
    glVertex2i(870, 80);
	glEnd();


    ///Right Mid Stopping Boat
	glColor3f(255,255,0);
    glBegin(GL_QUADS);
    glVertex2i(620, 90);
    glVertex2i(600, 110);
	glVertex2i(680, 110);
	glVertex2i(660, 90);
	glEnd();

	glColor3f(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(620, 130);
    glVertex2i(640, 130);
	glVertex2i(640, 110);
	glVertex2i(620, 110);
	glEnd();

	glColor3ub (0,0,0);
    glPointSize(5);
    glBegin(GL_QUADS);
    glVertex2i(670, 140);
    glVertex2i(672, 140);
    glVertex2i(672, 80);
    glVertex2i(670, 80);
	glEnd();

	///Left Mid Stopping Boat
	glColor3ub (255,255,255);
    glBegin(GL_QUADS);
    glVertex2i(270, 90);
    glVertex2i(250, 110);
	glVertex2i(330, 110);
	glVertex2i(310, 90);
	glEnd();

	glColor3ub (255,255,0);
    glBegin(GL_QUADS);
    glVertex2i(290, 130);
    glVertex2i(310, 130);
	glVertex2i(310, 110);
	glVertex2i(290, 110);
	glEnd();

	glColor3ub (0,0,0);
    glPointSize(5);
    glBegin(GL_QUADS);
    glVertex2i(260, 140);
    glVertex2i(262, 140);
    glVertex2i(262, 80);
    glVertex2i(260, 80);
    glEnd();


}
void night_color()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4ub(0, 0, 0, 950);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(1000, 0);
    glVertex2i(1000, 1000);
    glVertex2i(0, 1000);
    glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3b(1,0,0);
    sky();
    land();

    Hill();
    sun();
    Cloud1();
    Cloud2();
    Cloud3();
    Cloud4();
    Cloud5();



    house1();
    house2();
    house3();
    house4();
    house10();
    house11();
    LeftRoadTree();

    HillTree();
    HillTree2();
    HillTree3();
    railtree();

    house5();
    house6();
    house7();
    house8();
    house9();

    tree1();

    building7();
    building6();
    building4();
    hospital();
    building2();
    building1();
    building3();
    building5();

    school();
    flag();
    road();
    RoadLeftLamp();
    car1();
    car2();
    RoadRightLamp();


    Net1();

    Bird();
    grass();
    tree2();

    glFlush();
}
void Night_Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3b(1,0,0);
    sky();
    land();

    Hill();




    house1();
    house2();
    house3();
    house4();
    house10();
    house11();
    LeftRoadTree();

    HillTree();
    HillTree2();
    HillTree3();

    house5();
    house6();
    house7();
    house8();
    house9();

    tree1();
    railtree();

    building7();
    building6();
    building4();
    hospital();
    building2();
    building1();
    building3();
    building5();

    school();
    flag();
    road();
    RoadLeftLamp();
    car1();
    car2();
    RoadRightLamp();


    Net1();

    grass();
    tree2();
    moon();
    star1();
    star2();
    star3();
    star4();
    star5();
    star6();



    night_color();

    glFlush();
}




void update(int value)
{

    _run += 1.0f;
	if (_run > 1000)
    {
        _run -= 1700;
    }

    _run1 += 1.0f;
	if (_run1 > 1000)
    {
        _run1 -= 1200;
    }

    _run2 += 3.5f;
	if (_run2 > 1000)
    {
        _run2 -= 1300;
    }

     _run3 += 0.8f;
	if (_run3 > 1000)
    {
        _run3 -= 1700;
    }

     car1_speed += 1.5f;
	if (car1_speed > 1000)
    {
        car1_speed -= 1100;
    }

    car2_speed += 2.0f;
	if (car2_speed > 1000)
    {
        car2_speed -= 1100;
    }

    if(onOff){
	_ang_tri += 2.5f;
	if (_ang_tri > 1000){
		_ang_tri = 1300;
	}
	 }

	 _angle += 2.0;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);

}



int main(int argc,char **argv)
{
    cout<<endl << "*********** Natural View  ********************" << endl << endl;


    cout<<"Press r : For Rain  "<<endl<<endl;
    cout<<"Press e : For Stop Rain "<<endl<<endl;

    cout<< "Press n : For Night"<<endl<<endl;
    cout<<"Press b : For Day"<<endl<<endl;

    cout<<"Press Esc : For Exit Windows"<<endl<<endl;



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Natural View ");

	glutDisplayFunc(display);
	glutTimerFunc(25, update, 0);
    init();


	glutMainLoop();
	return 0;
}
