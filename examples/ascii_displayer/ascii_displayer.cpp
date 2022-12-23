#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GL/glut.h>
#include<zqVisualization/visualization_opengl_utils.h>
#include<zqVisualization/visualization_vector_opengl_utils.h>
#include<zqVisualization/visualization_glut_window.h>
#include<zqVisualization/visualization_fbo.h>
#include<zqVisualization/visualization_ascii_displayer.h>
#include<zqBasicUtils/utils_timer.h>

zq::opengl::DemoWindowManager	manager;
zq::opengl::DemoWindow3D		win3d;
zq::opengl::AsciiDisplayer		ascii_disp;

void draw(){

	zq::opengl::drawXYZAxis();

	glDisable(GL_LIGHTING);
	glColor3f(0, 1, 1);

	for(int j=0; j<16; j++)
		for(int i=0; i<16; i++){
			ascii_disp.Draw(j*16+i, i, j, i+0.5, j+1);
		}

	glEnable(GL_LIGHTING);
}

int main(){
	win3d.CreateGLUTWindow();
	win3d.SetDraw(draw);

	ascii_disp.Setup8x16();


	manager.AddIdleFunc(win3d.idleFunc);
	manager.EnterMainLoop();
}