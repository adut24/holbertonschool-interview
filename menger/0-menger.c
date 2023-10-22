#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
*/
void menger(int level)
{
	int size, i, j, x, y, empty = 0;

	if (level < 0)
		return;

	size = pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			i = x;
			j = y;
			empty = 0;

			while (i > 0 || j > 0)
			{
				if (i % 3 == 1 && j % 3 == 1)
				{
					empty = 1;
					break;
				}
				i /= 3;
				j /= 3;
			}
			if (empty)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
