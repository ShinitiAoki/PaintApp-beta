
#include "canvas.hpp"


int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480); // Especifica as dimensões da janela em pixels.
	glutInitWindowPosition (500, 100); 
	glutCreateWindow ("Noteapp"); 
	myInit(); // Rotina que implementa as configurações iniciais do programa.
	glutDisplayFunc(display);
	glutMouseFunc(handle_click);
	glutMotionFunc(handle_motion);
	glutKeyboardFunc(keyboard);
	glutMainLoop( ); 

	return 0;

}