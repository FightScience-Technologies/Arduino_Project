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
           Serial.println("Ingrese el tiempo de la prueba");
          InsertarNumero();
          V3[0] = numero;
          Serial.println( "Ingrese Numero de Round");
          InsertarNumero();
          while (numero > 7)
          {
            Serial.println("No esta dentro del limite");
            InsertarNumero();
          }
          V3[1] = numero;
          Serial.println("Ingrese Tiempo de descanso");
          InsertarNumero();
          V3[2] = numero;
          Serial.println("Numero de leds a usar");
          InsertarNumero();
          while (numero > 10)
          {
            Serial.println("No esta dentro del limite");
            InsertarNumero();
          }
          V3[3] = numero;
          cont_v = 0;
          Val = 0;
          Serial.println("Qué leds usará? seleccione entre 1 y 6 (En orden de secuencia)");
          while (true)
          {
            Val = Serial.parseInt();
            if (Val > 0 && Val <= 6)
            {
              V[cont_v] = Val;
              cont_v = cont_v + 1;
              Serial.print(Val, DEC);
              Serial.print("- \n");
              Val = 0;
            }
            else if (Val > 6)
            {
              Serial.println("Ingrese otro valor entre (0 a 6)");
              cont_v = cont_v;
              Val = 0;
            }
            if (cont_v == V3[3])
            {
              break;
            }
          }
          if (cont_v >= data)
          {
            cont_v = 0;
            Time3 = 0;
            Step = 0;
            Val = 0;
          }
          Serial.println("Ingrese el tiempo de encendido entre leds");
          InsertarNumero();
          V3[4] = numero;
          InicioLed();
          elpipe = 1;
          c = 0;
          Previus = millis();
          TimePa = millis() + (V3[0] * 1000);    
          while (c < V3[1] && millis() < TimePa)
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
