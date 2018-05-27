% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

function [y] = insertaSonido(s1, s2, frecMuestreo, tiempo)

  % trozo1: desde el inicio de la señal 1 hasta el tiempo que se pasa como parámetro
  % trozo2: señal 2
  % trozo3: desde donde se quedó la señal 1 hasta el final
  trozo1 = s1(1 : frecMuestreo*tiempo, :);
  trozo2 = s2;
  trozo3 = s1((frecMuestreo*tiempo)+1 : end, :);
  
  % Se concatenan los 3 trozos
  y = [trozo1; trozo2; trozo3];

end