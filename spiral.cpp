#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <ctime>

int winW = 400;
int winH = 400;

struct point {
	float x ,y;
};

void line(float x0, float y0, float x1, float y1) {
	glBegin(GL_LINES);
	    glVertex2f(x0, y0);
	    glVertex2f(x1, y1);
	glEnd();
}

void rect(
	float x0, float y0, float x1, float y1, 
	float x2, float y2, float x3, float y3
	) {
	line(x0, y0, x1, y1);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x0, y0);
}


point rotatePoint(float x, float y, float angle) {
	point s;
	s.x = x*cos(angle) - y*sin(angle);
	s.y = y*cos(angle) + x*sin(angle);
	return s;
}

void square(float x, float y, float w, float angle = 0) {
	point p1 = rotatePoint(x,y,angle);
	point p2 = rotatePoint(x+w,y,angle);
	line(p1.x,p1.y, p2.x,p2.y);

	p1 = rotatePoint(x+w,y+w,angle);
	line(p2.x,p2.y, p1.x,p1.y);

	p2 = rotatePoint(x,y+w,angle);
	line(p1.x,p1.y, p2.x,p2.y);

	p1 = rotatePoint(x,y,angle);
	line(p2.x,p2.y, p1.x,p1.y);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
		glVertex2f(0,0);
	glEnd();

	float w = 0.1f;
	float r = M_PI;

	float wd = 0.0f;
	float ad = 0.0f;

	for (int i=0; i < 400; i++) {
		square(-w/2,-w/2, w, r);

		w =+ wd;
		r += M_PI/30 - ad;

		if (ad < M_PI/40) ad += 0.0005f;
		wd += 0.01f;

		Sleep(50);
		glutSwapBuffers();
	}


}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(winW, winH);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Spiral");

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
