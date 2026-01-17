/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:11:12 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 15:33:23 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t count)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < count)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest1[20] = "ABCDEFGHIJ";
    char dest2[20] = "ABCDEFGHIJ";
    char src[] = "12345";

    printf("=== Test ft_memcpy ===\n\n");

    ft_memcpy(NULL, NULL, 5);
    memcpy(dest2, src, 5);

    printf("Résultat ft_memcpy : %s\n", dest1);
    printf("Résultat memcpy    : %s\n", dest2);

    return 0;
}
*/
