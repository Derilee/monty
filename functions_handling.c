#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: 0, if s1 and s2 are equals.
 *         another value if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index] == s2[index] && s1[index]; index++)
		;
	if (s1[index] > s2[index])
		return (1);
	if (s1[index] < s2[index])
		return (-1);
	return (0);
}

/**
 * _strchr - function to search if a char is inside a string
 * @str: string to be reviewed
 * @chr: char to find from the string
 * Return: 1 if successful, 0 if not
 */
int _strchr(char *str, char chr)
{
	int total = 0;

	while (str[total] != '\0')
	{
		if (str[total] == chr)
		{
			break;
		}
		total++;
	}
	if (str[total] == chr)
		return (1);
	else
		return (0);
}

/**
 * _strtokenize - function that cut a string into tokens
 *                depending of the delimiters
 * @s: string to cut in parts
 * @d: delimiters
 * Return: string if successful or null if failed
 */
char *_strtokenize(char *s, char *d)
{
	static char *new;
	int index = 0, line = 0;

	if (!s)
		s = new;
	while (s[index] != '\0')
	{
		if (_strchr(d, s[index]) == 0 && s[index + 1] == '\0')
		{
			new = s + index + 1;
			*new = '\0';
			s = s + line;
			return (s);
		}
		else if (_strchr(d, s[index]) == 0 && _strchr(d, s[index + 1]) == 0)
			index++;
		else if (_strchr(d, s[index]) == 0 && _strchr(d, s[index + 1]) == 1)
		{
			new = s + index + 1;
			*new = '\0';
			new++;
			s = s + line;
			return (s);
		}
		else if (_strchr(d, s[index]) == 1)
		{
			line++;
			index++;
		}
	}
	return (NULL);
}
