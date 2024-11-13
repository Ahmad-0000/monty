#include <stdlib.h>
#include "monty.h"

void freestack(stack_t *rear)
{
	if (!rear)
		return;
	while (rear->prev)
	{
		rear = rear->prev;
		free(rear->next);
	}
	free(rear);
}

void freewarray(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
		free(array[i]);
	free(array[i]);
	free(array);
}
