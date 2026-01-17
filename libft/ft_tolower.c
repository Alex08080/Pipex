/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:30:00 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 17:57:56 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("=== Test ft_tolower ===\n\n");
    char tests[] = {'A', 'Z', 'a', 'z', '5', '#'};
    int i;

    for (i = 0; i < 6; i++)
        printf("'%c' → ft_tolower = '%c' | tolower = '%c'\n",
       	tests[i], ft_tolower(tests[i]), tolower(tests[i]));

    return 0;
}
*/
