#include "hsh.h"

/**
 * _strdup()- does stuff
 * @str: the string in question
 *
 * Return: pointer to string
 */

char *_strdup(char *str)
{
	unsigned int i, j;
	char *arr;

	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	arr = malloc(sizeof(char) * (i + 1));

	if (arr == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		arr[j] = str[j];
	}
	arr[i] = '\0';
	return (arr);
}

/**
 * _str_concat()- concatenates!
 * @s1: string 1!
 * @s2: string 2!
 *
 * Return: pointer to concatenated string!
 */

char *_str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int k, l, len1, len2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
	{
		return (NULL);
	}
	for (k = 0; k < len1; k++)
	{
		concat[k] = s1[k];
	}
	for (l = 0; l < len2; l++)
	{
		concat[k] = s2[l];
		k++;
	}
	concat[k] = '\0';

	return (concat);
}

/**
 * _strlen()- gives length of string
 * @str: string in question
 *
 * Return: length of string
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strstr()- finds a string in another string
 * @haystack: the string in question
 * @needle: the string to find
 *
 * Return: pointer to pos in haystack where needle lives
 */

char *_strstr(char *haystack, char *needle)
{
	int i, j, count, len;

	len = 55;
	for (i = 0; haystack[i] != '\0'; i++)
	{
		count = 0;
		if (haystack[i] == needle[0])
		{
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[(i + j)] == needle[j])
				{
					count++;
				}
				if (needle[(j + 1)] == '\0')
				{
					len = j + 1;
				}
			}
		}
		if (needle[0] == '\0')
		{
			return (haystack);
		}
		if (count == len)
		{
			return (haystack + i);
		}
	}
	return (NULL);
}

/**
 * _strcmp()- works JUST like strcmp, compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int sign, lens1, lens2, i, output;

	i = 0;
	sign = 1;
	lens1 = 0;
	lens2 = 0;
	output = 0;
	while (s1[lens1] != '\0')
	{
		lens1++;
	}
	while (s2[lens2] != '\0')
	{
		lens2++;
	}
	if (lens2 > lens1)
	{
		sign = -1;
	}
	for (i = 0; i < lens1; i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
			{
				output = ((s1[i] - s2[i]) * sign);
				break;
			}
			else
			{
				output = ((s2[i] - s1[i]) * sign);
				break;
			}
		}
	}
	return (output);
}
