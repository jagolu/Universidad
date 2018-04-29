#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Constantes
#define COLS 16         // Columnas del LCD
#define ROWS 2          // Filas del LCD
#define VELOCIDAD 300   // Velocidad para mover el texto

//Variables globales
float tempC;        // Variable para almacenar el valor obtenido del sensor
int pin = A0;       // Variable del pin de entrada del sensor
int cont=0;         // Total de datos leidos
char input;


void setup() {
  
 // Configurar filas y columnas del LCD
 lcd.begin(COLS, ROWS);
 Serial.begin(9600);
 tempC = analogRead(pin);

 // Obtener temperatura a partir de lectura analógica
 tempC = (((5.0 * tempC )/1024.0)-0.5)/0.01;

 Serial.println((byte)tempC);

   // Valores LED
 lcd.clear();
 cont++;
 lcd.setCursor(0,0);
 lcd.print("Temp: ");
 lcd.setCursor(0,1);
 lcd.print("Lectura: ");
 lcd.setCursor(7,0);
 lcd.print(tempC);
 lcd.print(" C");
 lcd.setCursor(12,1);
 lcd.print(cont);
 delay(5000);
}

void loop() {

 input=Serial.read();

 //Obtenemos datos del sensor
 tempC = analogRead(pin);

 // Obtener temperatura a partir de lectura analógica
 tempC = (((5.0 * tempC )/1024.0)-0.5)/0.01;

 Serial.println((byte)tempC);

 // Valores LED
 lcd.clear();
 cont++;
 lcd.setCursor(0,0);
 lcd.print("Temp: ");
 lcd.setCursor(0,1);
 lcd.print("Lectura: ");
 lcd.setCursor(7,0);
 lcd.print(tempC);
 lcd.print(" C");
 lcd.setCursor(12,1);
 lcd.print(cont);
 delay(10000);  
}
