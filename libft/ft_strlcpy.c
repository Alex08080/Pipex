/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:36:08 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 20:11:10 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main(void)
{
    char src[] = "Hello World";
    char dest1[20];
    char dest2[20];

    printf("=== Test ft_strlcpy ===\n\n");
    size_t n = 6;

    size_t r1 = ft_strlcpy(dest1, src, n);
    size_t r2 = strlcpy(dest2, src, n);

    printf("ft_strlcpy : \"%s\" (ret = %zu)\n", dest1, r1);
    printf("strlcpy    : \"%s\" (ret = %zu)\n", dest2, r2);

    return 0;
}
*/
