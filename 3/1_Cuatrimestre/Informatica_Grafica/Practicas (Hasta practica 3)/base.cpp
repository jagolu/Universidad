#include "base.h"
base::base(){}

base::base(float size, int veces):c1(size), c2(size), cin1(size,veces), cin2(size, veces){}

void base::draw_points(float n, int giro){
	glPushMatrix();
	glScalef(3,1,1);
	c1.draw_points();
	glPopMatrix();

	glPushMatrix();
	glRotatef(giro,0,1,0);	

	glPushMatrix();
	glTranslatef(0,5.5,0);
	glScalef(0.2,11,0.2);
	cin1.draw_points();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.5+n,0);
	glScalef(2,1,1);
	c2.draw_points();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75,2+n,0);
	glScalef(0.1,2.5,0);
	cin2.draw_points();
	glPopMatrix();
	
	glPopMatrix();
}

void base::draw_edges(float n, int giro){
	glPushMatrix();
	glScalef(3,1,1);
	c1.draw_edges();
	glPopMatrix();

	glPushMatrix();
	glRotatef(giro,0,1,0);	

	glPushMatrix();
	glTranslatef(0,5.5,0);
	glScalef(0.2,11,0.2);
	cin1.draw_edges();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.5+n,0);
	glScalef(2,1,1);
	c2.draw_edges();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75,2+n,0);
	glScalef(0.1,2.5,0);
	cin2.draw_edges();
	glPopMatrix();

	glPopMatrix();
}

void base::draw_solid(float n, int giro){
	glPushMatrix();
	glScalef(3,1,1);
	c1.draw_solid();
	glPopMatrix();

	glPushMatrix();
	glRotatef(giro,0,1,0);	

	glPushMatrix();
	glTranslatef(0,5.5,0);
	glScalef(0.2,11,0.2);
	cin1.draw_solid();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.5+n,0);
	glScalef(2,1,1);
	c2.draw_solid();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.75,2+n,0);
	glScalef(0.1,2.5,0);
	cin2.draw_solid();
	glPopMatrix();
	
	glPopMatrix();
}

void base::draw_solid_chess(float n, int giro){
	glPushMatrix();
	glScalef(3,1,1);
	c1.draw_solid_chess();
	glPopMatrix();

	glPushMatrix();
	glRotatef(giro,0,1,0);	

	glPushMatrix();
	glTranslatef(0,5.5,0);
	glScalef(0.2,11,0.2);
	cin1.draw_solid_chess();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,3.5+n,0);
	glScalef(2,1,1);
	c2.draw_solid_chess();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.75,2+n,0);
	glScalef(0.1,2.5,0);
	cin2.draw_solid_chess();
	glPopMatrix();

	glPopMatrix();
}
