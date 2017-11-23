/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:35:23 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/20 20:21:38 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		word_counter(char *str)
{
	int	i;
	int s;
	int len;
	int wlen;

	i = 0;
	s = 0;
	len = ft_strlen(str);
	wlen = 0;
	while (i <= len)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (s == 1)
			{
				wlen++;
				s = 0;
			}
		}
		else
		{
			if (s == 0)
			{
				s = 1;
			}
		}
		i++;
	}
	return (wlen);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int i;

	i = 0;
	while ((src + i) && i < n)
	{
		dst[i] = *(src + i);
		i++;
	}
	dst[n] = '\0';
	return (dst);
}

char	**ft_strsplit(char **strarr, char *str, int wlen)
{
	int	i;
	int s;
	int len;
	int cc;
	int wc;

	i = 0;
	s = 0;
	cc = 0;
	wc = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == ' ' || str[i] == '\0' || str[i] == '\t')
		{
			if (s == 1)
			{
				strarr[wc] = (char*)malloc(sizeof(char) * (cc + 1));
				strarr[wc] = ft_strncpy(strarr[wc], str + i - cc, cc);
				wc++;
				cc = 0;
				s = 0;
			}
		}
		else
		{
			if (s == 0)
			{
				s = 1;
			}
			cc++;
		}
		i++;
	}
	strarr[wlen] = 0;
	return (strarr);
}

int	main(int argc, char **argv)
{
	char	**strarr;
	int		wlen;

	if (argc > 1)
	{
		wlen = word_counter(argv[1]);
		strarr = (char **)malloc(sizeof(char*) * (wlen + 1));
		strarr = ft_strsplit(strarr, argv[1], wlen);
		int i = 1;
		while (strarr[i])
		{
			ft_putstr(strarr[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putstr(strarr[0]);		
	}
	ft_putchar('\n');
	return (0);
}
