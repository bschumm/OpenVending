// **********************************
// Open Vending
//
//**********************************



// Port Config

// TES = Tray Empty Sensors
// msens = motor sensors
// Analog pins können auch als Digitale pins verwendet werden

// Buttons / tes / morors / msens have to match @ pos
//
//     Schacht    1     2      3      4      5      6
//                |     |      |      |      |      |
//                |     |      |      |      |      |
//                V     V      V      V      V      V
int buttons[] = {23,   25,    27,    29,    31,    33 };
int tes[] =     {52,   50,    48,    46,    44,    42 };
int led[] =     {22,   24,    26,    28,    30,    32 };
int motors[] =  {A0,   A1,    A2,    A3,    A4,    A5 };
int msens[] =   {A8,   A9,   A10,   A11,   A12,   A13 };

int heartbeat = 53;

// Fixme: no delay !
void hb()
{
  digitalWrite(heartbeat, HIGH);
  delay(500);
  digitalWrite(heartbeat, LOW);
  delay(500);
}



void setup()
{
  pinMode(heartbeat, OUTPUT);
  
  hb();

   Serial.begin(9600); 
   Serial.println("Init");
  /* Serial Coin stuff
  Serial1.begin(9600);
  Serial1.write(1); // Status
  Serial1.println(Serial.read(), hex)
  */

  
  for(int i = 0; i < sizeof(buttons)/sizeof(int); i++)
  {
      pinMode(buttons[i], INPUT);
      digitalWrite(buttons[i], LOW);
      
      Serial.print("Button ");
      Serial.print(i , DEC);
      Serial.print(" an ");
      Serial.println(buttons[i] , DEC);
      
  }
  
  hb();
  
  for(int i = 0; i < sizeof(tes)/sizeof(int); i++)
  {
      pinMode(tes[i], INPUT);
      
      Serial.print("Tray empty sensor ");
      Serial.print(i , DEC);
      Serial.print(" an ");
      Serial.println(tes[i] , DEC);
  }

  hb();
  
  for(int i = 0; i < sizeof(motors)/sizeof(int); i++)
  {
      pinMode(motors[i], OUTPUT);
      digitalWrite(motors[i],HIGH);
      
      Serial.print("Motor ");
      Serial.print(i , DEC);
      Serial.print(" an ");
      Serial.println(motors[i] , DEC);
  }
  hb();
  
  for(int i = 0; i < sizeof(msens)/sizeof(int); i++)
  {
      pinMode(msens[i], INPUT);
      
      Serial.print("Motorsensors ");
      Serial.print(i , DEC);
      Serial.print(" an ");
      Serial.println(msens[i] , DEC);
  }
  hb();
  Serial.println("################### Ready #####################");
}


void loop()
{
//  hb();


  
  for(int i = 0; i < sizeof(buttons)/sizeof(int); i++)
  {
    
   /* int buttonpushtimer = 0;
    for(int i=0;1==1;i++)
    {
      if(digitalRead(buttons[i]) == HIGH)
      {
        buttonpushtimer++;
      }
      if(i>=500)
      {
        Serial.print("Schalter break:");
        Serial.println(buttons[i], DEC);
        break;
      }
    
      
    }
    
    */
    boolean check = false;
    
    
    //if (digitalRead(buttons[i]) == HIGH && buttonpushtimer > 200)
    if(digitalRead(buttons[i]) == HIGH)
    {
      
      check = false;
     
        
      delay(100);
     
     
      if (digitalRead(buttons[i]) == HIGH)
        {
          check = true;
          Serial.println(i, DEC);
        }    
     
     /* for(int i2 = 0; i2 < 1000 && check == true; i2++)
      {
        if (digitalRead(buttons[i]) == LOW)
        {
          check = false;
          Serial.println(i, DEC);
        } 
      }
      */
    
     if(check == true) 
     {
        
        hb();
        Serial.print("Schalter:");
        Serial.println(buttons[i], DEC);
        

        Serial.print("Motor Sensor Status: ");
        Serial.println(digitalRead(msens[i]), DEC);
        
        unsigned long time = millis();
        
        
        
        digitalWrite(motors[i], LOW);
        Serial.print("Motor ON:");
        Serial.println(motors[i], DEC);

        delay(1000); // halbe Sekunde warten bis Mororsensor angedreht ist        
        
        while(digitalRead(msens[i]) == LOW && ((millis() - time) < 8000 )) // Wenn Mortor sensor wieder OFF oder länger als 8 sec braucht
          {
            Serial.print("Motor Sensor Status");
            Serial.println(digitalRead(msens[i]), DEC);
            Serial.print("Off time: ");
            Serial.println(time - millis(), DEC);
          }   
        
        Serial.print("Motor Sensor Status");
        Serial.println(digitalRead(msens[i]), DEC);
        
        digitalWrite(motors[i], HIGH); // Motor wieder aussschalten
        Serial.print("Motor OFF:");
        Serial.println(motors[i], DEC);
        
     }
      
    }
  }
}

