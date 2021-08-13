int RED = D1; 
int GREEN = D2;
int BLUE = D3;
void setup() {
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
}
void loop() { 
for(int i=20;i>0;i--)
{
digitalWrite(RED,HIGH);
digitalWrite(GREEN,HIGH);
digitalWrite(BLUE,LOW);
delay (i*10); 
digitalWrite(RED,HIGH);
digitalWrite(GREEN,LOW);
digitalWrite(BLUE,HIGH);
delay (1*100);
digitalWrite(RED,LOW);
digitalWrite(GREEN,HIGH);
digitalWrite(BLUE,HIGH);
delay (i*100); 
}

}
