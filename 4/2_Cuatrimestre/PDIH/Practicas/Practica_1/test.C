#include <stdio.h>
#include "conio2.h"
int main(){
	int x, y;
	miclrscr();
	printf("Pulse una tecla para continuar (Prueba del kbhit): ");
	while(!mikbhit());
	printf("\nTecla pulsada...");
	printf("\nPrueba del gotoxy. Voy a avanzar una linea en Y y 10 caracteres en X.\n");
	migotoxy(miwherex()+10, miwherey()+1);
	x=miwherex();
	y=miwherey();
	printf("Prueba del wherex/y. EL cursor esta en (X=%i, Y=%i).Pulse una tecla para continuar", x, y);
	migetch();
	printf("\nPrueba del clrscr. Pulse una tecla para borrar la pantalla.");
	migetch();
	miclrscr();
	printf("Pantalla borrada. A partir de este punto voy a borrar la linea");
	printf("\nPantalla borrada. A partir de este punto NO voy a borrar la linea");
	migetch();
	migotoxy(41,miwherey()-1);
	miclreol();
	migetch();
	miclrscr();
	printf("Cambiamos de color. FG=RED, BG=BLUE\n");
	printf("Prueba cputchar: \n");
	migetch();
	mitextcolor(4);
	mitextbackground(1);
	micputchar('C');
	migetch();
	printf("\nAhora prueba con getche (No le afectan los cambios de colores): \n");
	migetche();
	migetch();
	mitextcolor(15);
	mitextbackground(0);
	miclrscr();
	printf("Borrar pantalla en fondo azul. Despues ponemos el rojo.");
	migetch();
	mitextbackground(1);
	miclrscr();
	migotoxy(1, miwherey()+1);
	micputs("Ahora hacemos scrollup 1 linea");
	migotoxy(1, miwherey()+1);
	migetch();
	mitextbackground(4);
	miscrollup();
	mitextbackground(1);
	migotoxy(1, miwherey()+1);
	micputs("Ahora hacemos scrolldown 1 linea");
	migotoxy(1, miwherey()+1);
	migetch();
	mitextbackground(4);
	miscrolldown();
	migetch();
	miclrscr();
	micputs("Cursor invisible:");
	misetcursortype(3);
	migetch();
	migotoxy(1, miwherey()+1);
	micputs("Cursor grueso:");
	misetcursortype(1);
	migetch();
	migotoxy(1, miwherey()+1);
	micputs("Cursor normal:");
	misetcursortype(2);
	migetch();
	migotoxy(1, miwherey()+1);
	micputs("Cambiar a modo de video 0x1 (40x25) ");
	migetch();
	mitextbackground(0);
	misetvideomode(1);
	printf("Modo de video actual: %d. Restituir modo de video.", migetvideomode());
	migetch();
	misetvideomode(3);
	printf("Pulse una tecla para finalizar.");
	migetch();
	printf("\nPrograma terminado");
}