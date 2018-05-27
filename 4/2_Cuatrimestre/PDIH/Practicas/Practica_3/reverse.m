% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

function [y] = reverse(signal)

  % Se hace la transposicion, ya que fliplr invierte elementos en el eje horizontal
  signal = signal';
  % Se invierte la señal
  signal_reverse = fliplr(signal);

  %Se vuelve a hacer transposicion
  y = signal_reverse';

end