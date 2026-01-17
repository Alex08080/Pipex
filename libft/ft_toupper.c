/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:21:36 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 17:56:06 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("=== Test ft_toupper ===\n\n");
    char tests[] = {'a', 'z', 'A', 'Z', '1', '!', '\n'};
    int i;

    for (i = 0; i < 7; i++)
        printf("'%c' → ft_toupper = '%c' | toupper = '%c'\n",
       	tests[i], ft_toupper(tests[i]), toupper(tests[i]));

    return 0;
}
*/
