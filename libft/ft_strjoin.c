/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:27:20 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 16:14:47 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}
/*
#include <stdio.h>

int main(void)
{
    printf("=== Test ft_strjoin ===\n\n");

    char *s1 = "Hello ";
    char *s2 = "World!";
    char *res = ft_strjoin(s1, s2);

    printf("ft_strjoin(\"%s\", \"%s\") = \"%s\"\n", s1, s2, res);
    free(res);

    res = ft_strjoin("", "42");
    printf("ft_strjoin(\"\", \"42\") = \"%s\"\n", res);
    free(res);

    return 0;
}
*/
