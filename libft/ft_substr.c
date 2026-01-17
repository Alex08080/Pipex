/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:01:20 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/11 15:29:02 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len >= len_s - start)
		len = len_s - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int main(void)
{
    printf("=== Test ft_substr ===\n\n");

    char s[15] = "Hello World!";
    char *res;

    res = ft_substr(s, 0, 5);
    printf("ft_substr(\"%s\", 0, 5) = \"%s\"\n", s, res);
    free(res);

    res = ft_substr(s, 6, 10);
    printf("ft_substr(\"%s\", 6, 10) = \"%s\"\n", s, res);
    free(res);

    res = ft_substr(s, 20, 5);
    printf("ft_substr(\"%s\", 20, 5) = \"%s\"\n", s, res);
    free(res);

    return 0;
}
*/
