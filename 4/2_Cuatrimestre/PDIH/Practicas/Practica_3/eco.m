% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

function [y] = eco(signal, frecMuestreo, retraso, potencia)
  
  % Obtenemos el tiempo de retraso
  t_retraso = round(retraso*frecMuestreo);
  
  % Obtenemos el numero de canales
  canales=size(signal,2);

  %Creamos la primera parte con la señal al principio y ceros al final
  signal_eco1=[signal;zeros(t_retraso,canales)];
  %Creamos la segunda parte con ceros al principio y la señal atenuada despues
  signal_eco2=[zeros(t_retraso,canales);signal*potencia];
  
  % Se suman las señales
  y = signal_eco1+signal_eco2;

end