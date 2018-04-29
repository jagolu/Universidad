/**
* @file conio2.c
* @Author Javier Gómez Luzón
* @date 17/03/2018
* @brief Implementación propia de algunas funciones de la librería
		 conio.h de Borland
*/

#include <dos.h>
#include "conio2.h"
#include <string.h>
unsigned char FG_COLOR=15; /*Color de la letra. 15 (blanco)  por defecto*/
unsigned char BG_COLOR=0; /*Color de fondo. 0 (negro) por defecto.*/
int n_filas=25;

/**
* @brief Espera que se pulse una tecla en el teclado. La tecla se mostrará.
* @return 0 si hay una tecla en el buffer, 1 si no hay nada en el buffer.
*/
int mikbhit(){
	union REGS inregs, outregs;
	inregs.h.ah=0x01;
	int86(0x16, &inregs, &outregs);
	//Comprobamos que si el sexto bit de x.flags es 0 o 1.
	if(outregs.x.flags & 0X40){
		return 0;
	}
	else{
		return 1;
	}
}

/**
* @brief Devuelve la coordenada X del cursor.
* @return La columna del cursor.
*/
int miwherex(){
	union REGS inregs, outregs;
	inregs.h.ah=0x03;
	inregs.h.bh=0x00;
	int86(0x10,&inregs, &outregs);
	return outregs.h.dl+0x01;
}

/**
* @brief Devuelve la coordenada Y del cursor.
* @return La fila del cursor.
*/
int miwherey(){
	union REGS inregs, outregs;
	inregs.h.ah=0x03;
	inregs.h.bh=0x00;
	int86(0x10,&inregs, &outregs);
	return outregs.h.dh+0x01;
}

/**
* @brief Lleva el cursor a la coordenada que le indiquemos.
* @param x La columna a la que queremos ir.
* @param y La fila a la que queremos ir.
*/
void migotoxy(int x, int y){
	union REGS inregs, outregs;
	y--;
	x--;
	if(y<get_fil() && y>=0 && x<get_col() && x>=0){
		inregs.h.ah=0x02;
		inregs.h.dh=y;
		inregs.h.dl=x;
		inregs.h.bh=0x00;
		int86(0x10, &inregs, &outregs);
	}
	return;
}

/**
* @brief Nos pone el cursor en la forma en que elijamos.
* @param El modo de video que queremos poner. 1 grueso, 2 normal, 3 invisible.
*/
void misetcursortype(int tipo_cursor){
	union REGS inregs, outregs;
	inregs.h.ah=0x01;
	if(tipo_cursor==1){
		inregs.h.ch= 0x00;
		inregs.h.cl=0x07;
	}
	else if(tipo_cursor==2){
		inregs.h.ch=0x06;
		inregs.h.cl=0x07;
	}
	else if(tipo_cursor==3){
		inregs.h.ch= 0x01;
		inregs.h.cl=0x00;
	}
	int86(0x10, &inregs, &outregs);
	return;	
}

/**
* @brief Elegimos el modo de video.
* @param El modo de video que queremos poner. (0h, 1h, 2h, 3h, 7h) texto, 
	     (4h, 5h, 6h, dh, eh, fh, 10h, 11h, 12h, 13h) gráfico.
*/
void misetvideomode(unsigned char modo){
	union REGS inregs, outregs;
	inregs.h.ah=0x00;
	inregs.h.al=modo;
	int86(0x10, &inregs, &outregs);
	if(modo==0x00) n_filas=25;
	else if(modo==0x01) n_filas=25;
	else if(modo==0x02) n_filas=25;
	else if(modo==0x03) n_filas=25;
	else if(modo==0x04) n_filas=200;
	else if(modo==0x05) n_filas=200;
	else if(modo==0x06) n_filas=200;
	else if(modo==0x0D) n_filas=200;
	else if(modo==0x0E) n_filas=200;
	else if(modo==0x0F) n_filas=350;
	else if(modo==0x10) n_filas=350;
	else if(modo==0x11) n_filas=480;
	else if(modo==0x12) n_filas=480;
	else if(modo==0x13) n_filas=200;
	return;
}

/**
* @brief Nos dice en qué modo de video estamos.
* @return El modo de video actual.
*/
int migetvideomode(){
	int modo;
	union REGS inregs, outregs;
	inregs.h.ah=0xf;
	int86(0x10, &inregs, &outregs);
	modo=outregs.h.al;
	return modo;
}

/**
* @brief Pone la variable global FG_COLOR al color que deseamos.
* @param El color de texto que queremos poner. (0-15, 128).
*/
void mitextcolor(int color){
	FG_COLOR=color;
	return;
}

/**
* @brief Pone la variable global BG_COLOR al color que deseemos.
* @param El color de fondo que queremos poner. (0-7).
*/
void mitextbackground(int color){
	BG_COLOR=color<<4;
	return;
}

/**
* @brief Nos limpia la pantalla por completo, rellenandola con el color  que tengamos seleccionado y     
 colocamos el cursor en la posición 1,1.
*/
void miclrscr(){
	int i;
	for(i=0;i<get_fil();i++){
		miscrollup();
	}
	migotoxy(1, 1);
	return;
}

