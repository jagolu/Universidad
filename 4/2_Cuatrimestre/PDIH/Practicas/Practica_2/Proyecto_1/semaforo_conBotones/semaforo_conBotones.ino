// Configurar pines
const int rojo1=9;  // Semaforo rojo 1 -> pin 9
const int rojo2=6;  // Semaforo rojo 2 -> pin 6
const int ambar1=4; // Semaforo ambar 1 -> pin 4
const int ambar2=7; // Semaforo ambar 2 -> pin 7
const int verde1=5; // Semaforo verde 1 -> pin 5
const int verde2=8; // Semaforo verde 2 -> pin 8

const int button1=2;  // Boton 1 -> pin 2 
const int button2=3;  // Boton 2 -> pin 3

// Variables globales
volatile byte state=0;
int buttonState=0;

// Funcion para encender semaforo 1 rojo y semaforo 2 verde
void rojo1verde2(){
  digitalWrite(rojo1, HIGH);
  digitalWrite(ambar1,LOW);
  digitalWrite(verde1,LOW);
  digitalWrite(rojo2,LOW);
  digitalWrite(ambar2,LOW);
  digitalWrite(verde2, HIGH);
}

// Funcion para encender semaforo 1 rojo y semaforo 2 ambar
void rojo1ambar2(){
  digitalWrite(rojo1, HIGH);
  digitalWrite(ambar1,LOW);
  digitalWrite(verde1,LOW);
  digitalWrite(rojo2,LOW);
  digitalWrite(ambar2,HIGH);
  digitalWrite(verde2, LOW);
}

// Funcion para encender semaforo 1 verde y semaforo 2 rojo
void verde1rojo2(){
  digitalWrite(rojo1, LOW);
  digitalWrite(ambar1,LOW);
  digitalWrite(verde1,HIGH);
  digitalWrite(rojo2,HIGH);
  digitalWrite(ambar2,LOW);
  digitalWrite(verde2, LOW);
}

// Funcion para encender semaforo 1 ambar y semaforo 2 rojo
void ambar1rojo2(){
  digitalWrite(rojo1, LOW);
  digitalWrite(ambar1,HIGH);
  digitalWrite(verde1,LOW);
  digitalWrite(rojo2,HIGH);
  digitalWrite(ambar2,LOW);
  digitalWrite(verde2, LOW);
}

//Funcion para cambio de manual a automatico
void changingMode(){
  state=!state;
}

int i=0;
//Funcion para cambiar semaforos manualmente
void changingSemaforos(){
  if(i<4) i++;
  else if(i==4) i=1;
}

// the setup function runs once when you press reset or power the board
void setup() {
 //Inicializar LEDs, botones y puerto serie
 Serial.begin(9600);
 pinMode(rojo1,OUTPUT); 
 pinMode(ambar1,OUTPUT); 
 pinMode(verde1,OUTPUT); 
 pinMode(rojo2,OUTPUT); 
 pinMode(ambar2,OUTPUT); 
 pinMode(verde2,OUTPUT); 
 pinMode(button1, INPUT_PULLUP);
 pinMode(button2, INPUT_PULLUP);
 buttonState=digitalRead(button1);
 buttonState=digitalRead(button2);

  //Definir interrupciones
 attachInterrupt(digitalPinToInterrupt(button1),changingMode,RISING);
 attachInterrupt(digitalPinToInterrupt(button2),changingSemaforos,RISING);
}


// the loop function runs over and over again forever
void loop() {

  //Automatico
  while(state){
    rojo1verde2();
    delay(3000);
    rojo1ambar2();
    delay(500);   
    verde1rojo2();
    delay(3000);
    ambar1rojo2();
    delay(500);
  }

  //Manual
  while(!state){
    if(i==1) rojo1verde2();
    if(i==2) rojo1ambar2();
    if(i==3) verde1rojo2();
    if(i==4) ambar1rojo2();
  }
  
  
    
}
