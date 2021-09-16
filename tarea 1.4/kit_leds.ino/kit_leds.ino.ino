/*
  DISEÑO MECATRÓNICO
  PRACTICA 1 "KITT con LEDs"

  EQUIPO:
  ARCOS PERALTA HERNÁN
  BÁRCENAS MARTÍNEZ ERICK IVÁN
  NIETO LARA ALDO
  PADILLA BARRERA ANDRÉS ALEJANDRO
  
*/


// En nuestra configuración lo que hacemos es declarar
// cada pin del 4 al 9 como elementos de salida
// para ello iteramos mediante un bucle for
int minPin = 4;
int maxPin = 9;
int forward = 1;

void setup()
{
  Serial.begin(9600); 
  pinMode(9,OUTPUT);
  for(int i = minPin ; i<=maxPin; i++) {
    pinMode(i,OUTPUT);
  }
}
// A continuación tenemos que definir un bucle que va a ahcer que el pin
// no. 4 se encienda, luego se pague y avance con el pin no. 5 para que 
// se encienda y apague, y así repetir el proceso hasta llegar al pin no. 9
// una vez que llega al límite se debe de intertir el proceso hasta
// llegar al pin no. 4

void loop() 
{
  if(forward == 1){
    for(int j = minPin; j<=maxPin; j++){
      digitalWrite(j, HIGH); // se enceinde el LED
      delay(100);
      digitalWrite(j,LOW); // se apaga el LED
      delay(100);
    }
    forward=0;
  }
  delay(100);
  if(forward == 0){
    for(int k = maxPin; k>=minPin; k--){
      digitalWrite(k, HIGH); // se enceinde el LED
      delay(100);
      digitalWrite(k,LOW); // se apaga el LED
      delay(100);
    }
    forward=1;
  }
}