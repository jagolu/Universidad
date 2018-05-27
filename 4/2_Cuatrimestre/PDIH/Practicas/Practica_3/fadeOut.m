% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

function [y] = fadeOut(signal, frecMuestreo, duracion)
  
  % Obtenemos nº de muestras (redondeando) para el fadeout
  muestras = round(duracion*frecMuestreo);
    
  % si el nº de muestras es mayor que la duracion de la señal
  % se hace fadeout desde el inicio
  if(muestras>length(signal))
      muestras = length(signal);
  end
    
  % vector fila con tantos puntos como muestras, cuyo espacio es 1/(muestras-1)
  rampa = linspace(0,1,muestras); 
   
  % Se hace la transposicion, es decir, pasar de un vector fila a un vector columna
  rampa = rampa';
  
  % señal a modificar 
  signal_fadeout = signal;
  
  % desde el final menos la duracion del fadeout, la señal pasa a ser  
  % la misma, multiplicando elemento por elemento esta con el vector rampa 
  signal_fadeout(end-muestras+1 : end, 1) = signal(end-muestras+1 : end, 1).*rampa(end : -1 : 1 , 1);
  signal_fadeout(end-muestras+1 : end, 2) = signal(end-muestras+1 : end, 2).*rampa(end : -1 : 1 , 1);
                           
  y = signal_fadeout;
    
end