/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:06:16 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 14:33:00 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int tests[] = {-5, 0, 31, 65, 127, 128, 255};
    int i;
    int size = sizeof(tests) / sizeof(tests[0]);

    printf("=== Test de ft_isascii ===\n\n");

    for (i = 0; i < size; i++)
    {
        int c = tests[i];
        printf("%3d : ft_isascii = %d | isascii = %d\n",
               c, ft_isascii(c), isascii(c));
    }

    return 0;
}
*/
