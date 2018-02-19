/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:31:09 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/19 19:33:38 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		rpn_calc(char *str, int *result);

int main(int ac, char **av)
{
	int	result;

	result = 0;
	if(ac != 2)
		printf("Error\n");
	else
	{
		if (rpn_calc(av[1], &result) == -1)
			printf("Error\n");
		else
			printf("%d\n", result);
	}
	return (0);
}


