void Velocidad_Reaccion()
{
  while (0 == 0)
  {
    if (Serial.available() > 0)
    {
      incomingByte = Serial.read();
      if (incomingByte == 'x')
      {
        Salir();
      }
      if (incomingByte == 'k')
      {
        alea = random(500, 3000);
        Serial.println("Ingrese el numero del sensor");
        InsertarNumero();
        while (numero > 6)
        { Serial.println("Ingrese Numero dentro del rango");
          InsertarNumero();
        }
        Serial.println("Tome posición inicial");
        while (true)
        {
          for (int i = 0; i < 7; i++)
          {
            while (numero == i)
            {
              Salida();
              IniAnalog();
              if (SensoAnalog[0] > 800)
              {
                delay(alea);
                Previus = millis();
                digitalWrite(Leds[i], HIGH);
                flagEx1 == i;
                i = 7;
              }
            }
          }
          salidaVel();
        }
      }
      else if (incomingByte == 'r')
      {
        Serial.println("Tome posición inicial");
        while (true)
        {

          alea2 = random(200, 3000);
          aleatorio2 = random(1, 19);
          for (int i = 1; i < 7; i++)
          {
            if (aleatorio2 == i || aleatorio2 == i + 6 || aleatorio2 == i + 12)
            { while (true)
              {
                Salida();
                IniAnalog();
                if (SensoAnalog[0] > 800)
                {
                  delay(alea2);
                  Previus = millis();
                  digitalWrite(Leds[i], HIGH);
                  break;
                }
              }
            }
          }
          salidaVel();
          Step = 0;
        }
      }
    }
  }
}

void salidaVel()
{
  elpipe = 0;
  while (elpipe == 0)
  { IniAnalog();
    if (SensoAnalog[0] < 800)
    {
      Serial.print("\nEl tiempo que se demoro despegando el pie es: ");
      Serial.print((millis() - Previus) / 1000);
      Serial.println(" Segundos");
      elpipe = 1;
    }
  }
  tiempos = 1;
  while (tiempos == 1)
  { IniAnalog();
    for ( int i = 1; i < 7; i++)
    {
      if ( SensoAnalog[i] > 800)
      {
        digitalWrite(Leds[i], LOW);
        Serial.println("\nSensor #" + String(i));
        Mostrarpeso();
        tiempos = 0;
      }
    }
  }
  Milli = millis();
  Time1 = Milli - Previus;
  Serial.print("Tiempo toda la prueba: ");
  Serial.print(Time1 / 1000);
  Serial.println(" Segundos");
  Finalizo();
  Previus = 0;
  tiempos = 0;
  Serial.println("Ejercicio terminado");
  Serial.println("Presione x: salir --- Tome posicion inicial para repetir el ejericio");
}
