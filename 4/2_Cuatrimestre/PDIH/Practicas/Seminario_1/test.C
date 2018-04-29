#include <stdio.h>
#include "MiLib.h"
int main(){
	int byte;
	printf("Ingrese un numero para cambiar el modo de pantalla: ");
	scanf("%d", &byte);
	selecciona_modo_video(byte);
	printf("Este es el nuevo modo de pantalla. Pulse una tecla para volver al anterior ");
	scanf("%d", &byte);
	selecciona_modo_video(3);
	printf("Este es el modo de pantalla original");
	return;
}