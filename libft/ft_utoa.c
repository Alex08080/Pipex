/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 22:39:27 by alex              #+#    #+#             */
/*   Updated: 2025/12/04 23:51:26 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_su(char *s, int size, unsigned int n)
{
	unsigned int	nb;

	s[size] = '\0';
	if (n == 0)
		s[0] = '0';
	else
	{
		nb = n;
		while (nb)
		{
			s[size - 1] = (nb % 10) + 48;
			nb /= 10;
			size--;
		}
	}
}

char	*ft_utoa(unsigned int n)
{
	char				*s;
	unsigned int		nb;
	int					size;

	size = 0;
	nb = n;
	if (n == 0)
		size++;
	while (nb)
	{
		size++;
		nb /= 10;
	}
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	ft_su(s, size, n);
	return (s);
}
