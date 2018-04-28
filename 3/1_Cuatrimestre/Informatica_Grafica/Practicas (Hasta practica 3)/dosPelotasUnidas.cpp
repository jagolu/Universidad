#include "dosPelotasUnidas.h"
dosPelotasUnidas::dosPelotasUnidas(){}
dosPelotasUnidas::dosPelotasUnidas(float size, int veces):pp1(size, veces), pp2(size,veces), c(size){}
void dosPelotasUnidas::draw_points(float n){
	glPushMatrix();
	glTranslatef(0,3.75,0);
	glRotatef(180,0,1,0);
	glRotatef(-45-(n*5.8),0,0,1);
	pp1.draw_points(n);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.75,0);
	glRotatef(315-(n*5.8),0,0,1);
	pp2.draw_points(n);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.5,0);
	glScalef(2,1,1);
	c.draw_points();
	glPopMatrix();
}

void dosPelotasUnidas::draw_edges(float n){
	glPushMatrix();
	glTranslatef(0,3.75,0);
	glRotatef(180,0,1,0);
	glRotatef(-45-(n*5.8),0,0,1);
	pp1.draw_edges(n);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.75,0);
	glRotatef(315-(n*5.8),0,0,1);
	pp2.draw_edges(n);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.5,0);
	glScalef(2,1,1);
	c.draw_edges();
	glPopMatrix();
}

void dosPelotasUnidas::draw_solid(float n){
	glPushMatrix();
	glTranslatef(0,3.75,0);
	glRotatef(180,0,1,0);
	glRotatef(-45-(n*5.8),0,0,1);
	pp1.draw_solid(n);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.75,0);
	glRotatef(315-(n*5.8),0,0,1);
	pp2.draw_solid(n);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.5,0);
	glScalef(2,1,1);
	c.draw_solid();
	glPopMatrix();
}

void dosPelotasUnidas::draw_solid_chess(float n){
	glPushMatrix();
	glTranslatef(0,3.75,0);
	glRotatef(180,0,1,0);
	glRotatef(-45-(n*5.8),0,0,1);
	pp1.draw_solid_chess(n);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.75,0);
	glRotatef(315-(n*5.8),0,0,1);
	pp2.draw_solid_chess(n);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.5,0);
	glScalef(2,1,1);
	c.draw_solid_chess();
	glPopMatrix();
}
