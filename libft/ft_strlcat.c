/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:28:52 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 15:29:05 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size < len_dest + 1)
		return (size + len_src);
	while (src[i] != '\0' && i < size - len_dest - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main(void)
{
    char dest1[20] = "Hello ";
    char dest2[20] = "Hello ";
    char src[] = "World!";
    size_t n = 4;

    printf("=== Test ft_strlcat ===\n\n");

    size_t r1 = ft_strlcat(dest1, src, n);
    size_t r2 = strlcat(dest2, src, n);

    printf("ft_strlcat : \"%s\" (ret = %zu)\n", dest1, r1);
    printf("strlcat    : \"%s\" (ret = %zu)\n", dest2, r2);

    return 0;
}
*/
