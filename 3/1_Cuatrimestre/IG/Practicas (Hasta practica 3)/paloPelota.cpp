#include "paloPelota.h"
paloPelota::paloPelota(){}
paloPelota::paloPelota(float size, int veces):e(size, veces), c1(size,veces), c2(size, veces){}
void paloPelota::draw_points(float n){
	glPushMatrix();
	glTranslatef(0,-5.5,0);
	glScalef(0.5,11,0.5);
	c1.draw_points();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-12,0);
	glScalef(1,1,1);
	e.draw_points();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3,-5.25,0);
	glRotatef(90+(n*12.8), 0, 0, 1);
	glTranslatef(0,-2.25,0);
	glScalef(0.1,5.5,0.1);
	c2.draw_points();
	glPopMatrix();
}

void paloPelota::draw_edges(float n){
	glPushMatrix();
	glTranslatef(0,-5.5,0);
	glScalef(0.5,11,0.5);
	c1.draw_edges();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-12,0);
	glScalef(1,1,1);
	e.draw_edges();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3,-5.25,0);
	glRotatef(90+(n*12.8), 0, 0, 1);
	glTranslatef(0,-2.25,0);
	glScalef(0.1,5.5,0.1);
	c2.draw_edges();
	glPopMatrix();
}

void paloPelota::draw_solid(float n){
	glPushMatrix();
	glTranslatef(0,-5.5,0);
	glScalef(0.5,11,0.5);
	c1.draw_solid();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-12,0);
	glScalef(1,1,1);
	e.draw_solid();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3,-5.25,0);
	glRotatef(90+(n*12.8), 0, 0, 1);
	glTranslatef(0,-2.25,0);
	glScalef(0.1,5.5,0.1);
	c2.draw_solid();
	glPopMatrix();
}

void paloPelota::draw_solid_chess(float n){
	glPushMatrix();
	glTranslatef(0,-5.5,0);
	glScalef(0.5,11,0.5);
	c1.draw_solid_chess();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-12,0);
	glScalef(1,1,1);
	e.draw_solid_chess();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3,-5.25,0);
	glRotatef(90+(n*12.8), 0, 0, 1);
	glTranslatef(0,-2.25,0);
	glScalef(0.1,5.5,0.1);
	c2.draw_solid_chess();
	glPopMatrix();
}
