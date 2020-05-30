#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/freeglut.h>

GLint a=647,b=-583,c=190,flag=0,traffic_regulator=1,control_keyl,control_keyr;
GLfloat red=0,blue=1,green=.3;
int state=1,pos=1,score=0;

void setFont();
void *currentfont;
void drawstring();
void frontsreen();
void gamescreen();
void box();
void road();
void outerbox();
void box();
void tile();
void tile1();
void tile2();
void update();
void mydisplay();
void gameover();
//void keyboard_callback(int,int,int);

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
 
	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void frontscreen(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);/*background for cover page*/
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(370.0,640.0,0.0,"BAPUJI INSTITUTE OF ENGINEERING & TECHNOLOGY");
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(600.0,615.0,0.0,"DAVANGERE");
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(345,590,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(580,530,0.0,"PROJECT NAME");
glColor3f(0.5,0.0,0.5);
drawstring(600,480,0.0,"FLAPPY BOX");
box();
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(600,310,0.0,"DEVELOPER:");
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(590,270,0.0,"ANIL KAUNDAL");
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(535,100,0.0,"PRESS               TO START");
glColor3f(1,0,0);
drawstring(612,100,0.0,"ENTER");
outerbox();
glFlush();
}

void update(int value)
{
	for(int i=0;i<=50;i++)
	{
		if((a==(50-i)||b==(50+i))&&c==190)
		{
			gameover();
		}
		}
	switch(state)
	{
		case 1:
			if(b<647&&a>-583)
			{
				a=a-20;
				b=b+20;
			}
			else
				state=-1;
		break;
		case -1:
			if(a<647&&b>-583)
			{
				a=a+20;
				b=b-20;
			}
			else
				state=1;
		break;
		default:break;
	}
glutPostRedisplay();
}

void gameover()
{
char _score[10];
itoa(score,_score,10);
char text[50]="Your Score:";
strcat(text,_score);
MessageBox(NULL,text,"GAME OVER",0);
exit(0);
}

void gamescreen()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(1.0, 1.0, 1.0, 0.0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
outerbox();
glutTimerFunc(50,update,0);
road();
tile();
tile1();
tile2();
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(565.0,670.0,0.0,"HOW TO PLAY:");
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(240.0,640.0,0.0,"Press spacebar to jump the tile. When the tile go through a barrier, you loose score!");
glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
drawstring(550.0,40.0,0.0,"EXIT:	 Press        ");
glColor3f(1,0,0);
drawstring(615.0,40.0,0.0,"   		  		  'ENTER'");
glFlush();
}

void outerbox()
{
	glPushMatrix();
	glBegin(GL_LINE_LOOP); 
	glColor3f(1,0,0);
    glVertex2i(1335, 20); 
    glVertex2i(10, 20); 
    glVertex2i(10, 700); 
    glVertex2i(1335, 700); 
    glEnd(); 
	glPopMatrix();
}

void box()
{
glPushMatrix();
glScaled(16.0,50.0,0.0);
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
glVertex3f(39.0, 7.0, 0.0);
glVertex3f(45.0, 7.0, 0.0);
glVertex3f(45.0, 9.0, 0.0);
glVertex3f(39.0, 9.0, 0.0);
glEnd();
glPopMatrix();
}

void tile()
{
glPushMatrix();
glTranslated(50.0,c,0.0);
glScaled(16.0,50.0,0.0);
glBegin(GL_POLYGON);
glColor3f(1.0,0.5,0.0);
glVertex2i(37.0, 1.0);
glVertex2i(43.0, 1.0);
glVertex2i(43.0, 3.0);
glVertex2i(37.0, 3.0);
glEnd();
glPopMatrix();
}

void tile1()
{
glPushMatrix();
glTranslated(b,190.0,0.0);
glScaled(16.0,50.0,0.0);
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
glVertex2i(37.0, 1.0);
glVertex2i(43.0, 1.0);
glVertex2i(43.0, 3.0);
glVertex2i(37.0, 3.0);
glEnd();
glPopMatrix();
}


void tile2()
{
glPushMatrix();
glTranslated(a,190.0,0.0);
glScaled(16.0,50.0,0.0);
glBegin(GL_POLYGON);
glColor3f(0.5,0.5,0.5);
glVertex2i(37.0, 1.0);
glVertex2i(43.0, 1.0);
glVertex2i(43.0, 3.0);
glVertex2i(37.0, 3.0);
glEnd();
glPopMatrix();
}

void road()
{
glPushMatrix();
glScaled(40.0,50.0,0.0);
glBegin(GL_POLYGON);
glColor3f(0.5,1.0,0.0);
glVertex2f(0,5);
glVertex2f(40,5);
glVertex2f(40,4);
glVertex2f(0,4);
glEnd();
glPopMatrix();
}

void myKeyboard( unsigned char key, int x, int y )
{
switch(key)
{
	case 13:
		if(flag==1)
		{
			flag=2;
			mydisplay();
		}
		if(flag==0) //Ascii of 'enter' key is 13
		{
			flag=1;mydisplay();
		}	
	break;
	case 32:
		if(pos==1)
		{
			c=c+110;
			pos=-1;
		}
		else
		{
			c=c-110;
			pos=1;
			score++;
			glutPostRedisplay();
		}
	break;
	default:break;
}
}

void mydisplay(void)
{
glutSetCursor(GLUT_CURSOR_NONE);	
glClear(GL_COLOR_BUFFER_BIT);
if(flag==0)
	frontscreen();
if(flag==1)
	gamescreen();
if(flag==2)
	gameover();
	glutSwapBuffers();
}

void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1346.0,0.0,728.0);
}

int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1346,728);
glutInitWindowPosition(0,0);
glutCreateWindow("Flappy Box");
glutDisplayFunc(mydisplay);
glutKeyboardFunc(myKeyboard);
myinit();
glutMainLoop();
return 0;
}
