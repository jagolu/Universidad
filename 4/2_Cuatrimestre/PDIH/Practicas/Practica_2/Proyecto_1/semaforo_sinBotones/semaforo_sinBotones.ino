// Configurar pines
const int rojo1=3;  // Semaforo rojo 1 -> pin 3
const int rojo2=6;  // Semaforo rojo 2 -> pin 6
const int ambar1=4; // Semaforo ambar 1 -> pin 4
const int ambar2=7; // Semaforo ambar 2 -> pin 7
const int verde1=5; // Semaforo verde 1 -> pin 5
const int verde2=8; // Semaforo verde 2 -> pin 8

// the setup function runs once when you press reset or power the board
void setup() {
 // Inicializar LEDS
 pinMode(rojo1,OUTPUT); 
 pinMode(ambar1,OUTPUT); 
 pinMode(verde1,OUTPUT); 
 pinMode(rojo2,OUTPUT); 
 pinMode(ambar2,OUTPUT); 
 pinMode(verde2,OUTPUT); 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(rojo1, HIGH);
  digitalWrite(ambar1,LOW);
  digitalWrite(verde1,LOW);
  digitalWrite(rojo2,LOW);
  digitalWrite(ambar2,LOW);
  digitalWrite(verde2, HIGH);
  delay(3000);
  digitalWrite(rojo1, HIGH);
  digitalWrite(ambar1,LOW);
  digitalWrite(verde1,LOW);
  digitalWrite(rojo2,LOW);
  digitalWrite(ambar2,HIGH);
  digitalWrite(verde2, LOW);
  delay(500);
  digitalWrite(rojo1, LOW);
  digitalWrite(ambar1,LOW);
  digitalWrite(verde1,HIGH);
  digitalWrite(rojo2,HIGH);
  digitalWrite(ambar2,LOW);
  digitalWrite(verde2, LOW);
  delay(3000);
  digitalWrite(rojo1, LOW);
  digitalWrite(ambar1,HIGH);
  digitalWrite(verde1,LOW);
  digitalWrite(rojo2,HIGH);
  digitalWrite(ambar2,LOW);
  digitalWrite(verde2, LOW);
  delay(500);
}
