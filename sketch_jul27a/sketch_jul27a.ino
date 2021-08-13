int A,B,C;

void setup() {
  Serial.begin(9600);
  }
void loop()
{
while(Serial.available()<=0);
A=10;
while(Serial.available()<=0);
B=20
while((A+B)%2==0)
{
C=A+B;
Serial.print(C);
  }}
