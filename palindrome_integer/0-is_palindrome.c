#include "palindrome.h"

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome.
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	char content[21];
	int len, i = 0;

	sprintf(content, "%lu", n);
	len = strlen(content) - 1;

	while(i < len)
	{
		if(content[i] != content[len])
		{
			return (0);
		}
		i++;
		len--;
	}
	return (1);
}
