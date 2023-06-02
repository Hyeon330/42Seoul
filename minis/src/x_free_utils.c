#include "minishell.h"

void	free_str_array(char **str_array)
{
	int	i;

	i = 0;
	if (str_array)
	{
		while (str_array[i])
		{
			if (str_array[i])
				free_ptr(str_array[i]);
			i++;
		}
		free_ptr(str_array);
	}
}

void	free_ptr1(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
