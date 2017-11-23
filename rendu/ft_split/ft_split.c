/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 20:25:30 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/20 20:28:35 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		if (str[i] == ' ' || str[i] == '\0' || str[i] == '\t' || str[i] == '\n')
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

char    **ft_split(char *str)
{
	char	**strarr;
	int		wlen;


	wlen = word_counter(str);
	strarr = (char **)malloc(sizeof(char*) * (wlen + 1));
	strarr = ft_strsplit(strarr, str, wlen);
	return (strarr);
}
