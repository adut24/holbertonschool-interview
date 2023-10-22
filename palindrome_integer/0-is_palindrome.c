#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome.
 *
 * @n: number to check
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	return (n == reverse_number(n));
}

/**
 * reverse_number - reverses a number.
 *
 * @n: number to reverse
 *
 * Return: reversed number
*/
unsigned long reverse_number(unsigned long n)
{
	unsigned long number = 0;

	while (n)
	{
		number = number * 10 + (n % 10);
		n /= 10;
	}
	return (number);
}
