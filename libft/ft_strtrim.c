/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:47:13 by amoderan          #+#    #+#             */
/*   Updated: 2026/01/22 02:00:18 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (i != ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_begin(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (is_set(set, s[i]))
		i++;
	return (i);
}

size_t	ft_end(char const *s, char const *set)
{
	size_t	i;

	if (!ft_strlen(s))
		return (0);
	i = ft_strlen(s) - 1;
	while (i > 0 && is_set(set, s[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*s;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(set))
		return (ft_strdup(s1));
	if (!ft_strlen(s1))
		return (ft_strdup(""));
	begin = ft_begin(s1, set);
	end = ft_end(s1, set);
	if (begin > end)
		return (ft_strdup(""));
	s = malloc(sizeof(char) * (end - begin + 2));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1 + begin, end - begin + 2);
	return (s);
}

/*
#include <stdio.h>

int main(void)
{
    printf("=== Test ft_strtrim ===\n\n");

    char s1[] = "lorem ipsum dolor sit amet";
	 
    printf("len de s : %ld\n", ft_strlen(s1));
    char *set = "te";
    char *res = ft_strtrim(s1, set);


    printf("Avant : \"%s\"\nAprès : \"%s\"\n", s1, res);
    free(res);

    return 0;
}
*/
