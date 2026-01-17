/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:35:07 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 14:27:46 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tests[] = {'A', 'z', '0', '9', '!', ' ', '_', 'm'};
    int i;
    int size = sizeof(tests) / sizeof(tests[0]);

    printf("=== Test de ft_isalnum ===\n\n");

    for (i = 0; i < size; i++)
    {
        char c = tests[i];
        printf("'%c' : ft_isalnum = %d | isalnum = %d\n",
               (c >= 32 && c <= 126) ? c : '?',
               ft_isalnum(c), isalnum(c));
    }

    return 0;
}
*/
