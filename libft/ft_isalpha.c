/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:42:06 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 14:23:33 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    char tests[] = {'A', 'z', 'M', '1', '*', ' ', '\n', 't', 'Z'};
    int i;
    int size = sizeof(tests) / sizeof(tests[0]);

    printf("=== Test de ft_isalpha ===\n\n");

    for (i = 0; i < size; i++)
    {
        char c = tests[i];
        int result = ft_isalpha(c);

        if (c == '\n')
            printf("'\\n' : %d\n", result);
        else if (c == ' ')
            printf("' ' (espace) : %d\n", result);
        else
            printf("'%c' : %d\n", c, result);
    }

    return 0;
}
*/
