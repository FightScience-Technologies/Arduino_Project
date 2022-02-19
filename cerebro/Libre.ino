void Libre()
{
  while (0 == 0),
  {
    if (Serial.available() > 0)
    {
      incomingByte = Serial.read();
      if (incomingByte == 'x')
      {
        Salir();
      }
      if (incomingByte == 'l')
      {
        Serial.print("Numero de patadas a realizar: \n");
        InsertarNumero();
        rep1 = numero;
        Serial.print("Ingrese el tiempo de la prueba: \n");
        InsertarNumero();
        InicioLed();
        while (millis() < TimePa)
        {
          OffAll();
          IniAnalog();
          for ( int i = 0; i < 7; i++)
          {
            if ( SensoAnalog[i] > 800 && !flagPress)
            {

              digitalWrite(Leds[i], HIGH);
              flagPress = 1;
              Serial.println("\nSensor #" + String(i));
              Mostrarpeso();
              Serial.println("Sensor# " + String(i) + " presionado");
            }
            if (SensoAnalog[i] < 800 && flagPress == 1)
            {
              delay(50);
              flagPress = 0;
              Gol();
            }
          }
        }
        Serial.println("\nCantidad de patadas:");
        Serial.println(Pat);
        if (Pat < rep1)
        {
          Serial.println("No pudiste completar la prueba");
          digitalWrite(LedGre4, HIGH);
          delay(2000);
          digitalWrite(LedGre4, LOW);
        }
        else if (Pat >= rep1)
        {
          Serial.println("Tuviste exito con la prueba");
          digitalWrite(LedIni, HIGH);
          delay(2000);
          digitalWrite(LedIni, LOW);
        }

        Finalizo();
        TimePa = 0;
        rep1 = 0;
        OffAll();
        Serial.println("Presione x: salir  --- k: Predeterminado --- r: Modo Libre -- l: Modo competencia");
      }
      if (incomingByte == 'k')
      {
        Serial.println("Ingrese el Tiempo de la prueba");
        InsertarNumero();
        InicioLed();
        while (millis() < TimePa)
        {
          Aleatorio();
          if (flagEx2 == 1 || flagEx2 == 2 || flagEx2 == 3 || flagEx2 == 4 || flagEx2 == 5 || flagEx2 == 6)
          {
            while (elfla == 0)
            {
              IniAnalog();
              for ( int i = 1; i < 7; i++)
              {
                if (SensoAnalog[i] >= 800 && flagEx2 == i)
                {
                  Time1 = millis() - Previus;
                  Serial.println("\nSensor # " + String(i));
                  Mostrarpeso();
                  Serial.print("Tiempo de reacción: ");
                  Serial.print(Time1 / 1000);
                  Serial.println("  Segundos");
                  Gol();
                  flagEx2 = 0;
                  digitalWrite(Leds[i], LOW);
                  elfla = 1;
                  Serial.println("Preparese...");
                }
              }

            }
            elfla = 0;
          }
        }
        Serial.println("Cantidad de patadas: ");
        Serial.println(Pat);
        Finalizo();
        TimePa = 0;
        OffAll();
        Serial.println("Presione x: salir  --- k: Predeterminado --- r: Modo Libre --- l: Modo competencia ");
      }
      if (incomingByte == 'r')
      {
        Serial.print("Ingrese el tiempo de la prueba \n");
        InsertarNumero();
        InicioLed();
        while (millis() < TimePa)
        {
          OffAll();
          IniAnalog();
          for ( int i = 0; i < 7; i++)
          {
            if ( SensoAnalog[i] > 800 && !flagPress)
            {
              Serial.println("Sensor# " + String(i) + " presionado");
              digitalWrite(Leds[i], HIGH);
              flagPress = 1;
              Serial.println("\nSensor #" + String(i));
              Mostrarpeso();
            }
            if (SensoAnalog[i] < 800 && flagPress == 1)
            {
              delay(50);
              flagPress = 0;
              Gol();
            }
          }
        }
        Serial.println("\nCantidad de patadas:");
        Serial.println(Pat);
        delay(200);
        Finalizo();
        TimePa = 0;
        OffAll();
        Serial.println("Presione x: salir  --- k: Predeterminado --- r: Modo Libre -- l: Modo competencia");
      }


    }

  }
}
