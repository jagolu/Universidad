% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

% 1. Leer un fichero .WAV con wavread. 
y = audioread ('mika_relax.wav');

% 2. Dibujar la forma de onda de los canales. 
dibujaSonido (y, 'Relax');

% 3. Obtener la informacion de la cabecera del fichero. 
[canales, frequencia, resolucion, numBytesMuestras] = getCabeceraWav ('mika_relax.wav');

%reproduceSonido(y, 11025, 8);

% 4. Grabar un fichero de 2 segundos desde la tarjeta de sonido. 
sonido = grabaSonido('sonido.wav', 11025, 16, 2, 2.0);
%reproduceSonido (sonido, 11025, 8);

% 5. Insertar la señal grabada a los 3 segundos de la primera señal. 
insercion = insertaSonido(y, sonido, 11025, 3.0);
%reproduceSonido (insercion, 11025, 8);

% 6. Aplicar un eco del 40% con 0.5 segundos de retraso. 
ecoSignal = eco(insercion, 8000, 0.5, 0.4);
%reproduceSonido (ecoSignal, 11025, 8);


% 7. Aplicar un efecto de fadeout en el último segundo. 
%fadeout = fadeOut(y, 11025, 1.0);
fadeout = fadeOut(ecoSignal, 11025, 1.0);
%reproduceSonido (fadeout, 11025, 8);
%Descomentar para escuchar señal con todo lo anterior

% 8. Dibujar la forma de onda de la señal resultante.
dibujaSonido (fadeout, 'Resultante');

% 9. Almacenar la señal obtenida como un fichero WAV denominado mezcla.wav.
audiowrite('mezcla.wav', fadeout, 11025);

% 10. Reproducir al revés la señal obtenida.
alreves = reverse(fadeout);
reproduceSonido (alreves, 11025, 8);




