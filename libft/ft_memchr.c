/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:23:17 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 14:47:34 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((const unsigned char *)buf)[i] == (unsigned char) c)
			return ((unsigned char *)buf + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Hello World!";
    char *res1, *res2;

    printf("=== Test ft_memchr ===\n\n");

    res1 = ft_memchr(str, 'W', strlen(str));
    res2 = memchr(str, 'W', strlen(str));

    printf("Recherche de 'W' :\n");
    printf("ft_memchr -> %s\n", res1 ? res1 : "(null)");
    printf("memchr    -> %s\n", res2 ? res2 : "(null)");

    res1 = ft_memchr(str, 'x', strlen(str));
    res2 = memchr(str, 'x', strlen(str));

    printf("\nRecherche de 'x' :\n");
    printf("ft_memchr -> %s\n", res1 ? res1 : "(null)");
    printf("memchr    -> %s\n", res2 ? res2 : "(null)");

    return 0;
}
*/
