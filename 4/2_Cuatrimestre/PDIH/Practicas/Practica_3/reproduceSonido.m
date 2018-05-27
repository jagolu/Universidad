% Estrella Afán de Rivera Díaz
% Javier Gómez Luzón

function [y] = reproduceSonido (signal, fMuest, resol, t_ini, t_fin)

	% Si hay 5 argumentos (es decir, se dan los tiempos de inicio y fin)
	if nargin == 5
		
		% Calcular muestras
		m_ini = t_ini*fMuest;
		m_fin = t_fin*fMuest;
		
		% Comprobar que: (muestra inicio > 0) &
    % (muestra inicio < muestra fin) & (muestra inicio < longitud señal)
		if (m_ini > 0) && (m_ini < m_fin) &&  (m_ini < length(signal))
			signal = signal(m_ini:m_fin);
		end
	end

	% Reproducir la señal
	sound (signal, fMuest, resol);

end
