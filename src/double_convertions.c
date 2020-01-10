/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_convertions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflannel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:23:08 by mflannel          #+#    #+#             */
/*   Updated: 2019/12/05 17:04:46 by mflannel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <limits.h>
#include "../libft/libft.h"

void			dbl_convert_dec(char **str, int *i,
								long double chislo, int accuracy)
{
	int		j;
	int		tmp;
	char	*s;

	chislo *= 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < accuracy)
	{
		tmp = ((int)chislo != 9) ? (int)(chislo + 0.01) : (int)chislo;
		s[(*i)++] = (char)(tmp + 48);
		chislo = (chislo - tmp) * 10;
	}
}

long long int	find_mnozhitel(float chislo, int *size)
{
	long int	mnozhitel;
	long int	extra;

	extra = (long int)(chislo);
	mnozhitel = 1;
	while ((extra /= 10) != 0)
	{
		mnozhitel *= 10;
		size++;
	}
	return (mnozhitel);
}

void			dbl_convert_int(long double *chislo, char **str, int *i,
								long int mnozhitel)
{
	char		*s;
	long int	b;

	b = (long int)*chislo;
	s = *str;
	if (b < 0)
	{
		*chislo *= -1;
		b *= -1;
	}
	*chislo -= (long double)b;
	while (mnozhitel >= 1)
	{
		s[(*i)++] = (char)((b / mnozhitel) + 48);
		b = b - (b / mnozhitel) * mnozhitel;
		mnozhitel /= 10;
	}
}

int				economy(double chislo)
{
	char	*str;
	int		k;

	str = ft_itoa(chislo);
	k = ft_strlen(str);
	ft_strdel(&str);
	return (k);
}

char			*lf_conversion(double get_d)
{
	int			i;
	long double	chislo;
	int			size;
	char		*str;
	int			sign;

	chislo = get_d;
	i = 0;
	size = 1;
	sign = 0;
	if (chislo < 0)
		sign = 1;
	size += 3;
	size += (economy(chislo) + sign);
	str = ft_strnew(100 + 1);
	if (sign == 1)
	{
		str[i++] = '-';
		chislo *= -1;
	}
	dbl_convert_int(&chislo, &str, &i, (find_mnozhitel(chislo, &size)));
	dbl_convert_dec(&str, &i, chislo, (economy(chislo) + 3 + sign));
	str[i - 1] = '\0';
	str[i - 2] = sign == 1 ? '\0' : str[i - 2];
	return (str);
}
