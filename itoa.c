#include <stdlib.h>

/**
 * _itoa - converts unsigned integer to alphanumeric
 * @num: number to convert to string
 * Return: text of number
 */
char *_itoa(unsigned int num)
{
	int divisor = 1, d, t, index = 0, highestorderdigit = 0;
	char *digits = NULL;

	if (num <= 0)
		return ("0");
	else if (num > 5000)
		return ("5000 is max");

	digits = malloc(5 * sizeof(char));
	if (digits == NULL)
		return (NULL);

	divisor = 1000;
	for (t = 0; t < 4; t++)
	{
		d = (num / divisor) % 10;
		if ((d != 0) && !highestorderdigit)
			highestorderdigit = 1;
		if (highestorderdigit)
		{
			digits[index++] = d + '0';
		}
		divisor = divisor / 10;
	}
	digits[index] = '\0';
	return (digits);
}
