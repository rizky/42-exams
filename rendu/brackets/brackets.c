/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:40:23 by rnugroho          #+#    #+#             */
/*   Updated: 2018/02/19 19:14:02 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_open_bracket(char c)
{
	if (c == '{' || c == '(' || c == '[')
		return (1);
	else
		return (0);
}

int		is_close_bracket(char c)
{
	if (c == '}' || c == ')' || c == ']')
		return (1);
	else
		return (0);
}

int		is_pair(char c1, char c2)
{
	if (c1 == '[' && c2 == ']')
		return (1);
	if (c1 == '{' && c2 == '}')
		return (1);
	if (c1 == '(' && c2 == ')')
		return (1);
	return (0);
}

int		brackets(char *str)
{
	char	bracket_tab[5000];
	int		index;
	char	*ptr;

	index = -1;
	ptr = str;
	while (*ptr)
	{
		if (is_open_bracket(*ptr))
		{
			index++;
			bracket_tab[index] = *ptr;
		}
		else if (is_close_bracket(*ptr))
		{
			if (is_pair(bracket_tab[index], *ptr))
				index--;
			else
				return (0);
		}
		ptr++;
	}
	if (index >= 0)
		return (0);
	else
		return (1);
}
