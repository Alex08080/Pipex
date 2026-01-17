/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:30:52 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 17:57:09 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((const unsigned char *)buf1)[i]
				!= ((const unsigned char *)buf2)[i])
			return (((const unsigned char *)buf1)[i]
					- ((const unsigned char *)buf2)[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[] = "abcdef";
    char s2[] = "abcdeg";
    char s3[] = "abcdef";

    printf("=== Test ft_memcmp ===\n\n");

    printf("s1 : %s  s2 : %s  s3 : %s\n",s1,s2,s3);
    printf("Comparaison s1 / s2 :\n");
    printf("ft_memcmp : %d\n", ft_memcmp(s1, s2, 6));
    printf("memcmp    : %d\n", memcmp(s1, s2, 6));

    printf("\nComparaison s1 / s3 :\n");
    printf("ft_memcmp : %d\n", ft_memcmp(s1, s3, 6));
    printf("memcmp    : %d\n", memcmp(s1, s3, 6));

    return 0;
}
*/
