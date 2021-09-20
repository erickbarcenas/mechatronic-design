/*
  DISEÑO MECATRÓNICO
  PRACTICA 2 "Teclado‐7seg"

  EQUIPO:
  ARCOS PERALTA HERNÁN
  BÁRCENAS MARTÍNEZ ERICK IVÁN
  NIETO LARA ALDO
  PADILLA BARRERA ANDRÉS ALEJANDRO
  
*/


#include <Keypad.h>
 
const byte rowsCount = 4;
const byte columsCount = 4;

int pinBtn = A5;

 
char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' }, // A = 17
   { '4','5','6', 'B' }, // B = 18
   { '7','8','9', 'C' }, // C = 19
   { '*','0','#', 'D' } // * = -13   // # = -6   // D= 20
};
 
const byte rowPins[rowsCount] = { 9, 8, 7, 6 };
const byte columnPins[columsCount] = { 5,4,3,2 };
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
// termina el código necesario




void setup() {
   Serial.begin(9600);
   // 7 SEGMENTOS
   // Configuración de pines analógicos y digitales como salidas
   pinMode(A1, OUTPUT);
   pinMode(A2, OUTPUT);
   pinMode(A3, OUTPUT);
   pinMode(A4, OUTPUT);

   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   // Termina 7 segmentos

  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
   // PUSH BUTTON
      
  pinMode(pinBtn, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinBtn), toggle , FALLING);//configuramos la interrupción externa
}
 
char key;
int keyNumber;

// Configurando puerto analógicos como digitales 


int a = A1;
int b = A2;
int c = A3;
int d = 11;
int e = 10;
int f = 13;
int g = 12;



void displayMode(int a_mode, int b_mode, int c_mode, int d_mode, int e_mode, int f_mode, int g_mode){
  digitalWrite(a,a_mode);
  digitalWrite(b,b_mode);
  digitalWrite(c,c_mode);
  digitalWrite(d,d_mode);
  digitalWrite(e,e_mode);
  digitalWrite(f,f_mode);
  digitalWrite(g,g_mode);
}


void toggle() {//Función que atenderá la interrupción externa
  displayMode(0, 0, 0, 0, 0, 0, 0);
  Serial.println( "El estado del led ha cambiado" );//Imprimimos en el monitor serie
}

void loop() {
  key = keypad.getKey(); // leemos lo que nos manda el teclado
 
 
  

   if (key) {  // comprobamos si se presionó una tecla
      keyNumber = key - 48; // le restamos 48 al caracter del código ascii para que sea número
       // Serial.println(key);
      switch(keyNumber){
        case 0: 
          displayMode(1, 1, 1, 1, 1, 1, 0); // a=1, b=1, c=1, d=1, e=1, f=1, g=0
        break;
        case 1: 
          displayMode(0, 1, 1, 0, 0, 0, 0); // a=0, b=1, c=1, d=0, e=0, f=0, g=0
        break;
        case 2: 
          displayMode(1, 1, 0, 1, 1, 0, 1); // a=1, b=1, c=0, d=1, e=1, f=0, g=1
        break;
        case 3: 
          displayMode(1, 1, 1, 1, 0, 0, 1); // a=1, b=1, c=1, d=1, e=0, f=0, g=0
        break;
        case 4: 
          displayMode(0, 1, 1, 0, 0, 1, 1); // a=0, b=1, c=1, d=0, e=0, f=1, g=1
        break;
        case 5: 
          displayMode(1, 0, 1, 1, 0, 1, 1); // a=1, b=0, c=1, d=1, e=0, f=1, g=1
        break;
        case 6: 
          displayMode(1, 0, 1, 1, 1, 1, 1); // a=1, b=0, c=1, d=1, e=1, f=1, g=1
        break;
        case 7: 
          displayMode(1, 1, 1, 0, 0, 0, 0); // a=1, b=1, c=1, d=0, e=0, f=0, g=0
        break;
        case 8: 
          displayMode(1, 1, 1, 1, 1, 1, 1); // a=1, b=1, c=1, d=1, e=1, f=1, g=1
        break;
        case 9: 
          displayMode(1, 1, 1, 0, 0, 1, 1); // a=1, b=1, c=1, d=0, e=0, f=1, g=1
        break;

        /// CARACTERES
        // Asterisco (*)
        case -6: 
          displayMode(0, 1, 1, 0, 0, 0, 1); // a=0, b=1, c=1, d=0, e=0, f=0, g=1
        break;
        // Almohadilla (#)
        case -13: 
          displayMode(1, 0, 1, 0, 1, 0, 0); // a=1, b=0, c=1, d=0, e=1, f=0, g=0
        break;
        /// LETRAS
        // A
        case 17: 
          displayMode(1, 1, 1, 0, 1, 1, 1); // a=1, b=1, c=1, d=0, e=1, f=1, g=1
        break;
        // B
        case 18: 
          displayMode(0, 0, 1, 1, 1, 1, 1); // a=0, b=0, c=1, d=1, e=1, f=1, g=1
        break;
        // C
        case 19: 
          displayMode(1, 0, 0, 1, 1, 1, 0); // a=1, b=0, c=0, d=1, e=1, f=1, g=0
        break;
        // D
        case 20: 
          displayMode(0, 1, 1, 1, 1, 0, 1); // a=0, b=1, c=1, d=1, e=1, f=0, g=1
        break;
        default:
        break;
      }
      delay(1000);
      displayMode(0, 0, 0, 0, 0, 0, 0); // a=0, b=0, c=0, d=0, e=0, f=0, g=0
      Serial.println(keyNumber); // mostramos el caracter en el monitor serial  // el ln nos hace saltar un renglón
   }
}
