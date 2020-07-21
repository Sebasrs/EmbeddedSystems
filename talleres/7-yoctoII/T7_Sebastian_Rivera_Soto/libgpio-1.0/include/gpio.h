#ifndef _GPIO_H
#define _GPIO_H

int exportPin(int pin);
int unexportPin(int pin);
int pinMode(int pin, int mode);
int digitalWrite(int pin, int value);
int digitalRead(int pin);
void blink(int pin, float freq, int duration);
void delay(unsigned int milliseconds);

#endif