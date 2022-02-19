
void setupGlobales()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LedGre1, OUTPUT);
  pinMode(LedRed1, OUTPUT);
  pinMode(LedGre2, OUTPUT);
  pinMode(LedRed2, OUTPUT);
  pinMode(LedGre3, OUTPUT);
  pinMode(LedRed3, OUTPUT);
  pinMode(LedGre4, OUTPUT);
  pinMode(LedRed4, OUTPUT);
  pinMode(LedIni, OUTPUT);
  pinMode(alarma, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  Serial.setTimeout(1500);
  randomSeed(analogRead(A7));
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.print("\nLectura del valor del ADC:  ");
  Serial.println(scale.read()); Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  scale.set_scale(47777);
  scale.tare(100);
}

void Acerto()
{
  digitalWrite(LedIni, HIGH);
  delay(150);
  digitalWrite(LedIni, LOW);
  delay(150);
  digitalWrite(LedIni, HIGH);
  delay(150);
  digitalWrite(LedIni, LOW);
  Serial.println("Bien hecho campeón");
  delay(200);
}

void error()
{
  digitalWrite(LedGre4, HIGH);
  delay(150);
  digitalWrite(LedGre4, LOW);
  delay(150);
  digitalWrite(LedGre4, HIGH);
  delay(150);
  digitalWrite(LedGre4, LOW);
  Serial.println("\nMas suerte para la proxima");
  delay(200);
}

void Gol()
{
  if (Nu > 0)
  {
    Time2 = millis() - Time3;
    if (Time2 > 50)
    { //Verificar que si se esta haciendo bien la conversión de tiempo entre golpes
      Serial.print("Tiempo entre golpes: ");
      Serial.print(Time2 / 1000);
      Serial.println("  Segundos ");
    }
    Nu = 0;
  }
  Pat = Pat + 1;
  Nu = Nu + 1;
  Time3 = millis();
}

void Finalizo()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(LedIni, HIGH);
    digitalWrite(alarma, HIGH);
    digitalWrite(LedGre4, HIGH);
    delay(500);
    digitalWrite(LedGre4, LOW);
    digitalWrite(LedIni, LOW);
    digitalWrite(alarma, LOW);
    delay(500);
    digitalWrite(LedGre1, HIGH);
    digitalWrite(LedGre2, HIGH);
    digitalWrite(LedGre3, HIGH);
    digitalWrite(LedRed1, HIGH);
    digitalWrite(LedRed2, HIGH);
    digitalWrite(LedRed3, HIGH);
    delay(200);
    digitalWrite(LedGre1, LOW);
    digitalWrite(LedGre2, LOW);
    digitalWrite(LedGre3, LOW);
    digitalWrite(LedRed1, LOW);
    digitalWrite(LedRed2, LOW);
    digitalWrite(LedRed3, LOW);
    delay(200);
  }

}

void OffAll()
{
  digitalWrite(LedIni, LOW);
  digitalWrite(LedGre1, LOW);
  digitalWrite(LedGre2, LOW);
  digitalWrite(LedGre3, LOW);
  digitalWrite(LedGre4, LOW);
  digitalWrite(LedRed1, LOW);
  digitalWrite(LedRed2, LOW);
  digitalWrite(LedRed3, LOW);
  digitalWrite(LedRed4, LOW);

}

void Salir()
{
  Serial.println("\nVolviendo al menu");
  printMenu();
}
void Salida()
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    if (incomingByte == 'x')
    {
      Salir();
    }
  }
}
void printMenu()
{
  Serial.println("Seleccione ejercicio");
  Serial.println("e--Velocidad de reaccion");
  Serial.println("f--Memoria");
  Serial.println("g--Secuencia");
  Serial.println("h--Libre");
  Serial.println("i--Velocidad gestual de reacción");
  Serial.println("j--Modo libre de reacción");
  Inicializacion();
}
void Inicializacion()
{
  while (true)
  {
    if (Serial.available() > 0)
    {
      // read the incoming byte:
      incomingByte = Serial.read();
      if (incomingByte == 'e')
      {
        Serial.println("Ejercicio 1 seleccionado: Velocidad de reacción");
        Serial.println("Presione x: Salir -- k-- Modo predeterminado, r--Modo aleatorio");
        Velocidad_Reaccion();
      }
      else if (incomingByte == 'f')
      {
        Serial.println("Ejercicio 2 seleccionado: Memoria");
        Serial.println("Presione x: Salir  --- v: Ingresar secuencia -- r: Modo aleatorio ");
        Memoria();
      }
      else if (incomingByte == 'g')
      {
        Serial.println("Ejercicio 3 seleccionado: Secuencia ");
        Serial.println("Presione x: Salir  --- v: Ingresar secuencia --- r: Modo aleatorio ");
        Secuence();
      }
      else if (incomingByte == 'h')
      {
        Serial.println("Ejercicio 4 seleccionado: Libre");
        Serial.println("Presione x: Salir  --- k: Predeterminado --- r: Modo libre --- l: Modo libre competencia ");
        Libre();
      }
      else if (incomingByte == 'i')
      {
        Serial.println("Ejercicio 5 seleccionado: Velocidad Gestual");
        Serial.println("Presione x: Salir  --- k: Predeterminado --- r: Modo aleatorio ");
        Gestual();
      }
      else if (incomingByte == 'j')
      {
        Serial.println("Ejercicio 6 seleccionado: Modo Libre de Reacción");
        Serial.println("Presione x: Salir  --- k: Predeterminado --- r: Modo aleatorio --- m: Modo mixto ");
        modoLibreReaccion();
      }
    }
  }
}
void InsertarNumero()
{
  while (tiempos == 0)
  {
    if (Serial.available())
    {
      int data = 0;
      data = Serial.parseInt();
      delay(100);
      if (data != 0)
      {
        DEBUG(data);
        TimePa = millis() + (data * 1000);
        Pat = 0;
        tiempos = 1;
        numero = data;
      }
    }
  }
  tiempos = 0;
}

void InicioLed()
{
  digitalWrite(LedIni, HIGH);
  digitalWrite(alarma, HIGH);
  delay(500);
  digitalWrite(LedIni, LOW);
  digitalWrite(alarma, LOW);
  delay(500);
  digitalWrite(LedIni, HIGH);
  digitalWrite(alarma, HIGH);
  delay(500);
  digitalWrite(LedIni, LOW);
  digitalWrite(alarma, LOW);
  delay(500);
}
void IniAnalog()
{
  for ( int i = 0; i < 7; i++)
  {
    SensoAnalog[i] = analogRead(i);
  }
}
void Mostrarpeso()
{
  if (scale.is_ready())
  {
    Serial.print("peso ");
    r = abs(((scale.get_units(1) * 10)));
    Serial.print(abs(r));
    Serial.println(" kg");
    delay(100); 
  }
  else
  {
    Serial.println("HX711 no se encuentra");
  }
}
void Aleatorio()
{
  alea2 = random(200, 3000);
  aleatorio2 = random(1, 19);
  for (int i = 1; i < 7; i++)
  {
    if (aleatorio2 == i || aleatorio2 == i + 6 || aleatorio2 == i + 12)
    {
      delay(alea2);
      Previus = millis();
      flagEx2 = i;
      digitalWrite(Leds[i], HIGH);
    }
  }
}

void Swap (int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Randomize (int arr[], int n) //For generate a random position of vector values
{
  for (int i = n - 1; i > 0; i--)
  {
    if(arr[i]!=0)
    {
    int j = rand() % (i + 1);
    Swap(&arr[i], &arr[j]);
    }
  }
}
