#include <NewPing.h>


//Sensor 1 (argada)
#define PINO_TRIGGER  12
#define PINO_ECHO     11
#define DISTANCIA_MAXIMA 500

//Sensor 2 (Chegada)
#define PINO_TRIGGER2  2
#define PINO_ECHO2     3
#define DISTANCIA_MAXIMA2 500

#define INICIO 5 //Porta do LED

int distancia1;
int distancia2;

NewPing sonar1(PINO_TRIGGER, PINO_ECHO, DISTANCIA_MAXIMA);
NewPing sonar2(PINO_TRIGGER2, PINO_ECHO2, DISTANCIA_MAXIMA2);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  distancia1 = sonar1.convert_cm(sonar1.ping_median());
  distancia2 = sonar2.convert_cm(sonar2.ping_median());

  if (distancia1 < 15)
  {
    digitalWrite(INICIO, HIGH);

  }

    if (distancia2 < 15)
    {
      digitalWrite(INICIO, LOW);
    }

  delay(50);

}