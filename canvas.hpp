#include <iostream>
#include <cmath>
#include <vector>
#include <GL/freeglut.h>


struct Point{
	int x, y;
};

std::vector<std::vector<Point>> strokes;
std::vector<Point> currentStroke;
bool isDrawing = false;

int currentColor = 0;
GLfloat colors[][3] = {
	{0.0, 0.0, 0.0},
	{0.0, 0.0, 1.0}
	{1.0, 0.0, 0.0},
};
int currentThickness = 0;
GLfloat thickness[] = {1.0, 3.0, 5.0};

void drawPoint(int x, int y){
	glPointSize(thickness[currentThickness]);
	glBegin(GL_POINTS);
	glColor3fv(colors[currentColor]);
	glVertex2f(x, y);
	glEnd();
}

void drawStroke(const std::vector<Point>& stroke){
	for(const Point& p : stroke){
		drawPoint(p.x, p.y);
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	for(const auto& stroke : strokes){
		drawStroke(stroke);
	}

	if(isDrawing){
		drawStroke(currentStroke);
	}
	glFlush();
}