/**
* @brief Nos borra la pantalla desde la posición actual del cursor hasta el final de línea.
*/
void miclreol(){
	union REGS inregs, outregs;
	inregs.h.ah=0x06;
	inregs.h.al=0x00;
	inregs.h.bh=BG_COLOR|FG_COLOR;
	inregs.h.ch=miwherey()-1;  //Mi fila.
	inregs.h.cl=miwherex()-1;  //Mi columna.
	inregs.h.dh=miwherey()-1;  //Mi fila.
	inregs.h.dl=0x4f;        //Final de linea.
	int86(0x10, &inregs, &outregs);
	return;
}

/**
* @brief Nos desplaza la pantalla una línea hacia arriba.
*/
void miscrollup(){
	union REGS inregs, outregs;
	inregs.h.ah=0x06;
	inregs.h.al=0x01; //Solo subirmos una linea.
	inregs.h.bh=BG_COLOR|FG_COLOR;
	inregs.h.ch=0x00; //Fila de la esquina superior izquierda.
	inregs.h.cl=0x00; //Columa de la esquina superior izquierda.
	inregs.h.dh=get_fil(); //Fila de la esquina inferior derecha.
	inregs.h.dl=get_col(); //Columna de la esquina inferior derecha.
	int86(0x10, &inregs, &outregs);
	migotoxy(miwherex(), miwherey()-1);
	return;
}

/**
* @brief Nos desplaza la pantalla una línea hacia abajo.
*/
void miscrolldown(){
	union REGS inregs, outregs;
	inregs.h.ah=0x07;
	inregs.h.al=0x01; //Solo bajamos una linea.
	inregs.h.bh=BG_COLOR|FG_COLOR;
	inregs.h.ch=0x00; //Fila de la esquina superior izquierda.
	inregs.h.cl=0x00; //Columa de la esquina superior izquierda.
	inregs.h.dh=get_fil(); //Fila de la esquina inferior derecha.
	inregs.h.dl=get_col(); //Columna de la esquina inferior derecha.
	int86(0x10, &inregs, &outregs);
	migotoxy(miwherex(), miwherey()+1);
	return;
}

/**
* @brief Imprime un caracter en pantalla con el color de fondo y de texto seleccionados
* @param El código Ascii del carácter que queremos imprimir.
* @return El código Ascii del carácter escrito.
*/
int micputchar(int c){
	union REGS inregs, outregs;
	inregs.h.ah=0x09;
	inregs.h.al=c;
	inregs.h.bl=FG_COLOR|BG_COLOR;
	inregs.h.bh=0;
	inregs.x.cx=1;
	int86(0x10, &inregs, &outregs);
	//Con este código nos vamos desplazando el cursor hacia la 
	//derecha si escribimos en cualquier posición que no sea el
	//final de línea, si es el final de línea, vamos a la siguiente línea
	//en la columna 0. Y si estamos en la última fila, hacemos un scrollup
	//para sacar una fila nueva.
	if(miwherex()==get_col()-1 && miwherey()==get_fil()-1){
		miscrollup();
		migotoxy(1,25);
	}
	else if(miwherex()==get_col()-1 && miwherey()<get_fil()-1){
		migotoxy(1, miwherey()+1);
	}
	else{
		migotoxy(miwherex()+1, miwherey());
	}
	return c;
}

/**
* @brief Obtiene un carácter por teclado y lo imprime por pantalla.
* @return Devuelve el código Ascii del carácter pulsado.
*/
int migetche(){
	int cod_ascii;
	unsigned char aux_FG, aux_BG;
	union REGS inregs, outregs;
	inregs.h.ah=0x09;
	cod_ascii=getch();
	aux_FG=FG_COLOR;
	aux_BG=BG_COLOR;
	mitextcolor(15);
	mitextbackground(0);
	micputchar(cod_ascii);
	mitextcolor(FG_COLOR);
	mitextbackground(BG_COLOR);
	return cod_ascii;
}

/**
* @brief Imprime una cadena de texto por pantalla.
* @param La cadena de texto que queremos imprimir.
*/
void micputs(const char * texto){
	int i, caracter;
	for(i=0;i<strlen(texto);i++){
		caracter=texto[i];
		micputchar(caracter);
	}
	return;
}

/**
* @brief Obtiene un carácter por teclado.
* @return Devuelve el código Ascii del carácter pulsado.
*/
int migetch(){
	int cod_ascii;
	union REGS inregs, outregs;
	inregs.h.ah=0x00;
	int86(0x16, &inregs, &outregs);
	cod_ascii=outregs.h.al;
	if(cod_ascii==0){ //Nos fijamos en si es un carácter o una tecla especial.
		cod_ascii=outregs.h.ah;
	}
	return cod_ascii;
}

/**
* @brief Nos dice el número de columnas que tiene el modo de video actual.
* @return El número de columnas del modo de video actual.
*/
int get_col(){
  int numero;
  union REGS inregs, outregs;
  inregs.h.ah=0x0F;
  int86(0x10,&inregs,&outregs);
  numero=outregs.h.ah;
  return numero;
}

/**
* @brief Nos dice el número de filas que tiene el modo de video actual.
* @return El número de filas del modo de video actual.
*/
int get_fil(){
  return n_filas;
}
