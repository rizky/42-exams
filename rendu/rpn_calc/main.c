/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:31:09 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/19 17:25:37 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     rpn_calc(char *str);

int main(int ac, char **av)
{
	int	result;

	result = 0;
	if(ac != 2)
		printf("Error\n");
	else
	{
		result = rpn_calc(av[1]);
		if (result == -99997)
			printf("Error\n");
		else
			printf("%d\n", result);
	}
	return (0);
}


