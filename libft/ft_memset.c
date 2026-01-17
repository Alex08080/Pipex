/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:37:15 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 14:38:44 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *) s;
	while (i < n)
	{
		*dest = c;
		i++;
		dest++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[20] = "";
    char str2[20] = "";

    printf("=== Test ft_memset ===\n\n");

    printf("Avant : %s\n", str1);
    ft_memset(str1, '*', 5);
    memset(str2, '*', 5);
    printf("Après  ft_memset : %s\n", str1);
    printf("Après  memset    : %s\n", str2);

    return 0;
}
*/
