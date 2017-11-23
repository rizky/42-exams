/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:22:45 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/20 19:35:54 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	hidenp(char *word, char *str)
{
	int hide;
	int i;
	int j;

	hide = 0;
	i = 0;
	j = 0;
	while (str[i] && word[j])
	{
		if (str[i] == word[j])
			j++;
		i++;
	}

	if (word[j] == '\0')
		hide = 1;
	return (hide);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (hidenp(argv[1], argv[2]))
			ft_putchar('1');
		else
			ft_putchar('0');
	}
	ft_putchar('\n');
	return (0);
}
