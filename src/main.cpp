#include <Arduino.h>

/*  Button's  */
#define F1_BTN 2
#define F2_BTN 3
#define F3_BTN 4
#define F4_BTN 5

/*  Switch  */
#define DOOR_LOCK_SWITCH 6

/*  LED's  */
#define WATER_LEVEL_LED 7
#define WATER_HEAT_LED 8
#define INPUT_PIPE_LED 13
#define OUTPUT_PIPE_LED 19

/*  Drum  */
#define WASHING_DRUM_POSITION_LSB 9
#define WASHING_DRUM_POSITION 10
#define WASHING_DRUM_POSITION_MSB 11
#define WASHING_DRUM_ON_OFF 12

/*  Pipe's  */
#define INPUT_PIPE 14
#define OUTPUT_PIPE 15

/*  Metric's  */
#define WATER_LEVEL_MEASURE 16
#define WATER_HEAT_MEASURE 18

/*  Other's  */
#define WATER_HEAT_ON_OFF 17

int period = 500;
unsigned long timeNow = 0;

void setup()
{

  Serial.begin(9600);

  /*  Input's  */
  pinMode(F1_BTN, INPUT_PULLUP);
  pinMode(F2_BTN, INPUT_PULLUP);
  pinMode(F3_BTN, INPUT_PULLUP);
  pinMode(F4_BTN, INPUT_PULLUP);
  pinMode(DOOR_LOCK_SWITCH, INPUT_PULLUP);
  pinMode(WATER_LEVEL_MEASURE, INPUT_PULLUP);
  pinMode(WATER_HEAT_MEASURE, INPUT_PULLUP);

  /*  Output's  */
  pinMode(WATER_LEVEL_LED, OUTPUT);
  pinMode(WATER_HEAT_LED, OUTPUT);
  pinMode(WASHING_DRUM_POSITION_LSB, OUTPUT);
  pinMode(WASHING_DRUM_POSITION, OUTPUT);
  pinMode(WASHING_DRUM_POSITION_MSB, OUTPUT);
  pinMode(WASHING_DRUM_ON_OFF, OUTPUT);
  pinMode(INPUT_PIPE_LED, OUTPUT);
  pinMode(INPUT_PIPE, OUTPUT);
  pinMode(OUTPUT_PIPE, OUTPUT);
  pinMode(WATER_HEAT_ON_OFF, OUTPUT);
  pinMode(OUTPUT_PIPE_LED, OUTPUT);
}

void loop()
{
  if (millis() >= timeNow + period)
  {
    timeNow += period;
    Serial.println(analogRead(WATER_LEVEL_MEASURE));
  }

  if (!digitalRead(F1_BTN))
  {
    digitalWrite(INPUT_PIPE, HIGH);
    digitalWrite(INPUT_PIPE_LED, HIGH);
  }
  else
  {
    digitalWrite(INPUT_PIPE, LOW);
    digitalWrite(INPUT_PIPE_LED, LOW);
  }

  if (!digitalRead(F2_BTN))
  {
    digitalWrite(OUTPUT_PIPE, HIGH);
    digitalWrite(OUTPUT_PIPE_LED, HIGH);
  }
  else
  {
    digitalWrite(OUTPUT_PIPE, LOW);
    digitalWrite(OUTPUT_PIPE_LED, LOW);
  }
}