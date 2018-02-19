/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:33:18 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/19 17:32:14 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_number(char *c)
{
	if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%')
	{
		if (is_number(c + 1))
			return (1);
		else
			return (0);
	}
	if (*c >= '0' && *c<= '9')
		return (1);
	else
		return (0);
}

int		is_operator(char *c)
{
	if(*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%')
	{
		if (!is_number(c + 1))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		rpn_calc(char *str)
{
	char	*ptr;
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * 5000);
	i = -1;
	ptr = str;
	while (*ptr)
	{
		if (is_number(ptr))
		{
			i++;
			tab[i] = atoi(ptr);
			ptr++;
			while(is_number(ptr))
				ptr++;
		}
		if (is_operator(ptr))
		{
			if ((i - 1) < 0)
				return (-99997);
			if (*ptr == '/' || *ptr == '%')
				if (tab[i] == 0)
					return (-99997);
			if (*ptr == '+')
				tab[i - 1] = tab[i - 1] + tab[i];
			if (*ptr == '-')
				tab[i - 1] = tab[i - 1] - tab[i];
			if (*ptr == '*')
				tab[i - 1] = tab[i - 1] * tab[i];
			if (*ptr == '/')
				tab[i - 1] = tab[i - 1] / tab[i];
			if (*ptr == '%')
				tab[i - 1] = tab[i - 1] % tab[i];
			i--;
		}
		ptr++;
	}
	if (i != 0)
		return (-99997);
	else
		return (tab[0]);
}
