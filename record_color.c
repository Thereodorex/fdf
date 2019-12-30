
#include "header.h"

static int		get_color(char *ptr)
{
	int		res;
	
	while (*ptr && *ptr != ' ')
	{
		if (*ptr >= '0' && *ptr <= '9')
			res = res * 16 + *ptr - '0';
		else if (*ptr >= 'A' && *ptr <= 'F')
			res = res * 16 + *ptr - 'A' + 10;
		else if (*ptr >= 'a' && *ptr <= 'f')
			res = res * 16 + *ptr - 'a' + 10;
		else
			break ;
		ptr--;
	}
	if (*ptr != 'x' || *(ptr - 1) != '0')
		return (-1);
	return (res);
}

char	*record_color(char *ptr, int *color)
{
	int 	res;
	char	*to_return;

	res = 0;
	ptr += 2;
	while (*ptr && *ptr != ' ' && *ptr != '\n')
		ptr++;
	*color = get_color(ptr - 1);
	return (*color == -1 ? ptr - 1 : ptr);
}
