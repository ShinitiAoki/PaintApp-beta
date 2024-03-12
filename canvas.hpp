#include <iostream>
#include <cmath>
#include <vector>
#include <GL/freeglut.h>


bool isDrawing;
int iX, iY;
GLfloat currentColor[3] = {0.047, 0.079, 0.079};
GLfloat LineWidth = 1.0;

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}


void handle_motion(GLint x, GLint y) {
    std::cout << "Mouse is at (" << x << ", " << y << ")" << std::endl;
    if(isDrawing) {
        glColor3f(currentColor[0], currentColor[1], currentColor[2]); // Set drawing color to black
		glLineWidth(LineWidth);
        glBegin(GL_LINES);
        glVertex2i(iX, iY);
        glVertex2i(x, 480 - y); // Invert Y-coordinate
        glEnd();
        glFlush(); // Flush OpenGL buffer
        iX = x;
        iY = 480 - y; // Invert Y-coordinate
    }
}

void handle_menu(GLint op){ }
void handle_sub2(GLint choice){ 
	switch (choice)
	{
	case 1:
		currentColor[0] = 0.1;
		currentColor[1] = 0.1;
		currentColor[2] = 0.1;
		std::cout << "new color value: R:" << currentColor[0] << " G:" << currentColor[1] << " B:" << currentColor[2] << std::endl;
		break;
	case 2:
		currentColor[0] = 1.0;
		currentColor[1] = 0.0;
		currentColor[2] = 0.0;
		std::cout << "new color value: R:" << currentColor[0] << " G:" << currentColor[1] << " B:" << currentColor[2] << std::endl;

		break;
	case 3:
		currentColor[0] = 0.0;
		currentColor[1] = 0.0;
		currentColor[2] = 1.0;
		std::cout << "new color value: R:" << currentColor[0] << " G:" << currentColor[1] << " B:" << currentColor[2] << std::endl;

		break;
	default:
		break;
	}
}
void handle_sub1(GLint choice){//width_handler
	switch (choice)
	{
	case 1:
		LineWidth = 1.0;
		break;
	case 2:
		LineWidth = 4.0;
		break;
	case 3:
		LineWidth = 7.0;
		break;
	default:
		break;
	}
}
void create_menu(){
	GLint menu, submenu1, submenu2;
	submenu1 = glutCreateMenu(handle_sub1);
	glutAddMenuEntry("1px", 1);
	glutAddMenuEntry("3px", 2);
	glutAddMenuEntry("7px", 3);

	submenu2 = glutCreateMenu(handle_sub2);
	glutAddMenuEntry("black", 1);
	glutAddMenuEntry("red", 2);
	glutAddMenuEntry("blue", 3);
	menu = glutCreateMenu(handle_menu);
	glutAddSubMenu("Color", submenu2);
	glutAddSubMenu("Width", submenu1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
} 

void handle_click(GLint button, GLint action, GLint Xcoord, GLint Ycoord)
{
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN){
		std::cout << "Mouse clicked at (" << Xcoord << ", " << Ycoord << ")" << std::endl;
		isDrawing = true;
		iX = Xcoord;
		iY = 480 - Ycoord; // Invert Y-coordinate
	}
	else if (button == GLUT_LEFT_BUTTON && action == GLUT_UP){
		isDrawing = false;
	}
	else if(button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN){
		
		create_menu();
	}
} 

void keyboard(GLubyte key, GLint x, GLint y){
	if(key == 'd' || key == 'D'){
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
	else if(key == 'e' || key == 'E'){
		currentColor[0] = 1.0;
		currentColor[1] = 1.0;
		currentColor[2] = 1.0;
		LineWidth = 20.0;
		std::cout << "erase mode" << std::endl;
	}

}

void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0); // cor de fundo branco
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // janela com resolução de 640 por 480
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}