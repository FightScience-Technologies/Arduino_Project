 
void Memoria()
{
  
  while (0 == 0)
  { 
    if (NoP == 0)
    {
      if (Serial.available() > 0)
      {
        incomingByte = Serial.read();
        if (incomingByte == 'x')
        {
          Salir();
        }
        else if (incomingByte == 'r')
        {
          Serial.println("Secuencia aleatoria");
          Serial.println("Rango de numeros");
          InsertarNumero();
          rango=numero;
          while (rango>=10)
          {
            Serial.println("El rango maximo de numeros son 10");
            InsertarNumero();
          }
          InicioLed();
          for (int i = 0; i < numero; i++)
          {
            int vr = random(1, 7);
            V[i] = vr;
            Serial.println(vr);
          }
          NoP=1;
        }
        else if (incomingByte == 'v')
        { 
          Serial.println("Secuencia Predeterminada");
          Serial.println("Ingrese Rango");
          InsertarNumero();
          rango= numero;
          while (numero>=10)
          {
           Serial.println("El rango maximo de numeros son 10");
           InsertarNumero();
          }
          Serial.println("Ingresar los valores");
          for (int i=0;i<rango;)
          {
            InsertarNumero();
            Val = numero;
            if(Val>0 && Val <=6)
            {
              V1[i] = Val;
              Serial.print("- \n");
              V[i] = V1[i];
              i++;
            }
            else if (Val>6)
            { 
              Serial.println("Ingrese otro valor entre (0 a 6)");
            }
          }                 
            NoP=1;
            Val = 0;
        }   
      }
    }
    else
    { 
      for (int i = 0; i < rango; i++)
      { 
      digitalWrite(Leds[V[i]], HIGH);
      delay(1000);
      digitalWrite(Leds[V[i]], LOW);
      delay(1000);
      }
      Time1 = millis();
      InicioLed();
      Salida(); 
      for (int j=0;j<rango;j++)
      { 
      for (int i=1;i<7;i++)
      {
        if(V[j]== i)
        { 
          while(flagPress==0)
        { 
          IniAnalog();
          if(SensoAnalog[i]>800 &&  !flagPress )
          {
           digitalWrite(Leds[i],HIGH);
           Serial.println("\nSensor # " + String(i));
           Mostrarpeso(); 
           delay(50);
           flagPress=1;
           c=c+1;
           OffAll();
           SensoAnalog-SensoAnalog[i];
          }
          
          for (int k=1;k<7;k++)
          { 
          if(SensoAnalog[k]>800)
            { 
              if(k!=i)
              { Serial.println("Se presiono otro sensor");
                k=7;
                i=7;
                j=rango;
                flagPress=1;
                c=0;
              }
             }
            } 
           }
         flagPress=0;
         }
        
        }
       } 
      if (c == rango)
      {
        
        Serial.println("Ejercicio termiando");
        Serial.print("tiempo de la prueba: ");
        Serial.print((millis() - Time1) / 1000);
        Serial.print(" Segundos \n");
        Time3 = 0;
        NoP = 0;
        c=0;
        Finalizo();
        Serial.println("Presione x: salir  --- v: ingresar nueva secuencia --- r: nueva secuencia aleatoria ");
      }
      
      }
    }
  }


  
