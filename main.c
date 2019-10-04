#include <GL/glut.h>

void desenhar_linha(int x1, int y1, int x2, int y2)
{
	int dx, dy, incE, incNE, d, x, y;
	if (x1 > x2) {
		int tmp;
		tmp = x1;
		x1 = x2;
		x2 = tmp;
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
	glBegin(GL_POINTS);
	dx = x2 - x1;
	dy = y2 - y1;
	d = 2 * dy - dx;
	incE = 2 * dy;
	incNE = 2 * (dy - dx);
	x = x1;
	y = y1;
	glVertex2i(x, y);
	while (x < x2) {
		if (d <= 0) {
			d = d + incE;
			x = x + 1;
		}	
		else {
			d = d + incNE;
			x = x + 1;
			y = y + 1;
		}
		glVertex2i(x, y);
	}
	glEnd();
}

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0); 
	glMatrixMode(GL_PROJECTION);  
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);  
	glColor3f(1.0, 0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(180, 145);
	glVertex2i(10, 15); 
	glEnd(); 

	glColor3f(0.0, 0.0,1.0);
	desenhar_linha(10, 10, 180, 140);

	glColor3f(0.0, 0.8,0.0);
	desenhar_linha(180, 140, 10, 10);

	glColor3f(0.0, 0.0,0.0);
	// desenhar_linha(10, 140, 180, 10);

	glBegin(GL_LINES);
	glVertex2i(10, 140);
	glVertex2i(180, 10); 
	glEnd(); 

	desenhar_linha(20, 140, 190, 10);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition(50, 100); 
	glutInitWindowSize(400, 300);  
	glutCreateWindow("Linha");  
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}
