/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:18:20 by apluzhni          #+#    #+#             */
/*   Updated: 2018/11/08 15:18:40 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_wordcount(const char *s, char c)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1 != c])
			n++;
		i++;
	}
	n++;
	return (n);
}
