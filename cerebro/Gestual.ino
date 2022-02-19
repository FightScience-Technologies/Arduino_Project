void Gestual()
{
  elpipe = 1;
  while (0 == 0)
  {
    if (Serial.available() > 0)
    {
      incomingByte = Serial.read();
      if (incomingByte == 'x')
      {
        Salir();
      }
      if (incomingByte == 'r')
      {
        Serial.println("Ingrese el Tiempo de la prueba");
        InsertarNumero();
        while (millis() < TimePa)
        { Aleatorio();
          if (flagEx2 == 1 || flagEx2 == 2 || flagEx2 == 3 || flagEx2 == 4 || flagEx2 == 5 || flagEx2 == 6)
          {
            elfla = 0;
            int flagPress = 0;
            alea2 = random(500, 1200);
            while (millis() - Previus <= alea2)
            {
              for (int i = 1; i < 7; i++)
              { IniAnalog();
                if (SensoAnalog[i] > 800 && flagEx2 == i)
                {
                  Milli = millis();
                  Time1 = Milli - Previus;
                  Serial.println("\nSensor # " + String(i));
                  Mostrarpeso();
                  Serial.print("Tiempo de reacción: ");
                  Serial.print(Time1 / 1000);
                  Serial.println("  Segundos");
                  flagEx2 = 0;
                  digitalWrite(Leds[i], LOW);
                  elfla = 1;
                  Gol();
                  Acerto();
                  Serial.println("Preparese...");
                }
              }
            }
            OffAll();
            if (elfla == 0)
            {
              error();
            }
          }
        }

        Serial.println("\nCantidad de patadas: ");
        Serial.println(Pat);
        Finalizo();
        Serial.println("Presione x: salir  --- k: Predeterminado --- r: Modo aleatorio ");
      }

      if (incomingByte == 'k')
      {
        elfla = 0;
        Serial.println("Ingrese el Tiempo de la prueba");
        InsertarNumero();
        TimePa2 = millis() + (numero * 1000);
        Serial.println("Ingrese Sensor");
        InsertarNumero();
        while (millis() < TimePa2)
        {
          flagEx2 = 0;
          alea2 = random(500, 1200);
          delay(alea2);
          for (int i = 1; i < 7; i++)
          {
            if (numero == i)
            {
              Previus = millis();
              flagEx2 = i;
              digitalWrite(Leds[i], HIGH);
            }
          }
          if (flagEx2 == 1 || flagEx2 == 2 || flagEx2 == 3 || flagEx2 == 4 || flagEx2 == 5 || flagEx2 == 6)
          {
            elfla = 0;
            while (millis() - Previus <= alea2)
            {
              for (int i = 1; i < 7; i++)
              { IniAnalog();
                if (SensoAnalog[i] > 800 && flagEx2 == i)
                {
                  Milli = millis();
                  Time1 = Milli - Previus;
                  Serial.println("\nSensor # " + String(i));
                  Mostrarpeso();
                  Serial.print("Tiempo de reacción: ");
                  Serial.print(Time1 / 1000);
                  Serial.println("  Segundos");
                  flagEx2 = 0;
                  digitalWrite(Leds[i], LOW);
                  elfla = 1;
                  Gol();
                  Acerto();
                  Serial.println("Preparese...");
                }
              }
            }
            OffAll();
            if (elfla == 0)
            {
              error();
            }
          }

        }
        Serial.println("\nCantidad de patadas: ");
        Serial.println(Pat);
        Finalizo();
        Time3 = 0;
        Serial.println("Presione x: salir  --- k: Predeterminado --- r: Modo aleatorio ");
      }
    }
  }
}
