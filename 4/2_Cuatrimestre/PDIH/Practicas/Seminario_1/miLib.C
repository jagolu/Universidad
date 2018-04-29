
#include <dos.h>
#include "MiLib.h"
#define BYTE unsigned char

/*Selecciona el modo de video deseado*/
void selecciona_modo_video(BYTE modo){
	union REGS inregs, outregs;
	inregs.h.ah=0x00;
	inregs.h.al=modo;
	int86(0x10, &inregs, &outregs);
	return;
}