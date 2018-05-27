% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

function dibujaSonido (signal,titulo)
	
	% Comprobamos nº de canales (nº columnas)
	[f,c] = size(signal);
	
  % Si hay 2 canales
	if c==2
		% Se divide la ventana en 2 filas y 1 columna y se activa la primera fila
		subplot(2,1,1)
		% Se dibuja la primera fila
		plot(signal(:,1));
		% Si hay dos argumentos
		if nargin == 2
			title(strcat(titulo, ' 1'));
		end	
   % Se divide la ventana en 2 filas y 1 columna y se activa la segunda fila
		subplot(2,1,2)
    % Se dibuja la segunda fila
		plot(signal(:,2));
    % Si hay dos argumentos
		if nargin == 2
			title(strcat(titulo, ' 2'));
		end
    
  % Si hay 1 canal
	else
    % Se dibuja la señal
		plot(signal);
    % Si hay dos argumentos
		if nargin == 2
			title(titulo);
		end
	end

end
