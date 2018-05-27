% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

function [canales,frecMuestreo,resolucion,numeroBytesMuestras] = getCabeceraWav (fichero)

	% Se abre el fichero
	fileID = fopen(fichero);
	% Se lee el contenido del fichero y se almacena en F
	F = fread(fileID);
	
	% El nº de canales está almacenado en el byte 23
	canales = F(23);
	
  % La frecuencia de muestreo está almacenado en los bytes 25, 26, 27 y 28
	% Se usa little-endian, por lo que hay que invertir los bytes
	% Primero se pasan a hexadecimal
	f1 = dec2hex(F(25));
	f2 = dec2hex(F(26));
  f3 = dec2hex(F(27));
  f4 = dec2hex(F(28));
  % Despues se pasan a decimal y se unen los bytes en orden inverso
	frecMuestreo = hex2dec(strcat(f4, f3, f2, f1));

  % La resolucion está almacenada en el byte 35
	resolucion = F(35);

  % El nº de bytes de muestras está almacenado en los bytes 41, 42, 43 y 44
	% Se usa little-endian, por lo que hay que invertir los bytes
	% Primero se pasan a hexadecimal
	nb1 = dec2hex(F(41));
	nb2 = dec2hex(F(42));
	nb3 = dec2hex(F(43));
	nb4 = dec2hex(F(44));
  % Despues se pasan a decimal y se unen los bytes en orden inverso
	numeroBytesMuestras = hex2dec(strcat(nb4, nb3, nb2, nb1));

end
