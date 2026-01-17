/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:40:55 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 15:38:04 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len_s;
	char	*dup;

	i = 0;
	len_s = ft_strlen(s);
	dup = malloc(sizeof(char) * (len_s + 1));
	if (!dup)
		return (NULL);
	while (i < len_s)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    printf("=== Test ft_strdup ===\n\n");

    char *s = "Hello Libft!";
    char *dup1 = ft_strdup(s);
    char *dup2 = strdup(s);

    printf("ft_strdup : %s\n", dup1);
    printf("strdup    : %s\n", dup2);

    free(dup1);
    free(dup2);

    return 0;
}
*/
