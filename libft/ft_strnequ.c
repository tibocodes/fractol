/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:16:46 by tfolly            #+#    #+#             */
/*   Updated: 2015/12/05 15:19:50 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	j;

	if (s1 && s2)
	{
		j = 0;
		if (n == 0)
			return (1);
		while (j < n && *s1)
		{
			if (*s1 == *s2)
			{
				s1++;
				s2++;
				j++;
			}
			else
			{
				return (0);
			}
		}
		return ((*s1 == *s2 || j == n) ? 1 : 0);
	}
	return (0);
}
