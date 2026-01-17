/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:07:45 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 15:10:21 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s);
	while (len != -1)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Hello World!";
    printf("=== Test ft_strrchr ===\n\n");

    printf("Dernier 'o' : ft_strrchr = %s | strrchr = %s\n",
    ft_strrchr(str, 'o'), strrchr(str, 'o'));
    printf("Recherche 'H' : ft_strrchr = %s | strrchr = %s\n", 
    ft_strrchr(str, 'H'), strrchr(str, 'H'));
    printf("Recherche 'z' : ft_strrchr = %s | strrchr = %s\n",
    ft_strrchr(str, 'z'), strrchr(str, 'z'));
    printf("Recherche '\\0' : ft_strrchr = %s | strrchr = %s\n",
    ft_strrchr(str, '\0'), strrchr(str, '\0'));

    return 0;
}
*/
