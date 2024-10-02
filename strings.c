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

char *_str_char_concat(char *s1, char a, char *s2)
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
	concat = malloc(sizeof(char) * (len1 + len2 + 2));
	if (concat == NULL)
	{
		return (NULL);
	}
	for (k = 0; k < len1; k++)
	{
		concat[k] = s1[k];
	}
	concat[k++] = a;
	for (l = 0; l < len2; l++)
	{
		concat[k++] = s2[l];
	}
	concat[k] = '\0';

	return (concat);
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
	int i, j;

	if (*needle == '\0')
		return (NULL);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[i])
		{
			for (j = 0; needle[j] != '\0'; i++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
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
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strncmp()- works JUST like strncmp, compares two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to check
 *
 * Return: int
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}

		if ((s1[i] == '\0') || (s2[i] == '\0'))
		{
			return (0);
		}
	}
	return (0);
}
