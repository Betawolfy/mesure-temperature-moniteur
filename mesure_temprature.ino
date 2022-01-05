/* Afficher la température sur le moniteur série - Temperature Sensor V1.1/1.2
 *  Vincent Marais | 05/01/2022
 *  github: https://github.com/Betawolfy
 */

 
#include <math.h> // librairy math néssesaire au fonctionnement au code. 
 
const int B = 4275;               // Valeur B de la thermistance
const int R0 = 100000;            // la resistance est égale à 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connecté en A0
 
#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif
 
void setup()  // mise en place du programme
{
    Serial.begin(9600); // le programme commence après 9600 millisecondes
}
 
void loop()  //boucle du programme
{
    int a = analogRead(pinTempSensor); // la valeur donnée par le Grove - Temperature Sensor est stockée dans "a"
 
    float R = 1023.0/a-1.0; 
    R = R0*R; // calcul de r
 
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convertion en température avec une formule et stockage du résultat dans la variable "temperature"
 
    Serial.print("temperature = "); 
    Serial.println(temperature);

// dans le moniteur série, il y a écrit "température" puis la valeur de "temperature"
 
    delay(100); // délai de 100 ms avant de revenir au début de la boucle.
}
/* code utilisé: 
 *  Wikiseeed : https://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/
 * Travail réalisé pour un TP. 
 */
