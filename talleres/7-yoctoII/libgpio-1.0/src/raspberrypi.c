#include <stdio.h>
#include <gpio.h>

int main()
{
  int repeat = 10;

  /*
	 * Enable GPIO pins
	 */
  if (exportPin(17) == -1 || exportPin(24) == -1)
    return (1);

  /*
	 * Set GPIO directions
	 */
  if (pinMode(17, 1) == -1 || pinMode(24, 0) == -1)
    return (2);

  blink(17, 0.5, 5);

  do
  {
    printf("I'm reading %d in GPIO %d\n", digitalRead(24), 24);

    delay(500);
  } while (repeat--);

  /*
	 * Disable GPIO pins
	 */
  if (unexportPin(17) == -1 || unexportPin(24) == -1)
    return (4);

  return 0;
}