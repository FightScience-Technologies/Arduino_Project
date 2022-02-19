void modoLibreReaccion()
{
  while (0 == 0)
  {
    if (Serial.available() > 0)
    {
      while (true)
      {
        incomingByte = Serial.read();
        if (incomingByte == 'x')
        {
          Salir();
        }
        if (incomingByte == 'k')
        {
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
          Serial.println("Rango de leds");
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
            int n = sizeof(V) / sizeof(V[0]);
            for (int i = 0; i < V3[3]; i++)
            {
              while (true)
              {
                IniAnalog();
                delay(V3[4] * 1000);
                digitalWrite(Leds[V[i]], HIGH);
                tiempos = 0;
                break;
              }
              while (tiempos == 0)
              {
                for ( int j = 1; j < 7; j++)
                { IniAnalog();
                  if ( SensoAnalog[j] > 800 )
                  {
                    digitalWrite(Leds[V[i]], LOW);
                    Serial.println("\nSensor #" + String(V[i]));
                    Mostrarpeso();
                    tiempos = 1;
                    j = 7;
                  }
                }
              }
              elpipe = 1;
              if (i == V3[3] - 1)
              {
                c ++;
                Serial.print("Este es el delay en segundos: ");
                Serial.println(V3[2]);
                delay(V3[2] * 1000);
              }
            }
          }
          
          Finalizo();
          Milli = millis();
          Time1 = Milli - Previus;
          Serial.print("Tiempo toda la prueba: ");
          Serial.print(Time1 / 1000);
          Serial.println(" Segundos");
          Finalizo();
          Previus = 0;
          tiempos = 0;
          Serial.println("Ejercicio termiando");
          Serial.println("Presione x: salir --- k: Reiniciar secuencia -- l:nueva secuencia");
        }
        if (incomingByte == 'r')
        {
          //          Serial.println("Ingrese el tiempo de la prueba");
          //          InsertarNumero();
          //          V3[0] = TimePa;
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
          Serial.print("Rango de leds: ");
          V3[3] = random(1, 11);
          Serial.println(V3[3]);
          for (int i = 0; i < V3[3]; i++)
          {
            int vr = random(1, 7);
            V[i] = vr;
            Serial.println(vr);
          }
          V3[4] = random(1, 4);
          InicioLed();
          elpipe = 1;
          c = 0;
          Previus = millis();
          while (c < V3[1])
          {
            int n = sizeof(V) / sizeof(V[0]);
            for (int i = 0; i < V3[3]; i++)
            {
              while (true)
              {
                IniAnalog();
                Serial.print("segundos entre leds  ");
                Serial.println(V3[4]);
                delay(V3[4] * 1000);
                digitalWrite(Leds[V[i]], HIGH);
                tiempos = 0;
                break;
              }
              while (tiempos == 0)
              {

                for ( int j = 1; j < 7; j++)
                { IniAnalog();
                  if ( SensoAnalog[j] > 800 )
                  {
                    digitalWrite(Leds[V[i]], LOW);
                    Serial.println("\nSensor #" + String(V[i]));
                    Mostrarpeso();
                    tiempos = 1;
                    j = 7;
                  }
                }
              }
              elpipe = 1;
              if (i == V3[3] - 1)
              {
                c ++;
                Serial.print("Este es el delay en segundos: ");
                Serial.println(V3[2]);
                delay(V3[2] * 1000);
              }
            }
          }
          Finalizo();
          Milli = millis();
          Time1 = Milli - Previus;
          Serial.print("Tiempo toda la prueba: ");
          Serial.print(Time1 / 1000);
          Serial.println(" Segundos");
          Finalizo();
          Previus = 0;
          tiempos = 0;
          Serial.println("Ejercicio termiando");
          Serial.println("Presione x: salir --- r: Reiniciar secuencia -- v:nueva secuencia");
        }
        if (incomingByte == 'm')
        {
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
          Serial.println("Rango de leds");
          InsertarNumero();
          while (numero > 10)
          {
            Serial.println("No esta dentro del limite");
            InsertarNumero();
          }
          V3[3] = numero;
          break;
        }
      }
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

      Serial.println("Orden de los leds: presione el número de la selección deseada -- 1: Aleatorio -- 2: Predeterminado");
      InsertarNumero();
      while (numero > 2)
      {
        Serial.println("Escoja dentro de las dos opciones");
        InsertarNumero();
      }
      if (numero == 2)
      {
        Serial.println("Tiempo encendido entre leds: presione el número de la selección deseada -- 1: Aleatorio -- 2: Predeterminado");
        InsertarNumero();
        while (numero > 2)
        {
          Serial.println("Escoja dentro de las dos opciones");
          InsertarNumero();
        }
        if (numero == 1)
        {
          V3[4] = random(1, 4);
        }
        if (numero == 2)
        {
          Serial.println("Ingrese el tiempo");
          InsertarNumero();
          V3[4] = numero;
        }
      }
      else if (numero == 1)
      {
        Randomize(V, V3[3]);
        for (int i = 0; i < V3[3]; i++)
        {
          int l = V[i];
          Serial.println(l);
        }
        Serial.println("Tiempo encendido entre leds: presione el número de la selección deseada -- 1: Aleatorio -- 2: Predeterminado");
        InsertarNumero();
        while (numero > 2)
        {
          Serial.println("Escoja dentro de las dos opciones");
          InsertarNumero();
        }
        if (numero == 1)
        {
          V3[4] = random(1, 4);
        }
        if (numero == 2)
        {
          Serial.println("Ingrese el tiempo");
          InsertarNumero();
          V3[4] = numero;
        }
      }
      InicioLed();
      elpipe = 1;
      c = 0;
      Previus = millis();
      while (c < V3[1])
      {
        int n = sizeof(V) / sizeof(V[0]);
        for (int i = 0; i < V3[3]; i++)
        {
          while (true)
          {
            IniAnalog();
            Serial.print("Tiempo entre led: ");
            Serial.println(V3[4]);
            delay(V3[4] * 1000);
            digitalWrite(Leds[V[i]], HIGH);
            tiempos = 0;
            break;
          }
          while (tiempos == 0)
          {

            for ( int j = 1; j < 7; j++)
            { IniAnalog();
              if ( SensoAnalog[j] > 800 )
              {
                digitalWrite(Leds[V[i]], LOW);
                Serial.println("\nSensor #" + String(V[i]));
                Mostrarpeso();
                tiempos = 1;
                j = 7;
              }
            }
          }
          elpipe = 1;
          if (i == V3[3] - 1)
          {
            c ++;
            Serial.print("Este es el delay en segundos: ");
            Serial.println(V3[2]);
            delay(V3[2] * 1000);
          }
        }
      }
      Finalizo();
      Milli = millis();
      Time1 = Milli - Previus;
      Serial.print("Tiempo toda la prueba: ");
      Serial.print(Time1 / 1000);
      Serial.println(" Segundos");
      Finalizo();
      Previus = 0;
      tiempos = 0;
      Serial.println("Ejercicio termiando");
      Serial.println("Presione x: salir --- r: Reiniciar secuencia -- v:nueva secuencia");
    }
  }
}
