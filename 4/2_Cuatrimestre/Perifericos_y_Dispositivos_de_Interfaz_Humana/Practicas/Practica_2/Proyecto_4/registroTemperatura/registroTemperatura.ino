#include <EEPROM.h> //Librería para controlar la EEPROM de la Arduino
float tempC;
int tempPin = A0;
char input;
int addr = 0; //Cantidad de espacios (bytes) iniciales


void setup(){
  Serial.begin(9600); //Abre el puerto serial a 9600 bps
}
void loop(){
 input=Serial.read();

 if(input=='w'){
    tempC = analogRead(tempPin); //Toma los datos del sensor
    tempC = (((5.0 * tempC )/1024.0)-0.5)/0.01; //Convierte la señal análoga en temperatura
    //Serial.println((byte)tempC);
    EEPROM.write(addr, tempC);
    addr = addr + 1; //Por cada dato recibido lo guarda en una de los 512 espacios disponibles en la EEPROM
    if (addr == 512){ //Sí el número total de datos excede los 512
      for (int i = 0; i < 512; i++) EEPROM.write(i, 0);
    }
  }
  if(input=='r'){
    byte value;
    for (int i = 0; i < addr; i++){
      value = EEPROM.read(i);
      //value=(((value*5.0)/1024.0)-0.5)/0.01;
      Serial.print((byte)value);
      Serial.print("\n");
      //delay(500);
    }
  }
  
  if(input=='b'){
    for (int i = 0; i < 512; i++) EEPROM.write(i, 0);
  }
}
