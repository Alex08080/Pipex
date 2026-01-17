/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:16:15 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 15:33:17 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (count != 0)
		{
			((unsigned char *)dest)[count - 1]
				= ((unsigned char *)src)[count - 1];
			count--;
		}
	}
	else
	{
		while (i < count)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[30] = "1234567890";
    char str2[30] = "1234567890";

    printf("=== Test ft_memmove ===\n\n");

    printf("Avant : %s\n", str1);
    ft_memmove(str2, str1, 5);
    memmove(str2 + 2, str2, 5);
    printf("Après  ft_memmove : %s\n", str1);
    printf("Après  memmove    : %s\n", str2);

    return 0;
}
*/
