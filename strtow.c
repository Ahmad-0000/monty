#include <stdlib.h>
#include "monty.h"
#include <stdio.h>

int WordsCounting(char *str)
{
	int i, wordnum = 0, inWord = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && str[i] != '\t' && inWord == 0)
		{
			wordnum++;
			inWord = 1;
		}
		else if (str[i] == ' ' || str[i] == '\t')
		{
			inWord = 0;
		}
	}
	return (wordnum);
}

char *ext(char *ps, int *ps2)
{
	int i, length;
	char *word;

	for (length = 0; *ps != ' ' && *ps != '\n' && *ps != '\0' && *ps != '\t'; length++)
		ps++;
	for (i = 0; i < length; i++)
		ps--;
	word = malloc(sizeof(*word) * (length + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = *ps;
		ps++;
		i++;
		(*ps2)++;
	}
	word[i] = '\0';
	return (word);
}

char **strtow(char *str)
{
	int words, i, j;
	char **warray;

	if (!str || !(*str))
		return (NULL);
	words = WordsCounting(str);
	if (!words)
		return (NULL);
	warray = malloc(sizeof(char *) * (words + 1));
	if (!warray)
		return (NULL);
	for (i = 0; i < words + 1; i++)
		warray[i] = NULL;
	for (i = 0; str[i] == ' '; i++)
		;
	j = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			warray[j] = ext(str + i, &i);
			words++;
			if (!warray[j])
			{
				freewarray(warray);
				return (NULL);
			}
			j++;
		}
		else
		{
			i++;
		}
	}
	return (warray);
}
