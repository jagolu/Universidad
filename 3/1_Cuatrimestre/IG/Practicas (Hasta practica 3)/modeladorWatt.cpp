#include "modeladorWatt.h"
modeladorWatt::modeladorWatt(){}
modeladorWatt::modeladorWatt(float size, int veces):b(size, veces), pp(size, veces){}
void modeladorWatt::draw_points(float n, int giro){
	glPushMatrix();
	glTranslatef(0,7,0);
	glRotatef(giro,0,1,0);
	pp.draw_points(n);
	glPopMatrix();

	glPushMatrix();
	b.draw_points(n, giro);
	glPopMatrix();
}

void modeladorWatt::draw_edges(float n, int giro){
	glPushMatrix();
	glTranslatef(0,7,0);
	glRotatef(giro,0,1,0);
	pp.draw_edges(n);
	glPopMatrix();

	glPushMatrix();
	b.draw_edges(n, giro);
	glPopMatrix();
}

void modeladorWatt::draw_solid(float n, int giro){
	glPushMatrix();
	glTranslatef(0,7,0);
	glRotatef(giro,0,1,0);
	pp.draw_solid(n);
	glPopMatrix();

	glPushMatrix();
	b.draw_solid(n, giro);
	glPopMatrix();
}

void modeladorWatt::draw_solid_chess(float n, int giro){
	glPushMatrix();
	glTranslatef(0,7,0);
	glRotatef(giro,0,1,0);
	pp.draw_solid_chess(n);
	glPopMatrix();

	glPushMatrix();
	b.draw_solid_chess(n, giro);
	glPopMatrix();
}
