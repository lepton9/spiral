#include <windows.h>
#include <GL/glut.h>

int winW = 1000;
int winH = 1000;

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

void square(float x, float y, float w) {
	line(x,y, x+w,y);
	line(x+w,y, x+w,y+w);
	line(x+w,y+w, x,y+w);
	line(x,y+w, x,y);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//line(0, 0, 1.0f, 1.0f);
	//line(0.5, 0.5, 0.5, 1.0);

	square(0,0, 0.5f);

	glutSwapBuffers();

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
