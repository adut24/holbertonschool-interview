#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome or not
 * @n: number to check
 * Return: 1 if it's a palindrome or 0 if not.
*/
int is_palindrome(unsigned long n)
{
	return (n == reverse_number(n));
}

/**
 * reverse_number - Reverse a number.
 * @n: number to reverse
 * Return: the number n reversed.
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
