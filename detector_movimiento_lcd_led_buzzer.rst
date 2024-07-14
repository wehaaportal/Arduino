#Sensor de movimiento con pantalla LCD, Led y Buzzer
Este código implementa un sistema de seguridad utilizando un Arduino, un sensor de movimiento PIR, un LCD I2C, un LED y un buzzer. 

Diagrama de Conexión
Para generar un diagrama de cómo sería la conexión con el Arduino, aquí tienes la descripción de las conexiones necesarias:

LCD I2C:

SDA -> A4 (en Arduino Uno)
SCL -> A5 (en Arduino Uno)
VCC -> 5V
GND -> GND
Sensor PIR:

VCC -> 5V
GND -> GND
OUT -> Pin digital 2
LED:

Anodo -> Pin digital 4 (a través de una resistencia)
Cátodo -> GND
Buzzer:

VCC -> Pin digital 8
GND -> GND
