#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

// Creates the file structure for the gpio pin.
// Just writes the pin number in the file
int exportPin(int pin)
{
  const int BUFFER_MAX = 3;
  char buffer[BUFFER_MAX];

  ssize_t bytesSize;
  int file;

  file = open("/sys/class/gpio/export", O_WRONLY);
  if (file == -1)
  {
    fprintf(stderr, "Failed to open export for writing!\n");
    return -1;
  }

  bytesSize = snprintf(buffer, BUFFER_MAX, "%d", pin);
  write(file, buffer, bytesSize);
  close(file);
}

// Deletes the file structure for the gpio pin.
// Just writes the pin number in the file
int unexportPin(int pin)
{
  const int BUFFER_MAX = 3;
  char buffer[BUFFER_MAX];

  ssize_t bytesSize;
  int file;

  file = open("/sys/class/gpio/unexport", O_WRONLY);
  if (file == -1)
  {
    fprintf(stderr, "Failed to open unexport for writing!\n");
    return -1;
  }

  bytesSize = snprintf(buffer, BUFFER_MAX, "%d", pin);
  write(file, buffer, bytesSize);
  close(file);
}

// Selects the mode for the gpio pin.
// Just writes the pin mode in the file
// 1 for out, 0 for in
int pinMode(int pin, int mode)
{
  const int DIRECTION_MAX = 35;
  char path[DIRECTION_MAX];
  int file;
  int size = mode == 1 ? 3 : 2;
  char *strMode = mode == 1 ? "out" : "in";

  snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
  file = open(path, O_WRONLY);
  if (file == -1)
  {
    fprintf(stderr, "Failed to open gpio direction for writing!\n");
    return (-1);
  }

  if (write(file, strMode, size) == -1)
  {
    fprintf(stderr, "Failed to set direction!\n");
    return (-1);
  }

  close(file);
  return (0);
}

// Write the pin value.
// Just writes the pin value in the file
int digitalWrite(int pin, int value)
{
  const int VALUE_MAX = 30;
  char strValue = value == 1 ? '1' : '0';

  char path[VALUE_MAX];
  int file;

  snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
  file = open(path, O_WRONLY);
  if (file == -1)
  {
    fprintf(stderr, "Failed to open gpio value for writing!\n");
    return (-1);
  }

  if (write(file, &strValue, 1) == -1)
  {
    fprintf(stderr, "Failed to write value!\n");
    return (-1);
  }

  close(file);
}

int digitalRead(int pin)
{
  const int VALUE_MAX = 30;
  char path[VALUE_MAX];
  char strValue[3];
  int file;

  snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
  file = open(path, O_RDONLY);
  if (file == -1)
  {
    fprintf(stderr, "Failed to open gpio value for reading!\n");
    return (-1);
  }

  if (read(file, strValue, 3) == -1)
  {
    fprintf(stderr, "Failed to read value!\n");
    return (-1);
  }

  close(file);

  return (atoi(strValue));
}

void delay(unsigned int milliseconds)
{

  clock_t start = clock();

  while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds)
    ;
}

void blink(int pin, float freq, int duration)
{
  int out = 0;
  int counter = 0;
  float delaySec = (1 / (freq * 2));
  int durationCounter = (duration / delaySec);

  while (counter < durationCounter)
  {
    digitalWrite(pin, out);
    counter++;
    out = !out;
    delay(delaySec * 1000);
    printf("Blinking!!\n");
  }
}