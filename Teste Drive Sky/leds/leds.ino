const int in_a = 2;
const int in_b = 3;
const int en = 4;

int dly_cte = 20;
int effect = 1;

void setup() {
  Serial.begin(9600);
  pinMode(in_a, OUTPUT);
  pinMode(in_b, OUTPUT);
  pinMode(en, OUTPUT);
  digitalWrite(en, LOW);
}

void loop() 
{
  if (Serial.available())
  {
    int dado = Serial.read();

    switch (dado)
    {
      case '0': dly_cte = 50; break;
      case '1': dly_cte = 150; break;
      case '2': dly_cte = 200; break;
      case '3': dly_cte = 250; break;
      case '4': dly_cte = 300; break;
      case '5': dly_cte = 500; break;

      case 'a': effect = 1; break;
      case 'b': effect = 2; break;
      case 'c': effect = 3; break;
    }
  }
  
  if (effect == 1)
  {
    digitalWrite(en, HIGH);
    digitalWrite(in_a, HIGH);
    digitalWrite(in_b, LOW);
    delay(dly_cte);
    digitalWrite(in_b, HIGH);
    digitalWrite(in_a, LOW);
    delay(dly_cte);
  }

  if (effect == 2)
  {
    digitalWrite(in_a, HIGH);
    digitalWrite(in_b, LOW);

    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 1) 
    {
      analogWrite(en, fadeValue);
      delay(15);
    }
  
    // fade out from max to min in increments of 5 points:
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 1) 
    {
      analogWrite(en, fadeValue);
      delay(15);
    }
  }
  
  if (effect == 3)
  {
    
  }
}
