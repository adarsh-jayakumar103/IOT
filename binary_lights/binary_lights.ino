int LED1=D5;
int LED2=D6;
int LED3=D3;
void setup()
{ 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
 delay(1000);
 digitalWrite(LED3, HIGH);
 delay(1000);
 digitalWrite(LED3, LOW);
 digitalWrite(LED2, HIGH);
 delay(1000);
 digitalWrite(LED3, HIGH);
 delay(1000);
 digitalWrite(LED3, LOW);
 digitalWrite(LED2, LOW);
 digitalWrite(LED1, HIGH);
 delay(1000);
 digitalWrite(LED3, HIGH);
 delay(1000);
 digitalWrite(LED3, LOW);
 digitalWrite(LED2, HIGH);
 delay(1000);
 digitalWrite(LED3, HIGH);
 delay(500);
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, LOW);
 digitalWrite(LED3, LOW);
 
}
