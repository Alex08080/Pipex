/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:10:21 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 17:55:05 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tests[] = {'A', ' ', '~', 31, 127, '\n'};
    int i;
    int size = sizeof(tests) / sizeof(tests[0]);

    printf("=== Test de ft_isprint ===\n\n");

    for (i = 0; i < size; i++)
    {
        char c = tests[i];
        printf("'%c' : ft_isprint = %d | isprint = %d\n",
               (c >= 32 && c <= 126) ? c : '?',
               ft_isprint(c), isprint(c));
    }

    return 0;
}
*/
