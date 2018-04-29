void setup () {

   //Configurar salidas de los leds
   pinMode (2, OUTPUT);
   pinMode (3, OUTPUT);
   pinMode (4, OUTPUT);
   pinMode (5, OUTPUT);
   pinMode (6, OUTPUT);
   pinMode (7, OUTPUT);
   pinMode (8, OUTPUT);    
      
   
   //Configurar el pin de entrada del pulsador
   pinMode (10, INPUT);
    
   //Inicializar el generador de numeros aleatorios
   randomSeed(analogRead(0));   
    
   //Apagar todos los leds
   digitalWrite (2, LOW);
   digitalWrite (3, LOW);
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite (7, LOW);
   digitalWrite (8, LOW);  

}


//Escribir numero en el dado
void escribe_dado (unsigned char num) {
  
  switch (num) {
            
    case 1: //Encender el numero 1
            digitalWrite (2, LOW);
            digitalWrite (3, LOW);
            digitalWrite (4, LOW);
            digitalWrite (5, HIGH);
            digitalWrite (6, LOW);
            digitalWrite (7, LOW);
            digitalWrite (8, LOW);           
            break;
            
    case 2: //Encender el numero 2
            digitalWrite (2, HIGH);
            digitalWrite (3, LOW);
            digitalWrite (4, LOW);
            digitalWrite (5, LOW);
            digitalWrite (6, LOW);
            digitalWrite (7, LOW);
            digitalWrite (8, HIGH);              
            break;
            
    case 3: //Encender el numero 3
            digitalWrite (2, HIGH);
            digitalWrite (3, LOW);
            digitalWrite (4, LOW);
            digitalWrite (5, HIGH);
            digitalWrite (6, LOW);
            digitalWrite (7, LOW);
            digitalWrite (8, HIGH);  
            break;
            
    case 4: //Encender el numero 4
            digitalWrite (2, HIGH);
            digitalWrite (3, LOW);
            digitalWrite (4, HIGH);
            digitalWrite (5, LOW);
            digitalWrite (6, HIGH);
            digitalWrite (7, LOW);
            digitalWrite (8, HIGH);  
            break;
            
    case 5: //Encender el numero 5
            digitalWrite (2, HIGH);
            digitalWrite (3, LOW);
            digitalWrite (4, HIGH);
            digitalWrite (5, HIGH);
            digitalWrite (6, HIGH);
            digitalWrite (7, LOW);
            digitalWrite (8, HIGH);  
            break;
            
    case 6: //Encender el numero 6
            digitalWrite (2, HIGH);
            digitalWrite (3, HIGH);
            digitalWrite (4, HIGH);
            digitalWrite (5, LOW);
            digitalWrite (6, HIGH);
            digitalWrite (7, HIGH);
            digitalWrite (8, HIGH); 
            break;
        
    default:
    case 0:  //Apagar todos los leds
            digitalWrite (2, LOW);
            digitalWrite (3, LOW);
            digitalWrite (4, LOW);
            digitalWrite (5, LOW);
            digitalWrite (6, LOW);
            digitalWrite (7, LOW);
            digitalWrite (8, LOW); 
            break;
            
  }
  

}


void loop () {
  
 unsigned int numero;
  
  while (!digitalRead (10));     //Esperar a que se apriete pulsador

  escribe_dado (0);              //Apagar todos los leds
  
  while (digitalRead (10));      //Esperar a que se suelte pulsador
  
  numero = random(1, 7);        //Generar un numero al azar entre 1 y 6
  
  escribe_dado (numero);        //Mostrar el numero en el dado
 

}
