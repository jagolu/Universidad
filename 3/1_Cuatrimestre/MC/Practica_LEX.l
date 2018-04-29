%{
#include <stdio.h>
%}

%%

.	{}	//Esta linea hace que los caracteres que no estan en ninguna otra regla (salvo los saltos de linea) no los muestre
\n	{}	//Esta linea hace que tampoco se muestren los campos de linea, que era lo que faltaba en la linea anterior
"\""([_A-Za-z\.0-9-]+)*@([\.a-z0-9-]+)*"."([a-z]{2,4})"\""	{
	//La regla anterior lo que hace es que coge las cadenas que estan entre parentesis por lo de "\"" ("loquesea")
	//Las cadenas que empiezan por combinaciones con las letras de "a" a "z" (mayusculas incluidas), con numeros de 0 a 9, barras bajas, puntos y guiones ("l0q9SE.ae")
	//a esas cadenas les seguirá un arroba y otra combinacion de letras, numeros, guiones y puntos ("l0q9SE.ae@correo.ugr")
	//al final de las cadenas (y antes del los "\"") ira un punto y una cadena de 2 a 4 caracteres de letras para el .es, .com ("l0q9SE.ae@correo.ugr.es")
	int i;
	for(i=1;i<yyleng-1;i++){
	//como en yytext en yytext[0] y yytext[n-1] hay unas comillas no mostramos esos caracteres
		printf("%c",yytext[i]);
	};printf("\n");}

%%

int main(int argc, char * argv[]){
	if(argc==2){
		yyin=fopen(argv[1],"r");
		printf("Fichero abierto\n");
		if(yyin==NULL){
			printf("El fichero %s no se puede abrir\n", argv[1]);
			exit(-1);
		}
	}
	else yyin=stdin;
	yylex();
}
