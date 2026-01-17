/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:12:55 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 17:59:13 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("=== Test ft_strlen ===\n\n");
    char *tests[] = {"Hello", "", "42", "C programming", "!"};
    int i;

    for (i = 0; i < 5; i++)
        printf("\"%s\" → ft_strlen = %zu | strlen = %zu\n",
       	tests[i], ft_strlen(tests[i]), strlen(tests[i]));

    return 0;
}
*/
