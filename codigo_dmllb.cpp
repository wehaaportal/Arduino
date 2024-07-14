#include <Wire.h>

#include <LiquidCrystal_I2C.h>

//Creamos el objeto lcd con la dirección 0x3F, 16 columnas y 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

/* Sensor de movimiento PIR */
int pirPin = 2;  // Pin digital al que está conectado el sensor PIR
int pirState = LOW;  // Variable para almacenar el estado del sensor PIR
int LED = 4; // Pin del LED
int pinBuzzer = 8; // Pin del Buzzer
int tonos[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494}; // Frecuencia de tono
int countTonos = 10;

void setup() {
  // Inicializamos el objeto lcd
  lcd.init();

  //Encendemos la luz de fondo.
  lcd.backlight();
  lcd.clear();

  // Iniciar led
  pinMode(LED,OUTPUT);

  // Escribimos un Mensaje en la pantalla LCD.
  lcd.setCursor(0, 0);
  lcd.print("System Security");
  lcd.setCursor(0, 1);
  lcd.print("Welcome to SS ");

  pinMode(pirPin, INPUT);  // Configura el pin del sensor PIR como entrada
}

void loop() {
  pirState = digitalRead(pirPin);  // Lee el estado del sensor PIR

  lcd.display(); 
  //lcd.scrollDisplayLeft(); 

  lcd.clear();  // Borra la pantalla LCD

  if (pirState == HIGH) {  // Si se detecta movimiento
    lcd.setCursor(0, 0);
    lcd.print("Alerta!");
    digitalWrite(LED,LOW);
    for (int iTono = 0; iTono < countTonos; iTono++)
    {
      tone(pinBuzzer, tonos[iTono]);
      delay(1000);
    }
    //delay(1000);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Todo tranquilo!");
    digitalWrite(LED,HIGH);
    noTone(pinBuzzer);
  }
  delay(500);
}
