/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:06:43 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 17:04:20 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_s(char *s, int size, int n)
{
	unsigned int	nb;

	s[size] = '\0';
	if (n == 0)
		s[0] = '0';
	else
	{
		if (n < 0)
			nb = -n;
		else
			nb = n;
		while (nb)
		{
			s[size - 1] = (nb % 10) + 48;
			nb /= 10;
			size--;
		}
	}
	if (n < 0)
		s[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*s;
	int		nb;
	int		size;

	size = 0;
	nb = n;
	if (n <= 0)
		size++;
	while (nb)
	{
		size++;
		nb /= 10;
	}
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	ft_s(s, size, n);
	return (s);
}
/*
#include <stdio.h>

int main(void)
{
	char *s = NULL;
    printf("=== Test ft_itoa ===\n\n");

    int tests[5] = {0, 7, -42, 2147483647, -2147483648};
    for (int i = 0; i < 5; i++)
    {
        s = ft_itoa(tests[i]);
        printf("ft_itoa(%d) = \"%s\"\n", tests[i], s);
	printf("%ld", ft_strlen(s));
    }
    free(s);
    return 0;
}
*/
