% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

function [y] = grabaSonido (fichero, frecMuestreo, resolucion, canales, duracion)
	
  % frecuencia de muestreo admite 8000, 11025, 22050 y 44100
  % captura una señal a través de la tarjeta de sonido del computador
  % y crea un objeto para grabar el audio
	audio = audiorecorder (frecMuestreo, resolucion, canales);
  % graba la señal en audio
	recordblocking (audio, duracion);
  % guarda la señal en y
	y = getaudiodata(audio);
	
  % guarda la señal y en fichero a la frec de muestreo correspondiente
	audiowrite (fichero, y, frecMuestreo);

end
