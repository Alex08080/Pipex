/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:15:33 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 15:18:12 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n) && s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("=== Test ft_strncmp ===\n\n");

    printf("ft_strncmp(\"abc\", \"abc\", 3) = %d | strncmp = %d\n",
    ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
    printf("ft_strncmp(\"abc\", \"abd\", 3) = %d | strncmp = %d\n",
    ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
    printf("ft_strncmp(\"abc\", \"ab\", 3)  = %d | strncmp = %d\n"
    , ft_strncmp("abc", "ab", 3), strncmp("abc", "ab", 3));

    return 0;
}
*/
