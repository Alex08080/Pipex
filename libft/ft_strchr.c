/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:51:55 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 15:07:14 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	while (i <= len_s)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
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
    printf("=== Test ft_strchr ===\n\n");

    printf("Recherche 'o' : ft_strchr = %s | strchr = %s\n",
    ft_strchr(str, 'o'), strchr(str, 'o'));
    printf("Recherche 'z' : ft_strchr = %s | strchr = %s\n", 
    ft_strchr(str, 'z'), strchr(str, 'z'));
    printf("Recherche '\\0' : ft_strchr = %s | strchr = %s\n",
    ft_strchr(str, '\0'), strchr(str, '\0'));

    return 0;
}
*/
