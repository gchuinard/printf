#include "holberton.h"

/**
 * _strlen - return the size of a string.
 *
 * @str: the string.
 *
 * Return: the size of the string or 0.
 */

size_t	_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (str != NULL)
	{
		while (*(str++))
		{
			len++;
		}
	}
	return (len);
}

char	*_strrev(char *str)
{
	unsigned int	i;
	size_t		j;
	char		c;

	i = 0;
	if (!str)
		return (NULL);
	j = _strlen(str);
	j--;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

char	*_convert_base(unsigned int nbr, int base, int cap)
{
	char		b16[] = "0123456789abcdef";
	char		B16[] = "0123456789ABCDEF";
	char		*result;
	int		i;
	unsigned int	n;
	int		count;
	
	i = 0;
	n = nbr;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	result = (char *)malloc(sizeof(char) * count + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	n = nbr;
	while (n != 0)
	{
		if (cap == 1)
		{
			result[i] = B16[n % base];
		}
		else
		{
			result[i] = b16[n % base];
		}
		n /= base;
		i++;
	}
	result[i] = '\0';
	return (_strrev(result));
}
