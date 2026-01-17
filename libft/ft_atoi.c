/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:04:05 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 21:08:00 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		nb;
	int		sign;
	size_t	i;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("=== Test ft_atoi ===\n\n");

    char *tests[] = {"42", "   -42", "+123", "0", 
    "abc", "  2147483647", "-2147483648"};
    int i;

    for (i = 0; i < 7; i++)
        printf("\"%s\" → ft_atoi = %d | atoi = %d\n", 
	tests[i], ft_atoi(tests[i]), atoi(tests[i]));

    return 0;
}
*/
