/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:14:07 by amoderan          #+#    #+#             */
/*   Updated: 2025/11/10 16:51:02 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

char add_index(unsigned int i, char c)
{
    return (c + i);
}

int main(void)
{
    printf("=== Test ft_strmapi ===\n\n");

    char *s = "abcd";
    char *res = ft_strmapi(s, add_index);

    printf("Original : %s\nModifié : %s\n", s, res);
    free(res);

    return 0;
}
*/
