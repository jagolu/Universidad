/**
  * @file codificar.h
  * @brief Fichero cabecera para la codificacion y decodificacion de mensajes en imágenes
  *
  * Permite ocultar y revelar mensajes en archivos de tipos PGM,PPM
  *
  */


#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

/**
  * @brief Oculta un mensaje en la imagen guardada en el buffer de formato PPM o PGM
  *
  * @param buffer Zona de imagen para modificar los bits menos relevantes
  * @param mensaje El mensaje que se ocultara en la imagen
  * @param f filas de bytes de la imagen
  * @param c columnas de bytes de la imagen
  * @pre buffer debe ser una zona de memoria suficientemente grande como para
  * almacenar el mensaje completo y el fin de mensaje ('\0')
  * @return si ha  tenido éxito a la hora de ocultar
  */
bool Ocultar(unsigned char buffer[], char mensaje[], int f, int c);

/**
  * @brief Revela un mensaje en una imagen guardada en un buffer de formato PPM o PGM
  *
  * @param buffer Zona de imagen para leer los bits menos relevantes
  * @param mensaje en esta variable se guardara el mensaje que esta oculto en la imagen
  * @param total_mensaje total de tamanio del mensaje
  * @param total_buffer total de tamanio del buffer
  * @pre mensaje debe ser una zona de memoria suficientemente grande como para
  * almacenar el mensaje completo y el fin de mensaje ('\0') que esta oculto en buffer
  * @return si ha  tenido éxito a la hora de revelar
  */
bool Revelar(unsigned char buffer[], char mensaje[], int total_mensaje, int total_buffer);
#endif

/* Fin Fichero: codificar.h */
