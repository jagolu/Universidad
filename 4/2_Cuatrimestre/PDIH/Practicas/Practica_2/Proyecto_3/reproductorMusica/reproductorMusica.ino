// Definir notas
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880    
#define R 0

const int buttonPin=9; // Boton -> pin 9
int buttonState=0;
const int analogPin = A0;

int value; //variable que almacena la lectura analógica raw
int thispitch; //posicion del potenciometro en tanto por ciento

// Notas
int melody[] = {
 a, a, a, f, cH, a, f, cH, a, eH, eH , eH, fH, cH, gS, f, cH, a, aH, a, a, aH, gSH, gH,
 fSH, fH, fSH, R, aS, dSH, dH, cSH, cH, b, cH, R, f, gS, f, a, cH, a, cH, eH, aH, a, a,
 aH, gSH, gH, fSH, fH, fSH, R, aS, dSH, dH, cSH, cH, b, cH, R, f, gS, f, cH, a, f, c, a
};
// Duracion notas
int noteDurations[] = {
 500, 500, 500, 350, 150, 500, 350, 150, 1000, 500, 500, 500, 350, 150, 500, 350, 150, 1000,
 500, 350, 150, 500, 250, 250, 125, 125, 250, 250, 250, 500, 250, 250, 125, 125, 250, 250,
 125, 500, 375, 125, 500, 375, 125, 1000, 500, 350, 150, 500, 250, 250, 125, 125, 250, 250, 
 250, 500, 250 , 250, 125, 125, 250, 250, 250, 500, 375, 125, 500, 375, 125, 1000
};

int maxin=sizeof(melody)/2;

void setup() {
 pinMode(buttonPin,INPUT);
 Serial.begin(9600);
}

void loop() {
  int thisNote;
  for (thisNote = 0; thisNote < maxin; thisNote++) {
    value = analogRead(analogPin); // realizar la lectura analógica raw
    thispitch = map(value, 0, 1023, 0, 100); // convertir a porcentaje
    analogWrite(8, thispitch);
    buttonState=digitalRead(buttonPin);
    if(buttonState==LOW){
      tone(analogPin, melody[thisNote], noteDurations[thisNote]);
      int pauseBetweenNotes = noteDurations[thisNote] * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
    if(buttonState==HIGH){
      Serial.println("Pulsado");
      while(buttonState==HIGH){
        buttonState=digitalRead(buttonPin);
      }
      while(buttonState==LOW){
        buttonState=digitalRead(buttonPin);
      }
      while(buttonState==HIGH){
        buttonState=digitalRead(buttonPin);
      }
    }
  }
}
