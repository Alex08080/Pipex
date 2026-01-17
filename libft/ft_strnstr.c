/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:43:57 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 15:25:33 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little [0])
		{
			while (i + j < len && big[i + j]
				&& little[j] && big[i + j] == little[j])
				j++;
			if (j == ft_strlen(little))
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main(void)
{
    char haystack[] = "Hello 42 Network!";
    char needle1[] = "42";
    char needle2[] = "NotFound";

    printf("=== Test ft_strnstr ===\n\n");

    printf("ft_strnstr(\"%s\", \"%s\", 15) = %s\n", 
    haystack, needle1, ft_strnstr(haystack, needle1, 15));
    printf("strnstr(\"%s\", \"%s\", 15)    = %s\n", 
    haystack, needle1, strnstr(haystack, needle1, 15));

    printf("\nft_strnstr(\"%s\", \"%s\", 15) = %s\n", 
    haystack, needle2, ft_strnstr(haystack, needle2, 15));
    printf("strnstr(\"%s\", \"%s\", 15)    = %s\n",
    haystack, needle2, strnstr(haystack, needle2, 15));

    return 0;
}
*/
