// Libreria celda de carga
#include "HX711.h"

// Port def
#define DEBUG(a) Serial.println(a);
const int LedGre1 = 22;
const int LedRed1 = 23;
const int LedGre2 = 24;
const int LedRed2 = 25;
const int LedGre3 = 26;
const int LedRed3 = 27;
const int LedGre4 = 28;
const int LedRed4 = 7;
const int alarma = 29;
const int LedIni = 30;
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
float r = 0;

// Variable definition
int rango,c,numero,rep1, rep3, data, data2, data3, data4, data5, Val, aleatorio2, flaco, elpipe, Pat, SensorValue0, SensorValue1, SensorValue2, SensorValue3, SensorValue4, SensorValue5, SensorValue6, t, rep, rep2, step1, valor, cont_v, tiempos, tiempos2, tiempos3, tiempos4, tiempos5 = 0;
int V[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int V1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int V2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int V3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int SensoAnalog[] = { SensorValue0 ,  SensorValue1 , SensorValue2,  SensorValue3,  SensorValue4,  SensorValue5 , SensorValue6};
int Leds[]={ LedRed4,LedGre1,LedGre2,LedGre3,LedRed1,LedRed2,LedRed3};
char fall, elfla, NoP, NoP2, C_val, Nu, flagEx1, flagEx2, flagEx3, flagPress, Step, incomingByte, NoV = 0;
long alea, alea2, TimePa, TimePa2 = 0;
float Previus, Milli, Time1, Enc1, Enc2, Enc3, Enc4, Enc5, Time2, Time3, Time4 = 0;
HX711 scale;

void setupGlobales();

void printMenu();

void Velocidad_Reaccion();

void Acerto();

void Gol();

void InsertarNumero();

void Finalizo();

void Led1Off();

void OffAll();

void Salir();

void InicioLed();

void IniAnalog();

void Mostrarpeso();

void Aleatorio();

void Salida();
