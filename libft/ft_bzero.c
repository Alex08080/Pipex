/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 20:33:41 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 17:32:13 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char *) s;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h> 

int main(void)
{
    printf("=== Test ft_bzero ===\n\n");

    char buf1[10] = "123456789";
    char buf2[10] = "123456789";

    printf("Avant bzero :\n");
    printf("buf1 = %s\n", buf1);
    printf("buf2 = %s\n\n", buf2);

    ft_bzero(buf1 + 3, 4);
    bzero(buf2 + 3, 4);

    printf("Après ft_bzero et bzero :\n");
    printf("Affichage en hexadécimal pour visualiser les 0 :\n");

    printf("ft_bzero : ");
    for (int i = 0; i < 9; i++)
        printf("%02x ", (unsigned char)buf1[i]);
    printf("\n");

    printf("bzero    : ");
    for (int i = 0; i < 9; i++)
        printf("%02x ", (unsigned char)buf2[i]);
    printf("\n");

    printf("\nAffichage en texte (les \\0 n’apparaissent pas) :\n");
    printf("ft_bzero : %s\n", buf1);
    printf("bzero    : %s\n", buf2);

    return 0;
}
*/
