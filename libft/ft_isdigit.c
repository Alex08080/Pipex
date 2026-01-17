/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:32:00 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 17:56:52 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char tests[] = {'0', '5', '9', 'a', 'Z', ' ', '-', '\n'};
    int i;
    int size = sizeof(tests) / sizeof(tests[0]);

    printf("=== Test de ft_isdigit ===\n\n");

    for (i = 0; i < size; i++)
    {
        char c = tests[i];
        printf("'%c' : ft_isdigit = %d | isdigit = %d\n",
               (c >= 32 && c <= 126) ? c : '?', 
	       ft_isdigit(c), isdigit(c));
    }

    return 0;
}
*/
