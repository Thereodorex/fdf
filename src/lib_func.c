//
// Created by Hugor Chau on 2020-01-11.
//

#include "../includes/header.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	a;
	char	*my_s;

	a = 0;
	my_s = (char *)s;
	while (a < n)
		my_s[a++] = '\0';
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*new;

	if (!s1 || !s2)
		return (0);
	j = ft_strlen(s1);
	i = ft_strlen(s2);
	if ((i + j < i) || (i + j) < j)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_strnew(i + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	return (new);
}

char		*ft_itoa(int n)
{
	char		*res;
	size_t		i;
	long		a;

	a = n;
	i = 1;
	if (n < 0)
		i++;
	while ((n = n / 10) != 0 && (i + 1) > 0)
		i++;
	if (!(res = ft_strnew(i)))
		return (NULL);
	if (a == 0)
		res[0] = '0';
	if (a < 0)
	{
		res[0] = '-';
		a = a * -1;
	}
	while (a != 0)
	{
		res[--i] = a % 10 + 48;
		a = a / 10;
	}
	return (res);
}
